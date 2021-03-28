/******************************************************************************
*
* Register header file for DWC_USB
*
******************************************************************************
*/
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2019
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
*/



#ifndef PDK__HW_DWC_USB_H
#define PDK__HW_DWC_USB_H

#ifdef __cplusplus
extern "C"
{
#endif


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile uint32_t DWC_CAPLENGTH;    /* Offset: 0x0 */
    volatile uint32_t DWC_HCSPARAMS1;   /* Offset: 0x4 */
    volatile uint32_t DWC_HCSPARAMS2;   /* Offset: 0x8 */
    volatile uint32_t DWC_HCSPARAMS3;   /* Offset: 0xc */
    volatile uint32_t DWC_HCCPARAMS;    /* Offset: 0x10 */
    volatile uint32_t DWC_DBOFF;    /* Offset: 0x14 */
    volatile uint32_t DWC_RTSOFF;   /* Offset: 0x18 */
    volatile uint8_t  RSVD0[4];
    volatile uint32_t DWC_USBCMD;   /* Offset: 0x20 */
    volatile uint32_t DWC_USBSTS;   /* Offset: 0x24 */
    volatile uint32_t DWC_PAGESIZE; /* Offset: 0x28 */
    volatile uint8_t  RSVD1[8];
    volatile uint32_t DWC_DNCTRL;   /* Offset: 0x34 */
    volatile uint32_t DWC_CRCR_LO;  /* Offset: 0x38 */
    volatile uint32_t DWC_CRCR_HI;  /* Offset: 0x3c */
    volatile uint8_t  RSVD2[16];
    volatile uint32_t DWC_DCBAAP_LO;    /* Offset: 0x50 */
    volatile uint32_t DWC_DCBAAP_HI;    /* Offset: 0x54 */
    volatile uint32_t DWC_CONFIG;   /* Offset: 0x58 */
    volatile uint8_t  RSVD3[964];
    volatile uint32_t DWC_PORTSC1;  /* Offset: 0x420 */
    volatile uint32_t DWC_PORTPMSC1;    /* Offset: 0x424 */
    volatile uint32_t DWC_PORTLI1;  /* Offset: 0x428 */
    volatile uint32_t DWC_PORTHLPMC1;   /* Offset: 0x42c */
    volatile uint32_t DWC_PORTSC2;  /* Offset: 0x430 */
    volatile uint32_t DWC_PORTPMSC2;    /* Offset: 0x434 */
    volatile uint32_t DWC_PORTLI2;  /* Offset: 0x438 */
    volatile uint32_t DWC_PORTHLPMC2;   /* Offset: 0x43c */
    volatile uint32_t DWC_MFIDX;    /* Offset: 0x440 */
    volatile uint8_t  RSVD4[28];
    volatile uint32_t DWC_IMAN[4];  /* Offset: 0x460 */
    volatile uint32_t DWC_IMOD[4];  /* Offset: 0x464 */
    volatile uint32_t DWC_ERSTSZ[4];    /* Offset: 0x468 */
    volatile uint32_t DWC_ERSTBA_LO[4]; /* Offset: 0x470 */
    volatile uint32_t DWC_ERSTBA_HI[4]; /* Offset: 0x474 */
    volatile uint32_t DWC_ERDP_LO[4];   /* Offset: 0x478 */
    volatile uint32_t DWC_ERDP_HI[4];   /* Offset: 0x47c */
    volatile uint8_t  RSVD5[84];
    volatile uint32_t DWC_DB[64];   /* Offset: 0x4e0 */
    volatile uint8_t  RSVD6[768];
    volatile uint32_t DWC_USBLEGSUP;    /* Offset: 0x8e0 */
    volatile uint32_t DWC_USBLEGCTLSTS; /* Offset: 0x8e4 */
    volatile uint8_t  RSVD7[8];
    volatile uint32_t DWC_SUPTPRT2_DW0; /* Offset: 0x8f0 */
    volatile uint32_t DWC_SUPTPRT2_DW1; /* Offset: 0x8f4 */
    volatile uint32_t DWC_SUPTPRT2_DW2; /* Offset: 0x8f8 */
    volatile uint32_t DWC_SUPTPRT2_DW3; /* Offset: 0x8fc */
    volatile uint32_t DWC_SUPTPRT3_DW0; /* Offset: 0x900 */
    volatile uint32_t DWC_SUPTPRT3_DW1; /* Offset: 0x904 */
    volatile uint32_t DWC_SUPTPRT3_DW2; /* Offset: 0x908 */
    volatile uint32_t DWC_SUPTPRT3_DW3; /* Offset: 0x90c */
    volatile uint32_t DWC_DCID; /* Offset: 0x910 */
    volatile uint32_t DWC_DCDB; /* Offset: 0x914 */
    volatile uint32_t DWC_DCERSTSZ; /* Offset: 0x918 */
    volatile uint8_t  RSVD8[4];
    volatile uint32_t DWC_DCERSTBA_LO;  /* Offset: 0x920 */
    volatile uint32_t DWC_DCERSTBA_HI;  /* Offset: 0x924 */
    volatile uint32_t DWC_DCERDP_LO;    /* Offset: 0x928 */
    volatile uint32_t DWC_DCERDP_HI;    /* Offset: 0x92c */
    volatile uint32_t DWC_DCCTRL;   /* Offset: 0x930 */
    volatile uint32_t DWC_DCST; /* Offset: 0x934 */
    volatile uint32_t DWC_DCPORTSC; /* Offset: 0x938 */
    volatile uint8_t  RSVD9[4];
    volatile uint32_t DWC_DCCP_LO;  /* Offset: 0x940 */
    volatile uint32_t DWC_DCCP_HI;  /* Offset: 0x944 */
    volatile uint32_t DWC_DCDDI1;   /* Offset: 0x948 */
    volatile uint32_t DWC_DCDDI2;   /* Offset: 0x94c */
    volatile uint8_t  RSVD10[47024];
    volatile uint32_t DWC_GSBUSCFG0;    /* Offset: 0xc100 */
    volatile uint32_t DWC_GSBUSCFG1;    /* Offset: 0xc104 */
    volatile uint32_t DWC_GTXTHRCFG;    /* Offset: 0xc108 */
    volatile uint32_t DWC_GRXTHRCFG;    /* Offset: 0xc10c */
    volatile uint32_t DWC_GCTL; /* Offset: 0xc110 */
    volatile uint8_t  RSVD11[4];
    volatile uint32_t DWC_GSTS; /* Offset: 0xc118 */
    volatile uint8_t  RSVD12[4];
    volatile uint32_t DWC_GSNPSID;  /* Offset: 0xc120 */
    volatile uint32_t DWC_GGPIO;    /* Offset: 0xc124 */
    volatile uint32_t DWC_GUID; /* Offset: 0xc128 */
    volatile uint32_t DWC_GUCTL;    /* Offset: 0xc12c */
    volatile uint32_t DWC_GBUSERRADDRLO;    /* Offset: 0xc130 */
    volatile uint32_t DWC_GBUSERRADDRHI;    /* Offset: 0xc134 */
    volatile uint32_t DWC_GPRTBIMAPLO;  /* Offset: 0xc138 */
    volatile uint32_t DWC_GPRTBIMAPHI;  /* Offset: 0xc13c */
    volatile uint32_t DWC_GHWPARAMS0;   /* Offset: 0xc140 */
    volatile uint32_t DWC_GHWPARAMS1;   /* Offset: 0xc144 */
    volatile uint32_t DWC_GHWPARAMS2;   /* Offset: 0xc148 */
    volatile uint32_t DWC_GHWPARAMS3;   /* Offset: 0xc14c */
    volatile uint32_t DWC_GHWPARAMS4;   /* Offset: 0xc150 */
    volatile uint32_t DWC_GHWPARAMS5;   /* Offset: 0xc154 */
    volatile uint32_t DWC_GHWPARAMS6;   /* Offset: 0xc158 */
    volatile uint32_t DWC_GHWPARAMS7;   /* Offset: 0xc15c */
    volatile uint32_t DWC_GDBGFIFOSPACE;    /* Offset: 0xc160 */
    volatile uint32_t DWC_GDBGLTSSM;    /* Offset: 0xc164 */
    volatile uint32_t DWC_GDBGLNMCC;    /* Offset: 0xc168 */
    volatile uint32_t DWC_GDBGBMU;  /* Offset: 0xc16c */
    volatile uint32_t DWC_GDBGLSPMUX;   /* Offset: 0xc170 */
    volatile uint32_t DWC_GDBGLSP;  /* Offset: 0xc174 */
    volatile uint32_t DWC_GDBGEPINFO0;  /* Offset: 0xc178 */
    volatile uint32_t DWC_GDBGEPINFO1;  /* Offset: 0xc17c */
    volatile uint32_t DWC_GPRTBIMAP_HSLO;   /* Offset: 0xc180 */
    volatile uint32_t DWC_GPRTBIMAP_HSHI;   /* Offset: 0xc184 */
    volatile uint32_t DWC_GPRTBIMAP_FSLO;   /* Offset: 0xc188 */
    volatile uint32_t DWC_GPRTBIMAP_FSHI;   /* Offset: 0xc18c */
    volatile uint8_t  RSVD13[112];
    volatile uint32_t DWC_GUSB2PHYCFG;  /* Offset: 0xc200 */
    volatile uint8_t  RSVD14[124];
    volatile uint32_t DWC_GUSB2PHYACC;  /* Offset: 0xc280 */
    volatile uint8_t  RSVD15[60];
    volatile uint32_t DWC_GUSB3PIPECTL; /* Offset: 0xc2c0 */
    volatile uint8_t  RSVD16[60];
    volatile uint32_t DWC_GTXFIFOSIZ0;  /* Offset: 0xc300 */
    volatile uint32_t DWC_GTXFIFOSIZ1;  /* Offset: 0xc304 */
    volatile uint32_t DWC_GTXFIFOSIZ2;  /* Offset: 0xc308 */
    volatile uint32_t DWC_GTXFIFOSIZ3;  /* Offset: 0xc30c */
    volatile uint32_t DWC_GTXFIFOSIZ4;  /* Offset: 0xc310 */
    volatile uint32_t DWC_GTXFIFOSIZ5;  /* Offset: 0xc314 */
    volatile uint32_t DWC_GTXFIFOSIZ6;  /* Offset: 0xc318 */
    volatile uint32_t DWC_GTXFIFOSIZ7;  /* Offset: 0xc31c */
    volatile uint32_t DWC_GTXFIFOSIZ8;  /* Offset: 0xc320 */
    volatile uint32_t DWC_GTXFIFOSIZ9;  /* Offset: 0xc324 */
    volatile uint32_t DWC_GTXFIFOSIZ10; /* Offset: 0xc328 */
    volatile uint32_t DWC_GTXFIFOSIZ11; /* Offset: 0xc32c */
    volatile uint32_t DWC_GTXFIFOSIZ12; /* Offset: 0xc330 */
    volatile uint32_t DWC_GTXFIFOSIZ13; /* Offset: 0xc334 */
    volatile uint32_t DWC_GTXFIFOSIZ14; /* Offset: 0xc338 */
    volatile uint32_t DWC_GTXFIFOSIZ15; /* Offset: 0xc33c */
    volatile uint8_t  RSVD17[64];
    volatile uint32_t DWC_GRXFIFOSIZ0;  /* Offset: 0xc380 */
    volatile uint32_t DWC_GRXFIFOSIZ1;  /* Offset: 0xc384 */
    volatile uint32_t DWC_GRXFIFOSIZ2;  /* Offset: 0xc388 */
    volatile uint8_t  RSVD18[116];
    volatile uint32_t DWC_GEVNTADRLO[4];    /* Offset: 0xc400 */
    volatile uint32_t DWC_GEVNTADRHI[4];    /* Offset: 0xc404 */
    volatile uint32_t DWC_GEVNTSIZ[4];  /* Offset: 0xc408 */
    volatile uint32_t DWC_GEVNTCOUNT[4];    /* Offset: 0xc40c */
    volatile uint8_t  RSVD19[484];
    volatile uint32_t DWC_GHWPARAMS8;   /* Offset: 0xc600 */
    volatile uint32_t DWC_GHWPARAMS9;   /* Offset: 0xc604 */
    volatile uint8_t  RSVD20[8];
    volatile uint32_t DWC_GTXFIFOPRIDEV;    /* Offset: 0xc610 */
    volatile uint8_t  RSVD21[4];
    volatile uint32_t DWC_GTXFIFOPRIHST;    /* Offset: 0xc618 */
    volatile uint32_t DWC_GRXFIFOPRIHST;    /* Offset: 0xc61c */
    volatile uint32_t DWC_GFIFOPRIDBC;  /* Offset: 0xc620 */
    volatile uint32_t DWC_GDMAHLRATIO;  /* Offset: 0xc624 */
    volatile uint8_t  RSVD22[216];
    volatile uint32_t DWC_DCFG; /* Offset: 0xc700 */
    volatile uint32_t DWC_DCTL; /* Offset: 0xc704 */
    volatile uint32_t DWC_DEVTEN;   /* Offset: 0xc708 */
    volatile uint32_t DWC_DSTS; /* Offset: 0xc70c */
    volatile uint32_t DWC_DGCMDPAR; /* Offset: 0xc710 */
    volatile uint32_t DWC_DGCMD;    /* Offset: 0xc714 */
    volatile uint8_t  RSVD23[8];
    volatile uint32_t DWC_DALEPENA; /* Offset: 0xc720 */
    volatile uint8_t  RSVD24[220];
    volatile uint32_t DEPCMDPAR2[32];   /* Offset: 0xc800 */
    volatile uint32_t DEPCMDPAR1[32];   /* Offset: 0xc804 */
    volatile uint32_t DEPCMDPAR0[32];   /* Offset: 0xc808 */
    volatile uint32_t DEPCMD[32];   /* Offset: 0xc80c */
    volatile uint8_t  RSVD25[884];
    volatile uint32_t DWC_OCFG; /* Offset: 0xcc00 */
    volatile uint32_t DWC_OCTL; /* Offset: 0xcc04 */
    volatile uint32_t DWC_OEVT; /* Offset: 0xcc08 */
    volatile uint32_t DWC_OEVTEN;   /* Offset: 0xcc0c */
    volatile uint32_t DWC_OSTS; /* Offset: 0xcc10 */
    volatile uint8_t  RSVD26[12];
    volatile uint32_t DWC_ADPCFG;   /* Offset: 0xcc20 */
    volatile uint32_t DWC_ADPCTL;   /* Offset: 0xcc24 */
    volatile uint32_t DWC_ADPEVT;   /* Offset: 0xcc28 */
    volatile uint32_t DWC_ADPEVTEN; /* Offset: 0xcc2c */
    volatile uint32_t DWC_BCFG; /* Offset: 0xcc30 */
    volatile uint8_t  RSVD27[4];
    volatile uint32_t DWC_BCEVT;    /* Offset: 0xcc38 */
    volatile uint32_t DWC_BCEVTEN;  /* Offset: 0xcc3c */
} DWCUSBRegs;


/**************************************************************************
* Register Definitions
**************************************************************************/
#define DWC_USB_CAPLENGTH                                       (0x0u)
#define DWC_USB_HCSPARAMS1                                      (0x4u)
#define DWC_USB_HCSPARAMS2                                      (0x8u)
#define DWC_USB_HCSPARAMS3                                      (0xCu)
#define DWC_USB_HCCPARAMS                                       (0x10u)
#define DWC_USB_DBOFF                                           (0x14u)
#define DWC_USB_RTSOFF                                          (0x18u)
#define DWC_USB_USBCMD                                          (0x20u)
#define DWC_USB_USBSTS                                          (0x24u)
#define DWC_USB_PAGESIZE                                        (0x28u)
#define DWC_USB_DNCTRL                                          (0x34u)
#define DWC_USB_CRCR_LO                                         (0x38u)
#define DWC_USB_CRCR_HI                                         (0x3Cu)
#define DWC_USB_DCBAAP_LO                                       (0x50u)
#define DWC_USB_DCBAAP_HI                                       (0x54u)
#define DWC_USB_CONFIG                                          (0x58u)
#define DWC_USB_PORTSC2                                         (0x430u)
#define DWC_USB_PORTPMSC2                                       (0x434u)
#define DWC_USB_PORTLI2                                         (0x438u)
#define DWC_USB_PORTHLPMC2                                      (0x43Cu)
#define DWC_USB_PORTSC1                                         (0x420u)
#define DWC_USB_PORTPMSC1                                       (0x424u)
#define DWC_USB_PORTLI1                                         (0x428u)
#define DWC_USB_PORTHLPMC1                                      (0x42Cu)
#define DWC_USB_MFINDEX                                         (0x440u)
#define DWC_USB_IMAN(n)                                         (0x460U + ((n-1) * 0x20U))
#define DWC_USB_IMOD(n)                                         (0x464U + ((n-1) * 0x20U))
#define DWC_USB_ERSTSZ(n)                                       (0x468U + ((n-1) * 0x20U))
#define DWC_USB_ERSTBA_LO(n)                                    (0x470U + ((n-1) * 0x20U))
#define DWC_USB_ERSTBA_HI(n)                                    (0x474U + ((n-1) * 0x20U))
#define DWC_USB_ERDP_LO(n)                                      (0x478U + ((n-1) * 0x20U))
#define DWC_USB_ERDP_HI(n)                                      (0x47cU + ((n-1) * 0x20U))

#if defined(AM43XX_FAMILY_BUILD)
#define DWC_USB_DB(n)                                           (0x4e0U + ((n-1) * 0x4U))
#elif defined(AM57XX_FAMILY_BUILD) | defined(SOC_AM572x) | \
      defined(SOC_AM571x) | defined (SOC_AM574x) | \
      defined (SOC_DRA72x) | defined (SOC_DRA75x)
#define DWC_USB_DB(n)                                           (0x480U + ((n-1) * 0x4U))
#elif defined(SOC_K2G) || defined (SOC_AM65XX)
#define DWC_USB_DB(n)                                           (0x660U + ((n-1) * 0x4U))
#else
#warning "\nunknown DOORBELL register offset\n"
#endif

#define DWC_USB_USBLEGSUP                                       (0x8E0u)
#define DWC_USB_USBLEGCTLSTS                                    (0x8E4u)
#define DWC_USB_SUPTPRT2_DW0                                    (0x8F0u)
#define DWC_USB_SUPTPRT2_DW1                                    (0x8F4u)
#define DWC_USB_SUPTPRT2_DW2                                    (0x8F8u)
#define DWC_USB_SUPTPRT2_DW3                                    (0x8FCu)
#define DWC_USB_SUPTPRT3_DW0                                    (0x900u)
#define DWC_USB_SUPTPRT3_DW1                                    (0x904u)
#define DWC_USB_SUPTPRT3_DW2                                    (0x908u)
#define DWC_USB_SUPTPRT3_DW3                                    (0x90Cu)
#define DWC_USB_DCID                                            (0x910u)
#define DWC_USB_DCDB                                            (0x914u)
#define DWC_USB_DCERSTSZ                                        (0x918u)
#define DWC_USB_DCERSTBA_LO                                     (0x920u)
#define DWC_USB_DCERSTBA_HI                                     (0x924u)
#define DWC_USB_DCERDP_LO                                       (0x928u)
#define DWC_USB_DCERDP_HI                                       (0x92Cu)
#define DWC_USB_DCCTRL                                          (0x930u)
#define DWC_USB_DCST                                            (0x934u)
#define DWC_USB_DCPORTSC                                        (0x938u)
#define DWC_USB_DCCP_LO                                         (0x940u)
#define DWC_USB_DCCP_HI                                         (0x944u)
#define DWC_USB_DCDDI1                                          (0x948u)
#define DWC_USB_DCDDI2                                          (0x94Cu)
#define DWC_USB_GSBUSCFG0                                       (0xC100u)
#define DWC_USB_GSBUSCFG1                                       (0xC104u)
#define DWC_USB_GTXTHRCFG                                       (0xC108u)
#define DWC_USB_GRXTHRCFG                                       (0xC10Cu)
#define DWC_USB_GCTL                                            (0xC110u)
#define DWC_USB_GSTS                                            (0xC118u)
#define DWC_USB_GSNPSID                                         (0xC120u)
#define DWC_USB_GGPIO                                           (0xC124u)
#define DWC_USB_GUID                                            (0xC128u)
#define DWC_USB_GBUSERRADDRLO                                   (0xC130u)
#define DWC_USB_GBUSERRADDRHI                                   (0xC134u)
#define DWC_USB_GPRTBIMAPLO                                     (0xC138u)
#define DWC_USB_GPRTBIMAPHI                                     (0xC13Cu)
#define DWC_USB_GHWPARAMS0                                      (0xC140u)
#define DWC_USB_GHWPARAMS1                                      (0xC144u)
#define DWC_USB_GHWPARAMS2                                      (0xC148u)
#define DWC_USB_GHWPARAMS3                                      (0xC14Cu)
#define DWC_USB_GHWPARAMS4                                      (0xC150u)
#define DWC_USB_GHWPARAMS5                                      (0xC154u)
#define DWC_USB_GHWPARAMS6                                      (0xC158u)
#define DWC_USB_GHWPARAMS7                                      (0xC15Cu)
#define DWC_USB_GDBGFIFOSPACE                                   (0xC160u)
#define DWC_USB_GDBGLTSSM                                       (0xC164u)
#define DWC_USB_GUCTL                                           (0xC12Cu)
#define DWC_USB_GPRTBIMAP_HSLO                                  (0xC180u)
#define DWC_USB_GPRTBIMAP_HSHI                                  (0xC184u)
#define DWC_USB_GPRTBIMAP_FSLO                                  (0xC188u)
#define DWC_USB_GPRTBIMAP_FSHI                                  (0xC18Cu)
#define DWC_USB_GDBGLSPMUX                                      (0xC170u)
#define DWC_USB_GDBGLSP                                         (0xC174u)
#define DWC_USB_GDBGEPINFO0                                     (0xC178u)
#define DWC_USB_GDBGEPINFO1                                     (0xC17Cu)
#define DWC_USB_GDBGLNMCC                                       (0xC168u)
#define DWC_USB_GDBGBMU                                         (0xC16Cu)
#define DWC_USB_GUSB2PHYCFG                                     (0xC200u)
#define DWC_USB_GUSB2PHYACC                                     (0xC280u)
#define DWC_USB_GUSB3PIPECTL                                    (0xC2C0u)
#define DWC_USB_GTXFIFOSIZ0                                     (0xC300u)
#define DWC_USB_GTXFIFOSIZ1                                     (0xC304u)
#define DWC_USB_GTXFIFOSIZ2                                     (0xC308u)
#define DWC_USB_GTXFIFOSIZ3                                     (0xC30Cu)
#define DWC_USB_GTXFIFOSIZ4                                     (0xC310u)
#define DWC_USB_GTXFIFOSIZ5                                     (0xC314u)
#define DWC_USB_GTXFIFOSIZ6                                     (0xC318u)
#define DWC_USB_GTXFIFOSIZ7                                     (0xC31Cu)
#define DWC_USB_GTXFIFOSIZ8                                     (0xC320u)
#define DWC_USB_GTXFIFOSIZ9                                     (0xC324u)
#define DWC_USB_GTXFIFOSIZ10                                    (0xC328u)
#define DWC_USB_GTXFIFOSIZ11                                    (0xC32Cu)
#define DWC_USB_GTXFIFOSIZ12                                    (0xC330u)
#define DWC_USB_GTXFIFOSIZ13                                    (0xC334u)
#define DWC_USB_GTXFIFOSIZ14                                    (0xC338u)
#define DWC_USB_GTXFIFOSIZ15                                    (0xC33Cu)
#define DWC_USB_GRXFIFOSIZ0                                     (0xC380u)
#define DWC_USB_GRXFIFOSIZ1                                     (0xC384u)
#define DWC_USB_GRXFIFOSIZ2                                     (0xC388u)
#define DWC_USB_GEVNTADRLO(n)                                   (0xc400U + ((n-1) * 0x10U))
#define DWC_USB_GEVNTADRHI(n)                                   (0xc404U + ((n-1) * 0x10U))
#define DWC_USB_GEVNTSIZ(n)                                     (0xc408U + ((n-1) * 0x10U))
#define DWC_USB_GEVNTCOUNT(n)                                   (0xc40cU + ((n-1) * 0x10U))
#define DWC_USB_GHWPARAMS8                                      (0xC600u)
#define DWC_USB_GHWPARAMS9                                      (0xC604u)
#define DWC_USB_GTXFIFOPRIDEV                                   (0xC610u)
#define DWC_USB_GTXFIFOPRIHST                                   (0xC618u)
#define DWC_USB_GRXFIFOPRIHST                                   (0xC61Cu)
#define DWC_USB_GFIFOPRIDBC                                     (0xC620u)
#define DWC_USB_GDMAHLRATIO                                     (0xC624u)
#define DWC_USB_DCFG                                            (0xC700u)
#define DWC_USB_DCTL                                            (0xC704u)
#define DWC_USB_DEVTEN                                          (0xC708u)
#define DWC_USB_DSTS                                            (0xC70Cu)
#define DWC_USB_DGCMDPAR                                        (0xC710u)
#define DWC_USB_DGCMD                                           (0xC714u)
#define DWC_USB_DALEPENA                                        (0xC720u)
#define DWC_USB_OEVT                                            (0xCC08u)
#define DWC_USB_OEVTEN                                          (0xCC0Cu)
#define DWC_USB_OSTS                                            (0xCC10u)
#define DWC_USB_OCFG                                            (0xCC00u)
#define DWC_USB_OCTL                                            (0xCC04u)
#define DWC_USB_ADPCFG(n)                                       (0xcc20U + ((n-1) * 0x14U))
#define DWC_USB_ADPCTL(n)                                       (0xcc24U + ((n-1) * 0x14U))
#define DWC_USB_ADPEVT(n)                                       (0xcc28U + ((n-1) * 0x14U))
#define DWC_USB_ADPEVTEN(n)                                     (0xcc2cU + ((n-1) * 0x14U))
#define DWC_USB_BCFG(n)                                         (0xcc30U + ((n-1) * 0x10U))
#define DWC_USB_BCEVT(n)                                        (0xcc38U + ((n-1) * 0x10U))
#define DWC_USB_BCEVTEN(n)                                      (0xcc3cU + ((n-1) * 0x10U))
#define DWC_USB_DEPCMDPAR2_0(n)                                 (0xc800U + ((n-1) * 0x10U))
#define DWC_USB_DEPCMDPAR1_0(n)                                 (0xc804U + ((n-1) * 0x10U))
#define DWC_USB_DEPCMDPAR0_0(n)                                 (0xc808U + ((n-1) * 0x10U))
#define DWC_USB_DEPCMD_0(n)                                     (0xc80cU + ((n-1) * 0x10U))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

#define DWC_USB_CAPLENGTH_CAPLENGTH_SHIFT                       (0U)
#define DWC_USB_CAPLENGTH_CAPLENGTH_MASK                        (0x000000ffU)

#define DWC_USB_CAPLENGTH_HCIVERSION_SHIFT                      (16U)
#define DWC_USB_CAPLENGTH_HCIVERSION_MASK                       (0xffff0000U)
#define DWC_USB_CAPLENGTH_HCIVERSION_0_96                        (150U)
#define DWC_USB_CAPLENGTH_HCIVERSION_1_00                        (256U)

#define DWC_USB_HCSPARAMS1_MAXSLOTS_SHIFT                       (0U)
#define DWC_USB_HCSPARAMS1_MAXSLOTS_MASK                        (0x000000ffU)

#define DWC_USB_HCSPARAMS1_MAXINTRS_SHIFT                       (8U)
#define DWC_USB_HCSPARAMS1_MAXINTRS_MASK                        (0x0007ff00U)

#define DWC_USB_HCSPARAMS1_MAXPORTS_SHIFT                       (24U)
#define DWC_USB_HCSPARAMS1_MAXPORTS_MASK                        (0xff000000U)

#define DWC_USB_HCSPARAMS2_IST_SHIFT                            (0U)
#define DWC_USB_HCSPARAMS2_IST_MASK                             (0x0000000fU)

#define DWC_USB_HCSPARAMS2_ERSTMAX_SHIFT                        (4U)
#define DWC_USB_HCSPARAMS2_ERSTMAX_MASK                         (0x000000f0U)

#define DWC_USB_HCSPARAMS2_SPR_SHIFT                            (26U)
#define DWC_USB_HCSPARAMS2_SPR_MASK                             (0x04000000U)
#define DWC_USB_HCSPARAMS2_SPR_NO                                (0U)
#define DWC_USB_HCSPARAMS2_SPR_YES                               (1U)

#define DWC_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_SHIFT           (27U)
#define DWC_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_LO_MASK            (0xf8000000U)

#define DWC_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT           (21U)
#define DWC_USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK            (0x03e00000U)

#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT             (0U)
#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK              (0x000000ffU)
#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_ZERO               (0U)
#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_1                  (1U)
#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_2                  (2U)
#define DWC_USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_10                 (10U)

#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT             (16U)
#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK              (0xffff0000U)
#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_ZERO               (0U)
#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_1                  (1U)
#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_2                  (2U)
#define DWC_USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_2047               (2047U)

#define DWC_USB_HCCPARAMS_AC64_SHIFT                            (0U)
#define DWC_USB_HCCPARAMS_AC64_MASK                             (0x00000001U)

#define DWC_USB_HCCPARAMS_BNC_SHIFT                             (1U)
#define DWC_USB_HCCPARAMS_BNC_MASK                              (0x00000002U)

#define DWC_USB_HCCPARAMS_CSZ_SHIFT                             (2U)
#define DWC_USB_HCCPARAMS_CSZ_MASK                              (0x00000004U)

#define DWC_USB_HCCPARAMS_PPC_SHIFT                             (3U)
#define DWC_USB_HCCPARAMS_PPC_MASK                              (0x00000008U)

#define DWC_USB_HCCPARAMS_PIND_SHIFT                            (4U)
#define DWC_USB_HCCPARAMS_PIND_MASK                             (0x00000010U)

#define DWC_USB_HCCPARAMS_LHRC_SHIFT                            (5U)
#define DWC_USB_HCCPARAMS_LHRC_MASK                             (0x00000020U)

#define DWC_USB_HCCPARAMS_LTC_SHIFT                             (6U)
#define DWC_USB_HCCPARAMS_LTC_MASK                              (0x00000040U)

#define DWC_USB_HCCPARAMS_NSS_SHIFT                             (7U)
#define DWC_USB_HCCPARAMS_NSS_MASK                              (0x00000080U)

#define DWC_USB_HCCPARAMS_MAXPSASIZE_SHIFT                      (12U)
#define DWC_USB_HCCPARAMS_MAXPSASIZE_MASK                       (0x0000f000U)

#define DWC_USB_HCCPARAMS_XECP_SHIFT                            (16U)
#define DWC_USB_HCCPARAMS_XECP_MASK                             (0xffff0000U)

#define DWC_USB_HCCPARAMS_PAE_SHIFT                             (8U)
#define DWC_USB_HCCPARAMS_PAE_MASK                              (0x00000100U)

#define DWC_USB_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT               (2U)
#define DWC_USB_DBOFF_DOORBELL_ARRAY_OFFSET_MASK                (0xfffffffcU)

#define DWC_USB_DBOFF_ZERO_SHIFT                                (0U)
#define DWC_USB_DBOFF_ZERO_MASK                                 (0x00000003U)

#define DWC_USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT           (5U)
#define DWC_USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK            (0xffffffe0U)

#define DWC_USB_RTSOFF_ZERO_SHIFT                               (0U)
#define DWC_USB_RTSOFF_ZERO_MASK                                (0x0000001fU)

#define DWC_USB_USBCMD_R_S_SHIFT                                (0U)
#define DWC_USB_USBCMD_R_S_MASK                                 (0x00000001U)

#define DWC_USB_USBCMD_HCRST_SHIFT                              (1U)
#define DWC_USB_USBCMD_HCRST_MASK                               (0x00000002U)

#define DWC_USB_USBCMD_INTE_SHIFT                               (2U)
#define DWC_USB_USBCMD_INTE_MASK                                (0x00000004U)

#define DWC_USB_USBCMD_HSEE_SHIFT                               (3U)
#define DWC_USB_USBCMD_HSEE_MASK                                (0x00000008U)

#define DWC_USB_USBCMD_LHCRST_SHIFT                             (7U)
#define DWC_USB_USBCMD_LHCRST_MASK                              (0x00000080U)

#define DWC_USB_USBCMD_CSS_SHIFT                                (8U)
#define DWC_USB_USBCMD_CSS_MASK                                 (0x00000100U)

#define DWC_USB_USBCMD_CRS_SHIFT                                (9U)
#define DWC_USB_USBCMD_CRS_MASK                                 (0x00000200U)

#define DWC_USB_USBCMD_EWE_SHIFT                                (10U)
#define DWC_USB_USBCMD_EWE_MASK                                 (0x00000400U)

#define DWC_USB_USBCMD_EU3S_SHIFT                               (11U)
#define DWC_USB_USBCMD_EU3S_MASK                                (0x00000800U)

#define DWC_USB_USBSTS_HCH_SHIFT                                (0U)
#define DWC_USB_USBSTS_HCH_MASK                                 (0x00000001U)

#define DWC_USB_USBSTS_HSE_SHIFT                                (2U)
#define DWC_USB_USBSTS_HSE_MASK                                 (0x00000004U)

#define DWC_USB_USBSTS_EINT_SHIFT                               (3U)
#define DWC_USB_USBSTS_EINT_MASK                                (0x00000008U)

#define DWC_USB_USBSTS_PCD_SHIFT                                (4U)
#define DWC_USB_USBSTS_PCD_MASK                                 (0x00000010U)

#define DWC_USB_USBSTS_SSS_SHIFT                                (8U)
#define DWC_USB_USBSTS_SSS_MASK                                 (0x00000100U)

#define DWC_USB_USBSTS_RSS_SHIFT                                (9U)
#define DWC_USB_USBSTS_RSS_MASK                                 (0x00000200U)

#define DWC_USB_USBSTS_SRE_SHIFT                                (10U)
#define DWC_USB_USBSTS_SRE_MASK                                 (0x00000400U)

#define DWC_USB_USBSTS_CNR_SHIFT                                (11U)
#define DWC_USB_USBSTS_CNR_MASK                                 (0x00000800U)
#define DWC_USB_USBSTS_CNR_READY                                 (0U)
#define DWC_USB_USBSTS_CNR_NOTREADY                              (1U)

#define DWC_USB_USBSTS_HCE_SHIFT                                (12U)
#define DWC_USB_USBSTS_HCE_MASK                                 (0x00001000U)

#define DWC_USB_PAGESIZE_PAGE_SIZE_SHIFT                        (0U)
#define DWC_USB_PAGESIZE_PAGE_SIZE_MASK                         (0x0000ffffU)
#define DWC_USB_PAGESIZE_PAGE_SIZE_4KB                           (1U)

#define DWC_USB_DNCTRL_N0_SHIFT                                 (0U)
#define DWC_USB_DNCTRL_N0_MASK                                  (0x00000001U)

#define DWC_USB_DNCTRL_N1_SHIFT                                 (1U)
#define DWC_USB_DNCTRL_N1_MASK                                  (0x00000002U)

#define DWC_USB_DNCTRL_N2_SHIFT                                 (2U)
#define DWC_USB_DNCTRL_N2_MASK                                  (0x00000004U)

#define DWC_USB_DNCTRL_N3_SHIFT                                 (3U)
#define DWC_USB_DNCTRL_N3_MASK                                  (0x00000008U)

#define DWC_USB_DNCTRL_N4_SHIFT                                 (4U)
#define DWC_USB_DNCTRL_N4_MASK                                  (0x00000010U)

#define DWC_USB_DNCTRL_N5_SHIFT                                 (5U)
#define DWC_USB_DNCTRL_N5_MASK                                  (0x00000020U)

#define DWC_USB_DNCTRL_N6_SHIFT                                 (6U)
#define DWC_USB_DNCTRL_N6_MASK                                  (0x00000040U)

#define DWC_USB_DNCTRL_N7_SHIFT                                 (7U)
#define DWC_USB_DNCTRL_N7_MASK                                  (0x00000080U)

#define DWC_USB_DNCTRL_N8_SHIFT                                 (8U)
#define DWC_USB_DNCTRL_N8_MASK                                  (0x00000100U)

#define DWC_USB_DNCTRL_N9_SHIFT                                 (9U)
#define DWC_USB_DNCTRL_N9_MASK                                  (0x00000200U)

#define DWC_USB_DNCTRL_N10_SHIFT                                (10U)
#define DWC_USB_DNCTRL_N10_MASK                                 (0x00000400U)

#define DWC_USB_DNCTRL_N11_SHIFT                                (11U)
#define DWC_USB_DNCTRL_N11_MASK                                 (0x00000800U)

#define DWC_USB_DNCTRL_N12_SHIFT                                (12U)
#define DWC_USB_DNCTRL_N12_MASK                                 (0x00001000U)

#define DWC_USB_DNCTRL_N13_SHIFT                                (13U)
#define DWC_USB_DNCTRL_N13_MASK                                 (0x00002000U)

#define DWC_USB_DNCTRL_N14_SHIFT                                (14U)
#define DWC_USB_DNCTRL_N14_MASK                                 (0x00004000U)

#define DWC_USB_DNCTRL_N15_SHIFT                                (15U)
#define DWC_USB_DNCTRL_N15_MASK                                 (0x00008000U)

#define DWC_USB_CRCR_LO_RCS_SHIFT                               (0U)
#define DWC_USB_CRCR_LO_RCS_MASK                                (0x00000001U)

#define DWC_USB_CRCR_LO_CS_SHIFT                                (1U)
#define DWC_USB_CRCR_LO_CS_MASK                                 (0x00000002U)

#define DWC_USB_CRCR_LO_CA_SHIFT                                (2U)
#define DWC_USB_CRCR_LO_CA_MASK                                 (0x00000004U)

#define DWC_USB_CRCR_LO_CRR_SHIFT                               (3U)
#define DWC_USB_CRCR_LO_CRR_MASK                                (0x00000008U)

#define DWC_USB_CRCR_LO_CMD_RING_PNTR_SHIFT                     (6U)
#define DWC_USB_CRCR_LO_CMD_RING_PNTR_MASK                      (0xffffffc0U)

#define DWC_USB_CRCR_HI_CMD_RING_PNTR_SHIFT                     (0U)
#define DWC_USB_CRCR_HI_CMD_RING_PNTR_MASK                      (0xffffffffU)

#define DWC_USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT             (6U)
#define DWC_USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK              (0xffffffc0U)

#define DWC_USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT             (0U)
#define DWC_USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK              (0xffffffffU)

#define DWC_USB_CONFIG_MAXSLOTSEN_SHIFT                         (0U)
#define DWC_USB_CONFIG_MAXSLOTSEN_MASK                          (0x000000ffU)

#define DWC_USB_PORTSC2_CCS_SHIFT                               (0U)
#define DWC_USB_PORTSC2_CCS_MASK                                (0x00000001U)

#define DWC_USB_PORTSC2_PED_SHIFT                               (1U)
#define DWC_USB_PORTSC2_PED_MASK                                (0x00000002U)

#define DWC_USB_PORTSC2_OCA_SHIFT                               (3U)
#define DWC_USB_PORTSC2_OCA_MASK                                (0x00000008U)

#define DWC_USB_PORTSC2_PR_SHIFT                                (4U)
#define DWC_USB_PORTSC2_PR_MASK                                 (0x00000010U)

#define DWC_USB_PORTSC2_PLS_SHIFT                               (5U)
#define DWC_USB_PORTSC2_PLS_MASK                                (0x000001e0U)
#define DWC_USB_PORTSC2_PLS_U0                                   (0U)
#define DWC_USB_PORTSC2_PLS_U1                                   (1U)
#define DWC_USB_PORTSC2_PLS_U2                                   (2U)
#define DWC_USB_PORTSC2_PLS_U3                                   (3U)
#define DWC_USB_PORTSC2_PLS_DISABLED                             (4U)
#define DWC_USB_PORTSC2_PLS_RXDETECT                             (5U)
#define DWC_USB_PORTSC2_PLS_INACTIVE                             (6U)
#define DWC_USB_PORTSC2_PLS_POLLING                              (7U)
#define DWC_USB_PORTSC2_PLS_RECOVERY                             (8U)
#define DWC_USB_PORTSC2_PLS_HOTRESET                             (9U)
#define DWC_USB_PORTSC2_PLS_COMPLIANCEMODE                       (10U)
#define DWC_USB_PORTSC2_PLS_TESTMODE                             (11U)
#define DWC_USB_PORTSC2_PLS_RESUME                               (15U)

#define DWC_USB_PORTSC2_PP_SHIFT                                (9U)
#define DWC_USB_PORTSC2_PP_MASK                                 (0x00000200U)

#define DWC_USB_PORTSC2_PORTSPEED_SHIFT                         (10U)
#define DWC_USB_PORTSC2_PORTSPEED_MASK                          (0x00003c00U)

#define DWC_USB_PORTSC2_PIC_SHIFT                               (14U)
#define DWC_USB_PORTSC2_PIC_MASK                                (0x0000c000U)

#define DWC_USB_PORTSC2_LWS_SHIFT                               (16U)
#define DWC_USB_PORTSC2_LWS_MASK                                (0x00010000U)

#define DWC_USB_PORTSC2_CSC_SHIFT                               (17U)
#define DWC_USB_PORTSC2_CSC_MASK                                (0x00020000U)

#define DWC_USB_PORTSC2_PEC_SHIFT                               (18U)
#define DWC_USB_PORTSC2_PEC_MASK                                (0x00040000U)

#define DWC_USB_PORTSC2_WRC_SHIFT                               (19U)
#define DWC_USB_PORTSC2_WRC_MASK                                (0x00080000U)

#define DWC_USB_PORTSC2_OCC_SHIFT                               (20U)
#define DWC_USB_PORTSC2_OCC_MASK                                (0x00100000U)

#define DWC_USB_PORTSC2_PRC_SHIFT                               (21U)
#define DWC_USB_PORTSC2_PRC_MASK                                (0x00200000U)

#define DWC_USB_PORTSC2_PLC_SHIFT                               (22U)
#define DWC_USB_PORTSC2_PLC_MASK                                (0x00400000U)

#define DWC_USB_PORTSC2_CEC_SHIFT                               (23U)
#define DWC_USB_PORTSC2_CEC_MASK                                (0x00800000U)

#define DWC_USB_PORTSC2_WCE_SHIFT                               (25U)
#define DWC_USB_PORTSC2_WCE_MASK                                (0x02000000U)

#define DWC_USB_PORTSC2_WDE_SHIFT                               (26U)
#define DWC_USB_PORTSC2_WDE_MASK                                (0x04000000U)

#define DWC_USB_PORTSC2_WOE_SHIFT                               (27U)
#define DWC_USB_PORTSC2_WOE_MASK                                (0x08000000U)

#define DWC_USB_PORTSC2_DR_SHIFT                                (30U)
#define DWC_USB_PORTSC2_DR_MASK                                 (0x40000000U)

#define DWC_USB_PORTSC2_WPR_SHIFT                               (31U)
#define DWC_USB_PORTSC2_WPR_MASK                                (0x80000000U)

#define DWC_USB_PORTSC2_CAS_SHIFT                               (24U)
#define DWC_USB_PORTSC2_CAS_MASK                                (0x01000000U)

#define DWC_USB_PORTPMSC2_U1_TIMEOUT_SHIFT                      (0U)
#define DWC_USB_PORTPMSC2_U1_TIMEOUT_MASK                       (0x000000ffU)

#define DWC_USB_PORTPMSC2_U2_TIMEOUT_SHIFT                      (8U)
#define DWC_USB_PORTPMSC2_U2_TIMEOUT_MASK                       (0x0000ff00U)

#define DWC_USB_PORTPMSC2_FLA_SHIFT                             (16U)
#define DWC_USB_PORTPMSC2_FLA_MASK                              (0x00010000U)

#define DWC_USB_PORTLI2_LINK_ERROR_COUNT_SHIFT                  (0U)
#define DWC_USB_PORTLI2_LINK_ERROR_COUNT_MASK                   (0x0000ffffU)

#define DWC_USB_PORTSC1_CCS_SHIFT                               (0U)
#define DWC_USB_PORTSC1_CCS_MASK                                (0x00000001U)

#define DWC_USB_PORTSC1_PED_SHIFT                               (1U)
#define DWC_USB_PORTSC1_PED_MASK                                (0x00000002U)

#define DWC_USB_PORTSC1_OCA_SHIFT                               (3U)
#define DWC_USB_PORTSC1_OCA_MASK                                (0x00000008U)

#define DWC_USB_PORTSC1_PR_SHIFT                                (4U)
#define DWC_USB_PORTSC1_PR_MASK                                 (0x00000010U)

#define DWC_USB_PORTSC1_PLS_SHIFT                               (5U)
#define DWC_USB_PORTSC1_PLS_MASK                                (0x000001e0U)
#define DWC_USB_PORTSC1_PLS_U0                                   (0U)
#define DWC_USB_PORTSC1_PLS_U1                                   (1U)
#define DWC_USB_PORTSC1_PLS_U2                                   (2U)
#define DWC_USB_PORTSC1_PLS_U3                                   (3U)
#define DWC_USB_PORTSC1_PLS_DISABLED                             (4U)
#define DWC_USB_PORTSC1_PLS_RXDETECT                             (5U)
#define DWC_USB_PORTSC1_PLS_INACTIVE                             (6U)
#define DWC_USB_PORTSC1_PLS_POLLING                              (7U)
#define DWC_USB_PORTSC1_PLS_RECOVERY                             (8U)
#define DWC_USB_PORTSC1_PLS_HOTRESET                             (9U)
#define DWC_USB_PORTSC1_PLS_COMPLIANCEMODE                       (10U)
#define DWC_USB_PORTSC1_PLS_TESTMODE                             (11U)
#define DWC_USB_PORTSC1_PLS_RESUME                               (15U)

#define DWC_USB_PORTSC1_PP_SHIFT                                (9U)
#define DWC_USB_PORTSC1_PP_MASK                                 (0x00000200U)

#define DWC_USB_PORTSC1_PORTSPEED_SHIFT                         (10U)
#define DWC_USB_PORTSC1_PORTSPEED_MASK                          (0x00003c00U)

#define DWC_USB_PORTSC1_PIC_SHIFT                               (14U)
#define DWC_USB_PORTSC1_PIC_MASK                                (0x0000c000U)

#define DWC_USB_PORTSC1_LWS_SHIFT                               (16U)
#define DWC_USB_PORTSC1_LWS_MASK                                (0x00010000U)

#define DWC_USB_PORTSC1_CSC_SHIFT                               (17U)
#define DWC_USB_PORTSC1_CSC_MASK                                (0x00020000U)

#define DWC_USB_PORTSC1_PEC_SHIFT                               (18U)
#define DWC_USB_PORTSC1_PEC_MASK                                (0x00040000U)

#define DWC_USB_PORTSC1_WRC_SHIFT                               (19U)
#define DWC_USB_PORTSC1_WRC_MASK                                (0x00080000U)

#define DWC_USB_PORTSC1_OCC_SHIFT                               (20U)
#define DWC_USB_PORTSC1_OCC_MASK                                (0x00100000U)

#define DWC_USB_PORTSC1_PRC_SHIFT                               (21U)
#define DWC_USB_PORTSC1_PRC_MASK                                (0x00200000U)

#define DWC_USB_PORTSC1_PLC_SHIFT                               (22U)
#define DWC_USB_PORTSC1_PLC_MASK                                (0x00400000U)

#define DWC_USB_PORTSC1_CEC_SHIFT                               (23U)
#define DWC_USB_PORTSC1_CEC_MASK                                (0x00800000U)

#define DWC_USB_PORTSC1_WCE_SHIFT                               (25U)
#define DWC_USB_PORTSC1_WCE_MASK                                (0x02000000U)

#define DWC_USB_PORTSC1_WDE_SHIFT                               (26U)
#define DWC_USB_PORTSC1_WDE_MASK                                (0x04000000U)

#define DWC_USB_PORTSC1_WOE_SHIFT                               (27U)
#define DWC_USB_PORTSC1_WOE_MASK                                (0x08000000U)

#define DWC_USB_PORTSC1_DR_SHIFT                                (30U)
#define DWC_USB_PORTSC1_DR_MASK                                 (0x40000000U)

#define DWC_USB_PORTSC1_WPR_SHIFT                               (31U)
#define DWC_USB_PORTSC1_WPR_MASK                                (0x80000000U)

#define DWC_USB_PORTSC1_CAS_SHIFT                               (24U)
#define DWC_USB_PORTSC1_CAS_MASK                                (0x01000000U)

#define DWC_USB_PORTPMSC1_L1S_SHIFT                             (0U)
#define DWC_USB_PORTPMSC1_L1S_MASK                              (0x00000007U)

#define DWC_USB_PORTPMSC1_RWE_SHIFT                             (3U)
#define DWC_USB_PORTPMSC1_RWE_MASK                              (0x00000008U)

#define DWC_USB_PORTPMSC1_L1_DEVICE_SLOT_SHIFT                  (8U)
#define DWC_USB_PORTPMSC1_L1_DEVICE_SLOT_MASK                   (0x0000ff00U)

#define DWC_USB_PORTPMSC1_PORT_TEST_CTRL_SHIFT                  (28U)
#define DWC_USB_PORTPMSC1_PORT_TEST_CTRL_MASK                   (0xf0000000U)

#define DWC_USB_PORTPMSC1_HLE_SHIFT                             (16U)
#define DWC_USB_PORTPMSC1_HLE_MASK                              (0x00010000U)

#define DWC_USB_PORTPMSC1_BESL_SHIFT                            (4U)
#define DWC_USB_PORTPMSC1_BESL_MASK                             (0x000000f0U)

#define DWC_USB_PORTLI1_LINK_ERROR_COUNT_SHIFT                  (0U)
#define DWC_USB_PORTLI1_LINK_ERROR_COUNT_MASK                   (0x0000ffffU)

#define DWC_USB_PORTHLPMC1_HIRDM_SHIFT                          (0U)
#define DWC_USB_PORTHLPMC1_HIRDM_MASK                           (0x00000003U)

#define DWC_USB_PORTHLPMC1_L1_TIMEOUT_SHIFT                     (2U)
#define DWC_USB_PORTHLPMC1_L1_TIMEOUT_MASK                      (0x000003fcU)

#define DWC_USB_PORTHLPMC1_BESLD_SHIFT                          (10U)
#define DWC_USB_PORTHLPMC1_BESLD_MASK                           (0x00003c00U)

#define DWC_USB_MFINDEX_MICROFRM_IDX_SHIFT                      (0U)
#define DWC_USB_MFINDEX_MICROFRM_IDX_MASK                       (0x00003fffU)

#define DWC_USB_IMAN_IP_SHIFT                                   (0U)
#define DWC_USB_IMAN_IP_MASK                                    (0x00000001U)
#define DWC_USB_IMAN_IP_PENDING                                  (1U)
#define DWC_USB_IMAN_IP_IDLE                                     (0U)

#define DWC_USB_IMAN_IE_SHIFT                                   (1U)
#define DWC_USB_IMAN_IE_MASK                                    (0x00000002U)
#define DWC_USB_IMAN_IE_DIS                                      (0U)
#define DWC_USB_IMAN_IE_EN                                       (1U)

#define DWC_USB_IMOD_IMODI_SHIFT                                (0U)
#define DWC_USB_IMOD_IMODI_MASK                                 (0x0000ffffU)
#define DWC_USB_IMOD_IMODI_DIS                                   (0U)
#define DWC_USB_IMOD_IMODI_250NS                                 (1U)
#define DWC_USB_IMOD_IMODI_1MS1                                  (4000U)

#define DWC_USB_IMOD_IMODC_SHIFT                                (16U)
#define DWC_USB_IMOD_IMODC_MASK                                 (0xffff0000U)

#define DWC_USB_ERSTSZ_ERS_TBL_SIZE_SHIFT                       (0U)
#define DWC_USB_ERSTSZ_ERS_TBL_SIZE_MASK                        (0x0000ffffU)

#define DWC_USB_ERSTBA_LO_ERS_TBL_BAR_SHIFT                     (6U)
#define DWC_USB_ERSTBA_LO_ERS_TBL_BAR_MASK                      (0xffffffc0U)

#define DWC_USB_ERSTBA_HI_ERS_TBL_BAR_SHIFT                     (0U)
#define DWC_USB_ERSTBA_HI_ERS_TBL_BAR_MASK                      (0xffffffffU)

#define DWC_USB_ERDP_LO_DESI_SHIFT                              (0U)
#define DWC_USB_ERDP_LO_DESI_MASK                               (0x00000007U)

#define DWC_USB_ERDP_LO_EHB_SHIFT                               (3U)
#define DWC_USB_ERDP_LO_EHB_MASK                                (0x00000008U)

#define DWC_USB_ERDP_LO_ERD_PNTR_SHIFT                          (4U)
#define DWC_USB_ERDP_LO_ERD_PNTR_MASK                           (0xfffffff0U)

#define DWC_USB_ERDP_HI_ERD_PNTR_SHIFT                          (0U)
#define DWC_USB_ERDP_HI_ERD_PNTR_MASK                           (0xffffffffU)

#define DWC_USB_DB_DB_TARGET_SHIFT                              (0U)
#define DWC_USB_DB_DB_TARGET_MASK                               (0x000000ffU)

#define DWC_USB_DB_DB_STREAM_ID_SHIFT                           (16U)
#define DWC_USB_DB_DB_STREAM_ID_MASK                            (0xffff0000U)

#define DWC_USB_USBLEGSUP_ECID_SHIFT                            (0U)
#define DWC_USB_USBLEGSUP_ECID_MASK                             (0x000000ffU)
#define DWC_USB_USBLEGSUP_ECID_LEGACY                            (1U)
#define DWC_USB_USBLEGSUP_ECID_PROT                              (2U)
#define DWC_USB_USBLEGSUP_ECID_DBC                               (10U)

#define DWC_USB_USBLEGSUP_NCP_SHIFT                             (8U)
#define DWC_USB_USBLEGSUP_NCP_MASK                              (0x0000ff00U)
#define DWC_USB_USBLEGSUP_NCP_EOL                                (0U)

#define DWC_USB_USBLEGSUP_HCBOS_SHIFT                           (16U)
#define DWC_USB_USBLEGSUP_HCBOS_MASK                            (0x00010000U)

#define DWC_USB_USBLEGSUP_HCOOS_SHIFT                           (24U)
#define DWC_USB_USBLEGSUP_HCOOS_MASK                            (0x01000000U)

#define DWC_USB_USBLEGCTLSTS_USE_SHIFT                          (0U)
#define DWC_USB_USBLEGCTLSTS_USE_MASK                           (0x00000001U)

#define DWC_USB_USBLEGCTLSTS_SHSEE_SHIFT                        (4U)
#define DWC_USB_USBLEGCTLSTS_SHSEE_MASK                         (0x00000010U)

#define DWC_USB_USBLEGCTLSTS_SOOE_SHIFT                         (13U)
#define DWC_USB_USBLEGCTLSTS_SOOE_MASK                          (0x00002000U)

#define DWC_USB_USBLEGCTLSTS_SPCE_SHIFT                         (14U)
#define DWC_USB_USBLEGCTLSTS_SPCE_MASK                          (0x00004000U)

#define DWC_USB_USBLEGCTLSTS_SBE_SHIFT                          (15U)
#define DWC_USB_USBLEGCTLSTS_SBE_MASK                           (0x00008000U)

#define DWC_USB_USBLEGCTLSTS_SEI_SHIFT                          (16U)
#define DWC_USB_USBLEGCTLSTS_SEI_MASK                           (0x00010000U)

#define DWC_USB_USBLEGCTLSTS_SHSE_SHIFT                         (20U)
#define DWC_USB_USBLEGCTLSTS_SHSE_MASK                          (0x00100000U)

#define DWC_USB_USBLEGCTLSTS_SOOC_SHIFT                         (29U)
#define DWC_USB_USBLEGCTLSTS_SOOC_MASK                          (0x20000000U)

#define DWC_USB_USBLEGCTLSTS_SPC_SHIFT                          (30U)
#define DWC_USB_USBLEGCTLSTS_SPC_MASK                           (0x40000000U)

#define DWC_USB_USBLEGCTLSTS_SB_SHIFT                           (31U)
#define DWC_USB_USBLEGCTLSTS_SB_MASK                            (0x80000000U)

#define DWC_USB_SUPTPRT2_DW0_ECID_SHIFT                         (0U)
#define DWC_USB_SUPTPRT2_DW0_ECID_MASK                          (0x000000ffU)
#define DWC_USB_SUPTPRT2_DW0_ECID_LEGACY                         (1U)
#define DWC_USB_SUPTPRT2_DW0_ECID_PROT                           (2U)
#define DWC_USB_SUPTPRT2_DW0_ECID_DBC                            (10U)

#define DWC_USB_SUPTPRT2_DW0_NCP_SHIFT                          (8U)
#define DWC_USB_SUPTPRT2_DW0_NCP_MASK                           (0x0000ff00U)
#define DWC_USB_SUPTPRT2_DW0_NCP_EOL                             (0U)

#define DWC_USB_SUPTPRT2_DW0_MINREV_SHIFT                       (16U)
#define DWC_USB_SUPTPRT2_DW0_MINREV_MASK                        (0x00ff0000U)

#define DWC_USB_SUPTPRT2_DW0_MAJREV_SHIFT                       (24U)
#define DWC_USB_SUPTPRT2_DW0_MAJREV_MASK                        (0xff000000U)

#define DWC_USB_SUPTPRT2_DW1_CHAR0_SHIFT                        (0U)
#define DWC_USB_SUPTPRT2_DW1_CHAR0_MASK                         (0x000000ffU)

#define DWC_USB_SUPTPRT2_DW1_CHAR1_SHIFT                        (8U)
#define DWC_USB_SUPTPRT2_DW1_CHAR1_MASK                         (0x0000ff00U)

#define DWC_USB_SUPTPRT2_DW1_CHAR2_SHIFT                        (16U)
#define DWC_USB_SUPTPRT2_DW1_CHAR2_MASK                         (0x00ff0000U)

#define DWC_USB_SUPTPRT2_DW1_CHAR3_SHIFT                        (24U)
#define DWC_USB_SUPTPRT2_DW1_CHAR3_MASK                         (0xff000000U)

#define DWC_USB_SUPTPRT2_DW2_CPO_SHIFT                          (0U)
#define DWC_USB_SUPTPRT2_DW2_CPO_MASK                           (0x000000ffU)

#define DWC_USB_SUPTPRT2_DW2_CPC_SHIFT                          (8U)
#define DWC_USB_SUPTPRT2_DW2_CPC_MASK                           (0x0000ff00U)

#define DWC_USB_SUPTPRT2_DW2_PSIC_SHIFT                         (28U)
#define DWC_USB_SUPTPRT2_DW2_PSIC_MASK                          (0xf0000000U)
#define DWC_USB_SUPTPRT2_DW2_PSIC_ALL                            (0U)

#define DWC_USB_SUPTPRT2_DW2_HSO_SHIFT                          (17U)
#define DWC_USB_SUPTPRT2_DW2_HSO_MASK                           (0x00020000U)

#define DWC_USB_SUPTPRT2_DW2_IHI_SHIFT                          (18U)
#define DWC_USB_SUPTPRT2_DW2_IHI_MASK                           (0x00040000U)

#define DWC_USB_SUPTPRT2_DW2_HLC_SHIFT                          (19U)
#define DWC_USB_SUPTPRT2_DW2_HLC_MASK                           (0x00080000U)

#define DWC_USB_SUPTPRT2_DW2_BESLD_SHIFT                        (20U)
#define DWC_USB_SUPTPRT2_DW2_BESLD_MASK                         (0x00100000U)

#define DWC_USB_SUPTPRT2_DW3_PST_SHIFT                          (0U)
#define DWC_USB_SUPTPRT2_DW3_PST_MASK                           (0x0000001fU)

#define DWC_USB_SUPTPRT3_DW0_ECID_SHIFT                         (0U)
#define DWC_USB_SUPTPRT3_DW0_ECID_MASK                          (0x000000ffU)
#define DWC_USB_SUPTPRT3_DW0_ECID_LEGACY                         (1U)
#define DWC_USB_SUPTPRT3_DW0_ECID_PROT                           (2U)
#define DWC_USB_SUPTPRT3_DW0_ECID_DBC                            (10U)

#define DWC_USB_SUPTPRT3_DW0_MINREV_SHIFT                       (16U)
#define DWC_USB_SUPTPRT3_DW0_MINREV_MASK                        (0x00ff0000U)

#define DWC_USB_SUPTPRT3_DW0_MAJREV_SHIFT                       (24U)
#define DWC_USB_SUPTPRT3_DW0_MAJREV_MASK                        (0xff000000U)

#define DWC_USB_SUPTPRT3_DW0_NCP_SHIFT                          (8U)
#define DWC_USB_SUPTPRT3_DW0_NCP_MASK                           (0x0000ff00U)
#define DWC_USB_SUPTPRT3_DW0_NCP_EOL                             (0U)

#define DWC_USB_SUPTPRT3_DW1_CHAR0_SHIFT                        (0U)
#define DWC_USB_SUPTPRT3_DW1_CHAR0_MASK                         (0x000000ffU)

#define DWC_USB_SUPTPRT3_DW1_CHAR1_SHIFT                        (8U)
#define DWC_USB_SUPTPRT3_DW1_CHAR1_MASK                         (0x0000ff00U)

#define DWC_USB_SUPTPRT3_DW1_CHAR2_SHIFT                        (16U)
#define DWC_USB_SUPTPRT3_DW1_CHAR2_MASK                         (0x00ff0000U)

#define DWC_USB_SUPTPRT3_DW1_CHAR3_SHIFT                        (24U)
#define DWC_USB_SUPTPRT3_DW1_CHAR3_MASK                         (0xff000000U)

#define DWC_USB_SUPTPRT3_DW2_CPO_SHIFT                          (0U)
#define DWC_USB_SUPTPRT3_DW2_CPO_MASK                           (0x000000ffU)

#define DWC_USB_SUPTPRT3_DW2_CPC_SHIFT                          (8U)
#define DWC_USB_SUPTPRT3_DW2_CPC_MASK                           (0x0000ff00U)

#define DWC_USB_SUPTPRT3_DW2_PSIC_SHIFT                         (28U)
#define DWC_USB_SUPTPRT3_DW2_PSIC_MASK                          (0xf0000000U)
#define DWC_USB_SUPTPRT3_DW2_PSIC_SS                             (0U)

#define DWC_USB_SUPTPRT3_DW3_PST_SHIFT                          (0U)
#define DWC_USB_SUPTPRT3_DW3_PST_MASK                           (0x0000001fU)

#define DWC_USB_DCID_DCERSTMAX_SHIFT                            (16U)
#define DWC_USB_DCID_DCERSTMAX_MASK                             (0x001f0000U)
#define DWC_USB_DCID_DCERSTMAX_MIN                               (0U)
#define DWC_USB_DCID_DCERSTMAX_MAX                               (15U)

#define DWC_USB_DCID_NCP_SHIFT                                  (8U)
#define DWC_USB_DCID_NCP_MASK                                   (0x0000ff00U)
#define DWC_USB_DCID_NCP_EOL                                     (0U)

#define DWC_USB_DCID_ECID_SHIFT                                 (0U)
#define DWC_USB_DCID_ECID_MASK                                  (0x000000ffU)
#define DWC_USB_DCID_ECID_LEGACY                                 (1U)
#define DWC_USB_DCID_ECID_PROT                                   (2U)
#define DWC_USB_DCID_ECID_DBC                                    (10U)

#define DWC_USB_DCDB_DBTARGET_SHIFT                             (8U)
#define DWC_USB_DCDB_DBTARGET_MASK                              (0x0000ff00U)
#define DWC_USB_DCDB_DBTARGET_OUT                                (0U)
#define DWC_USB_DCDB_DBTARGET_IN                                 (1U)

#define DWC_USB_DCERSTSZ_TBLSIZE_SHIFT                          (0U)
#define DWC_USB_DCERSTSZ_TBLSIZE_MASK                           (0x0000ffffU)

#define DWC_USB_DCERSTBA_LO_BASEADDR_SHIFT                      (4U)
#define DWC_USB_DCERSTBA_LO_BASEADDR_MASK                       (0xfffffff0U)

#define DWC_USB_DCERSTBA_HI_BASEADDR_SHIFT                      (0U)
#define DWC_USB_DCERSTBA_HI_BASEADDR_MASK                       (0xffffffffU)

#define DWC_USB_DCERDP_LO_DEQUEUEPOINTER_SHIFT                  (4U)
#define DWC_USB_DCERDP_LO_DEQUEUEPOINTER_MASK                   (0xfffffff0U)

#define DWC_USB_DCERDP_LO_DESI_SHIFT                            (0U)
#define DWC_USB_DCERDP_LO_DESI_MASK                             (0x00000007U)

#define DWC_USB_DCERDP_HI_DEQUEUEPOINTER_SHIFT                  (0U)
#define DWC_USB_DCERDP_HI_DEQUEUEPOINTER_MASK                   (0xffffffffU)

#define DWC_USB_DCCTRL_DCR_SHIFT                                (0U)
#define DWC_USB_DCCTRL_DCR_MASK                                 (0x00000001U)

#define DWC_USB_DCCTRL_LSE_SHIFT                                (1U)
#define DWC_USB_DCCTRL_LSE_MASK                                 (0x00000002U)
#define DWC_USB_DCCTRL_LSE_DISABLED                              (0U)
#define DWC_USB_DCCTRL_LSE_ENABLED                               (1U)

#define DWC_USB_DCCTRL_HOT_SHIFT                                (2U)
#define DWC_USB_DCCTRL_HOT_MASK                                 (0x00000004U)

#define DWC_USB_DCCTRL_HIT_SHIFT                                (3U)
#define DWC_USB_DCCTRL_HIT_MASK                                 (0x00000008U)

#define DWC_USB_DCCTRL_DBG_MAX_BURST_SIZE_SHIFT                 (16U)
#define DWC_USB_DCCTRL_DBG_MAX_BURST_SIZE_MASK                  (0x00ff0000U)

#define DWC_USB_DCCTRL_DEVICE_ADDR_SHIFT                        (24U)
#define DWC_USB_DCCTRL_DEVICE_ADDR_MASK                         (0x7f000000U)

#define DWC_USB_DCCTRL_DCE_SHIFT                                (31U)
#define DWC_USB_DCCTRL_DCE_MASK                                 (0x80000000U)
#define DWC_USB_DCCTRL_DCE_DISABLED                              (0U)
#define DWC_USB_DCCTRL_DCE_ENABLED                               (1U)

#define DWC_USB_DCCTRL_DRC_SHIFT                                (4U)
#define DWC_USB_DCCTRL_DRC_MASK                                 (0x00000010U)

#define DWC_USB_DCST_ER_SHIFT                                   (0U)
#define DWC_USB_DCST_ER_MASK                                    (0x00000001U)

#define DWC_USB_DCST_DBG_PORT_NUMBER_SHIFT                      (24U)
#define DWC_USB_DCST_DBG_PORT_NUMBER_MASK                       (0xff000000U)

#define DWC_USB_DCPORTSC_CCS_SHIFT                              (0U)
#define DWC_USB_DCPORTSC_CCS_MASK                               (0x00000001U)

#define DWC_USB_DCPORTSC_PED_SHIFT                              (1U)
#define DWC_USB_DCPORTSC_PED_MASK                               (0x00000002U)

#define DWC_USB_DCPORTSC_PR_SHIFT                               (4U)
#define DWC_USB_DCPORTSC_PR_MASK                                (0x00000010U)

#define DWC_USB_DCPORTSC_PLS_SHIFT                              (5U)
#define DWC_USB_DCPORTSC_PLS_MASK                               (0x000001e0U)
#define DWC_USB_DCPORTSC_PLS_U0                                  (0U)
#define DWC_USB_DCPORTSC_PLS_U1                                  (1U)
#define DWC_USB_DCPORTSC_PLS_U2                                  (2U)
#define DWC_USB_DCPORTSC_PLS_U3                                  (3U)
#define DWC_USB_DCPORTSC_PLS_DISABLED                            (4U)
#define DWC_USB_DCPORTSC_PLS_RXDETECT                            (5U)
#define DWC_USB_DCPORTSC_PLS_INACTIVE                            (6U)
#define DWC_USB_DCPORTSC_PLS_POLLING                             (7U)
#define DWC_USB_DCPORTSC_PLS_RECOVERY                            (8U)
#define DWC_USB_DCPORTSC_PLS_HOTRESET                            (9U)

#define DWC_USB_DCPORTSC_PORTSPEED_SHIFT                        (10U)
#define DWC_USB_DCPORTSC_PORTSPEED_MASK                         (0x00003c00U)

#define DWC_USB_DCPORTSC_CSC_SHIFT                              (17U)
#define DWC_USB_DCPORTSC_CSC_MASK                               (0x00020000U)

#define DWC_USB_DCPORTSC_PRC_SHIFT                              (21U)
#define DWC_USB_DCPORTSC_PRC_MASK                               (0x00200000U)

#define DWC_USB_DCPORTSC_PLC_SHIFT                              (22U)
#define DWC_USB_DCPORTSC_PLC_MASK                               (0x00400000U)

#define DWC_USB_DCPORTSC_CEC_SHIFT                              (23U)
#define DWC_USB_DCPORTSC_CEC_MASK                               (0x00800000U)

#define DWC_USB_DCCP_LO_CONTEXTPOINTER_SHIFT                    (4U)
#define DWC_USB_DCCP_LO_CONTEXTPOINTER_MASK                     (0xfffffff0U)

#define DWC_USB_DCCP_HI_CONTEXTPOINTER_SHIFT                    (0U)
#define DWC_USB_DCCP_HI_CONTEXTPOINTER_MASK                     (0xffffffffU)

#define DWC_USB_DCDDI1_DBCPROTOCOL_SHIFT                        (0U)
#define DWC_USB_DCDDI1_DBCPROTOCOL_MASK                         (0x000000ffU)

#define DWC_USB_DCDDI1_VENDORID_SHIFT                           (16U)
#define DWC_USB_DCDDI1_VENDORID_MASK                            (0xffff0000U)

#define DWC_USB_DCDDI2_PRODUCTID_SHIFT                          (0U)
#define DWC_USB_DCDDI2_PRODUCTID_MASK                           (0x0000ffffU)

#define DWC_USB_DCDDI2_DEVICEREVISION_SHIFT                     (16U)
#define DWC_USB_DCDDI2_DEVICEREVISION_MASK                      (0xffff0000U)

#define DWC_USB_GSBUSCFG0_INCRBRSTENA_SHIFT                     (0U)
#define DWC_USB_GSBUSCFG0_INCRBRSTENA_MASK                      (0x00000001U)

#define DWC_USB_GSBUSCFG0_INCR4BRSTENA_SHIFT                    (1U)
#define DWC_USB_GSBUSCFG0_INCR4BRSTENA_MASK                     (0x00000002U)

#define DWC_USB_GSBUSCFG0_INCR8BRSTENA_SHIFT                    (2U)
#define DWC_USB_GSBUSCFG0_INCR8BRSTENA_MASK                     (0x00000004U)

#define DWC_USB_GSBUSCFG0_INCR16BRSTENA_SHIFT                   (3U)
#define DWC_USB_GSBUSCFG0_INCR16BRSTENA_MASK                    (0x00000008U)

#define DWC_USB_GSBUSCFG0_INCR32BRSTENA_SHIFT                   (4U)
#define DWC_USB_GSBUSCFG0_INCR32BRSTENA_MASK                    (0x00000010U)

#define DWC_USB_GSBUSCFG0_INCR64BRSTENA_SHIFT                   (5U)
#define DWC_USB_GSBUSCFG0_INCR64BRSTENA_MASK                    (0x00000020U)

#define DWC_USB_GSBUSCFG0_INCR128BRSTENA_SHIFT                  (6U)
#define DWC_USB_GSBUSCFG0_INCR128BRSTENA_MASK                   (0x00000040U)

#define DWC_USB_GSBUSCFG0_INCR256BRSTENA_SHIFT                  (7U)
#define DWC_USB_GSBUSCFG0_INCR256BRSTENA_MASK                   (0x00000080U)

#define DWC_USB_GSBUSCFG0_DATBIGEND_SHIFT                       (11U)
#define DWC_USB_GSBUSCFG0_DATBIGEND_MASK                        (0x00000800U)
#define DWC_USB_GSBUSCFG0_DATBIGEND_LITTLE                       (0U)
#define DWC_USB_GSBUSCFG0_DATBIGEND_BIG                          (1U)

#define DWC_USB_GSBUSCFG0_DESCBIGEND_SHIFT                      (12U)
#define DWC_USB_GSBUSCFG0_DESCBIGEND_MASK                       (0x00001000U)
#define DWC_USB_GSBUSCFG0_DESCBIGEND_LITTLE                      (0U)
#define DWC_USB_GSBUSCFG0_DESCBIGEND_BIG                         (1U)

#define DWC_USB_GSBUSCFG0_DESWRREQINFO_SHIFT                    (16U)
#define DWC_USB_GSBUSCFG0_DESWRREQINFO_MASK                     (0x000f0000U)

#define DWC_USB_GSBUSCFG0_DATWRREQINFO_SHIFT                    (20U)
#define DWC_USB_GSBUSCFG0_DATWRREQINFO_MASK                     (0x00f00000U)

#define DWC_USB_GSBUSCFG0_DESRDREQINFO_SHIFT                    (24U)
#define DWC_USB_GSBUSCFG0_DESRDREQINFO_MASK                     (0x0f000000U)

#define DWC_USB_GSBUSCFG0_DATRDREQINFO_SHIFT                    (28U)
#define DWC_USB_GSBUSCFG0_DATRDREQINFO_MASK                     (0xf0000000U)

#define DWC_USB_GSBUSCFG1_PIPETRANSLIMIT_SHIFT                  (8U)
#define DWC_USB_GSBUSCFG1_PIPETRANSLIMIT_MASK                   (0x00000f00U)
#define DWC_USB_GSBUSCFG1_PIPETRANSLIMIT_1                       (0U)
#define DWC_USB_GSBUSCFG1_PIPETRANSLIMIT_2                       (1U)
#define DWC_USB_GSBUSCFG1_PIPETRANSLIMIT_16                      (15U)

#define DWC_USB_GSBUSCFG1_EN1KPAGE_SHIFT                        (12U)
#define DWC_USB_GSBUSCFG1_EN1KPAGE_MASK                         (0x00001000U)
#define DWC_USB_GSBUSCFG1_EN1KPAGE_DIS                           (0U)
#define DWC_USB_GSBUSCFG1_EN1KPAGE_EN                            (1U)

#define DWC_USB_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT               (16U)
#define DWC_USB_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK                (0x00ff0000U)
#define DWC_USB_GTXTHRCFG_USBMAXTXBURSTSIZE_MIN                  (1U)
#define DWC_USB_GTXTHRCFG_USBMAXTXBURSTSIZE_MAX                  (16U)
#define DWC_USB_GTXTHRCFG_USBMAXTXBURSTSIZE_DIS                  (0U)

#define DWC_USB_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT                  (29U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNTSEL_MASK                   (0x20000000U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNTSEL_DIS                     (0U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNTSEL_EN                      (1U)

#define DWC_USB_GTXTHRCFG_USBTXPKTCNT_SHIFT                     (24U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNT_MASK                      (0x0f000000U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNT_DIS                        (0U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNT_MIN                        (1U)
#define DWC_USB_GTXTHRCFG_USBTXPKTCNT_MAX                        (15U)

#define DWC_USB_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT               (19U)
#define DWC_USB_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK                (0x00f80000U)
#define DWC_USB_GRXTHRCFG_USBMAXRXBURSTSIZE_MIN                  (1U)
#define DWC_USB_GRXTHRCFG_USBMAXRXBURSTSIZE_MAX                  (16U)
#define DWC_USB_GRXTHRCFG_USBMAXRXBURSTSIZE_DIS                  (0U)

#define DWC_USB_GRXTHRCFG_USBRXPKTCNT_SHIFT                     (24U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNT_MASK                      (0x0f000000U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNT_DIS                        (0U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNT_MIN                        (1U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNT_MAX                        (15U)

#define DWC_USB_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT                  (29U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNTSEL_MASK                   (0x20000000U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNTSEL_DIS                     (0U)
#define DWC_USB_GRXTHRCFG_USBRXPKTCNTSEL_EN                      (1U)

#define DWC_USB_GCTL_DSBLCLKGTNG_SHIFT                          (0U)
#define DWC_USB_GCTL_DSBLCLKGTNG_MASK                           (0x00000001U)

#define DWC_USB_GCTL_DISSCRAMBLE_SHIFT                          (3U)
#define DWC_USB_GCTL_DISSCRAMBLE_MASK                           (0x00000008U)

#define DWC_USB_GCTL_SCALEDOWN_SHIFT                            (4U)
#define DWC_USB_GCTL_SCALEDOWN_MASK                             (0x00000030U)
#define DWC_USB_GCTL_SCALEDOWN_NONE                              (0U)
#define DWC_USB_GCTL_SCALEDOWN_1                                 (1U)
#define DWC_USB_GCTL_SCALEDOWN_2                                 (2U)
#define DWC_USB_GCTL_SCALEDOWN_3                                 (3U)

#define DWC_USB_GCTL_RAMCLKSEL_SHIFT                            (6U)
#define DWC_USB_GCTL_RAMCLKSEL_MASK                             (0x000000c0U)
#define DWC_USB_GCTL_RAMCLKSEL_BUS                               (0U)
#define DWC_USB_GCTL_RAMCLKSEL_PIPE                              (1U)
#define DWC_USB_GCTL_RAMCLKSEL_PIPE_50                           (2U)
#define DWC_USB_GCTL_RAMCLKSEL_MAC                               (3U)

#define DWC_USB_GCTL_DBGATTACH_SHIFT                            (8U)
#define DWC_USB_GCTL_DBGATTACH_MASK                             (0x00000100U)

#define DWC_USB_GCTL_CORESOFTRESET_SHIFT                        (11U)
#define DWC_USB_GCTL_CORESOFTRESET_MASK                         (0x00000800U)
#define DWC_USB_GCTL_CORESOFTRESET_NO                            (0U)
#define DWC_USB_GCTL_CORESOFTRESET_RESET                         (1U)

#define DWC_USB_GCTL_PRTCAPDIR_SHIFT                            (12U)
#define DWC_USB_GCTL_PRTCAPDIR_MASK                             (0x00003000U)
#define DWC_USB_GCTL_PRTCAPDIR_HST                               (1U)
#define DWC_USB_GCTL_PRTCAPDIR_DEV                               (2U)
#define DWC_USB_GCTL_PRTCAPDIR_DRD                               (3U)

#define DWC_USB_GCTL_FRMSCLDWN_SHIFT                            (14U)
#define DWC_USB_GCTL_FRMSCLDWN_MASK                             (0x0000c000U)
#define DWC_USB_GCTL_FRMSCLDWN_0                                 (0U)
#define DWC_USB_GCTL_FRMSCLDWN_1                                 (1U)
#define DWC_USB_GCTL_FRMSCLDWN_2                                 (2U)
#define DWC_USB_GCTL_FRMSCLDWN_3                                 (3U)

#define DWC_USB_GCTL_U2RSTECN_SHIFT                             (16U)
#define DWC_USB_GCTL_U2RSTECN_MASK                              (0x00010000U)

#define DWC_USB_GCTL_PWRDNSCALE_SHIFT                           (19U)
#define DWC_USB_GCTL_PWRDNSCALE_MASK                            (0xfff80000U)
#define DWC_USB_GCTL_PWRDNSCALE_32K_MIN                          (2U)
#define DWC_USB_GCTL_PWRDNSCALE_12M                              (750U)
#define DWC_USB_GCTL_PWRDNSCALE_13M                              (813U)
#define DWC_USB_GCTL_PWRDNSCALE_19M2                             (1200U)
#define DWC_USB_GCTL_PWRDNSCALE_24M                              (1500U)
#define DWC_USB_GCTL_PWRDNSCALE_26M                              (1625U)
#define DWC_USB_GCTL_PWRDNSCALE_38M4                             (2400U)
#define DWC_USB_GCTL_PWRDNSCALE_125M                             (7813U)

#define DWC_USB_GCTL_MASTERFILTBYPASS_SHIFT                     (18U)
#define DWC_USB_GCTL_MASTERFILTBYPASS_MASK                      (0x00040000U)

#define DWC_USB_GCTL_BYPSSETADDR_SHIFT                          (17U)
#define DWC_USB_GCTL_BYPSSETADDR_MASK                           (0x00020000U)
#define DWC_USB_GCTL_BYPSSETADDR_FUNC                            (0U)
#define DWC_USB_GCTL_BYPSSETADDR_BYPASS                          (1U)

#define DWC_USB_GCTL_L1HIBERNATIONEN_SHIFT                      (1U)
#define DWC_USB_GCTL_L1HIBERNATIONEN_MASK                       (0x00000002U)

#define DWC_USB_GCTL_DISU1U2TIMERSCALEDOWN_SHIFT                (9U)
#define DWC_USB_GCTL_DISU1U2TIMERSCALEDOWN_MASK                 (0x00000200U)
#define DWC_USB_GCTL_DISU1U2TIMERSCALEDOWN_NOTDIS                (0U)
#define DWC_USB_GCTL_DISU1U2TIMERSCALEDOWN_DIS                   (1U)

#define DWC_USB_GCTL_SOFITPSYNC_SHIFT                           (10U)
#define DWC_USB_GCTL_SOFITPSYNC_MASK                            (0x00000400U)

#define DWC_USB_GCTL_U2EXIT_LFPS_SHIFT                          (2U)
#define DWC_USB_GCTL_U2EXIT_LFPS_MASK                           (0x00000004U)
#define DWC_USB_GCTL_U2EXIT_LFPS_SHORT                           (0U)
#define DWC_USB_GCTL_U2EXIT_LFPS_LONG                            (1U)

#define DWC_USB_GSTS_CURMOD_SHIFT                               (0U)
#define DWC_USB_GSTS_CURMOD_MASK                                (0x00000003U)
#define DWC_USB_GSTS_CURMOD_DEV                                  (0U)
#define DWC_USB_GSTS_CURMOD_HOST                                 (1U)
#define DWC_USB_GSTS_CURMOD_DRD                                  (2U)

#define DWC_USB_GSTS_BUSERRADDRVLD_SHIFT                        (4U)
#define DWC_USB_GSTS_BUSERRADDRVLD_MASK                         (0x00000010U)
#define DWC_USB_GSTS_BUSERRADDRVLD_NOEVENT                       (0U)
#define DWC_USB_GSTS_BUSERRADDRVLD_SET                           (1U)
#define DWC_USB_GSTS_BUSERRADDRVLD_CLEAR                         (1U)
#define DWC_USB_GSTS_BUSERRADDRVLD_NOACTION                      (0U)

#define DWC_USB_GSTS_CBELT_SHIFT                                (20U)
#define DWC_USB_GSTS_CBELT_MASK                                 (0xfff00000U)

#define DWC_USB_GSTS_CSRTIMEOUT_SHIFT                           (5U)
#define DWC_USB_GSTS_CSRTIMEOUT_MASK                            (0x00000020U)
#define DWC_USB_GSTS_CSRTIMEOUT_NOEVENT                          (0U)
#define DWC_USB_GSTS_CSRTIMEOUT_SET                              (1U)
#define DWC_USB_GSTS_CSRTIMEOUT_CLEAR                            (1U)
#define DWC_USB_GSTS_CSRTIMEOUT_NOACTION                         (0U)

#define DWC_USB_GSTS_DEVICE_IP_SHIFT                            (6U)
#define DWC_USB_GSTS_DEVICE_IP_MASK                             (0x00000040U)
#define DWC_USB_GSTS_DEVICE_IP_NONE                              (0U)
#define DWC_USB_GSTS_DEVICE_IP_PEND                              (1U)

#define DWC_USB_GSTS_HOST_IP_SHIFT                              (7U)
#define DWC_USB_GSTS_HOST_IP_MASK                               (0x00000080U)
#define DWC_USB_GSTS_HOST_IP_NONE                                (0U)
#define DWC_USB_GSTS_HOST_IP_PEND                                (1U)

#define DWC_USB_GSTS_ADP_IP_SHIFT                               (8U)
#define DWC_USB_GSTS_ADP_IP_MASK                                (0x00000100U)

#define DWC_USB_GSTS_BC_IP_SHIFT                                (9U)
#define DWC_USB_GSTS_BC_IP_MASK                                 (0x00000200U)

#define DWC_USB_GSTS_OTG_IP_SHIFT                               (10U)
#define DWC_USB_GSTS_OTG_IP_MASK                                (0x00000400U)
#define DWC_USB_GSTS_OTG_IP_NONE                                 (0U)
#define DWC_USB_GSTS_OTG_IP_PEND                                 (1U)

#define DWC_USB_GSNPSID_SYNOPSYSID_CORE_SHIFT                   (16U)
#define DWC_USB_GSNPSID_SYNOPSYSID_CORE_MASK                    (0xffff0000U)
#define DWC_USB_GSNPSID_SYNOPSYSID_CORE_ID                       (21811U)

#define DWC_USB_GSNPSID_SYNOPSYSID_REL_SHIFT                    (0U)
#define DWC_USB_GSNPSID_SYNOPSYSID_REL_MASK                     (0x0000ffffU)
#define DWC_USB_GSNPSID_SYNOPSYSID_REL_1_83A                     (6202U)
#define DWC_USB_GSNPSID_SYNOPSYSID_REL_2_02A                     (8234U)
#define DWC_USB_GSNPSID_SYNOPSYSID_REL_2_40A                     (9226U)

#define DWC_USB_GGPIO_GPI_SHIFT                                 (0U)
#define DWC_USB_GGPIO_GPI_MASK                                  (0x0000ffffU)

#define DWC_USB_GGPIO_GPO_SHIFT                                 (16U)
#define DWC_USB_GGPIO_GPO_MASK                                  (0xffff0000U)

#define DWC_USB_GUID_USERID_SHIFT                               (0U)
#define DWC_USB_GUID_USERID_MASK                                (0xffffffffU)

#define DWC_USB_GBUSERRADDRLO_BUSERRADDRLO_SHIFT                (0U)
#define DWC_USB_GBUSERRADDRLO_BUSERRADDRLO_MASK                 (0xffffffffU)

#define DWC_USB_GBUSERRADDRHI_BUSERRADDRHI_SHIFT                (0U)
#define DWC_USB_GBUSERRADDRHI_BUSERRADDRHI_MASK                 (0xffffffffU)

#define DWC_USB_GPRTBIMAPLO_BINUM1_SHIFT                        (0U)
#define DWC_USB_GPRTBIMAPLO_BINUM1_MASK                         (0x0000000fU)

#define DWC_USB_GHWPARAMS0_DWC_USB3_MODE_SHIFT                  (0U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_MODE_MASK                   (0x00000007U)
#define DWC_USB_GHWPARAMS0_USB3_MODE_DEV                         (0U)
#define DWC_USB_GHWPARAMS0_USB3_MODE_HST                         (1U)
#define DWC_USB_GHWPARAMS0_USB3_MODE_DRD                         (2U)

#define DWC_USB_GHWPARAMS0_DWC_USB3_MBUS_TYPE_SHIFT             (3U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_MBUS_TYPE_MASK              (0x00000038U)
#define DWC_USB_GHWPARAMS0_USB3_MBUS_TYPE_AXI                    (1U)

#define DWC_USB_GHWPARAMS0_DWC_USB3_SBUS_TYPE_SHIFT             (6U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_SBUS_TYPE_MASK              (0x000000c0U)
#define DWC_USB_GHWPARAMS0_USB3_SBUS_TYPE_NATIVE                 (0U)

#define DWC_USB_GHWPARAMS0_DWC_USB3_MDWIDTH_SHIFT               (8U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_MDWIDTH_MASK                (0x0000ff00U)

#define DWC_USB_GHWPARAMS0_DWC_USB3_SDWIDTH_SHIFT               (16U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_SDWIDTH_MASK                (0x00ff0000U)

#define DWC_USB_GHWPARAMS0_DWC_USB3_AWIDTH_SHIFT                (24U)
#define DWC_USB_GHWPARAMS0_DWC_USB3_AWIDTH_MASK                 (0xff000000U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_IDWIDTH_SHIFT               (0U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_IDWIDTH_MASK                (0x00000007U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_BURSTWIDTH_SHIFT            (3U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_BURSTWIDTH_MASK             (0x00000038U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_SHIFT         (6U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_DATAINFOWIDTH_MASK          (0x000001c0U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_SHIFT           (12U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_ASPACEWIDTH_MASK            (0x00007000U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_SHIFT        (15U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_DEVICE_NUM_INT_MASK         (0x001f8000U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_NUM_RAMS_SHIFT              (21U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_NUM_RAMS_MASK               (0x00600000U)
#define DWC_USB_GHWPARAMS1_USB3_NUM_RAMS_1                       (1U)
#define DWC_USB_GHWPARAMS1_USB3_NUM_RAMS_2                       (2U)
#define DWC_USB_GHWPARAMS1_USB3_NUM_RAMS_3                       (3U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_SPRAM_TYP_SHIFT             (23U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_SPRAM_TYP_MASK              (0x00800000U)
#define DWC_USB_GHWPARAMS1_USB3_SPRAM_TYP_SP                     (1U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_EN_PWROPT_SHIFT             (24U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_EN_PWROPT_MASK              (0x03000000U)
#define DWC_USB_GHWPARAMS1_USB3_EN_PWROPT_NONE                   (0U)
#define DWC_USB_GHWPARAMS1_USB3_EN_PWROPT_CLOCK                  (1U)
#define DWC_USB_GHWPARAMS1_USB3_EN_PWROPT_CLOCK_HIBERNATION      (2U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_SHIFT     (26U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_MAC_PHY_CLKS_SYNC_MASK      (0x04000000U)
#define DWC_USB_GHWPARAMS1_USB3_MAC_PHY_CLKS_SYNC_NO             (0U)
#define DWC_USB_GHWPARAMS1_USB3_MAC_PHY_CLKS_SYNC_YES            (1U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_SHIFT     (27U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_MAC_RAM_CLKS_SYNC_MASK      (0x08000000U)
#define DWC_USB_GHWPARAMS1_USB3_MAC_RAM_CLKS_SYNC_NO             (0U)
#define DWC_USB_GHWPARAMS1_USB3_MAC_RAM_CLKS_SYNC_YES            (1U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_SHIFT     (28U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_RAM_BUS_CLKS_SYNC_MASK      (0x10000000U)
#define DWC_USB_GHWPARAMS1_USB3_RAM_BUS_CLKS_SYNC_NO             (0U)
#define DWC_USB_GHWPARAMS1_USB3_RAM_BUS_CLKS_SYNC_YES            (1U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_SHIFT       (30U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_RM_OPT_FEATURES_MASK        (0x40000000U)
#define DWC_USB_GHWPARAMS1_USB3_RM_OPT_FEATURES_NO               (0U)
#define DWC_USB_GHWPARAMS1_USB3_RM_OPT_FEATURES_YES              (1U)

#define DWC_USB_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_SHIFT          (9U)
#define DWC_USB_GHWPARAMS1_DWC_USB3_REQINFOWIDTH_MASK           (0x00000e00U)

#define DWC_USB_GHWPARAMS2_DWC_USB3_USERID_SHIFT                (0U)
#define DWC_USB_GHWPARAMS2_DWC_USB3_USERID_MASK                 (0xffffffffU)

#define DWC_USB_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_SHIFT       (0U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_SSPHY_INTERFACE_MASK        (0x00000003U)
#define DWC_USB_GHWPARAMS3_USB3_SSPHY_INTERFACE_NONE             (0U)
#define DWC_USB_GHWPARAMS3_USB3_SSPHY_INTERFACE_PIPE             (1U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_SHIFT       (2U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_HSPHY_INTERFACE_MASK        (0x0000000cU)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_INTERFACE_NONE             (0U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_INTERFACE_UTMI             (1U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_INTERFACE_ULPI             (2U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_INTERFACE_BOTH             (3U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_SHIFT       (4U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_FSPHY_INTERFACE_MASK        (0x00000030U)
#define DWC_USB_GHWPARAMS3_USB3_FSPHY_INTERFACE_NONE             (0U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH_SHIFT          (6U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_HSPHY_DWIDTH_MASK           (0x000000c0U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_DWIDTH_8                   (0U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_DWIDTH_16                  (1U)
#define DWC_USB_GHWPARAMS3_USB3_HSPHY_DWIDTH_8_16                (2U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_SHIFT  (10U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_VENDOR_CTL_INTERFACE_MASK   (0x00000400U)
#define DWC_USB_GHWPARAMS3_USB3_VENDOR_CTL_INTERFACE_NO          (0U)
#define DWC_USB_GHWPARAMS3_USB3_VENDOR_CTL_INTERFACE_VC          (1U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_SHIFT           (11U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_ULPI_CARKIT_MASK            (0x00000800U)
#define DWC_USB_GHWPARAMS3_USB3_ULPI_CARKIT_NO                   (0U)
#define DWC_USB_GHWPARAMS3_USB3_ULPI_CARKIT_VC                   (1U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_NUM_EPS_SHIFT               (12U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_NUM_EPS_MASK                (0x0003f000U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_SHIFT            (18U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_NUM_IN_EPS_MASK             (0x007c0000U)

#define DWC_USB_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_SHIFT  (23U)
#define DWC_USB_GHWPARAMS3_DWC_USB3_CACHE_TOTAL_XFER_RESOURCES_MASK  (0x7f800000U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_SHIFT  (0U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_CACHE_TRBS_PER_TRANSFER_MASK  (0x0000003fU)

#define DWC_USB_GHWPARAMS4_DWC_USB3_NUM_SS_INSTANCES_SHIFT      (17U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_NUM_SS_INSTANCES_MASK       (0x001e0000U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_SHIFT          (23U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_EN_ISOC_SUPT_MASK           (0x00800000U)
#define DWC_USB_GHWPARAMS4_USB3_EN_ISOC_SUPT_NONE                (0U)
#define DWC_USB_GHWPARAMS4_USB3_EN_ISOC_SUPT_ISO                 (1U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_SHIFT         (24U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_BMU_PTL_DEPTH_MASK          (0x0f000000U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_SHIFT         (28U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_BMU_LSP_DEPTH_MASK          (0xf0000000U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_SHIFT     (13U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_HIBER_SCRATCHBUFS_MASK      (0x0001e000U)

#define DWC_USB_GHWPARAMS4_DWC_USB3_EXT_BUFF_CTRL_SHIFT         (21U)
#define DWC_USB_GHWPARAMS4_DWC_USB3_EXT_BUFF_CTRL_MASK          (0x00200000U)
#define DWC_USB_GHWPARAMS4_USB3_EXT_BUFF_CTRL_NO_EBC             (0U)
#define DWC_USB_GHWPARAMS4_USB3_EXT_BUFF_CTRL_EBC                (1U)

#define DWC_USB_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_SHIFT       (0U)
#define DWC_USB_GHWPARAMS5_DWC_USB3_BMU_BUSGM_DEPTH_MASK        (0x0000000fU)

#define DWC_USB_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_SHIFT        (4U)
#define DWC_USB_GHWPARAMS5_DWC_USB3_RXQ_FIFO_DEPTH_MASK         (0x000003f0U)

#define DWC_USB_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_SHIFT        (10U)
#define DWC_USB_GHWPARAMS5_DWC_USB3_TXQ_FIFO_DEPTH_MASK         (0x0000fc00U)

#define DWC_USB_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_SHIFT        (16U)
#define DWC_USB_GHWPARAMS5_DWC_USB3_DWQ_FIFO_DEPTH_MASK         (0x003f0000U)

#define DWC_USB_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_SHIFT        (22U)
#define DWC_USB_GHWPARAMS5_DWC_USB3_DFQ_FIFO_DEPTH_MASK         (0x0fc00000U)

#define DWC_USB_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_SHIFT            (16U)
#define DWC_USB_GHWPARAMS6_DWC_USB3_RAM0_DEPTH_MASK             (0xffff0000U)

#define DWC_USB_GHWPARAMS6_DWC_USB3_EN_FPGA_SHIFT               (7U)
#define DWC_USB_GHWPARAMS6_DWC_USB3_EN_FPGA_MASK                (0x00000080U)

#define DWC_USB_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_SHIFT        (0U)
#define DWC_USB_GHWPARAMS6_DWC_USB3_PSQ_FIFO_DEPTH_MASK         (0x0000003fU)

#define DWC_USB_GHWPARAMS6_SRPSUPPORT_SHIFT                     (10U)
#define DWC_USB_GHWPARAMS6_SRPSUPPORT_MASK                      (0x00000400U)
#define DWC_USB_GHWPARAMS6_SRPSUPPORT_NO                         (0U)
#define DWC_USB_GHWPARAMS6_SRPSUPPORT_SUPPORT                    (1U)

#define DWC_USB_GHWPARAMS6_HNPSUPPORT_SHIFT                     (11U)
#define DWC_USB_GHWPARAMS6_HNPSUPPORT_MASK                      (0x00000800U)
#define DWC_USB_GHWPARAMS6_HNPSUPPORT_NO                         (0U)
#define DWC_USB_GHWPARAMS6_HNPSUPPORT_SUPPORT                    (1U)

#define DWC_USB_GHWPARAMS6_ADPSUPPORT_SHIFT                     (12U)
#define DWC_USB_GHWPARAMS6_ADPSUPPORT_MASK                      (0x00001000U)
#define DWC_USB_GHWPARAMS6_ADPSUPPORT_NO                         (0U)
#define DWC_USB_GHWPARAMS6_ADPSUPPORT_IMP                        (1U)

#define DWC_USB_GHWPARAMS6_OTGSSSUPPORT_SHIFT                   (13U)
#define DWC_USB_GHWPARAMS6_OTGSSSUPPORT_MASK                    (0x00002000U)
#define DWC_USB_GHWPARAMS6_OTGSSSUPPORT_NO                       (0U)
#define DWC_USB_GHWPARAMS6_OTGSSSUPPORT_YES                      (1U)

#define DWC_USB_GHWPARAMS6_BCSUPPORT_SHIFT                      (14U)
#define DWC_USB_GHWPARAMS6_BCSUPPORT_MASK                       (0x00004000U)
#define DWC_USB_GHWPARAMS6_BCSUPPORT_NO                          (0U)
#define DWC_USB_GHWPARAMS6_BCSUPPORT_IMP                         (1U)

#define DWC_USB_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT                (15U)
#define DWC_USB_GHWPARAMS6_BUSFLTRSSUPPORT_MASK                 (0x00008000U)
#define DWC_USB_GHWPARAMS6_BUSFLTRSSUPPORT_NO                    (0U)
#define DWC_USB_GHWPARAMS6_BUSFLTRSSUPPORT_IMP                   (1U)

#define DWC_USB_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_SHIFT            (0U)
#define DWC_USB_GHWPARAMS7_DWC_USB3_RAM1_DEPTH_MASK             (0x0000ffffU)

#define DWC_USB_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_SHIFT            (16U)
#define DWC_USB_GHWPARAMS7_DWC_USB3_RAM2_DEPTH_MASK             (0xffff0000U)

#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_SHIFT  (0U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_MASK   (0x000000ffU)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_TXF0    (0U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_TXF31   (31U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RXF0    (32U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RXF31   (63U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_TRQ0    (64U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_PSQ     (162U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_EQ      (161U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_DFQ     (160U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_TRQ31   (95U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RRQ0    (96U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RRQ31   (127U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RIQ0    (128U)
#define DWC_USB_GDBGFIFOSPACE_FIFOQUEUESELECT_PORTSELECT_RIQ31   (159U)

#define DWC_USB_GDBGFIFOSPACE_SPACE_AVAILABLE_SHIFT             (16U)
#define DWC_USB_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK              (0xffff0000U)

#define DWC_USB_GDBGLTSSM_TXONESZEROS_SHIFT                     (0U)
#define DWC_USB_GDBGLTSSM_TXONESZEROS_MASK                      (0x00000001U)

#define DWC_USB_GDBGLTSSM_RXTERMINATION_SHIFT                   (1U)
#define DWC_USB_GDBGLTSSM_RXTERMINATION_MASK                    (0x00000002U)

#define DWC_USB_GDBGLTSSM_TXSWING_SHIFT                         (2U)
#define DWC_USB_GDBGLTSSM_TXSWING_MASK                          (0x00000004U)

#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_SHIFT                    (3U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_MASK                     (0x00000038U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_NORM                  (0U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_WAIT1                 (2U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_P3                    (3U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_TO_P0                 (4U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_WAIT2                 (5U)
#define DWC_USB_GDBGLTSSM_LTDBCLKSTATE_CLK_TO_P3                 (1U)

#define DWC_USB_GDBGLTSSM_TXDEEMPHASIS_SHIFT                    (6U)
#define DWC_USB_GDBGLTSSM_TXDEEMPHASIS_MASK                     (0x000000c0U)

#define DWC_USB_GDBGLTSSM_RXEQTRAIN_SHIFT                       (8U)
#define DWC_USB_GDBGLTSSM_RXEQTRAIN_MASK                        (0x00000100U)

#define DWC_USB_GDBGLTSSM_POWERDOWN_SHIFT                       (9U)
#define DWC_USB_GDBGLTSSM_POWERDOWN_MASK                        (0x00000600U)

#define DWC_USB_GDBGLTSSM_TXDETRXLOOPBACK_SHIFT                 (14U)
#define DWC_USB_GDBGLTSSM_TXDETRXLOOPBACK_MASK                  (0x00004000U)

#define DWC_USB_GDBGLTSSM_RXPOLARITY_SHIFT                      (15U)
#define DWC_USB_GDBGLTSSM_RXPOLARITY_MASK                       (0x00008000U)

#define DWC_USB_GDBGLTSSM_TXELECIDLE_SHIFT                      (16U)
#define DWC_USB_GDBGLTSSM_TXELECIDLE_MASK                       (0x00010000U)

#define DWC_USB_GDBGLTSSM_ELASTICBUFFERMODE_SHIFT               (17U)
#define DWC_USB_GDBGLTSSM_ELASTICBUFFERMODE_MASK                (0x00020000U)

#define DWC_USB_GDBGLTSSM_LTDBSUBSTATE_SHIFT                    (18U)
#define DWC_USB_GDBGLTSSM_LTDBSUBSTATE_MASK                     (0x003c0000U)

#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_SHIFT                   (22U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_MASK                    (0x03c00000U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_U0                       (0U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_U1                       (1U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_U2                       (2U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_U3                       (3U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_SSDISABLED               (4U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_RXDETECT                 (5U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_SSINACTIVE               (6U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_POLLING                  (7U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_RECOVERY                 (8U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_HOTRESET                 (9U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_COMPLIANCE               (10U)
#define DWC_USB_GDBGLTSSM_LTDBLINKSTATE_LOOPBACK                 (11U)

#define DWC_USB_GDBGLTSSM_LTDBTIMEOUT_SHIFT                     (26U)
#define DWC_USB_GDBGLTSSM_LTDBTIMEOUT_MASK                      (0x04000000U)

#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_SHIFT                 (11U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_MASK                  (0x00003800U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_IDLE               (0U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_DET                (1U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_DET_3              (2U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_DLY            (3U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_A              (4U)
#define DWC_USB_GDBGLTSSM_LTDBPHYCMDSTATE_PHY_PWR_B              (5U)

#define DWC_USB_GDBGLTSSM_PORTDIRECTION_SHIFT                   (27U)
#define DWC_USB_GDBGLTSSM_PORTDIRECTION_MASK                    (0x00000000U)
#define DWC_USB_GDBGLTSSM_PORTDIRECTION_US                       (0U)
#define DWC_USB_GDBGLTSSM_PORTDIRECTION_DS                       (1U)

#define DWC_USB_GDBGLTSSM_PORTSWAPPING_SHIFT                    (28U)
#define DWC_USB_GDBGLTSSM_PORTSWAPPING_MASK                     (0x00000000U)

#define DWC_USB_GDBGLTSSM_PORTSHUTDOWN_SHIFT                    (29U)
#define DWC_USB_GDBGLTSSM_PORTSHUTDOWN_MASK                     (0x00000000U)

#define DWC_USB_GUCTL_DTFT_SHIFT                                (0U)
#define DWC_USB_GUCTL_DTFT_MASK                                 (0x000001ffU)
#define DWC_USB_GUCTL_DTFT_2US                                   (1U)
#define DWC_USB_GUCTL_DTFT_10US                                  (5U)
#define DWC_USB_GUCTL_DTFT_100US                                 (50U)
#define DWC_USB_GUCTL_DTFT_256US                                 (125U)

#define DWC_USB_GUCTL_DTCT_SHIFT                                (9U)
#define DWC_USB_GUCTL_DTCT_MASK                                 (0x00000600U)
#define DWC_USB_GUCTL_DTCT_FINE                                  (0U)
#define DWC_USB_GUCTL_DTCT_0M5                                   (1U)
#define DWC_USB_GUCTL_DTCT_1M5                                   (2U)
#define DWC_USB_GUCTL_DTCT_5MS                                   (3U)

#define DWC_USB_GUCTL_USBHSTINAUTORETRYEN_SHIFT                 (14U)
#define DWC_USB_GUCTL_USBHSTINAUTORETRYEN_MASK                  (0x00004000U)
#define DWC_USB_GUCTL_USBHSTINAUTORETRYEN_DIS                    (0U)
#define DWC_USB_GUCTL_USBHSTINAUTORETRYEN_EN                     (1U)

#define DWC_USB_GUCTL_CMDEVADDR_SHIFT                           (15U)
#define DWC_USB_GUCTL_CMDEVADDR_MASK                            (0x00008000U)
#define DWC_USB_GUCTL_CMDEVADDR_EQ                               (0U)
#define DWC_USB_GUCTL_CMDEVADDR_DIFF                             (1U)

#define DWC_USB_GUCTL_RESBWHSEPS_SHIFT                          (16U)
#define DWC_USB_GUCTL_RESBWHSEPS_MASK                           (0x00010000U)
#define DWC_USB_GUCTL_RESBWHSEPS_80                              (0U)
#define DWC_USB_GUCTL_RESBWHSEPS_85                              (1U)

#define DWC_USB_GUCTL_SPRSCTRLTRANSEN_SHIFT                     (17U)
#define DWC_USB_GUCTL_SPRSCTRLTRANSEN_MASK                      (0x00020000U)
#define DWC_USB_GUCTL_SPRSCTRLTRANSEN_DIS                        (0U)
#define DWC_USB_GUCTL_SPRSCTRLTRANSEN_EN                         (1U)

#define DWC_USB_GUCTL_PSQEXTRRESSP_SHIFT                        (18U)
#define DWC_USB_GUCTL_PSQEXTRRESSP_MASK                         (0x001c0000U)
#define DWC_USB_GUCTL_PSQEXTRRESSP_DIS                           (0U)
#define DWC_USB_GUCTL_PSQEXTRRESSP_EN                            (1U)

#define DWC_USB_GUCTL_NOEXTRDL_SHIFT                            (21U)
#define DWC_USB_GUCTL_NOEXTRDL_MASK                             (0x00200000U)
#define DWC_USB_GUCTL_NOEXTRDL_DIS                               (0U)
#define DWC_USB_GUCTL_NOEXTRDL_EN                                (1U)

#define DWC_USB_GUCTL_REFCLKPER_SHIFT                           (22U)
#define DWC_USB_GUCTL_REFCLKPER_MASK                            (0xffc00000U)

#define DWC_USB_GUCTL_INSRTEXTRFSBODL_SHIFT                     (11U)
#define DWC_USB_GUCTL_INSRTEXTRFSBODL_MASK                      (0x00000800U)
#define DWC_USB_GUCTL_INSRTEXTRFSBODL_NODELAY                    (0U)
#define DWC_USB_GUCTL_INSRTEXTRFSBODL_DELAY                      (1U)

#define DWC_USB_GUCTL_EXTCAPSUPTEN_SHIFT                        (12U)
#define DWC_USB_GUCTL_EXTCAPSUPTEN_MASK                         (0x00001000U)
#define DWC_USB_GUCTL_EXTCAPSUPTEN_DISABLED                      (0U)
#define DWC_USB_GUCTL_EXTCAPSUPTEN_ENABLED                       (1U)

#define DWC_USB_GUCTL_ENOVERLAPCHK_SHIFT                        (13U)
#define DWC_USB_GUCTL_ENOVERLAPCHK_MASK                         (0x00002000U)
#define DWC_USB_GUCTL_ENOVERLAPCHK_DISABLED                      (0U)
#define DWC_USB_GUCTL_ENOVERLAPCHK_ENABLED                       (1U)

#define DWC_USB_GPRTBIMAP_HSLO_BINUM1_SHIFT                     (0U)
#define DWC_USB_GPRTBIMAP_HSLO_BINUM1_MASK                      (0x0000000fU)

#define DWC_USB_GPRTBIMAP_FSLO_BINUM1_SHIFT                     (0U)
#define DWC_USB_GPRTBIMAP_FSLO_BINUM1_MASK                      (0x0000000fU)

#define DWC_USB_GDBGLSPMUX_EPSELECT_SHIFT                       (0U)
#define DWC_USB_GDBGLSPMUX_EPSELECT_MASK                        (0x0000000fU)

#define DWC_USB_GDBGLSPMUX_DEVSELECT_SHIFT                      (4U)
#define DWC_USB_GDBGLSPMUX_DEVSELECT_MASK                       (0x000000f0U)

#define DWC_USB_GDBGLSPMUX_HOSTSELECT_SHIFT                     (8U)
#define DWC_USB_GDBGLSPMUX_HOSTSELECT_MASK                      (0x00003f00U)

#define DWC_USB_GDBGLSPMUX_TRACEPORTMUXSEL_SHIFT                (16U)
#define DWC_USB_GDBGLSPMUX_TRACEPORTMUXSEL_MASK                 (0x003f0000U)
#define DWC_USB_GDBGLSPMUX_TRACEPORTMUXSEL_ZERO                  (63U)

#define DWC_USB_GDBGLSP_DBG_SHIFT                               (0U)
#define DWC_USB_GDBGLSP_DBG_MASK                                (0xffffffffU)

#define DWC_USB_GDBGEPINFO0_DBG_SHIFT                           (0U)
#define DWC_USB_GDBGEPINFO0_DBG_MASK                            (0xffffffffU)

#define DWC_USB_GDBGEPINFO1_DBG_SHIFT                           (0U)
#define DWC_USB_GDBGEPINFO1_DBG_MASK                            (0xffffffffU)

#define DWC_USB_GDBGLNMCC_LNMCC_BERC_SHIFT                      (0U)
#define DWC_USB_GDBGLNMCC_LNMCC_BERC_MASK                       (0x000001ffU)

#define DWC_USB_GDBGBMU_BMU_CCU_SHIFT                           (0U)
#define DWC_USB_GDBGBMU_BMU_CCU_MASK                            (0x0000000fU)

#define DWC_USB_GDBGBMU_BMU_DCU_SHIFT                           (4U)
#define DWC_USB_GDBGBMU_BMU_DCU_MASK                            (0x000000f0U)

#define DWC_USB_GDBGBMU_BMU_BCU_SHIFT                           (8U)
#define DWC_USB_GDBGBMU_BMU_BCU_MASK                            (0xffffff00U)

#define DWC_USB_GUSB2PHYCFG_TOUTCAL_SHIFT                       (0U)
#define DWC_USB_GUSB2PHYCFG_TOUTCAL_MASK                        (0x00000007U)

#define DWC_USB_GUSB2PHYCFG_PHYIF_SHIFT                         (3U)
#define DWC_USB_GUSB2PHYCFG_PHYIF_MASK                          (0x00000008U)
#define DWC_USB_GUSB2PHYCFG_PHYIF_ZERO                           (0U)
#define DWC_USB_GUSB2PHYCFG_PHYIF_ONE                            (1U)

#define DWC_USB_GUSB2PHYCFG_ULPI_UTMI_SEL_SHIFT                 (4U)
#define DWC_USB_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK                  (0x00000000U)
#define DWC_USB_GUSB2PHYCFG_ULPI_UTMI_SEL                        (0U)
#define DWC_USB_GUSB2PHYCFG_ULPI_UTMI_SEL_SEL                    (1U)

#define DWC_USB_GUSB2PHYCFG_FSINTF_SHIFT                        (5U)
#define DWC_USB_GUSB2PHYCFG_FSINTF_MASK                         (0x00000020U)

#define DWC_USB_GUSB2PHYCFG_SUSPHY_SHIFT                        (6U)
#define DWC_USB_GUSB2PHYCFG_SUSPHY_MASK                         (0x00000040U)
#define DWC_USB_GUSB2PHYCFG_SUSPHY_0                             (0U)
#define DWC_USB_GUSB2PHYCFG_SUSPHY_1                             (1U)

#define DWC_USB_GUSB2PHYCFG_PHYSEL_SHIFT                        (7U)
#define DWC_USB_GUSB2PHYCFG_PHYSEL_MASK                         (0x00000080U)

#define DWC_USB_GUSB2PHYCFG_ENBLSLPM_SHIFT                      (8U)
#define DWC_USB_GUSB2PHYCFG_ENBLSLPM_MASK                       (0x00000100U)
#define DWC_USB_GUSB2PHYCFG_ENBLSLPM_NO                          (0U)
#define DWC_USB_GUSB2PHYCFG_ENBLSLPM_YES                         (1U)

#define DWC_USB_GUSB2PHYCFG_USBTRDTIM_SHIFT                     (10U)
#define DWC_USB_GUSB2PHYCFG_USBTRDTIM_MASK                      (0x00003c00U)

#define DWC_USB_GUSB2PHYCFG_ULPIAUTORES_SHIFT                   (15U)
#define DWC_USB_GUSB2PHYCFG_ULPIAUTORES_MASK                    (0x00000000U)
#define DWC_USB_GUSB2PHYCFG_ULPIAUTORES_NO                       (0U)
#define DWC_USB_GUSB2PHYCFG_ULPIAUTORES_AUTO                     (1U)

#define DWC_USB_GUSB2PHYCFG_ULPICLKSUSM_SHIFT                   (16U)
#define DWC_USB_GUSB2PHYCFG_ULPICLKSUSM_MASK                    (0x00000000U)

#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_SHIFT                (17U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK                 (0x00000000U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_INT                   (0U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_EXT                   (1U)

#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_SHIFT          (18U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_MASK           (0x00000000U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_INT             (0U)
#define DWC_USB_GUSB2PHYCFG_ULPIEXTVBUSINDICATOR_EXT             (1U)

#define DWC_USB_GUSB2PHYCFG_PHYSOFTRST_SHIFT                    (31U)
#define DWC_USB_GUSB2PHYCFG_PHYSOFTRST_MASK                     (0x80000000U)
#define DWC_USB_GUSB2PHYCFG_PHYSOFTRST_INACTIVE                  (0U)
#define DWC_USB_GUSB2PHYCFG_PHYSOFTRST_ACTIVE                    (1U)

#define DWC_USB_GUSB2PHYCFG_UTMI_SEL_SHIFT                      (4U)
#define DWC_USB_GUSB2PHYCFG_UTMI_SEL_MASK                       (0x00000010U)
#define DWC_USB_GUSB2PHYCFG_UTMI_SEL                             (0U)
#define DWC_USB_GUSB2PHYCFG_UTMI_SEL_ULPI                        (1U)

#define DWC_USB_GUSB2PHYACC_REGDATA_SHIFT                       (0U)
#define DWC_USB_GUSB2PHYACC_REGDATA_MASK                        (0x000000ffU)

#define DWC_USB_GUSB2PHYACC_EXTREGADDR_SHIFT                    (8U)
#define DWC_USB_GUSB2PHYACC_EXTREGADDR_MASK                     (0x00003f00U)

#define DWC_USB_GUSB2PHYACC_REGADDR_SHIFT                       (16U)
#define DWC_USB_GUSB2PHYACC_REGADDR_MASK                        (0x003f0000U)

#define DWC_USB_GUSB2PHYACC_REGWR_SHIFT                         (22U)
#define DWC_USB_GUSB2PHYACC_REGWR_MASK                          (0x00400000U)
#define DWC_USB_GUSB2PHYACC_REGWR_RD                             (0U)
#define DWC_USB_GUSB2PHYACC_REGWR_WR                             (1U)

#define DWC_USB_GUSB2PHYACC_VSTSBSY_SHIFT                       (23U)
#define DWC_USB_GUSB2PHYACC_VSTSBSY_MASK                        (0x00800000U)
#define DWC_USB_GUSB2PHYACC_VSTSBSY_DONE                         (0U)
#define DWC_USB_GUSB2PHYACC_VSTSBSY_BUSY                         (1U)

#define DWC_USB_GUSB2PHYACC_VSTSDONE_SHIFT                      (24U)
#define DWC_USB_GUSB2PHYACC_VSTSDONE_MASK                       (0x01000000U)
#define DWC_USB_GUSB2PHYACC_VSTSDONE_DONE                        (1U)
#define DWC_USB_GUSB2PHYACC_VSTSDONE_NOTDONE                     (0U)

#define DWC_USB_GUSB2PHYACC_NEWREGREQ_SHIFT                     (25U)
#define DWC_USB_GUSB2PHYACC_NEWREGREQ_MASK                      (0x02000000U)
#define DWC_USB_GUSB2PHYACC_NEWREGREQ_NEW                        (1U)
#define DWC_USB_GUSB2PHYACC_NEWREGREQ_NONE                       (0U)
#define DWC_USB_GUSB2PHYACC_NEWREGREQ_ACTIVE                     (1U)
#define DWC_USB_GUSB2PHYACC_NEWREGREQ_IDLE                       (0U)

#define DWC_USB_GUSB2PHYACC_DISULPIDRVR_SHIFT                   (26U)
#define DWC_USB_GUSB2PHYACC_DISULPIDRVR_MASK                    (0x04000000U)

#define DWC_USB_GUSB3PIPECTL_ELASTICBUFFERMODE_SHIFT            (0U)
#define DWC_USB_GUSB3PIPECTL_ELASTICBUFFERMODE_MASK             (0x00000001U)

#define DWC_USB_GUSB3PIPECTL_TXDEEMPHASIS_SHIFT                 (1U)
#define DWC_USB_GUSB3PIPECTL_TXDEEMPHASIS_MASK                  (0x00000006U)

#define DWC_USB_GUSB3PIPECTL_TXMARGIN_SHIFT                     (3U)
#define DWC_USB_GUSB3PIPECTL_TXMARGIN_MASK                      (0x00000038U)

#define DWC_USB_GUSB3PIPECTL_TXSWING_SHIFT                      (6U)
#define DWC_USB_GUSB3PIPECTL_TXSWING_MASK                       (0x00000040U)

#define DWC_USB_GUSB3PIPECTL_LFPSFILT_SHIFT                     (9U)
#define DWC_USB_GUSB3PIPECTL_LFPSFILT_MASK                      (0x00000200U)

#define DWC_USB_GUSB3PIPECTL_P3P2TRANOK_SHIFT                   (11U)
#define DWC_USB_GUSB3PIPECTL_P3P2TRANOK_MASK                    (0x00000800U)
#define DWC_USB_GUSB3PIPECTL_P3P2TRANOK_NOTSET                   (0U)
#define DWC_USB_GUSB3PIPECTL_P3P2TRANOK_SET                      (1U)

#define DWC_USB_GUSB3PIPECTL_LFPSP0ALGN_SHIFT                   (12U)
#define DWC_USB_GUSB3PIPECTL_LFPSP0ALGN_MASK                    (0x00001000U)
#define DWC_USB_GUSB3PIPECTL_LFPSP0ALGN_DEF                      (0U)
#define DWC_USB_GUSB3PIPECTL_LFPSP0ALGN_ALIGN                    (1U)

#define DWC_USB_GUSB3PIPECTL_SKIPRXDET_SHIFT                    (13U)
#define DWC_USB_GUSB3PIPECTL_SKIPRXDET_MASK                     (0x00002000U)

#define DWC_USB_GUSB3PIPECTL_DATWIDTH_SHIFT                     (15U)
#define DWC_USB_GUSB3PIPECTL_DATWIDTH_MASK                      (0x00018000U)
#define DWC_USB_GUSB3PIPECTL_DATWIDTH_32                         (0U)
#define DWC_USB_GUSB3PIPECTL_DATWIDTH_16                         (1U)
#define DWC_USB_GUSB3PIPECTL_DATWIDTH_8                          (2U)

#define DWC_USB_GUSB3PIPECTL_SUSPENDEN_SHIFT                    (17U)
#define DWC_USB_GUSB3PIPECTL_SUSPENDEN_MASK                     (0x00020000U)
#define DWC_USB_GUSB3PIPECTL_SUSPENDEN_0                         (0U)
#define DWC_USB_GUSB3PIPECTL_SUSPENDEN_1                         (1U)

#define DWC_USB_GUSB3PIPECTL_ABORTRXDETINU2_SHIFT               (14U)
#define DWC_USB_GUSB3PIPECTL_ABORTRXDETINU2_MASK                (0x00004000U)
#define DWC_USB_GUSB3PIPECTL_ABORTRXDETINU2_NO_ABORT             (0U)
#define DWC_USB_GUSB3PIPECTL_ABORTRXDETINU2_ABORT                (1U)

#define DWC_USB_GUSB3PIPECTL_DELAYP0TOP1P2P3_SHIFT              (18U)
#define DWC_USB_GUSB3PIPECTL_DELAYP0TOP1P2P3_MASK               (0x00040000U)
#define DWC_USB_GUSB3PIPECTL_DELAYP0TOP1P2P3_DIS                 (0U)
#define DWC_USB_GUSB3PIPECTL_DELAYP0TOP1P2P3_EN                  (1U)

#define DWC_USB_GUSB3PIPECTL_PHYSOFTRST_SHIFT                   (31U)
#define DWC_USB_GUSB3PIPECTL_PHYSOFTRST_MASK                    (0x80000000U)
#define DWC_USB_GUSB3PIPECTL_PHYSOFTRST_INACTIVE                 (0U)
#define DWC_USB_GUSB3PIPECTL_PHYSOFTRST_ACTIVE                   (1U)

#define DWC_USB_GUSB3PIPECTL_DISRXDETU3RXDET_SHIFT              (22U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETU3RXDET_MASK               (0x00400000U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETU3RXDET_AUTO                (0U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETU3RXDET_MANUAL              (1U)

#define DWC_USB_GUSB3PIPECTL_STARTRXDETU3RXDET_SHIFT            (23U)
#define DWC_USB_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK             (0x00800000U)
#define DWC_USB_GUSB3PIPECTL_STARTRXDETU3RXDET_NOOP              (0U)
#define DWC_USB_GUSB3PIPECTL_STARTRXDETU3RXDET_DETECT            (1U)

#define DWC_USB_GUSB3PIPECTL_P1P2P3DELAY_SHIFT                  (19U)
#define DWC_USB_GUSB3PIPECTL_P1P2P3DELAY_MASK                   (0x00380000U)

#define DWC_USB_GUSB3PIPECTL_REQUEST_P1P2P3_SHIFT               (24U)
#define DWC_USB_GUSB3PIPECTL_REQUEST_P1P2P3_MASK                (0x01000000U)
#define DWC_USB_GUSB3PIPECTL_REQUEST_P1P2P3_NONE                 (0U)
#define DWC_USB_GUSB3PIPECTL_REQUEST_P1P2P3_ALWAYS               (1U)

#define DWC_USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_SHIFT        (25U)
#define DWC_USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK         (0x02000000U)
#define DWC_USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_DEFAULT       (0U)
#define DWC_USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_ENHANCED      (1U)

#define DWC_USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_SHIFT          (26U)
#define DWC_USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK           (0x04000000U)
#define DWC_USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_DEFAULT         (0U)
#define DWC_USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_500             (1U)

#define DWC_USB_GUSB3PIPECTL_UX_EXIT_IN_PX_SHIFT                (27U)
#define DWC_USB_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK                 (0x08000000U)
#define DWC_USB_GUSB3PIPECTL_UX_EXIT_IN_PX_DEFAULT               (0U)
#define DWC_USB_GUSB3PIPECTL_UX_EXIT_IN_PX_WA                    (1U)

#define DWC_USB_GUSB3PIPECTL_P3EXSIGP2_SHIFT                    (10U)
#define DWC_USB_GUSB3PIPECTL_P3EXSIGP2_MASK                     (0x00000400U)
#define DWC_USB_GUSB3PIPECTL_P3EXSIGP2_DEFAULT                   (0U)
#define DWC_USB_GUSB3PIPECTL_P3EXSIGP2_P2                        (1U)

#define DWC_USB_GUSB3PIPECTL_DISRXDETP3_SHIFT                   (28U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETP3_MASK                    (0x10000000U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETP3_P3                       (0U)
#define DWC_USB_GUSB3PIPECTL_DISRXDETP3_P2                       (1U)

#define DWC_USB_GUSB3PIPECTL_U2SSINACTP3OK_SHIFT                (29U)
#define DWC_USB_GUSB3PIPECTL_U2SSINACTP3OK_MASK                 (0x20000000U)
#define DWC_USB_GUSB3PIPECTL_U2SSINACTP3OK_P2                    (0U)
#define DWC_USB_GUSB3PIPECTL_U2SSINACTP3OK_P3                    (1U)


#define DWC_USB_GUSB3PIPECTL_HSTPRTCMPL_SHIFT                   (30U)
#define DWC_USB_GUSB3PIPECTL_HSTPRTCMPL_MASK                    (0x40000000U)
#define DWC_USB_GUSB3PIPECTL_HSTPRTCMPL_0                       (0U)
#define DWC_USB_GUSB3PIPECTL_HSTPRTCMPL_1                       (1U)


#define DWC_USB_GUSB3PIPECTL_RXDETPOLLINGDELAYDIS_SHIFT         (8U)
#define DWC_USB_GUSB3PIPECTL_RXDETPOLLINGDELAYDIS_MASK          (0x00000100U)
#define DWC_USB_GUSB3PIPECTL_RXDETPOLLINGDELAYDIS_ENABLED        (0U)
#define DWC_USB_GUSB3PIPECTL_RXDETPOLLINGDELAYDIS_DISABLED       (1U)

#define DWC_USB_GTXFIFOSIZ0_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ0_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ0_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ0_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ0_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ0_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ0_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ0_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ1_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ1_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ1_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ1_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ1_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ1_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ1_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ1_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ2_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ2_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ2_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ2_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ2_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ2_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ2_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ2_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ3_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ3_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ3_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ3_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ3_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ3_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ3_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ3_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ4_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ4_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ4_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ4_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ4_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ4_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ4_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ4_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ5_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ5_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ5_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ5_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ5_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ5_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ5_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ5_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ6_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ6_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ6_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ6_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ6_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ6_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ6_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ6_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ7_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ7_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ7_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ7_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ7_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ7_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ7_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ7_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ8_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ8_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ8_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ8_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ8_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ8_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ8_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ8_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ9_TXFDEP_SHIFT                        (0U)
#define DWC_USB_GTXFIFOSIZ9_TXFDEP_MASK                         (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ9_TXFDEP_MIN                           (32U)
#define DWC_USB_GTXFIFOSIZ9_TXFDEP_MAX                           (5888U)

#define DWC_USB_GTXFIFOSIZ9_TXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GTXFIFOSIZ9_TXFSTADDR_MASK                      (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ9_TXFSTADDR_MIN                        (0U)
#define DWC_USB_GTXFIFOSIZ9_TXFSTADDR_MAX                        (5856U)

#define DWC_USB_GTXFIFOSIZ10_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ10_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ10_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ10_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ10_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ10_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ10_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ10_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GTXFIFOSIZ11_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ11_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ11_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ11_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ11_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ11_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ11_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ11_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GTXFIFOSIZ12_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ12_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ12_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ12_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ12_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ12_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ12_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ12_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GTXFIFOSIZ13_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ13_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ13_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ13_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ13_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ13_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ13_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ13_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GTXFIFOSIZ14_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ14_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ14_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ14_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ14_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ14_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ14_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ14_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GTXFIFOSIZ15_TXFDEP_SHIFT                       (0U)
#define DWC_USB_GTXFIFOSIZ15_TXFDEP_MASK                        (0x0000ffffU)
#define DWC_USB_GTXFIFOSIZ15_TXFDEP_MIN                          (32U)
#define DWC_USB_GTXFIFOSIZ15_TXFDEP_MAX                          (5888U)

#define DWC_USB_GTXFIFOSIZ15_TXFSTADDR_SHIFT                    (16U)
#define DWC_USB_GTXFIFOSIZ15_TXFSTADDR_MASK                     (0xffff0000U)
#define DWC_USB_GTXFIFOSIZ15_TXFSTADDR_MIN                       (0U)
#define DWC_USB_GTXFIFOSIZ15_TXFSTADDR_MAX                       (5856U)

#define DWC_USB_GRXFIFOSIZ0_RXFDEP_SHIFT                        (0U)
#define DWC_USB_GRXFIFOSIZ0_RXFDEP_MASK                         (0x0000ffffU)

#define DWC_USB_GRXFIFOSIZ0_RXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GRXFIFOSIZ0_RXFSTADDR_MASK                      (0xffff0000U)

#define DWC_USB_GRXFIFOSIZ1_RXFDEP_SHIFT                        (0U)
#define DWC_USB_GRXFIFOSIZ1_RXFDEP_MASK                         (0x0000ffffU)

#define DWC_USB_GRXFIFOSIZ1_RXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GRXFIFOSIZ1_RXFSTADDR_MASK                      (0xffff0000U)

#define DWC_USB_GRXFIFOSIZ2_RXFDEP_SHIFT                        (0U)
#define DWC_USB_GRXFIFOSIZ2_RXFDEP_MASK                         (0x0000ffffU)

#define DWC_USB_GRXFIFOSIZ2_RXFSTADDR_SHIFT                     (16U)
#define DWC_USB_GRXFIFOSIZ2_RXFSTADDR_MASK                      (0xffff0000U)

#define DWC_USB_GEVNTADRLO_EVNTADRLO_SHIFT                      (0U)
#define DWC_USB_GEVNTADRLO_EVNTADRLO_MASK                       (0xffffffffU)

#define DWC_USB_GEVNTADRHI_EVNTADRHI_SHIFT                      (0U)
#define DWC_USB_GEVNTADRHI_EVNTADRHI_MASK                       (0xffffffffU)

#define DWC_USB_GEVNTSIZ_EVTSIZ_SHIFT                           (0U)
#define DWC_USB_GEVNTSIZ_EVTSIZ_MASK                            (0x0000ffffU)

#define DWC_USB_GEVNTSIZ_EVNTINTRPTMASK_SHIFT                   (31U)
#define DWC_USB_GEVNTSIZ_EVNTINTRPTMASK_MASK                    (0x80000000U)

#define DWC_USB_GEVNTCOUNT_EVNTCOUNT_SHIFT                      (0U)
#define DWC_USB_GEVNTCOUNT_EVNTCOUNT_MASK                       (0x0000ffffU)

#define DWC_USB_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_SHIFT     (0U)
#define DWC_USB_GHWPARAMS8_DWC_USB3_DCACHE_DEPTH_INFO_MASK      (0xffffffffU)

#define DWC_USB_GHWPARAMS9_GHWPARAMS9_SHIFT                     (0U)
#define DWC_USB_GHWPARAMS9_GHWPARAMS9_MASK                      (0xffffffffU)

#define DWC_USB_GTXFIFOPRIDEV_EP_PRIO_SHIFT                     (0U)
#define DWC_USB_GTXFIFOPRIDEV_EP_PRIO_MASK                      (0x0000ffffU)

#define DWC_USB_GTXFIFOPRIHST_FSLS_PRIO_SHIFT                   (0U)
#define DWC_USB_GTXFIFOPRIHST_FSLS_PRIO_MASK                    (0x00000001U)
#define DWC_USB_GTXFIFOPRIHST_FSLS_PRIO_LOW                      (0U)
#define DWC_USB_GTXFIFOPRIHST_FSLS_PRIO_HIGH                     (1U)

#define DWC_USB_GTXFIFOPRIHST_HS_PRIO_SHIFT                     (1U)
#define DWC_USB_GTXFIFOPRIHST_HS_PRIO_MASK                      (0x00000002U)
#define DWC_USB_GTXFIFOPRIHST_HS_PRIO_LOW                        (0U)
#define DWC_USB_GTXFIFOPRIHST_HS_PRIO_HIGH                       (1U)

#define DWC_USB_GTXFIFOPRIHST_SS_PRIO_SHIFT                     (2U)
#define DWC_USB_GTXFIFOPRIHST_SS_PRIO_MASK                      (0x00000004U)
#define DWC_USB_GTXFIFOPRIHST_SS_PRIO_LOW                        (0U)
#define DWC_USB_GTXFIFOPRIHST_SS_PRIO_HIGH                       (1U)

#define DWC_USB_GRXFIFOPRIHST_FSLS_PRIO_SHIFT                   (0U)
#define DWC_USB_GRXFIFOPRIHST_FSLS_PRIO_MASK                    (0x00000001U)
#define DWC_USB_GRXFIFOPRIHST_FSLS_PRIO_LOW                      (0U)
#define DWC_USB_GRXFIFOPRIHST_FSLS_PRIO_HIGH                     (1U)

#define DWC_USB_GRXFIFOPRIHST_HS_PRIO_SHIFT                     (1U)
#define DWC_USB_GRXFIFOPRIHST_HS_PRIO_MASK                      (0x00000002U)
#define DWC_USB_GRXFIFOPRIHST_HS_PRIO_LOW                        (0U)
#define DWC_USB_GRXFIFOPRIHST_HS_PRIO_HIGH                       (1U)

#define DWC_USB_GRXFIFOPRIHST_SS_PRIO_SHIFT                     (2U)
#define DWC_USB_GRXFIFOPRIHST_SS_PRIO_MASK                      (0x00000004U)
#define DWC_USB_GRXFIFOPRIHST_SS_PRIO_LOW                        (0U)
#define DWC_USB_GRXFIFOPRIHST_SS_PRIO_HIGH                       (1U)

#define DWC_USB_GFIFOPRIDBC_DBC_PRIO_SHIFT                      (0U)
#define DWC_USB_GFIFOPRIDBC_DBC_PRIO_MASK                       (0x00000003U)
#define DWC_USB_GFIFOPRIDBC_DBC_PRIO_LOW                         (0U)
#define DWC_USB_GFIFOPRIDBC_DBC_PRIO_NORMAL                      (1U)
#define DWC_USB_GFIFOPRIDBC_DBC_PRIO_HIGH                        (2U)

#define DWC_USB_GDMAHLRATIO_TX_PRIO_RATIO_SHIFT                 (0U)
#define DWC_USB_GDMAHLRATIO_TX_PRIO_RATIO_MASK                  (0x0000001fU)

#define DWC_USB_GDMAHLRATIO_RX_PRIO_RATIO_SHIFT                 (8U)
#define DWC_USB_GDMAHLRATIO_RX_PRIO_RATIO_MASK                  (0x00001f00U)

#define DWC_USB_DCFG_DEVSPD_SHIFT                               (0U)
#define DWC_USB_DCFG_DEVSPD_MASK                                (0x00000007U)
#define DWC_USB_DCFG_DEVSPD_HS                                   (0U)
#define DWC_USB_DCFG_DEVSPD_FS                                   (1U)
#define DWC_USB_DCFG_DEVSPD_SS                                   (4U)
#define DWC_USB_DCFG_DEVSPD_LS_SERIAL                            (2U)
#define DWC_USB_DCFG_DEVSPD_FS_SERIAL                            (3U)

#define DWC_USB_DCFG_DEVADDR_SHIFT                              (3U)
#define DWC_USB_DCFG_DEVADDR_MASK                               (0x000003f8U)
#define DWC_USB_DCFG_DEVADDR_DEF                                 (0U)

#define DWC_USB_DCFG_PERFRINT_SHIFT                             (10U)
#define DWC_USB_DCFG_PERFRINT_MASK                              (0x00000c00U)
#define DWC_USB_DCFG_PERFRINT_80                                 (0U)
#define DWC_USB_DCFG_PERFRINT_85                                 (1U)
#define DWC_USB_DCFG_PERFRINT_90                                 (2U)
#define DWC_USB_DCFG_PERFRINT_95                                 (3U)

#define DWC_USB_DCFG_INTRNUM_SHIFT                              (12U)
#define DWC_USB_DCFG_INTRNUM_MASK                               (0x0001f000U)

#define DWC_USB_DCFG_NUMP_SHIFT                                 (17U)
#define DWC_USB_DCFG_NUMP_MASK                                  (0x003e0000U)

#define DWC_USB_DCFG_LPMCAP_SHIFT                               (22U)
#define DWC_USB_DCFG_LPMCAP_MASK                                (0x00400000U)
#define DWC_USB_DCFG_LPMCAP_NO                                   (0U)
#define DWC_USB_DCFG_LPMCAP_YES                                  (1U)

#define DWC_USB_DCFG_IGNORESTREAMPP_SHIFT                       (23U)
#define DWC_USB_DCFG_IGNORESTREAMPP_MASK                        (0x00800000U)
#define DWC_USB_DCFG_IGNORESTREAMPP_NOCHANGE                     (0U)
#define DWC_USB_DCFG_IGNORESTREAMPP_IGNORE                       (1U)

#define DWC_USB_DCTL_TSTCTL_SHIFT                               (1U)
#define DWC_USB_DCTL_TSTCTL_MASK                                (0x0000001eU)
#define DWC_USB_DCTL_TSTCTL_0                                    (0U)
#define DWC_USB_DCTL_TSTCTL_1                                    (1U)
#define DWC_USB_DCTL_TSTCTL_2                                    (2U)
#define DWC_USB_DCTL_TSTCTL_3                                    (3U)
#define DWC_USB_DCTL_TSTCTL_4                                    (4U)
#define DWC_USB_DCTL_TSTCTL_5                                    (5U)

#define DWC_USB_DCTL_ULSTCHNGREQ_SHIFT                          (5U)
#define DWC_USB_DCTL_ULSTCHNGREQ_MASK                           (0x000001e0U)
#define DWC_USB_DCTL_ULSTCHNGREQ_NOOP                            (0U)
#define DWC_USB_DCTL_ULSTCHNGREQ_DIS                             (4U)
#define DWC_USB_DCTL_ULSTCHNGREQ_RXDET                           (5U)
#define DWC_USB_DCTL_ULSTCHNGREQ_INACT                           (6U)
#define DWC_USB_DCTL_ULSTCHNGREQ_REC                             (8U)
#define DWC_USB_DCTL_ULSTCHNGREQ_COMP                            (10U)
#define DWC_USB_DCTL_ULSTCHNGREQ_LOOP                            (11U)

#define DWC_USB_DCTL_ACCEPTU1ENA_SHIFT                          (9U)
#define DWC_USB_DCTL_ACCEPTU1ENA_MASK                           (0x00000200U)
#define DWC_USB_DCTL_ACCEPTU1ENA_NO                              (0U)
#define DWC_USB_DCTL_ACCEPTU1ENA_YES                             (1U)

#define DWC_USB_DCTL_INITU1ENA_SHIFT                            (10U)
#define DWC_USB_DCTL_INITU1ENA_MASK                             (0x00000400U)
#define DWC_USB_DCTL_INITU1ENA_NO                                (0U)
#define DWC_USB_DCTL_INITU1ENA_YES                               (1U)

#define DWC_USB_DCTL_ACCEPTU2ENA_SHIFT                          (11U)
#define DWC_USB_DCTL_ACCEPTU2ENA_MASK                           (0x00000800U)
#define DWC_USB_DCTL_ACCEPTU2ENA_NO                              (0U)
#define DWC_USB_DCTL_ACCEPTU2ENA_YES                             (1U)

#define DWC_USB_DCTL_INITU2ENA_SHIFT                            (12U)
#define DWC_USB_DCTL_INITU2ENA_MASK                             (0x00001000U)
#define DWC_USB_DCTL_INITU2ENA_NEWENUM1                          (0U)
#define DWC_USB_DCTL_INITU2ENA_NEWENUM2                          (1U)

#define DWC_USB_DCTL_LPM_NYET_THRES_SHIFT                       (20U)
#define DWC_USB_DCTL_LPM_NYET_THRES_MASK                        (0x00f00000U)
#define DWC_USB_DCTL_LPM_NYET_THRES_CAN                          (0U)
#define DWC_USB_DCTL_LPM_NYET_THRES_ACK                          (1U)

#define DWC_USB_DCTL_HIRDTHRES_TIME_SHIFT                       (24U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_MASK                        (0x0f000000U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_0                            (0U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_1                            (1U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_2                            (2U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_3                            (3U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_4                            (4U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_5                            (5U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_6                            (6U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_7                            (7U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_8                            (8U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_9                            (9U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_10                           (10U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_11                           (11U)
#define DWC_USB_DCTL_HIRDTHRES_TIME_12                           (12U)

#define DWC_USB_DCTL_CSFTRST_SHIFT                              (30U)
#define DWC_USB_DCTL_CSFTRST_MASK                               (0x40000000U)
#define DWC_USB_DCTL_CSFTRST_IDLE                                (0U)
#define DWC_USB_DCTL_CSFTRST_ACTIVE                              (1U)
#define DWC_USB_DCTL_CSFTRST_RESET                               (1U)

#define DWC_USB_DCTL_RUNSTOP_SHIFT                              (31U)
#define DWC_USB_DCTL_RUNSTOP_MASK                               (0x80000000U)
#define DWC_USB_DCTL_RUNSTOP_STOP                                (0U)
#define DWC_USB_DCTL_RUNSTOP_START                               (1U)

#define DWC_USB_DCTL_HIRDTHRES_4_SHIFT                          (28U)
#define DWC_USB_DCTL_HIRDTHRES_4_MASK                           (0x10000000U)

#define DWC_USB_DCTL_CSS_SHIFT                                  (16U)
#define DWC_USB_DCTL_CSS_MASK                                   (0x00010000U)
#define DWC_USB_DCTL_CSS_SAVE                                    (0U)
#define DWC_USB_DCTL_CSS_NOACTION                                (1U)

#define DWC_USB_DCTL_CRS_SHIFT                                  (17U)
#define DWC_USB_DCTL_CRS_MASK                                   (0x00020000U)
#define DWC_USB_DCTL_CRS_RESTORE                                 (0U)
#define DWC_USB_DCTL_CRS_NOACTION                                (1U)

#define DWC_USB_DCTL_L1HIBERNATIONEN_SHIFT                      (18U)
#define DWC_USB_DCTL_L1HIBERNATIONEN_MASK                       (0x00040000U)

#define DWC_USB_DCTL_KEEPCONNECT_SHIFT                          (19U)
#define DWC_USB_DCTL_KEEPCONNECT_MASK                           (0x00080000U)

#define DWC_USB_DEVTEN_DISCONNEVTEN_SHIFT                       (0U)
#define DWC_USB_DEVTEN_DISCONNEVTEN_MASK                        (0x00000001U)

#define DWC_USB_DEVTEN_USBRSTEN_SHIFT                           (1U)
#define DWC_USB_DEVTEN_USBRSTEN_MASK                            (0x00000002U)

#define DWC_USB_DEVTEN_CONNECTDONEEN_SHIFT                      (2U)
#define DWC_USB_DEVTEN_CONNECTDONEEN_MASK                       (0x00000004U)

#define DWC_USB_DEVTEN_ULSTCNGEN_SHIFT                          (3U)
#define DWC_USB_DEVTEN_ULSTCNGEN_MASK                           (0x00000008U)

#define DWC_USB_DEVTEN_WKUPEVTEN_SHIFT                          (4U)
#define DWC_USB_DEVTEN_WKUPEVTEN_MASK                           (0x00000010U)

#define DWC_USB_DEVTEN_U3L2L1SUSPEN_SHIFT                       (6U)
#define DWC_USB_DEVTEN_U3L2L1SUSPEN_MASK                        (0x00000040U)

#define DWC_USB_DEVTEN_SOFEN_SHIFT                              (7U)
#define DWC_USB_DEVTEN_SOFEN_MASK                               (0x00000080U)

#define DWC_USB_DEVTEN_ERRTICERREN_SHIFT                        (9U)
#define DWC_USB_DEVTEN_ERRTICERREN_MASK                         (0x00000200U)

#define DWC_USB_DEVTEN_CMDCMPLTEN_SHIFT                         (10U)
#define DWC_USB_DEVTEN_CMDCMPLTEN_MASK                          (0x00000400U)

#define DWC_USB_DEVTEN_EVNTOVERFLOWEN_SHIFT                     (11U)
#define DWC_USB_DEVTEN_EVNTOVERFLOWEN_MASK                      (0x00000800U)

#define DWC_USB_DEVTEN_VNDRDEVTSTRCVEDEN_SHIFT                  (12U)
#define DWC_USB_DEVTEN_VNDRDEVTSTRCVEDEN_MASK                   (0x00001000U)

#define DWC_USB_DEVTEN_INACTTIMEOUTRCVEDEN_SHIFT                (13U)
#define DWC_USB_DEVTEN_INACTTIMEOUTRCVEDEN_MASK                 (0x00002000U)

#define DWC_USB_DEVTEN_HIBERNATIONREQEVTEN_SHIFT                (5U)
#define DWC_USB_DEVTEN_HIBERNATIONREQEVTEN_MASK                 (0x00000020U)

#define DWC_USB_DSTS_CONNECTSPD_SHIFT                           (0U)
#define DWC_USB_DSTS_CONNECTSPD_MASK                            (0x00000007U)
#define DWC_USB_DSTS_CONNECTSPD_HS                               (0U)
#define DWC_USB_DSTS_CONNECTSPD_FS                               (1U)
#define DWC_USB_DSTS_CONNECTSPD_SS                               (4U)
#define DWC_USB_DSTS_CONNECTSPD_LS_SERIAL                        (2U)
#define DWC_USB_DSTS_CONNECTSPD_FS_SERIAL                        (3U)

#define DWC_USB_DSTS_SOFFN_SHIFT                                (3U)
#define DWC_USB_DSTS_SOFFN_MASK                                 (0x0001fff8U)

#define DWC_USB_DSTS_RXFIFOEMPTY_SHIFT                          (17U)
#define DWC_USB_DSTS_RXFIFOEMPTY_MASK                           (0x00020000U)
#define DWC_USB_DSTS_RXFIFOEMPTY_NOTEMPTY                        (0U)
#define DWC_USB_DSTS_RXFIFOEMPTY_EMPTY                           (1U)

#define DWC_USB_DSTS_USBLNKST_SHIFT                             (18U)
#define DWC_USB_DSTS_USBLNKST_MASK                              (0x003c0000U)
#define DWC_USB_DSTS_USBLNKST_0                                  (0U)
#define DWC_USB_DSTS_USBLNKST_1                                  (1U)
#define DWC_USB_DSTS_USBLNKST_2                                  (2U)
#define DWC_USB_DSTS_USBLNKST_3                                  (3U)
#define DWC_USB_DSTS_USBLNKST_4                                  (4U)
#define DWC_USB_DSTS_USBLNKST_5                                  (5U)
#define DWC_USB_DSTS_USBLNKST_6                                  (6U)
#define DWC_USB_DSTS_USBLNKST_7                                  (7U)
#define DWC_USB_DSTS_USBLNKST_8                                  (8U)
#define DWC_USB_DSTS_USBLNKST_9                                  (9U)
#define DWC_USB_DSTS_USBLNKST_10                                 (10U)
#define DWC_USB_DSTS_USBLNKST_11                                 (11U)
#define DWC_USB_DSTS_USBLNKST_14                                 (14U)
#define DWC_USB_DSTS_USBLNKST_15                                 (15U)

#define DWC_USB_DSTS_DEVCTRLHLT_SHIFT                           (22U)
#define DWC_USB_DSTS_DEVCTRLHLT_MASK                            (0x00400000U)

#define DWC_USB_DSTS_COREIDLE_SHIFT                             (23U)
#define DWC_USB_DSTS_COREIDLE_MASK                              (0x00800000U)
#define DWC_USB_DSTS_COREIDLE_IDLE                               (1U)
#define DWC_USB_DSTS_COREIDLE_ACTIVE                             (0U)

#define DWC_USB_DSTS_SSS_SHIFT                                  (24U)
#define DWC_USB_DSTS_SSS_MASK                                   (0x01000000U)
#define DWC_USB_DSTS_SSS_IDLE                                    (0U)
#define DWC_USB_DSTS_SSS_SAVING                                  (1U)

#define DWC_USB_DSTS_RSS_SHIFT                                  (25U)
#define DWC_USB_DSTS_RSS_MASK                                   (0x02000000U)
#define DWC_USB_DSTS_RSS_IDLE                                    (0U)
#define DWC_USB_DSTS_RSS_RESTORING                               (1U)

#define DWC_USB_DSTS_SRE_SHIFT                                  (28U)
#define DWC_USB_DSTS_SRE_MASK                                   (0x10000000U)

#define DWC_USB_DSTS_DCNRD_SHIFT                                (29U)
#define DWC_USB_DSTS_DCNRD_MASK                                 (0x20000000U)
#define DWC_USB_DSTS_DCNRD_WAIT                                  (1U)
#define DWC_USB_DSTS_DCNRD_RDY                                   (0U)

#define DWC_USB_DGCMDPAR_PARAMETER_SHIFT                        (0U)
#define DWC_USB_DGCMDPAR_PARAMETER_MASK                         (0xffffffffU)

#define DWC_USB_DGCMD_CMDTYP_SHIFT                              (0U)
#define DWC_USB_DGCMD_CMDTYP_MASK                               (0x000000ffU)
#define DWC_USB_DGCMD_CMDTYP_1                                   (1U)
#define DWC_USB_DGCMD_CMDTYP_2                                   (2U)
#define DWC_USB_DGCMD_CMDTYP_3                                   (3U)
#define DWC_USB_DGCMD_CMDTYP_9                                   (9U)
#define DWC_USB_DGCMD_CMDTYP_10                                  (10U)
#define DWC_USB_DGCMD_CMDTYP_12                                  (12U)
#define DWC_USB_DGCMD_CMDTYP_16                                  (16U)
#define DWC_USB_DGCMD_CMDTYP_6                                   (6U)

#define DWC_USB_DGCMD_CMDIOC_SHIFT                              (8U)
#define DWC_USB_DGCMD_CMDIOC_MASK                               (0x00000100U)
#define DWC_USB_DGCMD_CMDIOC_IOC                                 (1U)

#define DWC_USB_DGCMD_CMDACT_SHIFT                              (10U)
#define DWC_USB_DGCMD_CMDACT_MASK                               (0x00000400U)
#define DWC_USB_DGCMD_CMDACT_IDLE                                (0U)
#define DWC_USB_DGCMD_CMDACT_ACTIVE                              (1U)
#define DWC_USB_DGCMD_CMDACT_START                               (1U)

#define DWC_USB_DGCMD_CMDSTS_SHIFT                              (15U)
#define DWC_USB_DGCMD_CMDSTS_MASK                               (0x00008000U)
#define DWC_USB_DGCMD_CMDSTS_NONE                                (0U)
#define DWC_USB_DGCMD_CMDSTS_NEWENUM2                            (1U)

#define DWC_USB_DALEPENA_USBACTEP0_OUT_SHIFT                    (0U)
#define DWC_USB_DALEPENA_USBACTEP0_OUT_MASK                     (0x00000001U)

#define DWC_USB_DALEPENA_USBACTEP0_IN_SHIFT                     (1U)
#define DWC_USB_DALEPENA_USBACTEP0_IN_MASK                      (0x00000002U)

#define DWC_USB_DALEPENA_USBACTEP1_OUT_SHIFT                    (2U)
#define DWC_USB_DALEPENA_USBACTEP1_OUT_MASK                     (0x00000004U)

#define DWC_USB_DALEPENA_USBACTEP1_IN_SHIFT                     (3U)
#define DWC_USB_DALEPENA_USBACTEP1_IN_MASK                      (0x00000008U)

#define DWC_USB_DALEPENA_USBACTEP2_OUT_SHIFT                    (4U)
#define DWC_USB_DALEPENA_USBACTEP2_OUT_MASK                     (0x00000010U)

#define DWC_USB_DALEPENA_USBACTEP2_IN_SHIFT                     (5U)
#define DWC_USB_DALEPENA_USBACTEP2_IN_MASK                      (0x00000020U)

#define DWC_USB_DALEPENA_USBACTEP3_OUT_SHIFT                    (6U)
#define DWC_USB_DALEPENA_USBACTEP3_OUT_MASK                     (0x00000040U)

#define DWC_USB_DALEPENA_USBACTEP3_IN_SHIFT                     (7U)
#define DWC_USB_DALEPENA_USBACTEP3_IN_MASK                      (0x00000080U)

#define DWC_USB_DALEPENA_USBACTEP4_OUT_SHIFT                    (8U)
#define DWC_USB_DALEPENA_USBACTEP4_OUT_MASK                     (0x00000100U)

#define DWC_USB_DALEPENA_USBACTEP4_IN_SHIFT                     (9U)
#define DWC_USB_DALEPENA_USBACTEP4_IN_MASK                      (0x00000200U)

#define DWC_USB_DALEPENA_USBACTEP5_OUT_SHIFT                    (10U)
#define DWC_USB_DALEPENA_USBACTEP5_OUT_MASK                     (0x00000400U)

#define DWC_USB_DALEPENA_USBACTEP5_IN_SHIFT                     (11U)
#define DWC_USB_DALEPENA_USBACTEP5_IN_MASK                      (0x00000800U)

#define DWC_USB_DALEPENA_USBACTEP6_OUT_SHIFT                    (12U)
#define DWC_USB_DALEPENA_USBACTEP6_OUT_MASK                     (0x00001000U)

#define DWC_USB_DALEPENA_USBACTEP6_IN_SHIFT                     (13U)
#define DWC_USB_DALEPENA_USBACTEP6_IN_MASK                      (0x00002000U)

#define DWC_USB_DALEPENA_USBACTEP7_OUT_SHIFT                    (14U)
#define DWC_USB_DALEPENA_USBACTEP7_OUT_MASK                     (0x00004000U)

#define DWC_USB_DALEPENA_USBACTEP7_IN_SHIFT                     (15U)
#define DWC_USB_DALEPENA_USBACTEP7_IN_MASK                      (0x00008000U)

#define DWC_USB_DALEPENA_USBACTEP8_OUT_SHIFT                    (16U)
#define DWC_USB_DALEPENA_USBACTEP8_OUT_MASK                     (0x00010000U)

#define DWC_USB_DALEPENA_USBACTEP8_IN_SHIFT                     (17U)
#define DWC_USB_DALEPENA_USBACTEP8_IN_MASK                      (0x00020000U)

#define DWC_USB_DALEPENA_USBACTEP9_OUT_SHIFT                    (18U)
#define DWC_USB_DALEPENA_USBACTEP9_OUT_MASK                     (0x00040000U)

#define DWC_USB_DALEPENA_USBACTEP9_IN_SHIFT                     (19U)
#define DWC_USB_DALEPENA_USBACTEP9_IN_MASK                      (0x00080000U)

#define DWC_USB_DALEPENA_USBACTEP10_OUT_SHIFT                   (20U)
#define DWC_USB_DALEPENA_USBACTEP10_OUT_MASK                    (0x00100000U)

#define DWC_USB_DALEPENA_USBACTEP10_IN_SHIFT                    (21U)
#define DWC_USB_DALEPENA_USBACTEP10_IN_MASK                     (0x00200000U)

#define DWC_USB_DALEPENA_USBACTEP11_OUT_SHIFT                   (22U)
#define DWC_USB_DALEPENA_USBACTEP11_OUT_MASK                    (0x00400000U)

#define DWC_USB_DALEPENA_USBACTEP11_IN_SHIFT                    (23U)
#define DWC_USB_DALEPENA_USBACTEP11_IN_MASK                     (0x00800000U)

#define DWC_USB_DALEPENA_USBACTEP12_OUT_SHIFT                   (24U)
#define DWC_USB_DALEPENA_USBACTEP12_OUT_MASK                    (0x01000000U)

#define DWC_USB_DALEPENA_USBACTEP12_IN_SHIFT                    (25U)
#define DWC_USB_DALEPENA_USBACTEP12_IN_MASK                     (0x02000000U)

#define DWC_USB_DALEPENA_USBACTEP13_OUT_SHIFT                   (26U)
#define DWC_USB_DALEPENA_USBACTEP13_OUT_MASK                    (0x04000000U)

#define DWC_USB_DALEPENA_USBACTEP13_IN_SHIFT                    (27U)
#define DWC_USB_DALEPENA_USBACTEP13_IN_MASK                     (0x08000000U)

#define DWC_USB_DALEPENA_USBACTEP14_OUT_SHIFT                   (28U)
#define DWC_USB_DALEPENA_USBACTEP14_OUT_MASK                    (0x10000000U)

#define DWC_USB_DALEPENA_USBACTEP14_IN_SHIFT                    (29U)
#define DWC_USB_DALEPENA_USBACTEP14_IN_MASK                     (0x20000000U)

#define DWC_USB_DALEPENA_USBACTEP15_OUT_SHIFT                   (30U)
#define DWC_USB_DALEPENA_USBACTEP15_OUT_MASK                    (0x40000000U)

#define DWC_USB_DALEPENA_USBACTEP15_IN_SHIFT                    (31U)
#define DWC_USB_DALEPENA_USBACTEP15_IN_MASK                     (0x80000000U)

#define DWC_USB_OEVT_DEVICEMODE_SHIFT                           (31U)
#define DWC_USB_OEVT_DEVICEMODE_MASK                            (0x80000000U)
#define DWC_USB_OEVT_DEVICEMODE_A                                (0U)
#define DWC_USB_OEVT_DEVICEMODE_B                                (1U)

#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_SHIFT                  (24U)
#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_MASK                   (0x01000000U)
#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_NOEVT                   (0U)
#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_EVT                     (1U)
#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_CLR                     (1U)
#define DWC_USB_OEVT_OTGCONIDSTSCHNGEVNT_NOOP                    (0U)

#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_SHIFT                (16U)
#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_MASK                 (0x00010000U)
#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_NOEVT                 (0U)
#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_EVT                   (1U)
#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_CLR                   (1U)
#define DWC_USB_OEVT_OTGADEVSESSENDDETEVNT_NOOP                  (0U)

#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_SHIFT                    (17U)
#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_MASK                     (0x00020000U)
#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_NOEVT                     (0U)
#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_EVT                       (1U)
#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_CLR                       (1U)
#define DWC_USB_OEVT_OTGADEVSRPDETEVNT_NOOP                      (0U)

#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_SHIFT                (18U)
#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_MASK                 (0x00040000U)
#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_NOEVT                 (0U)
#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_EVT                   (1U)
#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_CLR                   (1U)
#define DWC_USB_OEVT_OTGADEVHNPCHNGDETEVNT_NOOP                  (0U)

#define DWC_USB_OEVT_OTGADEVHOSTEVNT_SHIFT                      (19U)
#define DWC_USB_OEVT_OTGADEVHOSTEVNT_MASK                       (0x00080000U)
#define DWC_USB_OEVT_OTGADEVHOSTEVNT_NOEVT                       (0U)
#define DWC_USB_OEVT_OTGADEVHOSTEVNT_EVT                         (1U)
#define DWC_USB_OEVT_OTGADEVHOSTEVNT_CLR                         (1U)
#define DWC_USB_OEVT_OTGADEVHOSTEVNT_NOOP                        (0U)

#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_SHIFT                  (20U)
#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_MASK                   (0x00100000U)
#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_NOEVT                   (0U)
#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_EVT                     (1U)
#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_CLR                     (1U)
#define DWC_USB_OEVT_OTGADEVBHOSTENDEVNT_NOOP                    (0U)

#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_SHIFT                  (8U)
#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_MASK                   (0x00000100U)
#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_NOEVT                   (0U)
#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_EVT                     (1U)
#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_CLR                     (1U)
#define DWC_USB_OEVT_OTGBDEVVBUSCHNGEVNT_NOOP                    (0U)

#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_SHIFT                (9U)
#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_MASK                 (0x00000200U)
#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_NOEVT                 (0U)
#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_EVT                   (1U)
#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_CLR                   (1U)
#define DWC_USB_OEVT_OTGBDEVSESSVLDDETEVNT_NOOP                  (0U)

#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_SHIFT                   (10U)
#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_MASK                    (0x00000400U)
#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_NOEVT                    (0U)
#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_EVT                      (1U)
#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_CLR                      (1U)
#define DWC_USB_OEVT_OTGBDEVHNPCHNGEVNT_NOOP                     (0U)

#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_SHIFT                   (11U)
#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_MASK                    (0x00000800U)
#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_NOEVT                    (0U)
#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_EVT                      (1U)
#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_CLR                      (1U)
#define DWC_USB_OEVT_OTGBDEVHOSTENDEVNT_NOOP                     (0U)

#define DWC_USB_OEVT_OEVTERROR_SHIFT                            (0U)
#define DWC_USB_OEVT_OEVTERROR_MASK                             (0x00000001U)
#define DWC_USB_OEVT_OEVTERROR_NOEVT                             (0U)
#define DWC_USB_OEVT_OEVTERROR_EVT                               (1U)
#define DWC_USB_OEVT_OEVTERROR_CLR                               (1U)
#define DWC_USB_OEVT_OEVTERROR_NOOP                              (0U)

#define DWC_USB_OEVT_SESREQSTS_SHIFT                            (1U)
#define DWC_USB_OEVT_SESREQSTS_MASK                             (0x00000002U)
#define DWC_USB_OEVT_SESREQSTS_NOSRP                             (0U)
#define DWC_USB_OEVT_SESREQSTS_SRP                               (1U)

#define DWC_USB_OEVT_HSTNEGSTS_SHIFT                            (2U)
#define DWC_USB_OEVT_HSTNEGSTS_MASK                             (0x00000004U)
#define DWC_USB_OEVT_HSTNEGSTS_FAILURE                           (0U)
#define DWC_USB_OEVT_HSTNEGSTS_SUCCESS                           (1U)

#define DWC_USB_OEVT_BSESVLD_SHIFT                              (3U)
#define DWC_USB_OEVT_BSESVLD_MASK                               (0x00000008U)
#define DWC_USB_OEVT_BSESVLD_INVALID                             (0U)
#define DWC_USB_OEVT_BSESVLD_VALID                               (1U)

#define DWC_USB_OEVT_OTGADEVIDLEEVNT_SHIFT                      (21U)
#define DWC_USB_OEVT_OTGADEVIDLEEVNT_MASK                       (0x00200000U)
#define DWC_USB_OEVT_OTGADEVIDLEEVNT_NOEVT                       (0U)
#define DWC_USB_OEVT_OTGADEVIDLEEVNT_EVT                         (1U)
#define DWC_USB_OEVT_OTGADEVIDLEEVNT_CLR                         (1U)
#define DWC_USB_OEVT_OTGADEVIDLEEVNT_NOOP                        (0U)

#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_SHIFT                     (23U)
#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_MASK                      (0x00800000U)
#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_NOEVT                      (0U)
#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_EVT                        (1U)
#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_CLR                        (1U)
#define DWC_USB_OEVT_HRRCONFNOTIFEVNT_NOOP                       (0U)

#define DWC_USB_OEVT_HRRINITNOTIFEVNT_SHIFT                     (22U)
#define DWC_USB_OEVT_HRRINITNOTIFEVNT_MASK                      (0x00400000U)
#define DWC_USB_OEVT_HRRINITNOTIFEVNT_NOEVT                      (0U)
#define DWC_USB_OEVT_HRRINITNOTIFEVNT_EVT                        (1U)
#define DWC_USB_OEVT_HRRINITNOTIFEVNT_CLR                        (1U)
#define DWC_USB_OEVT_HRRINITNOTIFEVNT_NOOP                       (0U)

#define DWC_USB_OEVTEN_OTGCONIDSTSCHNGEVNTEN_SHIFT              (24U)
#define DWC_USB_OEVTEN_OTGCONIDSTSCHNGEVNTEN_MASK               (0x01000000U)
#define DWC_USB_OEVTEN_OTGCONIDSTSCHNGEVNTEN_DIS                 (0U)
#define DWC_USB_OEVTEN_OTGCONIDSTSCHNGEVNTEN_EN                  (1U)

#define DWC_USB_OEVTEN_OTGADEVSESSENDDETEVNTEN_SHIFT            (16U)
#define DWC_USB_OEVTEN_OTGADEVSESSENDDETEVNTEN_MASK             (0x00010000U)
#define DWC_USB_OEVTEN_OTGADEVSESSENDDETEVNTEN_DIS               (0U)
#define DWC_USB_OEVTEN_OTGADEVSESSENDDETEVNTEN_EN                (1U)

#define DWC_USB_OEVTEN_OTGADEVSRPDETEVNTEN_SHIFT                (17U)
#define DWC_USB_OEVTEN_OTGADEVSRPDETEVNTEN_MASK                 (0x00020000U)
#define DWC_USB_OEVTEN_OTGADEVSRPDETEVNTEN_DIS                   (0U)
#define DWC_USB_OEVTEN_OTGADEVSRPDETEVNTEN_EN                    (1U)

#define DWC_USB_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_SHIFT            (18U)
#define DWC_USB_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_MASK             (0x00040000U)
#define DWC_USB_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_DIS               (0U)
#define DWC_USB_OEVTEN_OTGADEVHNPCHNGDETEVNTEN_EN                (1U)

#define DWC_USB_OEVTEN_OTGADEVHOSTEVNTEN_SHIFT                  (19U)
#define DWC_USB_OEVTEN_OTGADEVHOSTEVNTEN_MASK                   (0x00080000U)
#define DWC_USB_OEVTEN_OTGADEVHOSTEVNTEN_DIS                     (0U)
#define DWC_USB_OEVTEN_OTGADEVHOSTEVNTEN_EN                      (1U)

#define DWC_USB_OEVTEN_OTGADEVBHOSTENDEVNTEN_SHIFT              (20U)
#define DWC_USB_OEVTEN_OTGADEVBHOSTENDEVNTEN_MASK               (0x00100000U)
#define DWC_USB_OEVTEN_OTGADEVBHOSTENDEVNTEN_DIS                 (0U)
#define DWC_USB_OEVTEN_OTGADEVBHOSTENDEVNTEN_EN                  (1U)

#define DWC_USB_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_SHIFT              (8U)
#define DWC_USB_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_MASK               (0x00000100U)
#define DWC_USB_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_DIS                 (0U)
#define DWC_USB_OEVTEN_OTGBDEVVBUSCHNGEVNTEN_EN                  (1U)

#define DWC_USB_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_SHIFT            (9U)
#define DWC_USB_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_MASK             (0x00000200U)
#define DWC_USB_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_DIS               (0U)
#define DWC_USB_OEVTEN_OTGBDEVSESSVLDDETEVNTEN_EN                (1U)

#define DWC_USB_OEVTEN_OTGBDEVHNPCHNGEVNTEN_SHIFT               (10U)
#define DWC_USB_OEVTEN_OTGBDEVHNPCHNGEVNTEN_MASK                (0x00000400U)
#define DWC_USB_OEVTEN_OTGBDEVHNPCHNGEVNTEN_DIS                  (0U)
#define DWC_USB_OEVTEN_OTGBDEVHNPCHNGEVNTEN_EN                   (1U)

#define DWC_USB_OEVTEN_OTGBDEVHOSTENDEVNTEN_SHIFT               (11U)
#define DWC_USB_OEVTEN_OTGBDEVHOSTENDEVNTEN_MASK                (0x00000800U)
#define DWC_USB_OEVTEN_OTGBDEVHOSTENDEVNTEN_DIS                  (0U)
#define DWC_USB_OEVTEN_OTGBDEVHOSTENDEVNTEN_EN                   (1U)

#define DWC_USB_OEVTEN_OTGADEVIDLEEVNTEN_SHIFT                  (21U)
#define DWC_USB_OEVTEN_OTGADEVIDLEEVNTEN_MASK                   (0x00200000U)
#define DWC_USB_OEVTEN_OTGADEVIDLEEVNTEN_DIS                     (0U)
#define DWC_USB_OEVTEN_OTGADEVIDLEEVNTEN_EN                      (1U)

#define DWC_USB_OEVTEN_HRRINITNOTIFEVNTEN_SHIFT                 (22U)
#define DWC_USB_OEVTEN_HRRINITNOTIFEVNTEN_MASK                  (0x00400000U)
#define DWC_USB_OEVTEN_HRRINITNOTIFEVNTEN_DIS                    (0U)
#define DWC_USB_OEVTEN_HRRINITNOTIFEVNTEN_EN                     (1U)

#define DWC_USB_OEVTEN_HRRCONFNOTIFEVNTEN_SHIFT                 (23U)
#define DWC_USB_OEVTEN_HRRCONFNOTIFEVNTEN_MASK                  (0x00800000U)
#define DWC_USB_OEVTEN_HRRCONFNOTIFEVNTEN_DIS                    (0U)
#define DWC_USB_OEVTEN_HRRCONFNOTIFEVNTEN_EN                     (1U)

#define DWC_USB_OSTS_CONIDSTS_SHIFT                             (0U)
#define DWC_USB_OSTS_CONIDSTS_MASK                              (0x00000001U)
#define DWC_USB_OSTS_CONIDSTS_A                                  (0U)
#define DWC_USB_OSTS_CONIDSTS_B                                  (1U)

#define DWC_USB_OSTS_VBUSVLD_SHIFT                              (1U)
#define DWC_USB_OSTS_VBUSVLD_MASK                               (0x00000002U)
#define DWC_USB_OSTS_VBUSVLD_NO                                  (0U)
#define DWC_USB_OSTS_VBUSVLD_YES                                 (1U)

#define DWC_USB_OSTS_BSESVLD_SHIFT                              (2U)
#define DWC_USB_OSTS_BSESVLD_MASK                               (0x00000004U)
#define DWC_USB_OSTS_BSESVLD_NO                                  (0U)
#define DWC_USB_OSTS_BSESVLD_YES                                 (1U)

#define DWC_USB_OSTS_OTGSTATE_SHIFT                             (8U)
#define DWC_USB_OSTS_OTGSTATE_MASK                              (0x00000f00U)
#define DWC_USB_OSTS_OTGSTATE_0                                  (0U)
#define DWC_USB_OSTS_OTGSTATE_1                                  (1U)
#define DWC_USB_OSTS_OTGSTATE_2                                  (2U)
#define DWC_USB_OSTS_OTGSTATE_3                                  (3U)
#define DWC_USB_OSTS_OTGSTATE_4                                  (4U)
#define DWC_USB_OSTS_OTGSTATE_5                                  (5U)
#define DWC_USB_OSTS_OTGSTATE_6                                  (6U)
#define DWC_USB_OSTS_OTGSTATE_15                                 (7U)
#define DWC_USB_OSTS_OTGSTATE_7                                  (8U)
#define DWC_USB_OSTS_OTGSTATE_8                                  (9U)
#define DWC_USB_OSTS_OTGSTATE_9                                  (10U)
#define DWC_USB_OSTS_OTGSTATE_10                                 (11U)
#define DWC_USB_OSTS_OTGSTATE_11                                 (12U)
#define DWC_USB_OSTS_OTGSTATE_12                                 (13U)
#define DWC_USB_OSTS_OTGSTATE_13                                 (14U)
#define DWC_USB_OSTS_OTGSTATE_14                                 (15U)

#define DWC_USB_OSTS_XHCIPRTPOWER_SHIFT                         (3U)
#define DWC_USB_OSTS_XHCIPRTPOWER_MASK                          (0x00000008U)

#define DWC_USB_OSTS_PERIPHERALSTATE_SHIFT                      (4U)
#define DWC_USB_OSTS_PERIPHERALSTATE_MASK                       (0x00000010U)
#define DWC_USB_OSTS_PERIPHERALSTATE_HOST                        (0U)
#define DWC_USB_OSTS_PERIPHERALSTATE_PERIPH                      (1U)

#define DWC_USB_OCFG_SRPCAP_SHIFT                               (0U)
#define DWC_USB_OCFG_SRPCAP_MASK                                (0x00000001U)
#define DWC_USB_OCFG_SRPCAP_NO                                   (0U)
#define DWC_USB_OCFG_SRPCAP_YES                                  (1U)

#define DWC_USB_OCFG_HNPCAP_SHIFT                               (1U)
#define DWC_USB_OCFG_HNPCAP_MASK                                (0x00000002U)
#define DWC_USB_OCFG_HNPCAP_NO                                   (0U)
#define DWC_USB_OCFG_HNPCAP_YES                                  (1U)

#define DWC_USB_OCFG_OTGVERSION_SHIFT                           (2U)
#define DWC_USB_OCFG_OTGVERSION_MASK                            (0x00000004U)

#define DWC_USB_OCFG_OTGSFTRSTMSK_SHIFT                         (3U)
#define DWC_USB_OCFG_OTGSFTRSTMSK_MASK                          (0x00000008U)
#define DWC_USB_OCFG_OTGSFTRSTMSK_DEFAULT                        (0U)
#define DWC_USB_OCFG_OTGSFTRSTMSK                                (1U)

#define DWC_USB_OCTL_SESREQ_SHIFT                               (3U)
#define DWC_USB_OCTL_SESREQ_MASK                                (0x00000008U)
#define DWC_USB_OCTL_SESREQ_SRP                                  (1U)
#define DWC_USB_OCTL_SESREQ_NOOP                                 (0U)
#define DWC_USB_OCTL_SESREQ_ZERO                                 (0U)

#define DWC_USB_OCTL_HNPREQ_SHIFT                               (4U)
#define DWC_USB_OCTL_HNPREQ_MASK                                (0x00000010U)
#define DWC_USB_OCTL_HNPREQ_ONGOING                              (1U)
#define DWC_USB_OCTL_HNPREQ_DONE                                 (0U)

#define DWC_USB_OCTL_PRTPWRCTL_SHIFT                            (5U)
#define DWC_USB_OCTL_PRTPWRCTL_MASK                             (0x00000020U)
#define DWC_USB_OCTL_PRTPWRCTL_REQ                               (1U)
#define DWC_USB_OCTL_PRTPWRCTL_ON                                (1U)
#define DWC_USB_OCTL_PRTPWRCTL_OFF                               (0U)
#define DWC_USB_OCTL_PRTPWRCTL_SWOFF                             (0U)

#define DWC_USB_OCTL_DEVSETHNPEN_SHIFT                          (1U)
#define DWC_USB_OCTL_DEVSETHNPEN_MASK                           (0x00000002U)
#define DWC_USB_OCTL_DEVSETHNPEN_DIS                             (0U)
#define DWC_USB_OCTL_DEVSETHNPEN_EN                              (1U)

#define DWC_USB_OCTL_HSTSETHNPEN_SHIFT                          (0U)
#define DWC_USB_OCTL_HSTSETHNPEN_MASK                           (0x00000001U)
#define DWC_USB_OCTL_HSTSETHNPEN_DIS                             (0U)
#define DWC_USB_OCTL_HSTSETHNPEN_EN                              (1U)

#define DWC_USB_OCTL_TERMSELDLPULSE_SHIFT                       (2U)
#define DWC_USB_OCTL_TERMSELDLPULSE_MASK                        (0x00000004U)
#define DWC_USB_OCTL_TERMSELDLPULSE_NEWENUM1                     (0U)
#define DWC_USB_OCTL_TERMSELDLPULSE_NEWENUM2                     (1U)

#define DWC_USB_OCTL_PERIMODE_SHIFT                             (6U)
#define DWC_USB_OCTL_PERIMODE_MASK                              (0x00000040U)
#define DWC_USB_OCTL_PERIMODE_NO                                 (0U)
#define DWC_USB_OCTL_PERIMODE_YES                                (1U)

#define DWC_USB_OCTL_OTG3_GOERR_SHIFT                           (7U)
#define DWC_USB_OCTL_OTG3_GOERR_MASK                            (0x00000080U)
#define DWC_USB_OCTL_OTG3_GOERR_GO                               (1U)
#define DWC_USB_OCTL_OTG3_GOERR_PENDING                          (1U)
#define DWC_USB_OCTL_OTG3_GOERR_NOOP                             (0U)

#define DWC_USB_ADPCFG_PRBDSCHG_SHIFT                           (26U)
#define DWC_USB_ADPCFG_PRBDSCHG_MASK                            (0x0c000000U)

#define DWC_USB_ADPCFG_PRBDELTA_SHIFT                           (28U)
#define DWC_USB_ADPCFG_PRBDELTA_MASK                            (0x30000000U)

#define DWC_USB_ADPCFG_PRBPER_SHIFT                             (30U)
#define DWC_USB_ADPCFG_PRBPER_MASK                              (0xc0000000U)

#define DWC_USB_ADPCTL_WB_SHIFT                                 (24U)
#define DWC_USB_ADPCTL_WB_MASK                                  (0x01000000U)

#define DWC_USB_ADPCTL_ADPRES_SHIFT                             (25U)
#define DWC_USB_ADPCTL_ADPRES_MASK                              (0x02000000U)

#define DWC_USB_ADPCTL_ADPEN_SHIFT                              (26U)
#define DWC_USB_ADPCTL_ADPEN_MASK                               (0x04000000U)

#define DWC_USB_ADPCTL_ENASNS_SHIFT                             (27U)
#define DWC_USB_ADPCTL_ENASNS_MASK                              (0x08000000U)

#define DWC_USB_ADPCTL_ENAPRB_SHIFT                             (28U)
#define DWC_USB_ADPCTL_ENAPRB_MASK                              (0x10000000U)

#define DWC_USB_ADPEVT_RTIM_SHIFT                               (0U)
#define DWC_USB_ADPEVT_RTIM_MASK                                (0x000007ffU)

#define DWC_USB_ADPEVT_ADPRSTCMPLTEVNT_SHIFT                    (25U)
#define DWC_USB_ADPEVT_ADPRSTCMPLTEVNT_MASK                     (0x02000000U)

#define DWC_USB_ADPEVT_ADPTMOUTEVNT_SHIFT                       (26U)
#define DWC_USB_ADPEVT_ADPTMOUTEVNT_MASK                        (0x04000000U)

#define DWC_USB_ADPEVT_ADPSNSEVNT_SHIFT                         (27U)
#define DWC_USB_ADPEVT_ADPSNSEVNT_MASK                          (0x08000000U)

#define DWC_USB_ADPEVT_ADPPRBEVNT_SHIFT                         (28U)
#define DWC_USB_ADPEVT_ADPPRBEVNT_MASK                          (0x10000000U)

#define DWC_USB_ADPEVTEN_ADPRSTCMPLTEVNTEN_SHIFT                (25U)
#define DWC_USB_ADPEVTEN_ADPRSTCMPLTEVNTEN_MASK                 (0x02000000U)

#define DWC_USB_ADPEVTEN_ADPTMOUTEVNTEN_SHIFT                   (26U)
#define DWC_USB_ADPEVTEN_ADPTMOUTEVNTEN_MASK                    (0x04000000U)

#define DWC_USB_ADPEVTEN_ADPSNSEVNTEN_SHIFT                     (27U)
#define DWC_USB_ADPEVTEN_ADPSNSEVNTEN_MASK                      (0x08000000U)

#define DWC_USB_ADPEVTEN_ADPPRBEVNTEN_SHIFT                     (28U)
#define DWC_USB_ADPEVTEN_ADPPRBEVNTEN_MASK                      (0x10000000U)

#define DWC_USB_BCFG_CHIRP_EN_SHIFT                             (0U)
#define DWC_USB_BCFG_CHIRP_EN_MASK                              (0x00000001U)

#define DWC_USB_BCFG_IDDIG_SEL_SHIFT                            (1U)
#define DWC_USB_BCFG_IDDIG_SEL_MASK                             (0x00000002U)

#define DWC_USB_BCEVT_MULTVALIDBC_SHIFT                         (0U)
#define DWC_USB_BCEVT_MULTVALIDBC_MASK                          (0x0000001fU)

#define DWC_USB_BCEVT_MV_CHNGEVNT_SHIFT                         (24U)
#define DWC_USB_BCEVT_MV_CHNGEVNT_MASK                          (0x01000000U)

#define DWC_USB_BCEVTEN_MV_CHNGEVNTENA_SHIFT                    (24U)
#define DWC_USB_BCEVTEN_MV_CHNGEVNTENA_MASK                     (0x01000000U)

#define DWC_USB_DEPCMDPAR2_0_PARAMETER2_SHIFT                   (0U)
#define DWC_USB_DEPCMDPAR2_0_PARAMETER2_MASK                    (0xffffffffU)

#define DWC_USB_DEPCMDPAR1_0_PARAMETER1_SHIFT                   (0U)
#define DWC_USB_DEPCMDPAR1_0_PARAMETER1_MASK                    (0xffffffffU)

#define DWC_USB_DEPCMDPAR0_0_PARAMETER0_SHIFT                   (0U)
#define DWC_USB_DEPCMDPAR0_0_PARAMETER0_MASK                    (0xffffffffU)

#define DWC_USB_DEPCMD_0_CMDTYP_SHIFT                           (0U)
#define DWC_USB_DEPCMD_0_CMDTYP_MASK                            (0x0000000fU)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPCFG                           (1U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPXFERCFG                       (2U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPGETDSEQ                       (3U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPSETSTALL                      (4U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPCSTALL                        (5U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPSTRTXFER                      (6U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPUPDXFER                       (7U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPENDXFER                       (8U)
#define DWC_USB_DEPCMD_0_CMDTYP_DEPSTARTCFG                      (9U)

#define DWC_USB_DEPCMD_0_CMDIOC_SHIFT                           (8U)
#define DWC_USB_DEPCMD_0_CMDIOC_MASK                            (0x00000100U)
#define DWC_USB_DEPCMD_0_CMDIOC_NO                               (0U)
#define DWC_USB_DEPCMD_0_CMDIOC_IRQ                              (1U)

#define DWC_USB_DEPCMD_0_CMDACT_SHIFT                           (10U)
#define DWC_USB_DEPCMD_0_CMDACT_MASK                            (0x00000400U)
#define DWC_USB_DEPCMD_0_CMDACT_DONE                             (0U)
#define DWC_USB_DEPCMD_0_CMDACT_ACTIVE                           (1U)
#define DWC_USB_DEPCMD_0_CMDACT_EXE                              (1U)

#define DWC_USB_DEPCMD_0_HIPRI_FORCERM_SHIFT                    (11U)
#define DWC_USB_DEPCMD_0_HIPRI_FORCERM_MASK                     (0x00000800U)
#define DWC_USB_DEPCMD_0_HIPRI_FORCERM_WR0                       (0U)
#define DWC_USB_DEPCMD_0_HIPRI_FORCERM_WR1                       (1U)

#define DWC_USB_DEPCMD_0_CMDSTS_SHIFT                           (12U)
#define DWC_USB_DEPCMD_0_CMDSTS_MASK                            (0x0000f000U)

#define DWC_USB_DEPCMD_0_CMDPARAM_EVTPARAM_SHIFT                (16U)
#define DWC_USB_DEPCMD_0_CMDPARAM_EVTPARAM_MASK                 (0xffff0000U)

#ifdef __cplusplus
}
#endif
#endif /* PDK__HW_DWC_USB_H */
