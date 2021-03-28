/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
 *
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
 *  Name        : cslr_cal.h
*/
#ifndef CSLR_CAL_H_
#define CSLR_CAL_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : cal_regs registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MOD_VER;                   /* Module and Version */
    volatile uint32_t COS;                       /* Class of Service */
    volatile uint32_t VID_MUX_CTRL;              /* Video Muc Control */
    volatile uint32_t PSI_CTRL;                  /* PSI Control */
    volatile uint32_t PSI_MAP;                   /* PSI Mapping register */
    volatile uint32_t PSI_TAG;                   /* PSI Tag Register */
    volatile uint32_t CAL_MODE;                  /* Cal Baseline Mode */
    volatile uint8_t  Resv_128[100];
    volatile uint32_t TE_GRP_03_00;              /* Trace Event Group 03 to 00 */
    volatile uint32_t TE_GRP_07_04;              /* Trace Event Group 07 to 04 */
    volatile uint8_t  Resv_1024[888];
} CSL_calRegs_top;


typedef struct {
    volatile uint32_t CTRL;                      /* Region Control Register */
    volatile uint32_t BASE;                      /* Region Base Register */
    volatile uint32_t TRANS_L;                   /* Region Translated Lower Address */
    volatile uint32_t TRANS_U;                   /* Region Translated Upper Address */
} CSL_calRegs_rat_region;


typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CONFIG;                    /* Config Register */
    volatile uint8_t  Resv_32[24];
    CSL_calRegs_rat_region REGION[16];
    volatile uint8_t  Resv_2052[1764];
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_2080[24];
    volatile uint32_t EXCEPTION_LOGGING_CONTROL;   /* Exception Logging Control Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_2112[4];
    volatile uint32_t EXCEPTION_PEND_SET;        /* Exception Logging Interrupt Pending Set Register */
    volatile uint32_t EXCEPTION_PEND_CLEAR;      /* Exception Logging Interrupt Pending Clear Register */
    volatile uint32_t EXCEPTION_ENABLE_SET;      /* Exception Logging Interrupt Enable Set Register */
    volatile uint32_t EXCEPTION_ENABLE_CLEAR;    /* Exception Logging Interrupt Enable Clear Register */
    volatile uint32_t EOI_REG;                   /* EOI Register */
    volatile uint8_t  Resv_4096[1964];
} CSL_calRegs_rat;


typedef struct {
    volatile uint32_t REVISION;
    volatile uint8_t  Resv_16[12];
    volatile uint32_t SYSCONFIG;
    volatile uint32_t CAMCFG;
    volatile uint8_t  Resv_28[4];
    volatile uint32_t IRQ_EOI;
    volatile uint32_t IRQSTATUS_RAW_0;
    volatile uint32_t IRQSTATUS_0;
    volatile uint32_t IRQENABLE_SET_0;
    volatile uint32_t IRQENABLE_CLR_0;
    volatile uint32_t IRQSTATUS_RAW_1;
    volatile uint32_t IRQSTATUS_1;
    volatile uint32_t IRQENABLE_SET_1;
    volatile uint32_t IRQENABLE_CLR_1;
    volatile uint32_t IRQSTATUS_RAW2_2;
    volatile uint32_t IRQSTATUS_2;
    volatile uint32_t IRQENABLE_SET_2;
    volatile uint32_t IRQENABLE_CLR_2;
    volatile uint32_t IRQSTATUS_RAW_3;
    volatile uint32_t IRQSTATUS_3;
    volatile uint32_t IRQENABLE_SET_3;
    volatile uint32_t IRQENABLE_CLR_3;
    volatile uint32_t CAM1_CFG;
    volatile uint32_t CAM1_FRMSIZE;
    volatile uint32_t CAM1_MAXWIDTH;
    volatile uint32_t CAM1_SYNCSOF;
    volatile uint32_t CAM1_SYNCEOF;
    volatile uint32_t CAM1_SYNCSOL;
    volatile uint32_t CAM1_SYNCEOL;
    volatile uint32_t CAM1_SYNCSOV;
    volatile uint32_t CAM2_CFG;
    volatile uint32_t CAM2_FRMSIZE;
    volatile uint32_t CAM2_MAXWIDTH;
    volatile uint32_t CAM2_SYNCSOF;
    volatile uint32_t CAM2_SYNCEOF;
    volatile uint32_t CAM2_SYNCSOL;
    volatile uint32_t CAM2_SYNCEOL;
    volatile uint32_t CAM2_SYNCSOV;
    volatile uint32_t CAM3_CFG;
    volatile uint32_t CAM3_FRMSIZE;
    volatile uint32_t CAM3_MAXWIDTH;
    volatile uint32_t CAM3_SYNCSOF;
    volatile uint32_t CAM3_SYNCEOF;
    volatile uint32_t CAM3_SYNCSOL;
    volatile uint32_t CAM3_SYNCEOL;
    volatile uint32_t CAM3_SYNCSOV;
    volatile uint32_t CAM4_CFG;
    volatile uint32_t CAM4_FRMSIZE;
    volatile uint32_t CAM4_MAXWIDTH;
    volatile uint32_t CAM4_SYNCSOF;
    volatile uint32_t CAM4_SYNCEOF;
    volatile uint32_t CAM4_SYNCSOL;
    volatile uint32_t CAM4_SYNCEOL;
    volatile uint32_t CAM4_SYNCSOV;
    volatile uint32_t WDRCFG;
    volatile uint32_t WDRGN;
    volatile uint32_t WDRKP1;
    volatile uint32_t WDRKP2;
    volatile uint8_t  Resv_256[16];
    volatile uint32_t TEST1;
    volatile uint32_t TEST2;
    volatile uint32_t TEST3;
    volatile uint32_t TEST4;
    volatile uint8_t  Resv_1024[752];
} CSL_calRegs_lvdsrx;


typedef struct {
    volatile uint32_t HL_REVISION;               /* HL_REVISION */
    volatile uint32_t HL_HWINFO;                 /* HL_HWINFO */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t HL_SYSCONFIG;              /* HL_SYSCONFIG */
    volatile uint8_t  Resv_28[8];
    volatile uint32_t HL_IRQ_EOI;                /* HL_IRQ_EOI */
} CSL_calRegs_c2ctl;


typedef struct {
    volatile uint32_t HL_IRQSTATUS_RAW;          /* HL_IRQSTATUS_RAW */
    volatile uint32_t HL_IRQSTATUS;              /* HL_IRQSTATUS */
    volatile uint32_t HL_IRQENABLE_SET;          /* HL_IRQENABLE_SET */
    volatile uint32_t HL_IRQENABLE_CLR;          /* HL_IRQENABLE_CLR */
} CSL_calRegs_c2irq;


typedef struct {
    volatile uint32_t PIX_PROC;                  /* PIX_PROC */
} CSL_calRegs_c2pix;


typedef struct {
    volatile uint32_t CTRL;                      /* CTRL */
    volatile uint32_t CTRL1;                     /* CTRL1 */
    volatile uint32_t LINE_NUMBER_EVT;           /* LINE_NUMBER_EVT */
    volatile uint8_t  Resv_32[20];
    volatile uint32_t VPORT_CTRL1;               /* VPORT_CTRL1 */
    volatile uint32_t VPORT_CTRL2;               /* VPORT_CTRL2 */
    volatile uint8_t  Resv_48[8];
    volatile uint32_t BYS_CTRL1;                 /* BYS_CTRL1 */
    volatile uint32_t BYS_CTRL2;                 /* BYS_CTRL2 */
    volatile uint8_t  Resv_64[8];
    volatile uint32_t RD_DMA_CTRL;               /* RD_DMA_CTRL */
    volatile uint32_t RD_DMA_PIX_ADDR;           /* RD_DMA_PIX_ADDR */
    volatile uint32_t RD_DMA_PIX_OFST;           /* RD_DMA_PIX_OFST */
    volatile uint32_t RD_DMA_XSIZE;              /* RD_DMA_XSIZE */
    volatile uint32_t RD_DMA_YSIZE;              /* RD_DMA_YSIZE */
    volatile uint32_t RD_DMA_INIT_ADDR;          /* RD_DMA_INIT_ADDR */
    volatile uint8_t  Resv_104[16];
    volatile uint32_t RD_DMA_INIT_OFST;          /* RD_DMA_INIT_OFST */
    volatile uint32_t RD_DMA_CTRL2;              /* RD_DMA_CTRL2 */
} CSL_calRegs_c2vid;


typedef struct {
    volatile uint32_t WR_DMA_CTRL;               /* CAL Write DMA Control */
    volatile uint32_t WR_DMA_ADDR;               /* CAL Write DMA Address */
    volatile uint32_t WR_DMA_OFST;               /* CAL Write DMA Offset */
    volatile uint32_t WR_DMA_XSIZE;              /* CAL Write DMA Size */
} CSL_calRegs_WR_DMA;


typedef struct {
    volatile uint32_t CSI2_PPI_CTRL;             /* CSI2_PPI_CTRL */
    volatile uint32_t CSI2_COMPLEXIO_CFG;        /* CSI2_COMPLEXIO_CFG */
    volatile uint32_t CSI2_COMPLEXIO_IRQSTATUS;   /* CSI2_COMPLEXIO_IRQSTATUS */
    volatile uint32_t CSI2_SHORT_PACKET;         /* CSI2_SHORT_PACKET */
    volatile uint32_t CSI2_COMPLEXIO_IRQENABLE;   /* CSI2_COMPLEXIO_IRQENABLE */
    volatile uint32_t CSI2_TIMING;               /* CSI2_TIMING */
    volatile uint32_t CSI2_VC_IRQENABLE;         /* CSI2_VC_IRQENABLE */
    volatile uint8_t  Resv_40[12];
    volatile uint32_t CSI2_VC_IRQSTATUS;         /* CSI2_VC_IRQSTATUS */
    volatile uint8_t  Resv_48[4];
    volatile uint32_t CSI2_CTX0;                 /* CSI2_CTX0 */
    volatile uint32_t CSI2_CTX1;                 /* CSI2_CTX1 */
    volatile uint32_t CSI2_CTX2;                 /* CSI2_CTX2 */
    volatile uint32_t CSI2_CTX3;                 /* CSI2_CTX3 */
    volatile uint32_t CSI2_CTX4;                 /* CSI2_CTX4 */
    volatile uint32_t CSI2_CTX5;                 /* CSI2_CTX5 */
    volatile uint32_t CSI2_CTX6;                 /* CSI2_CTX6 */
    volatile uint32_t CSI2_CTX7;                 /* CSI2_CTX7 */
    volatile uint32_t CSI2_STATUS0;              /* CSI2_STATUS0 */
    volatile uint32_t CSI2_STATUS1;              /* CSI2_STATUS1 */
    volatile uint32_t CSI2_STATUS2;              /* CSI2_STATUS2 */
    volatile uint32_t CSI2_STATUS3;              /* CSI2_STATUS3 */
    volatile uint32_t CSI2_STATUS4;              /* CSI2_STATUS4 */
    volatile uint32_t CSI2_STATUS5;              /* CSI2_STATUS5 */
    volatile uint32_t CSI2_STATUS6;              /* CSI2_STATUS6 */
    volatile uint32_t CSI2_STATUS7;              /* CSI2_STATUS7 */
    volatile uint8_t  Resv_128[16];
} CSL_calRegs_c2ppi;


typedef struct {
    volatile uint32_t SCP_PHY_A[64];             /* Phy #A over SCP */
    volatile uint32_t SCP_PHY_B[64];             /* Phy #B over SCP */
    volatile uint32_t SCP_PHY_C[64];             /* Phy #C over SCP */
    volatile uint32_t SCP_PHY_D[64];             /* Phy #D over SCP */
    volatile uint32_t SCP_PHY_E[64];             /* Phy #E over SCP */
    volatile uint32_t SCP_PHY_F[64];             /* Phy #F over SCP */
    volatile uint32_t SCP_PHY_G[64];             /* Phy #G over SCP */
    volatile uint32_t SCP_PHY_H[64];             /* Phy #H over SCP */
} CSL_calRegs_SCP;


typedef struct {
    CSL_calRegs_top TOP;
    volatile uint8_t  Resv_4096[3072];
    CSL_calRegs_rat RAT;
    CSL_calRegs_lvdsrx LVDSRX;
    volatile uint8_t  Resv_12288[3072];
    CSL_calRegs_c2ctl C2CTL;
    CSL_calRegs_c2irq C2IRQ[8];
    volatile uint8_t  Resv_12480[32];
    CSL_calRegs_c2pix C2PIX[4];
    volatile uint8_t  Resv_12544[48];
    CSL_calRegs_c2vid C2VID;
    volatile uint8_t  Resv_12800[144];
    CSL_calRegs_WR_DMA WR_DMA[8];
    volatile uint8_t  Resv_13056[128];
    CSL_calRegs_c2ppi C2PPI[2];
    volatile uint8_t  Resv_14336[1024];
    CSL_calRegs_SCP SCP;
} CSL_calRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CAL_TOP_MOD_VER                                                    (0x00000000U)
#define CSL_CAL_TOP_COS                                                        (0x00000004U)
#define CSL_CAL_TOP_VID_MUX_CTRL                                               (0x00000008U)
#define CSL_CAL_TOP_PSI_CTRL                                                   (0x0000000CU)
#define CSL_CAL_TOP_PSI_MAP                                                    (0x00000010U)
#define CSL_CAL_TOP_PSI_TAG                                                    (0x00000014U)
#define CSL_CAL_TOP_CAL_MODE                                                   (0x00000018U)
#define CSL_CAL_TOP_TE_GRP_03_00                                               (0x00000080U)
#define CSL_CAL_TOP_TE_GRP_07_04                                               (0x00000084U)
#define CSL_CAL_RAT_PID                                                        (0x00001000U)
#define CSL_CAL_RAT_CONFIG                                                     (0x00001004U)
#define CSL_CAL_RAT_REGION_CTRL(REGION)                                        (0x00001020U+((REGION)*0x10U))
#define CSL_CAL_RAT_REGION_BASE(REGION)                                        (0x00001024U+((REGION)*0x10U))
#define CSL_CAL_RAT_REGION_TRANS_L(REGION)                                     (0x00001028U+((REGION)*0x10U))
#define CSL_CAL_RAT_REGION_TRANS_U(REGION)                                     (0x0000102CU+((REGION)*0x10U))
#define CSL_CAL_RAT_DESTINATION_ID                                             (0x00001804U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL                                  (0x00001820U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0                                  (0x00001824U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1                                  (0x00001828U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA0                                    (0x0000182CU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA1                                    (0x00001830U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2                                    (0x00001834U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA3                                    (0x00001838U)
#define CSL_CAL_RAT_EXCEPTION_PEND_SET                                         (0x00001840U)
#define CSL_CAL_RAT_EXCEPTION_PEND_CLEAR                                       (0x00001844U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_SET                                       (0x00001848U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_CLEAR                                     (0x0000184CU)
#define CSL_CAL_RAT_EOI_REG                                                    (0x00001850U)
#define CSL_CAL_LVDSRX_REVISION                                                (0x00002000U)
#define CSL_CAL_LVDSRX_SYSCONFIG                                               (0x00002010U)
#define CSL_CAL_LVDSRX_CAMCFG                                                  (0x00002014U)
#define CSL_CAL_LVDSRX_IRQ_EOI                                                 (0x0000201CU)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0                                         (0x00002020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0                                             (0x00002024U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0                                         (0x00002028U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0                                         (0x0000202CU)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1                                         (0x00002030U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1                                             (0x00002034U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1                                         (0x00002038U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1                                         (0x0000203CU)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2                                        (0x00002040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2                                             (0x00002044U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2                                         (0x00002048U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2                                         (0x0000204CU)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3                                         (0x00002050U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3                                             (0x00002054U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3                                         (0x00002058U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3                                         (0x0000205CU)
#define CSL_CAL_LVDSRX_CAM1_CFG                                                (0x00002060U)
#define CSL_CAL_LVDSRX_CAM1_FRMSIZE                                            (0x00002064U)
#define CSL_CAL_LVDSRX_CAM1_MAXWIDTH                                           (0x00002068U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOF                                            (0x0000206CU)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOF                                            (0x00002070U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOL                                            (0x00002074U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOL                                            (0x00002078U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOV                                            (0x0000207CU)
#define CSL_CAL_LVDSRX_CAM2_CFG                                                (0x00002080U)
#define CSL_CAL_LVDSRX_CAM2_FRMSIZE                                            (0x00002084U)
#define CSL_CAL_LVDSRX_CAM2_MAXWIDTH                                           (0x00002088U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOF                                            (0x0000208CU)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOF                                            (0x00002090U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOL                                            (0x00002094U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOL                                            (0x00002098U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOV                                            (0x0000209CU)
#define CSL_CAL_LVDSRX_CAM3_CFG                                                (0x000020A0U)
#define CSL_CAL_LVDSRX_CAM3_FRMSIZE                                            (0x000020A4U)
#define CSL_CAL_LVDSRX_CAM3_MAXWIDTH                                           (0x000020A8U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOF                                            (0x000020ACU)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOF                                            (0x000020B0U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOL                                            (0x000020B4U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOL                                            (0x000020B8U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOV                                            (0x000020BCU)
#define CSL_CAL_LVDSRX_CAM4_CFG                                                (0x000020C0U)
#define CSL_CAL_LVDSRX_CAM4_FRMSIZE                                            (0x000020C4U)
#define CSL_CAL_LVDSRX_CAM4_MAXWIDTH                                           (0x000020C8U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOF                                            (0x000020CCU)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOF                                            (0x000020D0U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOL                                            (0x000020D4U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOL                                            (0x000020D8U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOV                                            (0x000020DCU)
#define CSL_CAL_LVDSRX_WDRCFG                                                  (0x000020E0U)
#define CSL_CAL_LVDSRX_WDRGN                                                   (0x000020E4U)
#define CSL_CAL_LVDSRX_WDRKP1                                                  (0x000020E8U)
#define CSL_CAL_LVDSRX_WDRKP2                                                  (0x000020ECU)
#define CSL_CAL_LVDSRX_TEST1                                                   (0x00002100U)
#define CSL_CAL_LVDSRX_TEST2                                                   (0x00002104U)
#define CSL_CAL_LVDSRX_TEST3                                                   (0x00002108U)
#define CSL_CAL_LVDSRX_TEST4                                                   (0x0000210CU)
#define CSL_CAL_C2CTL_HL_REVISION                                              (0x00003000U)
#define CSL_CAL_C2CTL_HL_HWINFO                                                (0x00003004U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG                                             (0x00003010U)
#define CSL_CAL_C2CTL_HL_IRQ_EOI                                               (0x0000301CU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW(C2IRQ)                                  (0x00003020U+((C2IRQ)*0x10U))
#define CSL_CAL_C2IRQ_HL_IRQSTATUS(C2IRQ)                                      (0x00003024U+((C2IRQ)*0x10U))
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET(C2IRQ)                                  (0x00003028U+((C2IRQ)*0x10U))
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR(C2IRQ)                                  (0x0000302CU+((C2IRQ)*0x10U))
#define CSL_CAL_C2PIX_PIX_PROC(C2PIX)                                          (0x000030C0U+((C2PIX)*0x4U))
#define CSL_CAL_C2VID_CTRL                                                     (0x00003100U)
#define CSL_CAL_C2VID_CTRL1                                                    (0x00003104U)
#define CSL_CAL_C2VID_LINE_NUMBER_EVT                                          (0x00003108U)
#define CSL_CAL_C2VID_VPORT_CTRL1                                              (0x00003120U)
#define CSL_CAL_C2VID_VPORT_CTRL2                                              (0x00003124U)
#define CSL_CAL_C2VID_BYS_CTRL1                                                (0x00003130U)
#define CSL_CAL_C2VID_BYS_CTRL2                                                (0x00003134U)
#define CSL_CAL_C2VID_RD_DMA_CTRL                                              (0x00003140U)
#define CSL_CAL_C2VID_RD_DMA_PIX_ADDR                                          (0x00003144U)
#define CSL_CAL_C2VID_RD_DMA_PIX_OFST                                          (0x00003148U)
#define CSL_CAL_C2VID_RD_DMA_XSIZE                                             (0x0000314CU)
#define CSL_CAL_C2VID_RD_DMA_YSIZE                                             (0x00003150U)
#define CSL_CAL_C2VID_RD_DMA_INIT_ADDR                                         (0x00003154U)
#define CSL_CAL_C2VID_RD_DMA_INIT_OFST                                         (0x00003168U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2                                             (0x0000316CU)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL(WR_DMA)                                     (0x00003200U+((WR_DMA)*0x10U))
#define CSL_CAL_WR_DMA_WR_DMA_ADDR(WR_DMA)                                     (0x00003204U+((WR_DMA)*0x10U))
#define CSL_CAL_WR_DMA_WR_DMA_OFST(WR_DMA)                                     (0x00003208U+((WR_DMA)*0x10U))
#define CSL_CAL_WR_DMA_WR_DMA_XSIZE(WR_DMA)                                    (0x0000320CU+((WR_DMA)*0x10U))
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL(C2PPI)                                     (0x00003300U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG(C2PPI)                                (0x00003304U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS(C2PPI)                          (0x00003308U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET(C2PPI)                                 (0x0000330CU+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE(C2PPI)                          (0x00003310U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_TIMING(C2PPI)                                       (0x00003314U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE(C2PPI)                                 (0x00003318U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS(C2PPI)                                 (0x00003328U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX0(C2PPI)                                         (0x00003330U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX1(C2PPI)                                         (0x00003334U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX2(C2PPI)                                         (0x00003338U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX3(C2PPI)                                         (0x0000333CU+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX4(C2PPI)                                         (0x00003340U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX5(C2PPI)                                         (0x00003344U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX6(C2PPI)                                         (0x00003348U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_CTX7(C2PPI)                                         (0x0000334CU+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS0(C2PPI)                                      (0x00003350U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS1(C2PPI)                                      (0x00003354U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS2(C2PPI)                                      (0x00003358U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS3(C2PPI)                                      (0x0000335CU+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS4(C2PPI)                                      (0x00003360U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS5(C2PPI)                                      (0x00003364U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS6(C2PPI)                                      (0x00003368U+((C2PPI)*0x80U))
#define CSL_CAL_C2PPI_CSI2_STATUS7(C2PPI)                                      (0x0000336CU+((C2PPI)*0x80U))
#define CSL_CAL_SCP_SCP_PHY_A(SCP_PHY_A)                                       (0x00003800U+((SCP_PHY_A)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_B(SCP_PHY_B)                                       (0x00003900U+((SCP_PHY_B)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_C(SCP_PHY_C)                                       (0x00003A00U+((SCP_PHY_C)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_D(SCP_PHY_D)                                       (0x00003B00U+((SCP_PHY_D)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_E(SCP_PHY_E)                                       (0x00003C00U+((SCP_PHY_E)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_F(SCP_PHY_F)                                       (0x00003D00U+((SCP_PHY_F)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_G(SCP_PHY_G)                                       (0x00003E00U+((SCP_PHY_G)*0x4U))
#define CSL_CAL_SCP_SCP_PHY_H(SCP_PHY_H)                                       (0x00003F00U+((SCP_PHY_H)*0x4U))
#define CAL_CSI2_PHY_REG0                                                      (0x0U)
#define CAL_CSI2_PHY_REG1                                                      (0x4U)
#define CAL_CSI2_PHY_REG2                                                      (0x8U)
#define CAL_CSI2_PHY_REG3                                                      (0xCU)
#define CAL_CSI2_PHY_REG10                                                     (0x28U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MOD_VER */

#define CSL_CAL_TOP_MOD_VER_MODULE_SCHEME_MASK                                 (0xC0000000U)
#define CSL_CAL_TOP_MOD_VER_MODULE_SCHEME_SHIFT                                (0x0000001EU)
#define CSL_CAL_TOP_MOD_VER_MODULE_SCHEME_MAX                                  (0x00000003U)

#define CSL_CAL_TOP_MOD_VER_MODULE_BU_MASK                                     (0x30000000U)
#define CSL_CAL_TOP_MOD_VER_MODULE_BU_SHIFT                                    (0x0000001CU)
#define CSL_CAL_TOP_MOD_VER_MODULE_BU_MAX                                      (0x00000003U)

#define CSL_CAL_TOP_MOD_VER_MODULE_FUNCTION_ID_MASK                            (0x0FFF0000U)
#define CSL_CAL_TOP_MOD_VER_MODULE_FUNCTION_ID_SHIFT                           (0x00000010U)
#define CSL_CAL_TOP_MOD_VER_MODULE_FUNCTION_ID_MAX                             (0x00000FFFU)

#define CSL_CAL_TOP_MOD_VER_RTL_VERSION_MASK                                   (0x0000F800U)
#define CSL_CAL_TOP_MOD_VER_RTL_VERSION_SHIFT                                  (0x0000000BU)
#define CSL_CAL_TOP_MOD_VER_RTL_VERSION_MAX                                    (0x0000001FU)

#define CSL_CAL_TOP_MOD_VER_MAJOR_REVISION_MASK                                (0x00000700U)
#define CSL_CAL_TOP_MOD_VER_MAJOR_REVISION_SHIFT                               (0x00000008U)
#define CSL_CAL_TOP_MOD_VER_MAJOR_REVISION_MAX                                 (0x00000007U)

#define CSL_CAL_TOP_MOD_VER_CUSTOM_REVISION_MASK                               (0x000000C0U)
#define CSL_CAL_TOP_MOD_VER_CUSTOM_REVISION_SHIFT                              (0x00000006U)
#define CSL_CAL_TOP_MOD_VER_CUSTOM_REVISION_MAX                                (0x00000003U)

#define CSL_CAL_TOP_MOD_VER_MINOR_REVISION_MASK                                (0x0000003FU)
#define CSL_CAL_TOP_MOD_VER_MINOR_REVISION_SHIFT                               (0x00000000U)
#define CSL_CAL_TOP_MOD_VER_MINOR_REVISION_MAX                                 (0x0000003FU)

/* COS */

#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_HI_MASK                                 (0x00000070U)
#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_HI_SHIFT                                (0x00000004U)
#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_HI_MAX                                  (0x00000007U)

#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_LO_MASK                                 (0x00000007U)
#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_LO_SHIFT                                (0x00000000U)
#define CSL_CAL_TOP_COS_MFLAG_PRIORITY_LO_MAX                                  (0x00000007U)

/* VID_MUX_CTRL */

#define CSL_CAL_TOP_VID_MUX_CTRL_BYS_MUX_SEL_MASK                              (0x00000007U)
#define CSL_CAL_TOP_VID_MUX_CTRL_BYS_MUX_SEL_SHIFT                             (0x00000000U)
#define CSL_CAL_TOP_VID_MUX_CTRL_BYS_MUX_SEL_MAX                               (0x00000007U)

/* PSI_CTRL */

#define CSL_CAL_TOP_PSI_CTRL_PS_FLAGS_MASK                                     (0x00F00000U)
#define CSL_CAL_TOP_PSI_CTRL_PS_FLAGS_SHIFT                                    (0x00000014U)
#define CSL_CAL_TOP_PSI_CTRL_PS_FLAGS_MAX                                      (0x0000000FU)

#define CSL_CAL_TOP_PSI_CTRL_PKT_TYPE_MASK                                     (0x0000001FU)
#define CSL_CAL_TOP_PSI_CTRL_PKT_TYPE_SHIFT                                    (0x00000000U)
#define CSL_CAL_TOP_PSI_CTRL_PKT_TYPE_MAX                                      (0x0000001FU)

/* PSI_MAP */

#define CSL_CAL_TOP_PSI_MAP_PSITX_SEL_MASK                                     (0x000000FFU)
#define CSL_CAL_TOP_PSI_MAP_PSITX_SEL_SHIFT                                    (0x00000000U)
#define CSL_CAL_TOP_PSI_MAP_PSITX_SEL_MAX                                      (0x000000FFU)

/* PSI_TAG */

#define CSL_CAL_TOP_PSI_TAG_SRC_TAG_MASK                                       (0xFFFF0000U)
#define CSL_CAL_TOP_PSI_TAG_SRC_TAG_SHIFT                                      (0x00000010U)
#define CSL_CAL_TOP_PSI_TAG_SRC_TAG_MAX                                        (0x0000FFFFU)

#define CSL_CAL_TOP_PSI_TAG_DST_TAG_MASK                                       (0x0000FFFFU)
#define CSL_CAL_TOP_PSI_TAG_DST_TAG_SHIFT                                      (0x00000000U)
#define CSL_CAL_TOP_PSI_TAG_DST_TAG_MAX                                        (0x0000FFFFU)

/* CAL_MODE */

#define CSL_CAL_TOP_CAL_MODE_BASELINE_MODE_MASK                                (0x00000001U)
#define CSL_CAL_TOP_CAL_MODE_BASELINE_MODE_SHIFT                               (0x00000000U)
#define CSL_CAL_TOP_CAL_MODE_BASELINE_MODE_MAX                                 (0x00000001U)

/* TE_GRP_03_00 */

#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_3_MASK                              (0xFF000000U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_3_SHIFT                             (0x00000018U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_3_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_2_MASK                              (0x00FF0000U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_2_SHIFT                             (0x00000010U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_2_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_1_MASK                              (0x0000FF00U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_1_SHIFT                             (0x00000008U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_1_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_0_MASK                              (0x000000FFU)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_0_SHIFT                             (0x00000000U)
#define CSL_CAL_TOP_TE_GRP_03_00_EVENT_SEL_0_MAX                               (0x000000FFU)

/* TE_GRP_07_04 */

#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_7_MASK                              (0xFF000000U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_7_SHIFT                             (0x00000018U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_7_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_6_MASK                              (0x00FF0000U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_6_SHIFT                             (0x00000010U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_6_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_5_MASK                              (0x0000FF00U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_5_SHIFT                             (0x00000008U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_5_MAX                               (0x000000FFU)

#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_4_MASK                              (0x000000FFU)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_4_SHIFT                             (0x00000000U)
#define CSL_CAL_TOP_TE_GRP_07_04_EVENT_SEL_4_MAX                               (0x000000FFU)

/* CTRL */

#define CSL_CAL_RAT_REGION_CTRL_CTRL_EN_MASK                                   (0x80000000U)
#define CSL_CAL_RAT_REGION_CTRL_CTRL_EN_SHIFT                                  (0x0000001FU)
#define CSL_CAL_RAT_REGION_CTRL_CTRL_EN_MAX                                    (0x00000001U)

#define CSL_CAL_RAT_REGION_CTRL_CTRL_SIZE_MASK                                 (0x0000003FU)
#define CSL_CAL_RAT_REGION_CTRL_CTRL_SIZE_SHIFT                                (0x00000000U)
#define CSL_CAL_RAT_REGION_CTRL_CTRL_SIZE_MAX                                  (0x0000003FU)

/* BASE */

#define CSL_CAL_RAT_REGION_BASE_BASE_BASE_MASK                                 (0xFFFFFFFFU)
#define CSL_CAL_RAT_REGION_BASE_BASE_BASE_SHIFT                                (0x00000000U)
#define CSL_CAL_RAT_REGION_BASE_BASE_BASE_MAX                                  (0xFFFFFFFFU)

/* TRANS_L */

#define CSL_CAL_RAT_REGION_TRANS_L_TRANS_L_LOWER_MASK                          (0xFFFFFFFFU)
#define CSL_CAL_RAT_REGION_TRANS_L_TRANS_L_LOWER_SHIFT                         (0x00000000U)
#define CSL_CAL_RAT_REGION_TRANS_L_TRANS_L_LOWER_MAX                           (0xFFFFFFFFU)

/* TRANS_U */

#define CSL_CAL_RAT_REGION_TRANS_U_TRANS_U_UPPER_MASK                          (0x0000FFFFU)
#define CSL_CAL_RAT_REGION_TRANS_U_TRANS_U_UPPER_SHIFT                         (0x00000000U)
#define CSL_CAL_RAT_REGION_TRANS_U_TRANS_U_UPPER_MAX                           (0x0000FFFFU)

/* PID */

#define CSL_CAL_RAT_PID_PID_SCHEME_MASK                                        (0xC0000000U)
#define CSL_CAL_RAT_PID_PID_SCHEME_SHIFT                                       (0x0000001EU)
#define CSL_CAL_RAT_PID_PID_SCHEME_MAX                                         (0x00000003U)

#define CSL_CAL_RAT_PID_PID_BU_MASK                                            (0x30000000U)
#define CSL_CAL_RAT_PID_PID_BU_SHIFT                                           (0x0000001CU)
#define CSL_CAL_RAT_PID_PID_BU_MAX                                             (0x00000003U)

#define CSL_CAL_RAT_PID_PID_FUNC_MASK                                          (0x0FFF0000U)
#define CSL_CAL_RAT_PID_PID_FUNC_SHIFT                                         (0x00000010U)
#define CSL_CAL_RAT_PID_PID_FUNC_MAX                                           (0x00000FFFU)

#define CSL_CAL_RAT_PID_PID_RTL_MASK                                           (0x0000F800U)
#define CSL_CAL_RAT_PID_PID_RTL_SHIFT                                          (0x0000000BU)
#define CSL_CAL_RAT_PID_PID_RTL_MAX                                            (0x0000001FU)

#define CSL_CAL_RAT_PID_PID_MAJOR_MASK                                         (0x00000700U)
#define CSL_CAL_RAT_PID_PID_MAJOR_SHIFT                                        (0x00000008U)
#define CSL_CAL_RAT_PID_PID_MAJOR_MAX                                          (0x00000007U)

#define CSL_CAL_RAT_PID_PID_CUSTOM_MASK                                        (0x000000C0U)
#define CSL_CAL_RAT_PID_PID_CUSTOM_SHIFT                                       (0x00000006U)
#define CSL_CAL_RAT_PID_PID_CUSTOM_MAX                                         (0x00000003U)

#define CSL_CAL_RAT_PID_PID_MINOR_MASK                                         (0x0000003FU)
#define CSL_CAL_RAT_PID_PID_MINOR_SHIFT                                        (0x00000000U)
#define CSL_CAL_RAT_PID_PID_MINOR_MAX                                          (0x0000003FU)

/* CONFIG */

#define CSL_CAL_RAT_CONFIG_CONFIG_ADDR_WIDTH_MASK                              (0x00FF0000U)
#define CSL_CAL_RAT_CONFIG_CONFIG_ADDR_WIDTH_SHIFT                             (0x00000010U)
#define CSL_CAL_RAT_CONFIG_CONFIG_ADDR_WIDTH_MAX                               (0x000000FFU)

#define CSL_CAL_RAT_CONFIG_CONFIG_ADDRS_MASK                                   (0x0000FF00U)
#define CSL_CAL_RAT_CONFIG_CONFIG_ADDRS_SHIFT                                  (0x00000008U)
#define CSL_CAL_RAT_CONFIG_CONFIG_ADDRS_MAX                                    (0x000000FFU)

#define CSL_CAL_RAT_CONFIG_CONFIG_REGIONS_MASK                                 (0x000000FFU)
#define CSL_CAL_RAT_CONFIG_CONFIG_REGIONS_SHIFT                                (0x00000000U)
#define CSL_CAL_RAT_CONFIG_CONFIG_REGIONS_MAX                                  (0x000000FFU)

/* DESTINATION_ID */

#define CSL_CAL_RAT_DESTINATION_ID_DESTINATION_ID_DEST_ID_MASK                 (0x000000FFU)
#define CSL_CAL_RAT_DESTINATION_ID_DESTINATION_ID_DEST_ID_SHIFT                (0x00000000U)
#define CSL_CAL_RAT_DESTINATION_ID_DESTINATION_ID_DEST_ID_MAX                  (0x000000FFU)

/* EXCEPTION_LOGGING_CONTROL */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MASK (0x00000002U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_SHIFT (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MAX (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MASK (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_F_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_CONTROL_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MAX (0x00000001U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK (0xFF000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT (0x00000018U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX (0x000000FFU)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK (0x00FFFF00U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT (0x00000008U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX (0x0000FFFFU)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK (0x000000FFU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER0_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_GROUP_MASK (0xFF000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT (0x00000018U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_GROUP_MAX (0x000000FFU)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_CODE_MASK (0x00FF0000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT (0x00000010U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_HEADER1_EXCEPTION_LOGGING_HEADER1_CODE_MAX (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA0_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK (0xFFFFFFFFU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA0_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA0_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA1_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK (0x0000FFFFU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA1_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA1_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK (0x0FFF0000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT (0x00000010U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX (0x00000FFFU)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_WRITE_MASK (0x00002000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT (0x0000000DU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_WRITE_MAX  (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_READ_MASK  (0x00001000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_READ_SHIFT (0x0000000CU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_READ_MAX   (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_DEBUG_MASK (0x00000800U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT (0x0000000BU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_DEBUG_MAX  (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK (0x00000400U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT (0x0000000AU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_MASK  (0x00000200U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT (0x00000009U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_MAX   (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_SECURE_MASK (0x00000100U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT (0x00000008U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_SECURE_MAX (0x00000001U)

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK (0x000000FFU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA2_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX (0x000000FFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA3_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK (0x000003FFU)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA3_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_LOGGING_DATA3_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX (0x000003FFU)

/* EXCEPTION_PEND_SET */

#define CSL_CAL_RAT_EXCEPTION_PEND_SET_EXCEPTION_PEND_SET_PEND_SET_MASK        (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_PEND_SET_EXCEPTION_PEND_SET_PEND_SET_SHIFT       (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_PEND_SET_EXCEPTION_PEND_SET_PEND_SET_MAX         (0x00000001U)

/* EXCEPTION_PEND_CLEAR */

#define CSL_CAL_RAT_EXCEPTION_PEND_CLEAR_EXCEPTION_PEND_CLEAR_PEND_CLR_MASK    (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_PEND_CLEAR_EXCEPTION_PEND_CLEAR_PEND_CLR_SHIFT   (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_PEND_CLEAR_EXCEPTION_PEND_CLEAR_PEND_CLR_MAX     (0x00000001U)

/* EXCEPTION_ENABLE_SET */

#define CSL_CAL_RAT_EXCEPTION_ENABLE_SET_EXCEPTION_ENABLE_SET_ENABLE_SET_MASK  (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_SET_EXCEPTION_ENABLE_SET_ENABLE_SET_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_SET_EXCEPTION_ENABLE_SET_ENABLE_SET_MAX   (0x00000001U)

/* EXCEPTION_ENABLE_CLEAR */

#define CSL_CAL_RAT_EXCEPTION_ENABLE_CLEAR_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MASK (0x00000001U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_CLEAR_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_SHIFT (0x00000000U)
#define CSL_CAL_RAT_EXCEPTION_ENABLE_CLEAR_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MAX (0x00000001U)

/* EOI_REG */

#define CSL_CAL_RAT_EOI_REG_EOI_REG_EOI_WR_MASK                                (0x0000FFFFU)
#define CSL_CAL_RAT_EOI_REG_EOI_REG_EOI_WR_SHIFT                               (0x00000000U)
#define CSL_CAL_RAT_EOI_REG_EOI_REG_EOI_WR_MAX                                 (0x0000FFFFU)

/* REVISION */

#define CSL_CAL_LVDSRX_REVISION_SCHEME_MASK                                    (0xC0000000U)
#define CSL_CAL_LVDSRX_REVISION_SCHEME_SHIFT                                   (0x0000001EU)
#define CSL_CAL_LVDSRX_REVISION_SCHEME_MAX                                     (0x00000003U)

#define CSL_CAL_LVDSRX_REVISION_FUNC_MASK                                      (0x0FFF0000U)
#define CSL_CAL_LVDSRX_REVISION_FUNC_SHIFT                                     (0x00000010U)
#define CSL_CAL_LVDSRX_REVISION_FUNC_MAX                                       (0x00000FFFU)

#define CSL_CAL_LVDSRX_REVISION_R_RTL_MASK                                     (0x0000F800U)
#define CSL_CAL_LVDSRX_REVISION_R_RTL_SHIFT                                    (0x0000000BU)
#define CSL_CAL_LVDSRX_REVISION_R_RTL_MAX                                      (0x0000001FU)

#define CSL_CAL_LVDSRX_REVISION_X_MAJOR_MASK                                   (0x00000700U)
#define CSL_CAL_LVDSRX_REVISION_X_MAJOR_SHIFT                                  (0x00000008U)
#define CSL_CAL_LVDSRX_REVISION_X_MAJOR_MAX                                    (0x00000007U)

#define CSL_CAL_LVDSRX_REVISION_CUSTOM_MASK                                    (0x000000C0U)
#define CSL_CAL_LVDSRX_REVISION_CUSTOM_SHIFT                                   (0x00000006U)
#define CSL_CAL_LVDSRX_REVISION_CUSTOM_MAX                                     (0x00000003U)

#define CSL_CAL_LVDSRX_REVISION_Y_MINOR_MASK                                   (0x0000003FU)
#define CSL_CAL_LVDSRX_REVISION_Y_MINOR_SHIFT                                  (0x00000000U)
#define CSL_CAL_LVDSRX_REVISION_Y_MINOR_MAX                                    (0x0000003FU)

/* SYSCONFIG */

#define CSL_CAL_LVDSRX_SYSCONFIG_RESERVED_0_MASK                               (0x00000001U)
#define CSL_CAL_LVDSRX_SYSCONFIG_RESERVED_0_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_SYSCONFIG_RESERVED_0_MAX                                (0x00000001U)

/* CAMCFG */

#define CSL_CAL_LVDSRX_CAMCFG_CAM4TEST_MASK                                    (0x00080000U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM4TEST_SHIFT                                   (0x00000013U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM4TEST_MAX                                     (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM3TEST_MASK                                    (0x00040000U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM3TEST_SHIFT                                   (0x00000012U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM3TEST_MAX                                     (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM2TEST_MASK                                    (0x00020000U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM2TEST_SHIFT                                   (0x00000011U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM2TEST_MAX                                     (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM1TEST_MASK                                    (0x00010000U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM1TEST_SHIFT                                   (0x00000010U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM1TEST_MAX                                     (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM4ENA_MASK                                     (0x00000008U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM4ENA_SHIFT                                    (0x00000003U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM4ENA_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM3ENA_MASK                                     (0x00000004U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM3ENA_SHIFT                                    (0x00000002U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM3ENA_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM2ENA_MASK                                     (0x00000002U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM2ENA_SHIFT                                    (0x00000001U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM2ENA_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_CAMCFG_CAM1ENA_MASK                                     (0x00000001U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM1ENA_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_CAMCFG_CAM1ENA_MAX                                      (0x00000001U)

/* IRQ_EOI */

#define CSL_CAL_LVDSRX_IRQ_EOI_LINE_NUMBER_MASK                                (0x00000007U)
#define CSL_CAL_LVDSRX_IRQ_EOI_LINE_NUMBER_SHIFT                               (0x00000000U)
#define CSL_CAL_LVDSRX_IRQ_EOI_LINE_NUMBER_MAX                                 (0x00000007U)

/* IRQSTATUS_RAW_0 */

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR7_MASK                          (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR7_SHIFT                         (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR7_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR6_MASK                          (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR6_SHIFT                         (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR6_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR5_MASK                          (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR5_SHIFT                         (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR5_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR4_MASK                          (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR4_SHIFT                         (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR4_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR3_MASK                          (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR3_SHIFT                         (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR3_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR2_MASK                          (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR2_SHIFT                         (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR2_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR1_MASK                          (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR1_SHIFT                         (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR1_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR0_MASK                          (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR0_SHIFT                         (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_ERR0_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_EOF_MASK                           (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_EOF_SHIFT                          (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_EOF_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_SOF_MASK                           (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_SOF_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_0_CAM1_SOF_MAX                            (0x00000001U)

/* IRQSTATUS_0 */

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR7_MASK                              (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR7_SHIFT                             (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR7_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR6_MASK                              (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR6_SHIFT                             (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR6_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR5_MASK                              (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR5_SHIFT                             (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR5_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR4_MASK                              (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR4_SHIFT                             (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR4_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR3_MASK                              (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR3_SHIFT                             (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR3_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR2_MASK                              (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR2_SHIFT                             (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR2_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR1_MASK                              (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR1_SHIFT                             (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR1_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR0_MASK                              (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR0_SHIFT                             (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_ERR0_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_EOF_MASK                               (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_EOF_SHIFT                              (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_EOF_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_SOF_MASK                               (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_SOF_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_0_CAM1_SOF_MAX                                (0x00000001U)

/* IRQENABLE_SET_0 */

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_0_EN_CAM1_SOF_MAX                         (0x00000001U)

/* IRQENABLE_CLR_0 */

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_0_EN_CAM1_SOF_MAX                         (0x00000001U)

/* IRQSTATUS_RAW_1 */

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR7_MASK                          (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR7_SHIFT                         (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR7_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR6_MASK                          (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR6_SHIFT                         (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR6_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR5_MASK                          (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR5_SHIFT                         (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR5_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR4_MASK                          (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR4_SHIFT                         (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR4_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR3_MASK                          (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR3_SHIFT                         (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR3_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR2_MASK                          (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR2_SHIFT                         (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR2_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR1_MASK                          (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR1_SHIFT                         (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR1_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR0_MASK                          (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR0_SHIFT                         (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_ERR0_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_EOF_MASK                           (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_EOF_SHIFT                          (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_EOF_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_SOF_MASK                           (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_SOF_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_1_CAM2_SOF_MAX                            (0x00000001U)

/* IRQSTATUS_1 */

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR7_MASK                              (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR7_SHIFT                             (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR7_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR6_MASK                              (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR6_SHIFT                             (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR6_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR5_MASK                              (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR5_SHIFT                             (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR5_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR4_MASK                              (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR4_SHIFT                             (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR4_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR3_MASK                              (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR3_SHIFT                             (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR3_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR2_MASK                              (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR2_SHIFT                             (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR2_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR1_MASK                              (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR1_SHIFT                             (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR1_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR0_MASK                              (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR0_SHIFT                             (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_ERR0_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_EOF_MASK                               (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_EOF_SHIFT                              (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_EOF_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_SOF_MASK                               (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_SOF_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_1_CAM2_SOF_MAX                                (0x00000001U)

/* IRQENABLE_SET_1 */

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_1_EN_CAM2_SOF_MAX                         (0x00000001U)

/* IRQENABLE_CLR_1 */

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_1_EN_CAM2_SOF_MAX                         (0x00000001U)

/* IRQSTATUS_RAW2_2 */

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR7_MASK                         (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR7_SHIFT                        (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR7_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR6_MASK                         (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR6_SHIFT                        (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR6_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR5_MASK                         (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR5_SHIFT                        (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR5_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR4_MASK                         (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR4_SHIFT                        (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR4_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR3_MASK                         (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR3_SHIFT                        (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR3_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR2_MASK                         (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR2_SHIFT                        (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR2_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR1_MASK                         (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR1_SHIFT                        (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR1_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR0_MASK                         (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR0_SHIFT                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_ERR0_MAX                          (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_EOF_MASK                          (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_EOF_SHIFT                         (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_EOF_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_SOF_MASK                          (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_SOF_SHIFT                         (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW2_2_CAM3_SOF_MAX                           (0x00000001U)

/* IRQSTATUS_2 */

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR7_MASK                              (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR7_SHIFT                             (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR7_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR6_MASK                              (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR6_SHIFT                             (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR6_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR5_MASK                              (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR5_SHIFT                             (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR5_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR4_MASK                              (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR4_SHIFT                             (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR4_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR3_MASK                              (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR3_SHIFT                             (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR3_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR2_MASK                              (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR2_SHIFT                             (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR2_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR1_MASK                              (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR1_SHIFT                             (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR1_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR0_MASK                              (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR0_SHIFT                             (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_ERR0_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_EOF_MASK                               (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_EOF_SHIFT                              (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_EOF_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_SOF_MASK                               (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_SOF_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_2_CAM3_SOF_MAX                                (0x00000001U)

/* IRQENABLE_SET_2 */

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_2_EN_CAM3_SOF_MAX                         (0x00000001U)

/* IRQENABLE_CLR_2 */

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_2_EN_CAM3_SOF_MAX                         (0x00000001U)

/* IRQSTATUS_RAW_3 */

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR7_MASK                          (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR7_SHIFT                         (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR7_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR6_MASK                          (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR6_SHIFT                         (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR6_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR5_MASK                          (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR5_SHIFT                         (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR5_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR4_MASK                          (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR4_SHIFT                         (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR4_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR3_MASK                          (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR3_SHIFT                         (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR3_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR2_MASK                          (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR2_SHIFT                         (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR2_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM5_ERR1_MASK                          (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM5_ERR1_SHIFT                         (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM5_ERR1_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR0_MASK                          (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR0_SHIFT                         (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_ERR0_MAX                           (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_EOF_MASK                           (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_EOF_SHIFT                          (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_EOF_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_SOF_MASK                           (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_SOF_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_RAW_3_CAM4_SOF_MAX                            (0x00000001U)

/* IRQSTATUS_3 */

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR7_MASK                              (0x00000200U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR7_SHIFT                             (0x00000009U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR7_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR6_MASK                              (0x00000100U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR6_SHIFT                             (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR6_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR5_MASK                              (0x00000080U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR5_SHIFT                             (0x00000007U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR5_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR4_MASK                              (0x00000040U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR4_SHIFT                             (0x00000006U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR4_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR3_MASK                              (0x00000020U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR3_SHIFT                             (0x00000005U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR3_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR2_MASK                              (0x00000010U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR2_SHIFT                             (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR2_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR1_MASK                              (0x00000008U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR1_SHIFT                             (0x00000003U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR1_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR0_MASK                              (0x00000004U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR0_SHIFT                             (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_ERR0_MAX                               (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_EOF_MASK                               (0x00000002U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_EOF_SHIFT                              (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_EOF_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_SOF_MASK                               (0x00000001U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_SOF_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_IRQSTATUS_3_CAM4_SOF_MAX                                (0x00000001U)

/* IRQENABLE_SET_3 */

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_SET_3_EN_CAM4_SOF_MAX                         (0x00000001U)

/* IRQENABLE_CLR_3 */

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR7_MASK                       (0x00000200U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR7_SHIFT                      (0x00000009U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR7_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR6_MASK                       (0x00000100U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR6_SHIFT                      (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR6_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR5_MASK                       (0x00000080U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR5_SHIFT                      (0x00000007U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR5_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR4_MASK                       (0x00000040U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR4_SHIFT                      (0x00000006U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR4_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR3_MASK                       (0x00000020U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR3_SHIFT                      (0x00000005U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR3_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR2_MASK                       (0x00000010U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR2_SHIFT                      (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR2_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR1_MASK                       (0x00000008U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR1_SHIFT                      (0x00000003U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR1_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR0_MASK                       (0x00000004U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR0_SHIFT                      (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_ERR0_MAX                        (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_EOF_MASK                        (0x00000002U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_EOF_SHIFT                       (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_EOF_MAX                         (0x00000001U)

#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_SOF_MASK                        (0x00000001U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_SOF_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_IRQENABLE_CLR_3_EN_CAM4_SOF_MAX                         (0x00000001U)

/* CAM1_CFG */

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE4_MASK                             (0x70000000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE4_SHIFT                            (0x0000001CU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE4_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE3_MASK                             (0x07000000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE3_SHIFT                            (0x00000018U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE3_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE2_MASK                             (0x00700000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE2_SHIFT                            (0x00000014U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE2_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE1_MASK                             (0x00070000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE1_SHIFT                            (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUM_LANE1_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_ALIGN_MASK                                 (0x00008000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_ALIGN_SHIFT                                (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_ALIGN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_DENDIAN_MASK                               (0x00004000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_DENDIAN_SHIFT                              (0x0000000EU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_DENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FILEN_MASK                                 (0x00002000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FILEN_SHIFT                                (0x0000000DU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FILEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_CRCEN_MASK                                 (0x00001000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_CRCEN_SHIFT                                (0x0000000CU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_CRCEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_SENDIAN_MASK                               (0x00000800U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_SENDIAN_SHIFT                              (0x0000000BU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_SENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_PIX_WIDTH_MASK                             (0x00000700U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_PIX_WIDTH_SHIFT                            (0x00000008U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_PIX_WIDTH_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FRSTAT_INIT_MASK                           (0x00000080U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FRSTAT_INIT_SHIFT                          (0x00000007U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_FRSTAT_INIT_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUMPHY_MASK                                (0x00000070U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUMPHY_SHIFT                               (0x00000004U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_NUMPHY_MAX                                 (0x00000007U)

#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_OP_MODE_MASK                               (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_OP_MODE_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_CFG_CC1_OP_MODE_MAX                                (0x0000000FU)

/* CAM1_FRMSIZE */

#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_FRWIDTH_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_FRWIDTH_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_FRWIDTH_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_LNWIDTH_MASK                          (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_LNWIDTH_SHIFT                         (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_FRMSIZE_C1FS_LNWIDTH_MAX                           (0x0000FFFFU)

/* CAM1_MAXWIDTH */

#define CSL_CAL_LVDSRX_CAM1_MAXWIDTH_C1MW_MAXWIDTH_MASK                        (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_MAXWIDTH_C1MW_MAXWIDTH_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_MAXWIDTH_C1MW_MAXWIDTH_MAX                         (0x0000FFFFU)

/* CAM1_SYNCSOF */

#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOF_C1SF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM1_SYNCEOF */

#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOF_C1EF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM1_SYNCSOL */

#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOL_C1SL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM1_SYNCEOL */

#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCEOL_C1EL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM1_SYNCSOV */

#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM1_SYNCSOV_C1SV_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM2_CFG */

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_2_MASK                            (0x07000000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_2_SHIFT                           (0x00000018U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_2_MAX                             (0x00000007U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_1_MASK                            (0x00700000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_1_SHIFT                           (0x00000014U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_RESERVED_1_MAX                             (0x00000007U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUM_LANE_MASK                              (0x00070000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUM_LANE_SHIFT                             (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUM_LANE_MAX                               (0x00000007U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_ALIGN_MASK                                 (0x00008000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_ALIGN_SHIFT                                (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_ALIGN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_DENDIAN_MASK                               (0x00004000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_DENDIAN_SHIFT                              (0x0000000EU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_DENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FILEN_MASK                                 (0x00002000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FILEN_SHIFT                                (0x0000000DU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FILEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_CRCEN_MASK                                 (0x00001000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_CRCEN_SHIFT                                (0x0000000CU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_CRCEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_SENDIAN_MASK                               (0x00000800U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_SENDIAN_SHIFT                              (0x0000000BU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_SENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_PIX_WIDTH_MASK                             (0x00000700U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_PIX_WIDTH_SHIFT                            (0x00000008U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_PIX_WIDTH_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FRSTAT_INIT_MASK                           (0x00000080U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FRSTAT_INIT_SHIFT                          (0x00000007U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_FRSTAT_INIT_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUMPHY_MASK                                (0x00000030U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUMPHY_SHIFT                               (0x00000004U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_NUMPHY_MAX                                 (0x00000003U)

#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_OP_MODE_MASK                               (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_OP_MODE_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_CFG_CC2_OP_MODE_MAX                                (0x0000000FU)

/* CAM2_FRMSIZE */

#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_FRWIDTH_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_FRWIDTH_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_FRWIDTH_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_LNWIDTH_MASK                          (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_LNWIDTH_SHIFT                         (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_FRMSIZE_C2FS_LNWIDTH_MAX                           (0x0000FFFFU)

/* CAM2_MAXWIDTH */

#define CSL_CAL_LVDSRX_CAM2_MAXWIDTH_C2MW_MAXWIDTH_MASK                        (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_MAXWIDTH_C2MW_MAXWIDTH_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_MAXWIDTH_C2MW_MAXWIDTH_MAX                         (0x0000FFFFU)

/* CAM2_SYNCSOF */

#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOF_C2SF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM2_SYNCEOF */

#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOF_C2EF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM2_SYNCSOL */

#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOL_C2SL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM2_SYNCEOL */

#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCEOL_C2EL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM2_SYNCSOV */

#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM2_SYNCSOV_C2SV_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM3_CFG */

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE2_MASK                             (0x00700000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE2_SHIFT                            (0x00000014U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE2_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE1_MASK                             (0x00070000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE1_SHIFT                            (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUM_LANE1_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_ALIGN_MASK                                 (0x00008000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_ALIGN_SHIFT                                (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_ALIGN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_DENDIAN_MASK                               (0x00004000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_DENDIAN_SHIFT                              (0x0000000EU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_DENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FILEN_MASK                                 (0x00002000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FILEN_SHIFT                                (0x0000000DU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FILEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_CRCEN_MASK                                 (0x00001000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_CRCEN_SHIFT                                (0x0000000CU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_CRCEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_SENDIAN_MASK                               (0x00000800U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_SENDIAN_SHIFT                              (0x0000000BU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_SENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_PIX_WIDTH_MASK                             (0x00000700U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_PIX_WIDTH_SHIFT                            (0x00000008U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_PIX_WIDTH_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FRSTAT_INIT_MASK                           (0x00000080U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FRSTAT_INIT_SHIFT                          (0x00000007U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_FRSTAT_INIT_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUMPHY_MASK                                (0x00000030U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUMPHY_SHIFT                               (0x00000004U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_NUMPHY_MAX                                 (0x00000003U)

#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_OP_MODE_MASK                               (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_OP_MODE_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_CFG_CC3_OP_MODE_MAX                                (0x0000000FU)

/* CAM3_FRMSIZE */

#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_FRWIDTH_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_FRWIDTH_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_FRWIDTH_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_LNWIDTH_MASK                          (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_LNWIDTH_SHIFT                         (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_FRMSIZE_C3FS_LNWIDTH_MAX                           (0x0000FFFFU)

/* CAM3_MAXWIDTH */

#define CSL_CAL_LVDSRX_CAM3_MAXWIDTH_C3MW_MAXWIDTH_MASK                        (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_MAXWIDTH_C3MW_MAXWIDTH_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_MAXWIDTH_C3MW_MAXWIDTH_MAX                         (0x0000FFFFU)

/* CAM3_SYNCSOF */

#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOF_C3SF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM3_SYNCEOF */

#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOF_C3EF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM3_SYNCSOL */

#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOL_C3SL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM3_SYNCEOL */

#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCEOL_C3EL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM3_SYNCSOV */

#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM3_SYNCSOV_C3SV_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM4_CFG */

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUM_LANE_MASK                              (0x00070000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUM_LANE_SHIFT                             (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUM_LANE_MAX                               (0x00000007U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_ALIGN_MASK                                 (0x00008000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_ALIGN_SHIFT                                (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_ALIGN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_DENDIAN_MASK                               (0x00004000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_DENDIAN_SHIFT                              (0x0000000EU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_DENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FILEN_MASK                                 (0x00002000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FILEN_SHIFT                                (0x0000000DU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FILEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_CRCEN_MASK                                 (0x00001000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_CRCEN_SHIFT                                (0x0000000CU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_CRCEN_MAX                                  (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_SENDIAN_MASK                               (0x00000800U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_SENDIAN_SHIFT                              (0x0000000BU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_SENDIAN_MAX                                (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_PIX_WIDTH_MASK                             (0x00000700U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_PIX_WIDTH_SHIFT                            (0x00000008U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_PIX_WIDTH_MAX                              (0x00000007U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FRSTAT_INIT_MASK                           (0x00000080U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FRSTAT_INIT_SHIFT                          (0x00000007U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_FRSTAT_INIT_MAX                            (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUMPHY_MASK                                (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUMPHY_SHIFT                               (0x00000004U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_NUMPHY_MAX                                 (0x00000001U)

#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_OP_MODE_MASK                               (0x0000000FU)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_OP_MODE_SHIFT                              (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_CFG_CC4_OP_MODE_MAX                                (0x0000000FU)

/* CAM4_FRMSIZE */

#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_FRWIDTH_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_FRWIDTH_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_FRWIDTH_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_LNWIDTH_MASK                          (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_LNWIDTH_SHIFT                         (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_FRMSIZE_C4FS_LNWIDTH_MAX                           (0x0000FFFFU)

/* CAM4_MAXWIDTH */

#define CSL_CAL_LVDSRX_CAM4_MAXWIDTH_C4MW_MAXWIDTH_MASK                        (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_MAXWIDTH_C4MW_MAXWIDTH_SHIFT                       (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_MAXWIDTH_C4MW_MAXWIDTH_MAX                         (0x0000FFFFU)

/* CAM4_SYNCSOF */

#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOF_C4SF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM4_SYNCEOF */

#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOF_C4EF_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM4_SYNCSOL */

#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOL_C4SL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM4_SYNCEOL */

#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCEOL_C4EL_SOFPTN_MAX                            (0x0000FFFFU)

/* CAM4_SYNCSOV */

#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_BITMASK_MASK                          (0xFFFF0000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_BITMASK_SHIFT                         (0x00000010U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_BITMASK_MAX                           (0x0000FFFFU)

#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_SOFPTN_MASK                           (0x0000FFFFU)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_SOFPTN_SHIFT                          (0x00000000U)
#define CSL_CAL_LVDSRX_CAM4_SYNCSOV_C4SV_SOFPTN_MAX                            (0x0000FFFFU)

/* WDRCFG */

#define CSL_CAL_LVDSRX_WDRCFG_PIX_WIDTH_MASK                                   (0x00000F00U)
#define CSL_CAL_LVDSRX_WDRCFG_PIX_WIDTH_SHIFT                                  (0x00000008U)
#define CSL_CAL_LVDSRX_WDRCFG_PIX_WIDTH_MAX                                    (0x0000000FU)

#define CSL_CAL_LVDSRX_WDRCFG_WDRMODE_MASK                                     (0x00000010U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRMODE_SHIFT                                    (0x00000004U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRMODE_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_WDRCFG_WDRENA4_MASK                                     (0x00000008U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA4_SHIFT                                    (0x00000003U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA4_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_WDRCFG_WDRENA3_MASK                                     (0x00000004U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA3_SHIFT                                    (0x00000002U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA3_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_WDRCFG_WDRENA2_MASK                                     (0x00000002U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA2_SHIFT                                    (0x00000001U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA2_MAX                                      (0x00000001U)

#define CSL_CAL_LVDSRX_WDRCFG_WDRENA1_MASK                                     (0x00000001U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA1_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_WDRCFG_WDRENA1_MAX                                      (0x00000001U)

/* WDRGN */

#define CSL_CAL_LVDSRX_WDRGN_WDRNPXY1_MASK                                     (0x003F0000U)
#define CSL_CAL_LVDSRX_WDRGN_WDRNPXY1_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_WDRGN_WDRNPXY1_MAX                                      (0x0000003FU)

#define CSL_CAL_LVDSRX_WDRGN_WDRGN4_MASK                                       (0x00000F00U)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN4_SHIFT                                      (0x00000008U)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN4_MAX                                        (0x0000000FU)

#define CSL_CAL_LVDSRX_WDRGN_WDRGN3_MASK                                       (0x000000F0U)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN3_SHIFT                                      (0x00000004U)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN3_MAX                                        (0x0000000FU)

#define CSL_CAL_LVDSRX_WDRGN_WDRGN2_MASK                                       (0x0000000FU)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN2_SHIFT                                      (0x00000000U)
#define CSL_CAL_LVDSRX_WDRGN_WDRGN2_MAX                                        (0x0000000FU)

/* WDRKP1 */

#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY3_MASK                                     (0x03FF0000U)
#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY3_MAX                                      (0x000003FFU)

#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY2_MASK                                     (0x000003FFU)
#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY2_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_WDRKP1_WDRNPY2_MAX                                      (0x000003FFU)

/* WDRKP2 */

#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX3_MASK                                     (0x3FFF0000U)
#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX3_MAX                                      (0x00003FFFU)

#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX2_MASK                                     (0x00003FFFU)
#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX2_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_WDRKP2_WDRNPX2_MAX                                      (0x00003FFFU)

/* TEST1 */

#define CSL_CAL_LVDSRX_TEST1_T1_LANE4_MASK                                     (0xFF000000U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE4_SHIFT                                    (0x00000018U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE4_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST1_T1_LANE3_MASK                                     (0x00FF0000U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE3_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST1_T1_LANE2_MASK                                     (0x0000FF00U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE2_SHIFT                                    (0x00000008U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE2_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST1_T1_LANE1_MASK                                     (0x000000FFU)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE1_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_TEST1_T1_LANE1_MAX                                      (0x000000FFU)

/* TEST2 */

#define CSL_CAL_LVDSRX_TEST2_T2_LANE4_MASK                                     (0xFF000000U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE4_SHIFT                                    (0x00000018U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE4_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST2_T2_LANE3_MASK                                     (0x00FF0000U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE3_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST2_T2_LANE2_MASK                                     (0x0000FF00U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE2_SHIFT                                    (0x00000008U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE2_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST2_T2_LANE1_MASK                                     (0x000000FFU)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE1_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_TEST2_T2_LANE1_MAX                                      (0x000000FFU)

/* TEST3 */

#define CSL_CAL_LVDSRX_TEST3_T3_LANE4_MASK                                     (0xFF000000U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE4_SHIFT                                    (0x00000018U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE4_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST3_T3_LANE3_MASK                                     (0x00FF0000U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE3_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST3_T3_LANE2_MASK                                     (0x0000FF00U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE2_SHIFT                                    (0x00000008U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE2_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST3_T3_LANE1_MASK                                     (0x000000FFU)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE1_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_TEST3_T3_LANE1_MAX                                      (0x000000FFU)

/* TEST4 */

#define CSL_CAL_LVDSRX_TEST4_T4_LANE4_MASK                                     (0xFF000000U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE4_SHIFT                                    (0x00000018U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE4_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST4_T4_LANE3_MASK                                     (0x00FF0000U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE3_SHIFT                                    (0x00000010U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE3_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST4_T4_LANE2_MASK                                     (0x0000FF00U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE2_SHIFT                                    (0x00000008U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE2_MAX                                      (0x000000FFU)

#define CSL_CAL_LVDSRX_TEST4_T4_LANE1_MASK                                     (0x000000FFU)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE1_SHIFT                                    (0x00000000U)
#define CSL_CAL_LVDSRX_TEST4_T4_LANE1_MAX                                      (0x000000FFU)

/* HL_REVISION */

#define CSL_CAL_C2CTL_HL_REVISION_SCHEME_MASK                                  (0xC0000000U)
#define CSL_CAL_C2CTL_HL_REVISION_SCHEME_SHIFT                                 (0x0000001EU)
#define CSL_CAL_C2CTL_HL_REVISION_SCHEME_MAX                                   (0x00000003U)

#define CSL_CAL_C2CTL_HL_REVISION_FUNC_MASK                                    (0x0FFF0000U)
#define CSL_CAL_C2CTL_HL_REVISION_FUNC_SHIFT                                   (0x00000010U)
#define CSL_CAL_C2CTL_HL_REVISION_FUNC_MAX                                     (0x00000FFFU)

#define CSL_CAL_C2CTL_HL_REVISION_R_RTL_MASK                                   (0x0000F800U)
#define CSL_CAL_C2CTL_HL_REVISION_R_RTL_SHIFT                                  (0x0000000BU)
#define CSL_CAL_C2CTL_HL_REVISION_R_RTL_MAX                                    (0x0000001FU)

#define CSL_CAL_C2CTL_HL_REVISION_X_MAJOR_MASK                                 (0x00000700U)
#define CSL_CAL_C2CTL_HL_REVISION_X_MAJOR_SHIFT                                (0x00000008U)
#define CSL_CAL_C2CTL_HL_REVISION_X_MAJOR_MAX                                  (0x00000007U)

#define CSL_CAL_C2CTL_HL_REVISION_CUSTOM_MASK                                  (0x000000C0U)
#define CSL_CAL_C2CTL_HL_REVISION_CUSTOM_SHIFT                                 (0x00000006U)
#define CSL_CAL_C2CTL_HL_REVISION_CUSTOM_MAX                                   (0x00000003U)

#define CSL_CAL_C2CTL_HL_REVISION_Y_MINOR_MASK                                 (0x0000003FU)
#define CSL_CAL_C2CTL_HL_REVISION_Y_MINOR_SHIFT                                (0x00000000U)
#define CSL_CAL_C2CTL_HL_REVISION_Y_MINOR_MAX                                  (0x0000003FU)

/* HL_HWINFO */

#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS1_MASK                            (0xC0000000U)
#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS1_SHIFT                           (0x0000001EU)
#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS1_MAX                             (0x00000003U)

#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS0_MASK                            (0x30000000U)
#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS0_SHIFT                           (0x0000001CU)
#define CSL_CAL_C2CTL_HL_HWINFO_NPPI_CONTEXTS0_MAX                             (0x00000003U)

#define CSL_CAL_C2CTL_HL_HWINFO_NCPORT_MASK                                    (0x0F800000U)
#define CSL_CAL_C2CTL_HL_HWINFO_NCPORT_SHIFT                                   (0x00000017U)
#define CSL_CAL_C2CTL_HL_HWINFO_NCPORT_MAX                                     (0x0000001FU)

#define CSL_CAL_C2CTL_HL_HWINFO_VFIFO_MASK                                     (0x00780000U)
#define CSL_CAL_C2CTL_HL_HWINFO_VFIFO_SHIFT                                    (0x00000013U)
#define CSL_CAL_C2CTL_HL_HWINFO_VFIFO_MAX                                      (0x0000000FU)

#define CSL_CAL_C2CTL_HL_HWINFO_WCTX_MASK                                      (0x0007E000U)
#define CSL_CAL_C2CTL_HL_HWINFO_WCTX_SHIFT                                     (0x0000000DU)
#define CSL_CAL_C2CTL_HL_HWINFO_WCTX_MAX                                       (0x0000003FU)

#define CSL_CAL_C2CTL_HL_HWINFO_PCTX_MASK                                      (0x00001F00U)
#define CSL_CAL_C2CTL_HL_HWINFO_PCTX_SHIFT                                     (0x00000008U)
#define CSL_CAL_C2CTL_HL_HWINFO_PCTX_MAX                                       (0x0000001FU)

#define CSL_CAL_C2CTL_HL_HWINFO_RFIFO_MASK                                     (0x000000F0U)
#define CSL_CAL_C2CTL_HL_HWINFO_RFIFO_SHIFT                                    (0x00000004U)
#define CSL_CAL_C2CTL_HL_HWINFO_RFIFO_MAX                                      (0x0000000FU)

#define CSL_CAL_C2CTL_HL_HWINFO_WFIFO_MASK                                     (0x0000000FU)
#define CSL_CAL_C2CTL_HL_HWINFO_WFIFO_SHIFT                                    (0x00000000U)
#define CSL_CAL_C2CTL_HL_HWINFO_WFIFO_MAX                                      (0x0000000FU)

/* HL_SYSCONFIG */

#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_MASK                               (0x0000000CU)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_SHIFT                              (0x00000002U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_MAX                                (0x00000003U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_FORCE                              (0U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_NO                                 (1U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_SMART1                             (2U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_IDLEMODE_SMART2                             (3U)


#define CSL_CAL_C2CTL_HL_SYSCONFIG_SOFTRESET_MASK                              (0x00000001U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_SOFTRESET_SHIFT                             (0x00000000U)
#define CSL_CAL_C2CTL_HL_SYSCONFIG_SOFTRESET_MAX                               (0x00000001U)

/* HL_IRQ_EOI */

#define CSL_CAL_C2CTL_HL_IRQ_EOI_LINE_NUMBER_MASK                              (0x00000001U)
#define CSL_CAL_C2CTL_HL_IRQ_EOI_LINE_NUMBER_SHIFT                             (0x00000000U)
#define CSL_CAL_C2CTL_HL_IRQ_EOI_LINE_NUMBER_MAX                               (0x00000001U)

/* HL_IRQSTATUS_RAW */

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ31_MASK                              (0x80000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ31_SHIFT                             (0x0000001FU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ31_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ30_MASK                              (0x40000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ30_SHIFT                             (0x0000001EU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ30_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ29_MASK                              (0x20000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ29_SHIFT                             (0x0000001DU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ29_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ28_MASK                              (0x10000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ28_SHIFT                             (0x0000001CU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ28_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ27_MASK                              (0x08000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ27_SHIFT                             (0x0000001BU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ27_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ26_MASK                              (0x04000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ26_SHIFT                             (0x0000001AU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ26_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ25_MASK                              (0x02000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ25_SHIFT                             (0x00000019U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ25_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ24_MASK                              (0x01000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ24_SHIFT                             (0x00000018U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ24_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ23_MASK                              (0x00800000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ23_SHIFT                             (0x00000017U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ23_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ22_MASK                              (0x00400000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ22_SHIFT                             (0x00000016U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ22_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ21_MASK                              (0x00200000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ21_SHIFT                             (0x00000015U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ21_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ20_MASK                              (0x00100000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ20_SHIFT                             (0x00000014U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ20_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ19_MASK                              (0x00080000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ19_SHIFT                             (0x00000013U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ19_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ18_MASK                              (0x00040000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ18_SHIFT                             (0x00000012U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ18_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ17_MASK                              (0x00020000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ17_SHIFT                             (0x00000011U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ17_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ16_MASK                              (0x00010000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ16_SHIFT                             (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ16_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ15_MASK                              (0x00008000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ15_SHIFT                             (0x0000000FU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ15_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ14_MASK                              (0x00004000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ14_SHIFT                             (0x0000000EU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ14_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ13_MASK                              (0x00002000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ13_SHIFT                             (0x0000000DU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ13_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ12_MASK                              (0x00001000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ12_SHIFT                             (0x0000000CU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ12_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ11_MASK                              (0x00000800U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ11_SHIFT                             (0x0000000BU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ11_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ10_MASK                              (0x00000400U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ10_SHIFT                             (0x0000000AU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ10_MAX                               (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ9_MASK                               (0x00000200U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ9_SHIFT                              (0x00000009U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ9_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ8_MASK                               (0x00000100U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ8_SHIFT                              (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ8_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ7_MASK                               (0x00000080U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ7_SHIFT                              (0x00000007U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ7_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ6_MASK                               (0x00000040U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ6_SHIFT                              (0x00000006U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ6_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ5_MASK                               (0x00000020U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ5_SHIFT                              (0x00000005U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ5_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ4_MASK                               (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ4_SHIFT                              (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ4_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ3_MASK                               (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ3_SHIFT                              (0x00000003U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ3_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ2_MASK                               (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ2_SHIFT                              (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ2_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ1_MASK                               (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ1_SHIFT                              (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ1_MAX                                (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ0_MASK                               (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ0_SHIFT                              (0x00000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_RAW_IRQ0_MAX                                (0x00000001U)

/* HL_IRQSTATUS */

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ31_MASK                                  (0x80000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ31_SHIFT                                 (0x0000001FU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ31_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ30_MASK                                  (0x40000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ30_SHIFT                                 (0x0000001EU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ30_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ29_MASK                                  (0x20000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ29_SHIFT                                 (0x0000001DU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ29_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ28_MASK                                  (0x10000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ28_SHIFT                                 (0x0000001CU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ28_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ27_MASK                                  (0x08000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ27_SHIFT                                 (0x0000001BU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ27_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ26_MASK                                  (0x04000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ26_SHIFT                                 (0x0000001AU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ26_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ25_MASK                                  (0x02000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ25_SHIFT                                 (0x00000019U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ25_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ24_MASK                                  (0x01000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ24_SHIFT                                 (0x00000018U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ24_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ23_MASK                                  (0x00800000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ23_SHIFT                                 (0x00000017U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ23_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ22_MASK                                  (0x00400000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ22_SHIFT                                 (0x00000016U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ22_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ21_MASK                                  (0x00200000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ21_SHIFT                                 (0x00000015U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ21_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ20_MASK                                  (0x00100000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ20_SHIFT                                 (0x00000014U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ20_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ19_MASK                                  (0x00080000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ19_SHIFT                                 (0x00000013U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ19_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ18_MASK                                  (0x00040000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ18_SHIFT                                 (0x00000012U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ18_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ17_MASK                                  (0x00020000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ17_SHIFT                                 (0x00000011U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ17_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ16_MASK                                  (0x00010000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ16_SHIFT                                 (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ16_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ15_MASK                                  (0x00008000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ15_SHIFT                                 (0x0000000FU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ15_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ14_MASK                                  (0x00004000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ14_SHIFT                                 (0x0000000EU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ14_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ13_MASK                                  (0x00002000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ13_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ13_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ12_MASK                                  (0x00001000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ12_SHIFT                                 (0x0000000CU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ12_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ11_MASK                                  (0x00000800U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ11_SHIFT                                 (0x0000000BU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ11_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ10_MASK                                  (0x00000400U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ10_SHIFT                                 (0x0000000AU)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ10_MAX                                   (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ9_MASK                                   (0x00000200U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ9_SHIFT                                  (0x00000009U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ9_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ8_MASK                                   (0x00000100U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ8_SHIFT                                  (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ8_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ7_MASK                                   (0x00000080U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ7_SHIFT                                  (0x00000007U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ7_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ6_MASK                                   (0x00000040U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ6_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ6_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ5_MASK                                   (0x00000020U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ5_SHIFT                                  (0x00000005U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ5_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ4_MASK                                   (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ4_SHIFT                                  (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ4_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ3_MASK                                   (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ3_SHIFT                                  (0x00000003U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ3_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ2_MASK                                   (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ2_SHIFT                                  (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ2_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ1_MASK                                   (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ1_SHIFT                                  (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ1_MAX                                    (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ0_MASK                                   (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ0_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2IRQ_HL_IRQSTATUS_IRQ0_MAX                                    (0x00000001U)

/* HL_IRQENABLE_SET */

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ31_EN_MASK                           (0x80000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ31_EN_SHIFT                          (0x0000001FU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ31_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ30_EN_MASK                           (0x40000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ30_EN_SHIFT                          (0x0000001EU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ30_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ29_EN_MASK                           (0x20000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ29_EN_SHIFT                          (0x0000001DU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ29_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ28_EN_MASK                           (0x10000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ28_EN_SHIFT                          (0x0000001CU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ28_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ27_EN_MASK                           (0x08000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ27_EN_SHIFT                          (0x0000001BU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ27_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ26_EN_MASK                           (0x04000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ26_EN_SHIFT                          (0x0000001AU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ26_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ25_EN_MASK                           (0x02000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ25_EN_SHIFT                          (0x00000019U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ25_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ24_EN_MASK                           (0x01000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ24_EN_SHIFT                          (0x00000018U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ24_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ23_EN_MASK                           (0x00800000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ23_EN_SHIFT                          (0x00000017U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ23_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ22_EN_MASK                           (0x00400000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ22_EN_SHIFT                          (0x00000016U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ22_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ21_EN_MASK                           (0x00200000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ21_EN_SHIFT                          (0x00000015U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ21_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ20_EN_MASK                           (0x00100000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ20_EN_SHIFT                          (0x00000014U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ20_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ19_EN_MASK                           (0x00080000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ19_EN_SHIFT                          (0x00000013U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ19_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ18_EN_MASK                           (0x00040000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ18_EN_SHIFT                          (0x00000012U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ18_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ17_EN_MASK                           (0x00020000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ17_EN_SHIFT                          (0x00000011U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ17_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ16_EN_MASK                           (0x00010000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ16_EN_SHIFT                          (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ16_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ15_EN_MASK                           (0x00008000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ15_EN_SHIFT                          (0x0000000FU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ15_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ14_EN_MASK                           (0x00004000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ14_EN_SHIFT                          (0x0000000EU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ14_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ13_EN_MASK                           (0x00002000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ13_EN_SHIFT                          (0x0000000DU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ13_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ12_EN_MASK                           (0x00001000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ12_EN_SHIFT                          (0x0000000CU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ12_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ11_EN_MASK                           (0x00000800U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ11_EN_SHIFT                          (0x0000000BU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ11_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ10_EN_MASK                           (0x00000400U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ10_EN_SHIFT                          (0x0000000AU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ10_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ9_EN_MASK                            (0x00000200U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ9_EN_SHIFT                           (0x00000009U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ9_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ8_EN_MASK                            (0x00000100U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ8_EN_SHIFT                           (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ8_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ7_EN_MASK                            (0x00000080U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ7_EN_SHIFT                           (0x00000007U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ7_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ6_EN_MASK                            (0x00000040U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ6_EN_SHIFT                           (0x00000006U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ6_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ5_EN_MASK                            (0x00000020U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ5_EN_SHIFT                           (0x00000005U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ5_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ4_EN_MASK                            (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ4_EN_SHIFT                           (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ4_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ3_EN_MASK                            (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ3_EN_SHIFT                           (0x00000003U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ3_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ2_EN_MASK                            (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ2_EN_SHIFT                           (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ2_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ1_EN_MASK                            (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ1_EN_SHIFT                           (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ1_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ0_EN_MASK                            (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ0_EN_SHIFT                           (0x00000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_SET_IRQ0_EN_MAX                             (0x00000001U)

/* HL_IRQENABLE_CLR */

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ31_EN_MASK                           (0x80000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ31_EN_SHIFT                          (0x0000001FU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ31_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ30_EN_MASK                           (0x40000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ30_EN_SHIFT                          (0x0000001EU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ30_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ29_EN_MASK                           (0x20000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ29_EN_SHIFT                          (0x0000001DU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ29_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ28_EN_MASK                           (0x10000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ28_EN_SHIFT                          (0x0000001CU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ28_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ27_EN_MASK                           (0x08000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ27_EN_SHIFT                          (0x0000001BU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ27_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ26_EN_MASK                           (0x04000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ26_EN_SHIFT                          (0x0000001AU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ26_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ25_EN_MASK                           (0x02000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ25_EN_SHIFT                          (0x00000019U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ25_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ24_EN_MASK                           (0x01000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ24_EN_SHIFT                          (0x00000018U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ24_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ23_EN_MASK                           (0x00800000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ23_EN_SHIFT                          (0x00000017U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ23_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ22_EN_MASK                           (0x00400000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ22_EN_SHIFT                          (0x00000016U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ22_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ21_EN_MASK                           (0x00200000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ21_EN_SHIFT                          (0x00000015U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ21_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ20_EN_MASK                           (0x00100000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ20_EN_SHIFT                          (0x00000014U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ20_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ19_EN_MASK                           (0x00080000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ19_EN_SHIFT                          (0x00000013U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ19_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ18_EN_MASK                           (0x00040000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ18_EN_SHIFT                          (0x00000012U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ18_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ17_EN_MASK                           (0x00020000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ17_EN_SHIFT                          (0x00000011U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ17_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ16_EN_MASK                           (0x00010000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ16_EN_SHIFT                          (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ16_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ15_EN_MASK                           (0x00008000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ15_EN_SHIFT                          (0x0000000FU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ15_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ14_EN_MASK                           (0x00004000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ14_EN_SHIFT                          (0x0000000EU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ14_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ13_EN_MASK                           (0x00002000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ13_EN_SHIFT                          (0x0000000DU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ13_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ12_EN_MASK                           (0x00001000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ12_EN_SHIFT                          (0x0000000CU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ12_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ11_EN_MASK                           (0x00000800U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ11_EN_SHIFT                          (0x0000000BU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ11_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ10_EN_MASK                           (0x00000400U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ10_EN_SHIFT                          (0x0000000AU)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ10_EN_MAX                            (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ9_EN_MASK                            (0x00000200U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ9_EN_SHIFT                           (0x00000009U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ9_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ8_EN_MASK                            (0x00000100U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ8_EN_SHIFT                           (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ8_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ7_EN_MASK                            (0x00000080U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ7_EN_SHIFT                           (0x00000007U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ7_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ6_EN_MASK                            (0x00000040U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ6_EN_SHIFT                           (0x00000006U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ6_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ5_EN_MASK                            (0x00000020U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ5_EN_SHIFT                           (0x00000005U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ5_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ4_EN_MASK                            (0x00000010U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ4_EN_SHIFT                           (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ4_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ3_EN_MASK                            (0x00000008U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ3_EN_SHIFT                           (0x00000003U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ3_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ2_EN_MASK                            (0x00000004U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ2_EN_SHIFT                           (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ2_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ1_EN_MASK                            (0x00000002U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ1_EN_SHIFT                           (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ1_EN_MAX                             (0x00000001U)

#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ0_EN_MASK                            (0x00000001U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ0_EN_SHIFT                           (0x00000000U)
#define CSL_CAL_C2IRQ_HL_IRQENABLE_CLR_IRQ0_EN_MAX                             (0x00000001U)

/* PIX_PROC */

#define CSL_CAL_C2PIX_PIX_PROC_CPORT_MASK                                      (0x00F80000U)
#define CSL_CAL_C2PIX_PIX_PROC_CPORT_SHIFT                                     (0x00000013U)
#define CSL_CAL_C2PIX_PIX_PROC_CPORT_MAX                                       (0x0000001FU)

#define CSL_CAL_C2PIX_PIX_PROC_PACK_MASK                                       (0x00070000U)
#define CSL_CAL_C2PIX_PIX_PROC_PACK_SHIFT                                      (0x00000010U)
#define CSL_CAL_C2PIX_PIX_PROC_PACK_MAX                                        (0x00000007U)

#define CSL_CAL_C2PIX_PIX_PROC_DPCME_MASK                                      (0x0000F800U)
#define CSL_CAL_C2PIX_PIX_PROC_DPCME_SHIFT                                     (0x0000000BU)
#define CSL_CAL_C2PIX_PIX_PROC_DPCME_MAX                                       (0x0000001FU)

#define CSL_CAL_C2PIX_PIX_PROC_DPCMD_MASK                                      (0x000003E0U)
#define CSL_CAL_C2PIX_PIX_PROC_DPCMD_SHIFT                                     (0x00000005U)
#define CSL_CAL_C2PIX_PIX_PROC_DPCMD_MAX                                       (0x0000001FU)

#define CSL_CAL_C2PIX_PIX_PROC_EXTRACT_MASK                                    (0x0000001EU)
#define CSL_CAL_C2PIX_PIX_PROC_EXTRACT_SHIFT                                   (0x00000001U)
#define CSL_CAL_C2PIX_PIX_PROC_EXTRACT_MAX                                     (0x0000000FU)

#define CSL_CAL_C2PIX_PIX_PROC_EN_MASK                                         (0x00000001U)
#define CSL_CAL_C2PIX_PIX_PROC_EN_SHIFT                                        (0x00000000U)
#define CSL_CAL_C2PIX_PIX_PROC_EN_MAX                                          (0x00000001U)

/* CTRL */

#define CSL_CAL_C2VID_CTRL_MFLAGH_MASK                                         (0xFF000000U)
#define CSL_CAL_C2VID_CTRL_MFLAGH_SHIFT                                        (0x00000018U)
#define CSL_CAL_C2VID_CTRL_MFLAGH_MAX                                          (0x000000FFU)

#define CSL_CAL_C2VID_CTRL_RD_DMA_STALL_MASK                                   (0x00400000U)
#define CSL_CAL_C2VID_CTRL_RD_DMA_STALL_SHIFT                                  (0x00000016U)
#define CSL_CAL_C2VID_CTRL_RD_DMA_STALL_MAX                                    (0x00000001U)

#define CSL_CAL_C2VID_CTRL_PWRSCPCLK_MASK                                      (0x00200000U)
#define CSL_CAL_C2VID_CTRL_PWRSCPCLK_SHIFT                                     (0x00000015U)
#define CSL_CAL_C2VID_CTRL_PWRSCPCLK_MAX                                       (0x00000001U)

#define CSL_CAL_C2VID_CTRL_MFLAGL_MASK                                         (0x001FE000U)
#define CSL_CAL_C2VID_CTRL_MFLAGL_SHIFT                                        (0x0000000DU)
#define CSL_CAL_C2VID_CTRL_MFLAGL_MAX                                          (0x000000FFU)

#define CSL_CAL_C2VID_CTRL_LL_FORCE_STATE_MASK                                 (0x00001F80U)
#define CSL_CAL_C2VID_CTRL_LL_FORCE_STATE_SHIFT                                (0x00000007U)
#define CSL_CAL_C2VID_CTRL_LL_FORCE_STATE_MAX                                  (0x0000003FU)

#define CSL_CAL_C2VID_CTRL_BURSTSIZE_MASK                                      (0x00000060U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_SHIFT                                     (0x00000005U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_MAX                                       (0x00000003U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_BURST16                                   (0U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_BURST32                                   (1U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_BURST64                                   (2U)
#define CSL_CAL_C2VID_CTRL_BURSTSIZE_BURST128                                  (3U)

#define CSL_CAL_C2VID_CTRL_TAGCNT_MASK                                         (0x0000001EU)
#define CSL_CAL_C2VID_CTRL_TAGCNT_SHIFT                                        (0x00000001U)
#define CSL_CAL_C2VID_CTRL_TAGCNT_MAX                                          (0x0000000FU)

#define CSL_CAL_C2VID_CTRL_POSTED_WRITES_MASK                                  (0x00000001U)
#define CSL_CAL_C2VID_CTRL_POSTED_WRITES_SHIFT                                 (0x00000000U)
#define CSL_CAL_C2VID_CTRL_POSTED_WRITES_MAX                                   (0x00000001U)

/* CTRL1 */

#define CSL_CAL_C2VID_CTRL1_INTERLEAVE23_MASK                                  (0x00000030U)
#define CSL_CAL_C2VID_CTRL1_INTERLEAVE23_SHIFT                                 (0x00000004U)
#define CSL_CAL_C2VID_CTRL1_INTERLEAVE23_MAX                                   (0x00000003U)

#define CSL_CAL_C2VID_CTRL1_INTERLEAVE01_MASK                                  (0x0000000CU)
#define CSL_CAL_C2VID_CTRL1_INTERLEAVE01_SHIFT                                 (0x00000002U)
#define CSL_CAL_C2VID_CTRL1_INTERLEAVE01_MAX                                   (0x00000003U)

#define CSL_CAL_C2VID_CTRL1_PPI_GROUPING_MASK                                  (0x00000003U)
#define CSL_CAL_C2VID_CTRL1_PPI_GROUPING_SHIFT                                 (0x00000000U)
#define CSL_CAL_C2VID_CTRL1_PPI_GROUPING_MAX                                   (0x00000003U)

/* LINE_NUMBER_EVT */

#define CSL_CAL_C2VID_LINE_NUMBER_EVT_LINE_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2VID_LINE_NUMBER_EVT_LINE_SHIFT                               (0x00000010U)
#define CSL_CAL_C2VID_LINE_NUMBER_EVT_LINE_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2VID_LINE_NUMBER_EVT_CPORT_MASK                               (0x0000001FU)
#define CSL_CAL_C2VID_LINE_NUMBER_EVT_CPORT_SHIFT                              (0x00000000U)
#define CSL_CAL_C2VID_LINE_NUMBER_EVT_CPORT_MAX                                (0x0000001FU)

/* VPORT_CTRL1 */

#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_WIDTH_MASK                               (0x80000000U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_WIDTH_SHIFT                              (0x0000001FU)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_WIDTH_MAX                                (0x00000001U)

#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_YBLK_MASK                                (0x7E000000U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_YBLK_SHIFT                               (0x00000019U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_YBLK_MAX                                 (0x0000003FU)

#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_XBLK_MASK                                (0x01FE0000U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_XBLK_SHIFT                               (0x00000011U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_XBLK_MAX                                 (0x000000FFU)

#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_PCLK_MASK                                (0x0001FFFFU)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_PCLK_SHIFT                               (0x00000000U)
#define CSL_CAL_C2VID_VPORT_CTRL1_VC1_PCLK_MAX                                 (0x0001FFFFU)

/* VPORT_CTRL2 */

#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_RDY_THR_MASK                             (0xFFFC0000U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_RDY_THR_SHIFT                            (0x00000012U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_RDY_THR_MAX                              (0x00003FFFU)

#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FSM_RESET_MASK                           (0x00020000U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FSM_RESET_SHIFT                          (0x00000011U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FSM_RESET_MAX                            (0x00000001U)

#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FS_RESETS_MASK                           (0x00010000U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FS_RESETS_SHIFT                          (0x00000010U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FS_RESETS_MAX                            (0x00000001U)

#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FREERUNNING_MASK                         (0x00008000U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FREERUNNING_SHIFT                        (0x0000000FU)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_FREERUNNING_MAX                          (0x00000001U)

#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_CPORT_MASK                               (0x0000003FU)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_CPORT_SHIFT                              (0x00000000U)
#define CSL_CAL_C2VID_VPORT_CTRL2_VC2_CPORT_MAX                                (0x0000003FU)

/* BYS_CTRL1 */

#define CSL_CAL_C2VID_BYS_CTRL1_BC1_BYSINEN_MASK                               (0x80000000U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_BYSINEN_SHIFT                              (0x0000001FU)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_BYSINEN_MAX                                (0x00000001U)

#define CSL_CAL_C2VID_BYS_CTRL1_BC1_YBLK_MASK                                  (0x7E000000U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_YBLK_SHIFT                                 (0x00000019U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_YBLK_MAX                                   (0x0000003FU)

#define CSL_CAL_C2VID_BYS_CTRL1_BC1_XBLK_MASK                                  (0x01FE0000U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_XBLK_SHIFT                                 (0x00000011U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_XBLK_MAX                                   (0x000000FFU)

#define CSL_CAL_C2VID_BYS_CTRL1_BC1_PCLK_MASK                                  (0x0001FFFFU)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_PCLK_SHIFT                                 (0x00000000U)
#define CSL_CAL_C2VID_BYS_CTRL1_BC1_PCLK_MAX                                   (0x0001FFFFU)

/* BYS_CTRL2 */

#define CSL_CAL_C2VID_BYS_CTRL2_BC2_FREERUNNING_MASK                           (0x00000800U)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_FREERUNNING_SHIFT                          (0x0000000BU)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_FREERUNNING_MAX                            (0x00000001U)

#define CSL_CAL_C2VID_BYS_CTRL2_BC2_DUPLICATEDDATA_MASK                        (0x00000400U)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_DUPLICATEDDATA_SHIFT                       (0x0000000AU)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_DUPLICATEDDATA_MAX                         (0x00000001U)

#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTOUT_MASK                              (0x000003E0U)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTOUT_SHIFT                             (0x00000005U)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTOUT_MAX                               (0x0000001FU)

#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTIN_MASK                               (0x0000001FU)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTIN_SHIFT                              (0x00000000U)
#define CSL_CAL_C2VID_BYS_CTRL2_BC2_CPORTIN_MAX                                (0x0000001FU)

/* RD_DMA_CTRL */

#define CSL_CAL_C2VID_RD_DMA_CTRL_PCLK_MASK                                    (0xFFFF8000U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_PCLK_SHIFT                                   (0x0000000FU)
#define CSL_CAL_C2VID_RD_DMA_CTRL_PCLK_MAX                                     (0x0001FFFFU)

#define CSL_CAL_C2VID_RD_DMA_CTRL_OCP_TAG_CNT_MASK                             (0x00007800U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_OCP_TAG_CNT_SHIFT                            (0x0000000BU)
#define CSL_CAL_C2VID_RD_DMA_CTRL_OCP_TAG_CNT_MAX                              (0x0000000FU)

#define CSL_CAL_C2VID_RD_DMA_CTRL_BW_LIMITER_MASK                              (0x000007FCU)
#define CSL_CAL_C2VID_RD_DMA_CTRL_BW_LIMITER_SHIFT                             (0x00000002U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_BW_LIMITER_MAX                               (0x000001FFU)

#define CSL_CAL_C2VID_RD_DMA_CTRL_INIT_MASK                                    (0x00000002U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_INIT_SHIFT                                   (0x00000001U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_INIT_MAX                                     (0x00000001U)

#define CSL_CAL_C2VID_RD_DMA_CTRL_GO_MASK                                      (0x00000001U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_GO_SHIFT                                     (0x00000000U)
#define CSL_CAL_C2VID_RD_DMA_CTRL_GO_MAX                                       (0x00000001U)

/* RD_DMA_PIX_ADDR */

#define CSL_CAL_C2VID_RD_DMA_PIX_ADDR_ADDR_MASK                                (0xFFFFFFF8U)
#define CSL_CAL_C2VID_RD_DMA_PIX_ADDR_ADDR_SHIFT                               (0x00000003U)
#define CSL_CAL_C2VID_RD_DMA_PIX_ADDR_ADDR_MAX                                 (0x1FFFFFFFU)

/* RD_DMA_PIX_OFST */

#define CSL_CAL_C2VID_RD_DMA_PIX_OFST_OFST_MASK                                (0xFFFFFFF0U)
#define CSL_CAL_C2VID_RD_DMA_PIX_OFST_OFST_SHIFT                               (0x00000004U)
#define CSL_CAL_C2VID_RD_DMA_PIX_OFST_OFST_MAX                                 (0x0FFFFFFFU)

/* RD_DMA_XSIZE */

#define CSL_CAL_C2VID_RD_DMA_XSIZE_XSIZE_MASK                                  (0xFFF80000U)
#define CSL_CAL_C2VID_RD_DMA_XSIZE_XSIZE_SHIFT                                 (0x00000013U)
#define CSL_CAL_C2VID_RD_DMA_XSIZE_XSIZE_MAX                                   (0x00001FFFU)

/* RD_DMA_YSIZE */

#define CSL_CAL_C2VID_RD_DMA_YSIZE_YSIZE_MASK                                  (0x3FFF0000U)
#define CSL_CAL_C2VID_RD_DMA_YSIZE_YSIZE_SHIFT                                 (0x00000010U)
#define CSL_CAL_C2VID_RD_DMA_YSIZE_YSIZE_MAX                                   (0x00003FFFU)

/* RD_DMA_INIT_ADDR */

#define CSL_CAL_C2VID_RD_DMA_INIT_ADDR_DIA_ADDR_MASK                           (0xFFFFFFF8U)
#define CSL_CAL_C2VID_RD_DMA_INIT_ADDR_DIA_ADDR_SHIFT                          (0x00000003U)
#define CSL_CAL_C2VID_RD_DMA_INIT_ADDR_DIA_ADDR_MAX                            (0x1FFFFFFFU)

/* RD_DMA_INIT_OFST */

#define CSL_CAL_C2VID_RD_DMA_INIT_OFST_DIO_OFST_MASK                           (0xFFFFFFF8U)
#define CSL_CAL_C2VID_RD_DMA_INIT_OFST_DIO_OFST_SHIFT                          (0x00000003U)
#define CSL_CAL_C2VID_RD_DMA_INIT_OFST_DIO_OFST_MAX                            (0x1FFFFFFFU)

/* RD_DMA_CTRL2 */

#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_SIZE_MASK                              (0x3FFF0000U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_SIZE_SHIFT                             (0x00000010U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_SIZE_MAX                               (0x00003FFFU)

#define CSL_CAL_C2VID_RD_DMA_CTRL2_BYSOUT_LE_WAIT_MASK                         (0x00000040U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_BYSOUT_LE_WAIT_SHIFT                        (0x00000006U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_BYSOUT_LE_WAIT_MAX                          (0x00000001U)

#define CSL_CAL_C2VID_RD_DMA_CTRL2_RD_PATTERN_MASK                             (0x00000030U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_RD_PATTERN_SHIFT                            (0x00000004U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_RD_PATTERN_MAX                              (0x00000003U)

#define CSL_CAL_C2VID_RD_DMA_CTRL2_ICM_CSTART_MASK                             (0x00000008U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_ICM_CSTART_SHIFT                            (0x00000003U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_ICM_CSTART_MAX                              (0x00000001U)

#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_MODE_MASK                              (0x00000007U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_MODE_SHIFT                             (0x00000000U)
#define CSL_CAL_C2VID_RD_DMA_CTRL2_CIRC_MODE_MAX                               (0x00000007U)

/* WR_DMA_CTRL */

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YSIZE_MASK                                  (0xFFFC0000U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YSIZE_SHIFT                                 (0x00000012U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YSIZE_MAX                                   (0x00003FFFU)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YUV422BP_MASK                               (0x00008000U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YUV422BP_SHIFT                              (0x0000000FU)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_YUV422BP_MAX                                (0x00000001U)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_STALL_RD_DMA_MASK                           (0x00004000U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_STALL_RD_DMA_SHIFT                          (0x0000000EU)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_STALL_RD_DMA_MAX                            (0x00000001U)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_CPORT_MASK                                  (0x00003E00U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_CPORT_SHIFT                                 (0x00000009U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_CPORT_MAX                                   (0x0000001FU)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_DTAG_MASK                                   (0x000001C0U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_DTAG_SHIFT                                  (0x00000006U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_DTAG_MAX                                    (0x00000007U)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_ICM_PSTART_MASK                             (0x00000020U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_ICM_PSTART_SHIFT                            (0x00000005U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_ICM_PSTART_MAX                              (0x00000001U)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_WR_PATTERN_MASK                             (0x00000018U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_WR_PATTERN_SHIFT                            (0x00000003U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_WR_PATTERN_MAX                              (0x00000003U)

#define CSL_CAL_WR_DMA_WR_DMA_CTRL_MODE_MASK                                   (0x00000007U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_MODE_SHIFT                                  (0x00000000U)
#define CSL_CAL_WR_DMA_WR_DMA_CTRL_MODE_MAX                                    (0x00000007U)

/* WR_DMA_ADDR */

#define CSL_CAL_WR_DMA_WR_DMA_ADDR_ADDR_MASK                                   (0xFFFFFFF0U)
#define CSL_CAL_WR_DMA_WR_DMA_ADDR_ADDR_SHIFT                                  (0x00000004U)
#define CSL_CAL_WR_DMA_WR_DMA_ADDR_ADDR_MAX                                    (0x0FFFFFFFU)

/* WR_DMA_OFST */

#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_SIZE_MASK                              (0xFF000000U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_SIZE_SHIFT                             (0x00000018U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_SIZE_MAX                               (0x000000FFU)

#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_MODE_MASK                              (0x00C00000U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_MODE_SHIFT                             (0x00000016U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_CIRC_MODE_MAX                               (0x00000003U)

#define CSL_CAL_WR_DMA_WR_DMA_OFST_OFST_MASK                                   (0x0007FFF0U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_OFST_SHIFT                                  (0x00000004U)
#define CSL_CAL_WR_DMA_WR_DMA_OFST_OFST_MAX                                    (0x00007FFFU)

/* WR_DMA_XSIZE */

#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSIZE_MASK                                 (0xFFF80000U)
#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSIZE_SHIFT                                (0x00000013U)
#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSIZE_MAX                                  (0x00001FFFU)

#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSKIP_MASK                                 (0x0000FFF8U)
#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSKIP_SHIFT                                (0x00000003U)
#define CSL_CAL_WR_DMA_WR_DMA_XSIZE_XSKIP_MAX                                  (0x00001FFFU)

/* CSI2_PPI_CTRL */

#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_FRAME_MASK                                 (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_FRAME_SHIFT                                (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_FRAME_MAX                                  (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_ECC_EN_MASK                                (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_ECC_EN_SHIFT                               (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_ECC_EN_MAX                                 (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_IF_EN_MASK                                 (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_IF_EN_SHIFT                                (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_PPI_CTRL_IF_EN_MAX                                  (0x00000001U)

/* CSI2_COMPLEXIO_CFG */

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_CTRL_MASK                       (0x40000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_CTRL_SHIFT                      (0x0000001EU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_CTRL_MAX                        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_DONE_MASK                       (0x20000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_DONE_SHIFT                      (0x0000001DU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_RESET_DONE_MAX                        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_MASK                          (0x18000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_SHIFT                         (0x0000001BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_MAX                           (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_STATE_OFF                     (0U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_STATE_ON                      (1U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_CMD_STATE_ULP                     (2U)


#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_MASK                       (0x06000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_SHIFT                      (0x00000019U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_MAX                        (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_STATE_OFF                  (0U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_STATE_ON                   (1U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_STATUS_STATE_ULP                  (2U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_AUTO_MASK                         (0x01000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_AUTO_SHIFT                        (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_PWR_AUTO_MAX                          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POL_MASK                        (0x00080000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POL_SHIFT                       (0x00000013U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POL_MAX                         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POSITION_MASK                   (0x00070000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POSITION_SHIFT                  (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA4_POSITION_MAX                    (0x00000007U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POL_MASK                        (0x00008000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POL_SHIFT                       (0x0000000FU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POL_MAX                         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POSITION_MASK                   (0x00007000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POSITION_SHIFT                  (0x0000000CU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA3_POSITION_MAX                    (0x00000007U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POL_MASK                        (0x00000800U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POL_SHIFT                       (0x0000000BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POL_MAX                         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POSITION_MASK                   (0x00000700U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POSITION_SHIFT                  (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA2_POSITION_MAX                    (0x00000007U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POL_MASK                        (0x00000080U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POL_SHIFT                       (0x00000007U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POL_MAX                         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POSITION_MASK                   (0x00000070U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POSITION_SHIFT                  (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_DATA1_POSITION_MAX                    (0x00000007U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POL_MASK                        (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POL_SHIFT                       (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POL_MAX                         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POSITION_MASK                   (0x00000007U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POSITION_SHIFT                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_CFG_CLOCK_POSITION_MAX                    (0x00000007U)

/* CSI2_COMPLEXIO_IRQSTATUS */

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ECC_NO_CORRECTION_MASK  (0x40000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ECC_NO_CORRECTION_SHIFT (0x0000001EU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ECC_NO_CORRECTION_MAX   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_SHORT_PACKET_MASK       (0x10000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_SHORT_PACKET_SHIFT      (0x0000001CU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_SHORT_PACKET_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_FIFO_OVR_MASK           (0x08000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_FIFO_OVR_SHIFT          (0x0000001BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_FIFO_OVR_MAX            (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMEXIT_MASK   (0x04000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMEXIT_SHIFT  (0x0000001AU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMEXIT_MAX    (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMENTER_MASK  (0x02000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMENTER_SHIFT (0x00000019U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEALLULPMENTER_MAX   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM5_MASK         (0x01000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM5_SHIFT        (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM5_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM4_MASK         (0x00800000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM4_SHIFT        (0x00000017U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM4_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM3_MASK         (0x00400000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM3_SHIFT        (0x00000016U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM3_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM2_MASK         (0x00200000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM2_SHIFT        (0x00000015U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM2_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM1_MASK         (0x00100000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM1_SHIFT        (0x00000014U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_STATEULPM1_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL5_MASK        (0x00080000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL5_SHIFT       (0x00000013U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL5_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL4_MASK        (0x00040000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL4_SHIFT       (0x00000012U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL4_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL3_MASK        (0x00020000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL3_SHIFT       (0x00000011U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL3_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL2_MASK        (0x00010000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL2_SHIFT       (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL2_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL1_MASK        (0x00008000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL1_SHIFT       (0x0000000FU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRCONTROL1_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC5_MASK            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC5_SHIFT           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC5_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC4_MASK            (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC4_SHIFT           (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC4_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC3_MASK            (0x00001000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC3_SHIFT           (0x0000000CU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC3_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC2_MASK            (0x00000800U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC2_SHIFT           (0x0000000BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC2_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC1_MASK            (0x00000400U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC1_SHIFT           (0x0000000AU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRESC1_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS5_MASK      (0x00000200U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS5_SHIFT     (0x00000009U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS5_MAX       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS4_MASK      (0x00000100U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS4_SHIFT     (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS4_MAX       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS3_MASK      (0x00000080U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS3_SHIFT     (0x00000007U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS3_MAX       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS2_MASK      (0x00000040U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS2_SHIFT     (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS2_MAX       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS1_MASK      (0x00000020U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS1_SHIFT     (0x00000005U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTSYNCHS1_MAX       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS5_MASK          (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS5_SHIFT         (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS5_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS4_MASK          (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS4_SHIFT         (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS4_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS3_MASK          (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS3_SHIFT         (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS3_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS2_MASK          (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS2_SHIFT         (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS2_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS1_MASK          (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS1_SHIFT         (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQSTATUS_IRQ_STS_ERRSOTHS1_MAX           (0x00000001U)

/* CSI2_SHORT_PACKET */

#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_RESERVED_0_MASK                   (0xFF000000U)
#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_RESERVED_0_SHIFT                  (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_RESERVED_0_MAX                    (0x000000FFU)

#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_SHORT_PACKET_MASK                 (0x00FFFFFFU)
#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_SHORT_PACKET_SHIFT                (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_SHORT_PACKET_INFO_SHORT_PACKET_MAX                  (0x00FFFFFFU)

/* CSI2_COMPLEXIO_IRQENABLE */

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ECC_NO_CORRECTION_MASK   (0x40000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ECC_NO_CORRECTION_SHIFT  (0x0000001EU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ECC_NO_CORRECTION_MAX    (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_SHORT_PACKET_MASK        (0x10000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_SHORT_PACKET_SHIFT       (0x0000001CU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_SHORT_PACKET_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_FIFO_OVR_MASK            (0x08000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_FIFO_OVR_SHIFT           (0x0000001BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_FIFO_OVR_MAX             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMEXIT_MASK    (0x04000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMEXIT_SHIFT   (0x0000001AU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMEXIT_MAX     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMENTER_MASK   (0x02000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMENTER_SHIFT  (0x00000019U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEALLULPMENTER_MAX    (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM5_MASK          (0x01000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM5_SHIFT         (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM5_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM4_MASK          (0x00800000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM4_SHIFT         (0x00000017U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM4_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM3_MASK          (0x00400000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM3_SHIFT         (0x00000016U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM3_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM2_MASK          (0x00200000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM2_SHIFT         (0x00000015U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM2_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM1_MASK          (0x00100000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM1_SHIFT         (0x00000014U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_STATEULPM1_MAX           (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL5_MASK         (0x00080000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL5_SHIFT        (0x00000013U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL5_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL4_MASK         (0x00040000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL4_SHIFT        (0x00000012U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL4_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL3_MASK         (0x00020000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL3_SHIFT        (0x00000011U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL3_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL2_MASK         (0x00010000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL2_SHIFT        (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL2_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL1_MASK         (0x00008000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL1_SHIFT        (0x0000000FU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRCONTROL1_MAX          (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC5_MASK             (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC5_SHIFT            (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC5_MAX              (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC4_MASK             (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC4_SHIFT            (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC4_MAX              (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC3_MASK             (0x00001000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC3_SHIFT            (0x0000000CU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC3_MAX              (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC2_MASK             (0x00000800U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC2_SHIFT            (0x0000000BU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC2_MAX              (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC1_MASK             (0x00000400U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC1_SHIFT            (0x0000000AU)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRESC1_MAX              (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS5_MASK       (0x00000200U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS5_SHIFT      (0x00000009U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS5_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS4_MASK       (0x00000100U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS4_SHIFT      (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS4_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS3_MASK       (0x00000080U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS3_SHIFT      (0x00000007U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS3_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS2_MASK       (0x00000040U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS2_SHIFT      (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS2_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS1_MASK       (0x00000020U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS1_SHIFT      (0x00000005U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTSYNCHS1_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS5_MASK           (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS5_SHIFT          (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS5_MAX            (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS4_MASK           (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS4_SHIFT          (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS4_MAX            (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS3_MASK           (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS3_SHIFT          (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS3_MAX            (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS2_MASK           (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS2_SHIFT          (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS2_MAX            (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS1_MASK           (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS1_SHIFT          (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_COMPLEXIO_IRQENABLE_IRQ_EN_ERRSOTHS1_MAX            (0x00000001U)

/* CSI2_TIMING */

#define CSL_CAL_C2PPI_CSI2_TIMING_FORCE_RX_MODE_IO1_MASK                       (0x00008000U)
#define CSL_CAL_C2PPI_CSI2_TIMING_FORCE_RX_MODE_IO1_SHIFT                      (0x0000000FU)
#define CSL_CAL_C2PPI_CSI2_TIMING_FORCE_RX_MODE_IO1_MAX                        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X16_IO1_MASK                      (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X16_IO1_SHIFT                     (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X16_IO1_MAX                       (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X4_IO1_MASK                       (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X4_IO1_SHIFT                      (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_X4_IO1_MAX                        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_COUNTER_IO1_MASK                  (0x00001FFFU)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_COUNTER_IO1_SHIFT                 (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_TIMING_STOP_STATE_COUNTER_IO1_MAX                   (0x00001FFFU)

/* CSI2_VC_IRQENABLE */

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_3_MASK       (0x20000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_3_SHIFT      (0x0000001DU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_3_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_3_MASK                    (0x10000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_3_SHIFT                   (0x0000001CU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_3_MASK                    (0x08000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_3_SHIFT                   (0x0000001BU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_3_MASK                    (0x04000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_3_SHIFT                   (0x0000001AU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_3_MASK                    (0x02000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_3_SHIFT                   (0x00000019U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_3_MASK                    (0x01000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_3_SHIFT                   (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_2_MASK       (0x00200000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_2_SHIFT      (0x00000015U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_2_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_2_MASK                    (0x00100000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_2_SHIFT                   (0x00000014U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_2_MASK                    (0x00080000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_2_SHIFT                   (0x00000013U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_2_MASK                    (0x00040000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_2_SHIFT                   (0x00000012U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_2_MASK                    (0x00020000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_2_SHIFT                   (0x00000011U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_2_MASK                    (0x00010000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_2_SHIFT                   (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_1_MASK       (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_1_SHIFT      (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_1_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_1_MASK                    (0x00001000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_1_SHIFT                   (0x0000000CU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_1_MASK                    (0x00000800U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_1_SHIFT                   (0x0000000BU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_1_MASK                    (0x00000400U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_1_SHIFT                   (0x0000000AU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_1_MASK                    (0x00000200U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_1_SHIFT                   (0x00000009U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_1_MASK                    (0x00000100U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_1_SHIFT                   (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_0_MASK       (0x00000020U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_0_SHIFT      (0x00000005U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_ECC_CORRECTION0_IRQ_0_MAX        (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_0_MASK                    (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_0_SHIFT                   (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_CS_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_0_MASK                    (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_0_SHIFT                   (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LE_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_0_MASK                    (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_0_SHIFT                   (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_LS_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_0_MASK                    (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_0_SHIFT                   (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FE_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_0_MASK                    (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_0_SHIFT                   (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQENABLE_VC_IE_FS_IRQ_0_MAX                     (0x00000001U)

/* CSI2_VC_IRQSTATUS */

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_3_MASK        (0x20000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_3_SHIFT       (0x0000001DU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_3_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_3_MASK                    (0x10000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_3_SHIFT                   (0x0000001CU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_3_MASK                    (0x08000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_3_SHIFT                   (0x0000001BU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_3_MASK                    (0x04000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_3_SHIFT                   (0x0000001AU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_3_MASK                    (0x02000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_3_SHIFT                   (0x00000019U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_3_MASK                    (0x01000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_3_SHIFT                   (0x00000018U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_3_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_2_MASK        (0x00200000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_2_SHIFT       (0x00000015U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_2_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_2_MASK                    (0x00100000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_2_SHIFT                   (0x00000014U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_2_MASK                    (0x00080000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_2_SHIFT                   (0x00000013U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_2_MASK                    (0x00040000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_2_SHIFT                   (0x00000012U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_2_MASK                    (0x00020000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_2_SHIFT                   (0x00000011U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_2_MASK                    (0x00010000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_2_SHIFT                   (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_2_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_1_MASK        (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_1_SHIFT       (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_1_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_1_MASK                    (0x00001000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_1_SHIFT                   (0x0000000CU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_1_MASK                    (0x00000800U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_1_SHIFT                   (0x0000000BU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_1_MASK                    (0x00000400U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_1_SHIFT                   (0x0000000AU)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_1_MASK                    (0x00000200U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_1_SHIFT                   (0x00000009U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_1_MASK                    (0x00000100U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_1_SHIFT                   (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_1_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_0_MASK        (0x00000020U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_0_SHIFT       (0x00000005U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_ECC_CORRECTION_IRQ_0_MAX         (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_0_MASK                    (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_0_SHIFT                   (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_CS_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_0_MASK                    (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_0_SHIFT                   (0x00000003U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LE_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_0_MASK                    (0x00000004U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_0_SHIFT                   (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_LS_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_0_MASK                    (0x00000002U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_0_SHIFT                   (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FE_IRQ_0_MAX                     (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_0_MASK                    (0x00000001U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_0_SHIFT                   (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_VC_IRQSTATUS_VC_IS_FS_IRQ_0_MAX                     (0x00000001U)

/* CSI2_CTX0 */

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX0_CTX0_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX1 */

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX1_CTX1_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX2 */

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX2_CTX2_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX3 */

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX3_CTX3_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX4 */

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX4_CTX4_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX5 */

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX5_CTX5_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX6 */

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX6_CTX6_DT_MAX                                    (0x0000003FU)

/* CSI2_CTX7 */

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_LINES_MASK                                (0x3FFF0000U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_LINES_SHIFT                               (0x00000010U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_LINES_MAX                                 (0x00003FFFU)

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_PACK_MODE_MASK                            (0x00004000U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_PACK_MODE_SHIFT                           (0x0000000EU)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_PACK_MODE_MAX                             (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_ATT_MASK                                  (0x00002000U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_ATT_SHIFT                                 (0x0000000DU)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_ATT_MAX                                   (0x00000001U)

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_CPORT_MASK                                (0x00001F00U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_CPORT_SHIFT                               (0x00000008U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_CPORT_MAX                                 (0x0000001FU)

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_VC_MASK                                   (0x000000C0U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_VC_SHIFT                                  (0x00000006U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_VC_MAX                                    (0x00000003U)

#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_DT_MASK                                   (0x0000003FU)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_DT_SHIFT                                  (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_CTX7_CTX7_DT_MAX                                    (0x0000003FU)

/* CSI2_STATUS0 */

#define CSL_CAL_C2PPI_CSI2_STATUS0_STS0_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS0_STS0_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS0_STS0_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS1 */

#define CSL_CAL_C2PPI_CSI2_STATUS1_STS1_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS1_STS1_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS1_STS1_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS2 */

#define CSL_CAL_C2PPI_CSI2_STATUS2_STS2_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS2_STS2_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS2_STS2_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS3 */

#define CSL_CAL_C2PPI_CSI2_STATUS3_STS3_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS3_STS3_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS3_STS3_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS4 */

#define CSL_CAL_C2PPI_CSI2_STATUS4_STS4_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS4_STS4_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS4_STS4_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS5 */

#define CSL_CAL_C2PPI_CSI2_STATUS5_STS5_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS5_STS5_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS5_STS5_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS6 */

#define CSL_CAL_C2PPI_CSI2_STATUS6_STS6_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS6_STS6_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS6_STS6_FRAME_MAX                              (0x0000FFFFU)

/* CSI2_STATUS7 */

#define CSL_CAL_C2PPI_CSI2_STATUS7_STS7_FRAME_MASK                             (0x0000FFFFU)
#define CSL_CAL_C2PPI_CSI2_STATUS7_STS7_FRAME_SHIFT                            (0x00000000U)
#define CSL_CAL_C2PPI_CSI2_STATUS7_STS7_FRAME_MAX                              (0x0000FFFFU)

/* SCP_PHY_A */

#define CSL_CAL_SCP_SCP_PHY_A_SCP_PHY_A_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_A_SCP_PHY_A_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_A_SCP_PHY_A_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_B */

#define CSL_CAL_SCP_SCP_PHY_B_SCP_PHY_B_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_B_SCP_PHY_B_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_B_SCP_PHY_B_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_C */

#define CSL_CAL_SCP_SCP_PHY_C_SCP_PHY_C_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_C_SCP_PHY_C_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_C_SCP_PHY_C_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_D */

#define CSL_CAL_SCP_SCP_PHY_D_SCP_PHY_D_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_D_SCP_PHY_D_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_D_SCP_PHY_D_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_E */

#define CSL_CAL_SCP_SCP_PHY_E_SCP_PHY_E_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_E_SCP_PHY_E_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_E_SCP_PHY_E_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_F */

#define CSL_CAL_SCP_SCP_PHY_F_SCP_PHY_F_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_F_SCP_PHY_F_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_F_SCP_PHY_F_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_G */

#define CSL_CAL_SCP_SCP_PHY_G_SCP_PHY_G_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_G_SCP_PHY_G_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_G_SCP_PHY_G_MAX                                    (0xFFFFFFFFU)

/* SCP_PHY_H */

#define CSL_CAL_SCP_SCP_PHY_H_SCP_PHY_H_MASK                                   (0xFFFFFFFFU)
#define CSL_CAL_SCP_SCP_PHY_H_SCP_PHY_H_SHIFT                                  (0x00000000U)
#define CSL_CAL_SCP_SCP_PHY_H_SCP_PHY_H_MAX                                    (0xFFFFFFFFU)

#define CAL_CSI2_PHY_REG0_HSCLOCKCONFIG_SHIFT                                  (24U)
#define CAL_CSI2_PHY_REG0_HSCLOCKCONFIG_MASK                                   (0x01000000U)

#define CAL_CSI2_PHY_REG0_THS_TERM_SHIFT                                       (8U)
#define CAL_CSI2_PHY_REG0_THS_TERM_MASK                                        (0x0000FF00U)

#define CAL_CSI2_PHY_REG0_THS_SETTLE_SHIFT                                     (0U)
#define CAL_CSI2_PHY_REG0_THS_SETTLE_MASK                                      (0x000000FFU)

#define CAL_CSI2_PHY_REG1_TCLK_TERM_MASK                                       (0x01FC0000U)
#define CAL_CSI2_PHY_REG1_TCLK_TERM_SHIFT                                      (0x18U)
#define CAL_CSI2_PHY_REG1_TCLK_SETTLE_MASK                                     (0x000000FFU)
#define CAL_CSI2_PHY_REG1_TCLK_SETTLE_SHIFT                                    (0x0U)

#define CAL_CSI2_PHY_REG10_LDO_DISABLE_MASK                                    (0x00000040U)

#ifdef __cplusplus
}
#endif
#endif
