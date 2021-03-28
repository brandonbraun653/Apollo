/*
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
 * 
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
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <stdint.h>

#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
#include <ti/csl/cslr_icss.h>
#include <ti/csl/hw_types.h>

#include "ti/drv/icss_emac/icss_emacDrv.h"
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>
#ifdef SOC_AM572x
#include "ti/drv/icss_emac/soc/am572x/icss_emacSoc.c"
#include <ti/drv/pruss/soc/am572x/pruicss_soc.c>
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>

#endif

#ifdef SOC_AM574x
#include "ti/drv/icss_emac/soc/am574x/icss_emacSoc.c"
#include <ti/drv/pruss/soc/am574x/pruicss_soc.c>
#include <ti/csl/soc/am574x/src/csl_device_xbar.h>
#endif

#ifdef SOC_AM571x
#include "ti/drv/icss_emac/soc/am571x/icss_emacSoc.c"
#include <ti/drv/pruss/soc/am571x/pruicss_soc.c>
#include <ti/csl/soc/am571x/src/csl_device_xbar.h>
#endif

#include "hw_ctrl_core_pad_io.h"
#include "icss_emac_startup.h"
#include "tiemac_pruss_intc_mapping.h"

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_rtc.h>
#include <ti/csl/csl_rtcAux.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_armGic.h>
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/src/ip/arm_gic/V1/cslr_arm_gic_distr.h>

#include <ti/csl/src/ip/gpio/V1/gpio_v2.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"

#define PKT_TX_COUNT 5

#define SWITCH_DEFAULT_MDIOBUSFREQ                          (2200000u)
#define SWITCH_DEFAULT_MDIOCLOCKFREQ                        (200000000)

#define MDIO_LINKSEL_ENABLE            1
#define MDIO_LINKSEL_DISABLE           0
static int phyCount = 0;

PRUICSS_Handle pruIcssHandle;
ICSS_EmacHandle emachandle;
uint32_t packetRcvd_port0 = 0;
uint32_t totalPktRcvd = 0;

extern CSL_ArmGicDistIntrf distrIntrf;
extern CSL_ArmGicCpuIntrf gCpuIntrf;

CSL_ArmGicIntrParams_t gIcssEmacIntrParams;
CSL_ArmGicIntrParams_t gIcssEmacIntrParamsLink;

uint32_t pktReceived = 0;
uint32_t totalPktsRcvd = 0;

PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;

uint8_t lclMac[6];

/* DO NOT CHANGE test_pkt UNLESS TEST_PKT_SIZE IS UPDATED */
#define TEST_PKT_SIZE       42
static const uint8_t test_pkt[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02
};

uint8_t packet_array[256] = {0};



#define PULLUDENABLE_ENABLE         (0U)
#define PULLUDENABLE_DISABLE        (1U)
#define PULLTYPESELECT_PULL_UP      (1U)
#define PULLTYPESELECT_PULL_DOWN    (0U)
#define INPUTENABLE_ENABLE          (1U)
#define INPUTENABLE_DISABLE         (0U)
#define SLEWCONTROL_FAST_SLEW       (0U)
#define SLEWCONTROL_SLOW_SLEW       (1U)
#define WAKEUPENABLE_ENABLE         (1U)
#define WAKEUPENABLE_DISABLE        (0U)

typedef struct {
    uint32_t pin_num;
    uint8_t  muxmode;
    uint8_t  pullud_enable;
    uint8_t  pull_typeselect;
    uint8_t  input_enable;
    uint8_t  slewcontrol;
    uint8_t  wakeup_enable;
}pad_config_t;





#define PRUSS_INSTANCE_IN_USE 2



void pruss_iep_PinMux(uint8_t prussn);
void pruss_iep_Initialization(uint8_t prussn);
void pruss_iep_MemFill(uint32_t StartAddress, uint32_t Length , uint16_t Pattern);
void pruss_iep_MDIOInitialization(uint8_t prussn);

typedef struct GPIO_INFO {
  uint32_t instance;
  uint32_t pin;
  uint32_t pinMux;
  uint32_t baseAddr;

}GPIO_INFO;
GPIO_INFO PhyResetInfo[4], PhyIntInfo[4];


static unsigned char prussIcssInstance = PRUSS_INSTANCE_IN_USE;



void Delay(uint32_t delay)
{
    volatile uint32_t delay1 = delay*10;
    while (delay1--) ;
}


/***********************************************************************/
/* local functions declaration                                         */
/***********************************************************************/
//void PowerGPIO();
/***********************************************************************/
/* function definitions                                                 */
/***********************************************************************/

void cntrl_core_pad_configuration(uint32_t baseAdd, pad_config_t *pad_config)
{
    uint32_t reg_val;

    //PlatformUnlockMMR();
    reg_val = HWREG(baseAdd + (pad_config->pin_num));

    reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_MUXMODE_MASK;

    reg_val |= (uint32_t) pad_config->muxmode <<
               CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_MUXMODE_SHIFT;

    if (pad_config->pullud_enable != 0xFF)
    {
        reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_PULLUDENABLE_MASK;
        reg_val |= (uint32_t) pad_config->pullud_enable <<
                   CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_PULLUDENABLE_SHIFT;
    }
    if (pad_config->pull_typeselect != 0xFF)
    {
        reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_PULLTYPESELECT_MASK;
        reg_val |= (uint32_t) pad_config->pull_typeselect <<
                   CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_PULLTYPESELECT_SHIFT;
    }
    if (pad_config->input_enable != 0xFF)
    {
        reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_INPUTENABLE_MASK;
        reg_val |= (uint32_t) pad_config->input_enable <<
                   CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_INPUTENABLE_SHIFT;
    }
    if (pad_config->slewcontrol != 0xFF)
    {
        reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_SLEWCONTROL_MASK;
        reg_val |= (uint32_t) pad_config->slewcontrol <<
                   CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_SLEWCONTROL_SHIFT;
    }
    if (pad_config->wakeup_enable != 0xFF)
    {
        reg_val &= ~CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_WAKEUPENABLE_MASK;
        reg_val |= (uint32_t) pad_config->wakeup_enable <<
                   CTRL_CORE_PAD_GPMC_AD0_GPMC_AD0_WAKEUPENABLE_SHIFT;
    }

    HWREG(baseAdd + (pad_config->pin_num)) = reg_val;
    //PlatformLockMMR();
}


void configure_pad(pad_config_t *pad_array, uint32_t elements)
{
    uint32_t i;

    for (i = 0; i < elements; ++i)
    {
        cntrl_core_pad_configuration(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS,
                                     &pad_array[i]);
    }
}


void pruss_iep_PinMux(uint8_t prussn)
{

    if(prussn==1)
    {
        /*
        Port 0 - PRUSS1 IEP0
        
        RGMII0_RXC - PR1_MII_MT0_CLK
        RGMII0_RXD2 - PR1_MII0_TXEN
        RGMII0_RXD0 - PR1_MII0_TXD0
        RGMII0_RXD1 - PR1_MII0_TXD1
        RGMII0_RXD3 - PR1_MII0_TXD2
        RGMII0_RXCTL - PR1_MII0_TXD3
        
        UART3_TXD - PR1_MII_MR0_CLK
        UART3_RXD - PR1_MII0_RXDV
        RGMII0_TXD2 - PR1_MII0_RXER
        
        RGMII0_TXD0 - PR1_MII0_RXD0
        RGMII0_TXD1 - PR1_MII0_RXD1
        RGMII0_TXCTL - PR1_MII0_RXD2
        RGMII0_TXC - PR1_MII0_RXD3
        
        RGMII0_TXD3 - PR1_MII0_CRS
        MDIO_CLK - PR1_MII0_COL
        MDIO_DATA - PR1_MII0_RXLINK
        
        VIN2A_D10 - PR1_MDIO_MDCLK
        VIN2A_D11 - PR1_MDIO_DATA
        */
        pad_config_t pruss1_iep0_pad_config[] = {
      
        /* MDIO (2 pads) */
        {CTRL_CORE_PAD_VIN2A_D10,
         CTRL_CORE_PAD_VIN2A_D10_VIN2A_D10_MUXMODE_PR1_MDIO_MDCLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_UP, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D11,
         CTRL_CORE_PAD_VIN2A_D11_VIN2A_D11_MUXMODE_PR1_MDIO_DATA_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_UP, INPUTENABLE_ENABLE, 0xff, WAKEUPENABLE_DISABLE},

        /*Pin_num,Muxmode,pullud_enable,pull_typeselect,io,slewrate,wakeupmode*/
        {CTRL_CORE_PAD_RGMII0_RXC,
         CTRL_CORE_PAD_RGMII0_RXC_RGMII0_RXC_MUXMODE_PR1_MII_MT0_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_RXD2,
         CTRL_CORE_PAD_RGMII0_RXD2_RGMII0_RXD2_MUXMODE_PR1_MII0_TXEN_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_RXD0,
         CTRL_CORE_PAD_RGMII0_RXD0_RGMII0_RXD0_MUXMODE_PR1_MII0_TXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_RXD1,
         CTRL_CORE_PAD_RGMII0_RXD1_RGMII0_RXD1_MUXMODE_PR1_MII0_TXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_RXD3,
         CTRL_CORE_PAD_RGMII0_RXD3_RGMII0_RXD3_MUXMODE_PR1_MII0_TXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_RXCTL,
         CTRL_CORE_PAD_RGMII0_RXCTL_RGMII0_RXCTL_MUXMODE_PR1_MII0_TXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_UART3_TXD,
         CTRL_CORE_PAD_UART3_TXD_UART3_TXD_MUXMODE_PR1_MII_MR0_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_UART3_RXD,
         CTRL_CORE_PAD_UART3_RXD_UART3_RXD_MUXMODE_PR1_MII0_RXDV_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXD2,
         CTRL_CORE_PAD_RGMII0_TXD2_RGMII0_TXD2_MUXMODE_PR1_MII0_RXER_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXD0,
         CTRL_CORE_PAD_RGMII0_TXD0_RGMII0_TXD0_MUXMODE_PR1_MII0_RXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXD1,
         CTRL_CORE_PAD_RGMII0_TXD1_RGMII0_TXD1_MUXMODE_PR1_MII0_RXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXCTL,
         CTRL_CORE_PAD_RGMII0_TXCTL_RGMII0_TXCTL_MUXMODE_PR1_MII0_RXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXC,
         CTRL_CORE_PAD_RGMII0_TXC_RGMII0_TXC_MUXMODE_PR1_MII0_RXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_RGMII0_TXD3,
         CTRL_CORE_PAD_RGMII0_TXD3_RGMII0_TXD3_MUXMODE_PR1_MII0_CRS_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#if 0
       {CTRL_CORE_PAD_MDIO_MCLK,
       CTRL_CORE_PAD_MDIO_MCLK_MDIO_MCLK_MUXMODE_PR1_MII0_COL_11,
       PULLUDENABLE_ENABLE,
       PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
       WAKEUPENABLE_DISABLE},
#else
        {CTRL_CORE_PAD_MDIO_MCLK,
         0xff,
         0xff,
         0xff, 0xff, 0xff,
         0xff},
#endif
        {CTRL_CORE_PAD_MDIO_D,
         CTRL_CORE_PAD_MDIO_D_MDIO_D_MUXMODE_PR1_MII0_RXLINK_11, 
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff, 
         WAKEUPENABLE_DISABLE}
    };

    /*configure the rgmii pad*/
    configure_pad(pruss1_iep0_pad_config, sizeof (pruss1_iep0_pad_config) /
            sizeof (pruss1_iep0_pad_config[0]));


    /*
      Port 1 - PRUSS1 IEP1

      VIN2A_D6 - PR1_MII_MT1_CLK
      VIN2A_D7 - PR1_MII1_TXEN
      VIN2A_D13 - PR1_MII1_TXD0  
      VIN2A_D12 - PR1_MII1_TXD1
      VIN2A_D9 - PR1_MII1_TXD2
      VIN2A_D8 - PR1_MII1_TXD3

      VIN2A_D14 - PR1_MII_MR1_CLK
      VIN2A_D15 - PR1_MII1_RXDV
      VIN2A_D20 - PR1_MII1_RXER

      VIN2A_D19 - PR1_MII1_RXD0
      VIN2A_D18 - PR1_MII1_RXD1
      VIN2A_D17 - PR1_MII1_RXD2
      VIN2A_D16 - PR1_MII1_RXD3    
      
      VIN2A_D23 - PR1_MII1_CRS
      VIN2A_D22 - PR1_MII1_COL
      VIN2A_D21 - PR1_MII1_RXLINK  

    */

        pad_config_t pruss1_iep1_pad_config[] = {       

      /*Pin_num,Muxmode,pullud_enable,pull_typeselect,io,slewrate,wakeupmode*/
        {CTRL_CORE_PAD_VIN2A_D6,
         CTRL_CORE_PAD_VIN2A_D6_VIN2A_D6_MUXMODE_PR1_MII_MT1_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D7,
         CTRL_CORE_PAD_VIN2A_D7_VIN2A_D7_MUXMODE_PR1_MII1_TXEN_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D13,
         CTRL_CORE_PAD_VIN2A_D13_VIN2A_D13_MUXMODE_PR1_MII1_TXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D12,
         CTRL_CORE_PAD_VIN2A_D12_VIN2A_D12_MUXMODE_PR1_MII1_TXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D9,
         CTRL_CORE_PAD_VIN2A_D9_VIN2A_D9_MUXMODE_PR1_MII1_TXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D8,
         CTRL_CORE_PAD_VIN2A_D8_VIN2A_D8_MUXMODE_PR1_MII1_TXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},
 
        {CTRL_CORE_PAD_VIN2A_D14,
         CTRL_CORE_PAD_VIN2A_D14_VIN2A_D14_MUXMODE_PR1_MII_MR1_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D15,
         CTRL_CORE_PAD_VIN2A_D15_VIN2A_D15_MUXMODE_PR1_MII1_RXDV_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D20,
         CTRL_CORE_PAD_VIN2A_D20_VIN2A_D20_MUXMODE_PR1_MII1_RXER_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D19,
         CTRL_CORE_PAD_VIN2A_D19_VIN2A_D19_MUXMODE_PR1_MII1_RXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
       
        {CTRL_CORE_PAD_VIN2A_D18,
         CTRL_CORE_PAD_VIN2A_D18_VIN2A_D18_MUXMODE_PR1_MII1_RXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
        
        {CTRL_CORE_PAD_VIN2A_D17,
         CTRL_CORE_PAD_VIN2A_D17_VIN2A_D17_MUXMODE_PR1_MII1_RXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D16,
         CTRL_CORE_PAD_VIN2A_D16_VIN2A_D16_MUXMODE_PR1_MII1_RXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_VIN2A_D23,
         CTRL_CORE_PAD_VIN2A_D23_VIN2A_D23_MUXMODE_PR1_MII1_CRS_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#if 0
        {CTRL_CORE_PAD_VIN2A_D22,
        CTRL_CORE_PAD_VIN2A_D22_VIN2A_D22_MUXMODE_PR1_MII1_COL_11,
        PULLUDENABLE_ENABLE,
        PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
        WAKEUPENABLE_DISABLE},
#else
        {CTRL_CORE_PAD_VIN2A_D22,
        0xff,
        0xff,
        0xff, 0xff, 0xff,
        0xff},
#endif
        {CTRL_CORE_PAD_VIN2A_D21,
         CTRL_CORE_PAD_VIN2A_D21_VIN2A_D21_MUXMODE_PR1_MII1_RXLINK_11, 
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff, 
         WAKEUPENABLE_DISABLE},
    };

    /*configure the rgmii pad*/
    configure_pad(pruss1_iep1_pad_config, sizeof (pruss1_iep1_pad_config) /
                  sizeof (pruss1_iep1_pad_config[0]));

    

  }
  else
  {  
    /* 
    Port2 - PRUSS2 IEP 0

    MCASP1_AXR1 - PR2_MII_MT0_CLK
    MCASP1_AXR8 - PR2_MII0_TXEN
    MCASP1_AXR12 - PR2_MII0_TXD0  
    MCASP1_AXR11 - PR2_MII0_TXD1
    MCASP1_AXR10 - PR2_MII0_TXD2
    MCASP1_AXR9 - PR2_MII0_TXD3

    MCASP1_AXR13 - PR2_MII_MR0_CLK
    MCASP1_AXR14 - PR2_MII0_RXDV
    MCASP1_AXR0 -PR2_MII0_RXER

    MCASP2_AXR2 -PR2_MII0_RXD0
    MCASP2_FSX - PR2_MII0_RXD1
    MCASP2_ACLKX - PR2_MII0_RXD2
    MCASP1_AXR15 - PR2_MII0_RXD3    
    
    MCASP3_ACLKX - PR2_MII0_CRS
    MCASP3_FSX - PR2_MII0_COL
    MCASP2_AXR3 - PR2_MII0_RXLINK  

    MCASP1_ACLKX - PR2_MDIO_MDCLK
    MCASP1_FSX - PR2_MDIO_DATA

    */

    pad_config_t pruss2_iep0_pad_config[] = {
        
        /* MDIO (2 pads) */
        {CTRL_CORE_PAD_MCASP1_ACLKX,
         CTRL_CORE_PAD_MCASP1_ACLKX_MCASP1_ACLKX_MUXMODE_PR2_MDIO_MDCLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_UP, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_FSX,
         CTRL_CORE_PAD_MCASP1_FSX_MCASP1_FSX_MUXMODE_PR2_MDIO_DATA_11, 
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_UP, INPUTENABLE_ENABLE, 0xff, WAKEUPENABLE_DISABLE},

        /*Pin_num,Muxmode,pullud_enable,pull_typeselect,io,slewrate,wakeupmode*/
        {CTRL_CORE_PAD_MCASP1_AXR1,
         CTRL_CORE_PAD_MCASP1_AXR1_MCASP1_AXR1_MUXMODE_PR2_MII_MT0_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR8,
         CTRL_CORE_PAD_MCASP1_AXR8_MCASP1_AXR8_MUXMODE_PR2_MII0_TXEN_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR12,
         CTRL_CORE_PAD_MCASP1_AXR12_MCASP1_AXR12_MUXMODE_PR2_MII0_TXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR11,
         CTRL_CORE_PAD_MCASP1_AXR11_MCASP1_AXR11_MUXMODE_PR2_MII0_TXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR10,
         CTRL_CORE_PAD_MCASP1_AXR10_MCASP1_AXR10_MUXMODE_PR2_MII0_TXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR9,
         CTRL_CORE_PAD_MCASP1_AXR9_MCASP1_AXR9_MUXMODE_PR2_MII0_TXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR13,
         CTRL_CORE_PAD_MCASP1_AXR13_MCASP1_AXR13_MUXMODE_PR2_MII_MR0_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR14,
         CTRL_CORE_PAD_MCASP1_AXR14_MCASP1_AXR14_MUXMODE_PR2_MII0_RXDV_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR0,
         CTRL_CORE_PAD_MCASP1_AXR0_MCASP1_AXR0_MUXMODE_PR2_MII0_RXER_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP2_AXR2,
         CTRL_CORE_PAD_MCASP2_AXR2_MCASP2_AXR2_MUXMODE_PR2_MII0_RXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP2_FSX,
         CTRL_CORE_PAD_MCASP2_FSX_MCASP2_FSX_MUXMODE_PR2_MII0_RXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP2_ACLKX,
         CTRL_CORE_PAD_MCASP2_ACLKX_MCASP2_ACLKX_MUXMODE_PR2_MII0_RXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP1_AXR15,
         CTRL_CORE_PAD_MCASP1_AXR15_MCASP1_AXR15_MUXMODE_PR2_MII0_RXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MCASP3_ACLKX,
         CTRL_CORE_PAD_MCASP3_ACLKX_MCASP3_ACLKX_MUXMODE_PR2_MII0_CRS_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#if 0
        {CTRL_CORE_PAD_MCASP3_FSX,
         CTRL_CORE_PAD_MCASP3_FSX_MCASP3_FSX_MUXMODE_PR2_MII0_COL_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#else
       {CTRL_CORE_PAD_MCASP3_FSX,
        0xff,
        0xff,
        0xff, 0xff, 0xff,
        0xff},
#endif

#if 0
        {CTRL_CORE_PAD_MCASP1_AXR3,
         CTRL_CORE_PAD_MCASP2_AXR3_MCASP2_AXR3_MUXMODE_PR2_MII0_RXLINK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE}
#else      
        {CTRL_CORE_PAD_MCASP1_AXR3,
         0xff,
         0xff,
         0xff, 0xff, 0xff,
         0xff},
#endif
    };

    /*configure the pruss2_iep0 pad*/
    configure_pad(pruss2_iep0_pad_config, sizeof (pruss2_iep0_pad_config) /
                sizeof (pruss2_iep0_pad_config[0]));

    /* 
    Port3 -   PRUSS2 IEP 1

    GPIO6_10 - PR2_MII_MT1_CLK
    GPIO6_11 - PR2_MII1_TXEN
    MMC3_DAT1 - PR2_MII1_TXD0  
    MMC3_DAT0 - PR2_MII1_TXD1
    MMC3_CMD - PR2_MII1_TXD2
    MMC3_CLK - PR2_MII1_TXD3

    MMC3_DAT2 - PR2_MII_MR1_CLK
    MMC3_DAT3 - PR2_MII1_RXDV
    MCASP3_AXR0 -PR2_MII1_RXER

    MMC3_DAT7 -PR2_MII1_RXD0
    MMC3_DAT6 - PR2_MII1_RXD1
    MMC3_DAT5 - PR2_MII1_RXD2
    MMC3_DAT4 - PR2_MII1_RXD3    
    
    XREF_CLK1 - PR2_MII1_CRS
    XREF_CLK0 - PR2_MII1_COL
    MCASP3_AXR1 - PR2_MII1_RXLINK    

    */
    pad_config_t pruss2_iep1_pad_config[] = {

        /*Pin_num,Muxmode,pullud_enable,pull_typeselect,io,slewrate,wakeupmode*/
        {CTRL_CORE_PAD_GPIO6_10,
         CTRL_CORE_PAD_GPIO6_10_GPIO6_10_MUXMODE_PR2_MII_MT1_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_GPIO6_11,
         CTRL_CORE_PAD_GPIO6_11_GPIO6_11_MUXMODE_PR2_MII1_TXEN_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT1,
         CTRL_CORE_PAD_MMC3_DAT1_MMC3_DAT1_MUXMODE_PR2_MII1_TXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT0,
         CTRL_CORE_PAD_MMC3_DAT0_MMC3_DAT0_MUXMODE_PR2_MII1_TXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_CMD,
         CTRL_CORE_PAD_MMC3_CMD_MMC3_CMD_MUXMODE_PR2_MII1_TXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_CLK,
         CTRL_CORE_PAD_MMC3_CLK_MMC3_CLK_MUXMODE_PR2_MII1_TXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_DISABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT2,
         CTRL_CORE_PAD_MMC3_DAT2_MMC3_DAT2_MUXMODE_PR2_MII_MR1_CLK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT3,
         CTRL_CORE_PAD_MMC3_DAT3_MMC3_DAT3_MUXMODE_PR2_MII1_RXDV_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

         {CTRL_CORE_PAD_MCASP3_AXR0,
         CTRL_CORE_PAD_MCASP3_AXR0_MCASP3_AXR0_MUXMODE_PR2_MII1_RXER_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT7,
         CTRL_CORE_PAD_MMC3_DAT7_MMC3_DAT7_MUXMODE_PR2_MII1_RXD0_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT6,
         CTRL_CORE_PAD_MMC3_DAT6_MMC3_DAT6_MUXMODE_PR2_MII1_RXD1_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT5,
         CTRL_CORE_PAD_MMC3_DAT5_MMC3_DAT5_MUXMODE_PR2_MII1_RXD2_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_MMC3_DAT4,
         CTRL_CORE_PAD_MMC3_DAT4_MMC3_DAT4_MUXMODE_PR2_MII1_RXD3_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},

        {CTRL_CORE_PAD_XREF_CLK1,
         CTRL_CORE_PAD_XREF_CLK1_XREF_CLK1_MUXMODE_PR2_MII1_CRS_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#if 0
        {CTRL_CORE_PAD_XREF_CLK0,
         CTRL_CORE_PAD_XREF_CLK0_XREF_CLK0_MUXMODE_PR2_MII1_COL_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE},
#else
       {CTRL_CORE_PAD_XREF_CLK0,
        0xff,
        0xff,
        0xff, 0xff, 0xff,
        0xff},
#endif

#if 0
        {CTRL_CORE_PAD_MCASP3_AXR1,
         CTRL_CORE_PAD_MCASP3_AXR1_MCASP3_AXR1_MUXMODE_PR2_MII1_RXLINK_11,
         PULLUDENABLE_ENABLE,
         PULLTYPESELECT_PULL_DOWN, INPUTENABLE_ENABLE, 0xff,
         WAKEUPENABLE_DISABLE}
#else
        {CTRL_CORE_PAD_MCASP3_AXR1,
         0xff,
         0xff,
         0xff, 0xff, 0xff,
         0xff},
#endif

    };

    /*configure the pruss2_iep0 pad*/
    configure_pad(pruss2_iep1_pad_config, sizeof (pruss2_iep1_pad_config) /
                sizeof (pruss2_iep1_pad_config[0]));  

    }

}

void pruss_iep_Initialization(uint8_t prussn)
{
    uint32_t pruss_base=0;

    if(prussn==1)
        pruss_base = CSL_MPU_PRUSS1_U_CFG_REGS;
    else
        pruss_base = CSL_MPU_PRUSS2_U_CFG_REGS;

    //perform all the pin muxing
    pruss_iep_PinMux(prussn);

    //Enable the PRUSS clock
    if(prussn==1)
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) = 0;
    }
    else
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) = 0;
    }

    Delay(50);

    if(prussn==1)
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) = 2;
        while(0 != (HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) & 0x00030000));
    }
    else
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) = 2;
        while(0 != (HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) & 0x00030000));
    }

    while(0x6100 != ((HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_CLKSTCTRL))&0x6100)); //ICSS_CLK, ICSS_IEP_CLK



    HWREG(pruss_base + 0x04)=0x06; //NO_STANDBY
    Delay(50);

}

void pruss_iep_MemFill(uint32_t StartAddress, uint32_t Length , uint16_t Pattern)
{
    uint32_t tempCount = 0;
    for(tempCount = 0; tempCount < (Length / 4 ) ; tempCount++ )
    {
        /*loading the pattern into the memory*/
        HWREG(StartAddress + (tempCount*4)) = Pattern;
    }
}

/*
 * this can be changed to use the MDIO API
 */
void pruss_iep_MDIOInitialization(uint8_t prussn)
{
    uint32_t pruss_base = 0;

    if(prussn==1)
    {
      pruss_base = icss_EmacBaseAddrCfgParams[prussn-1].prussMiiMdioRegs + 0x04;
    }
    else
    {
      pruss_base = icss_EmacBaseAddrCfgParams[prussn-1].prussMiiMdioRegs + 0x04;
    }

    /* Initialize the MDIO pin */
    HWREG(pruss_base) = 0x4000009F;//increase speed
                         /*200/(0x9F+1) = 1.25 MHz*/
    Delay(50);
}

void PhyIntConfig(int numPorts)
{
    int i =0;
    int startPort=0;

    if(numPorts==2)
    {
      startPort = 2;
      numPorts+=2;
    }

    for(i=startPort;i<numPorts;i++)
    {
        /* Do GPIO pin mux */
        HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + PhyIntInfo[i].pinMux) = (0x20000 | 0x0E);

        GPIOModuleEnable(PhyIntInfo[i].baseAddr);
        GPIODirModeSet(PhyIntInfo[i].baseAddr, PhyIntInfo[i].pin, GPIO_DIR_INPUT);
    }

}

void ManualPhyReset(int numPorts)
{
  int i =0;
  int startPort=0;

  if(numPorts==2)
  {
    startPort = 2;
    numPorts+=2;
  }

  for(i=startPort;i<numPorts;i++)
  {
    /* Do GPIO pin mux */
    HWREG(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + PhyResetInfo[i].pinMux) = (0x20000 | 0x0E);

    //GPIOModuleReset(info.baseAddr);
    GPIOModuleEnable(PhyResetInfo[i].baseAddr);
    GPIODirModeSet(PhyResetInfo[i].baseAddr, PhyResetInfo[i].pin, GPIO_DIR_OUTPUT);


    GPIOPinWrite(PhyResetInfo[i].baseAddr, PhyResetInfo[i].pin, GPIO_PIN_LOW);
    //Delay(100000);
    Delay(1000);
    GPIOPinWrite(PhyResetInfo[i].baseAddr, PhyResetInfo[i].pin, GPIO_PIN_HIGH);
    //Delay(100000);
    Delay(1000);
  }

}

void ICSS_EmacRxPktCallback(ICSS_EmacHandle ICSS_EmacSubSysHandle)
{
    int8_t     port_number;
    int8_t     queue_number;
    int32_t     morePkts = 0;
    short pLength;
    ICSS_EmacRxArgument rxArg;
    memset(&rxArg, 0, sizeof(ICSS_EmacRxArgument));
    packetRcvd_port0 = 1;
    pLength = ICSS_EmacRxPktInfo(ICSS_EmacSubSysHandle,&port_number, &queue_number);

    rxArg.icssEmacHandle = ICSS_EmacSubSysHandle;
    rxArg.destAddress = (uint32_t)(&packet_array[0]);
    rxArg.queueNumber = queue_number;
    rxArg.port = port_number;
    rxArg.more = morePkts;

    if(pLength > 0)
    {
        pktReceived++;
        ICSS_EmacRxPktGet(&rxArg, NULL);
    }
     //ICSS_EmacClearRxIrq(ICSS_EmacSubSysHandle);
    if((((ICSS_EmacObject*)ICSS_EmacSubSysHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0),
                CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, 1 << 21);
    else
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0),
                CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, 1 << 20);
}


int8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance)
{
    int8_t retVal = -1;

    /* LLD attributes callocs */
    handle->object = (ICSS_EmacObject*)calloc(1, sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)calloc(1, sizeof(ICSS_EmacHwAttrs));
    if((handle->object == NULL) || (handle->hwAttrs == NULL))
    {
        return -1;
    }

    /* Callback callocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)calloc(1, sizeof(ICSS_EmacCallBackObject));
    if(callBackObj == NULL)
    {
        return -1;
    }

    callBackObj->learningExCallBack=(ICSS_EmacCallBackConfig*)calloc(1, sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxRTCallBack=(ICSS_EmacCallBackConfig*)calloc(1, sizeof(ICSS_EmacCallBackConfig));
    callBackObj->rxCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    callBackObj->txCallBack=(ICSS_EmacCallBackConfig*)malloc(sizeof(ICSS_EmacCallBackConfig));
    ((ICSS_EmacObject*)handle->object)->callBackHandle = callBackObj;

    /*Allocate memory for learning*/
    ((ICSS_EmacObject*)handle->object)->macTablePtr = (HashTable_t*)calloc(1, NUM_PORTS * sizeof(HashTable_t));

    /*Allocate memory for PRU Statistics*/
    ((ICSS_EmacObject*)handle->object)->pruStat = (ICSS_EmacPruStatistics_t*)calloc(1, NUM_PORTS * sizeof(ICSS_EmacPruStatistics_t));

    /*Allocate memory for Host Statistics*/
    ((ICSS_EmacObject*)handle->object)->hostStat = (ICSS_EmacHostStatistics_t*)calloc(1, NUM_PORTS * sizeof(ICSS_EmacHostStatistics_t));

    /*Allocate memory for Storm Prevention*/
    ((ICSS_EmacObject*)handle->object)->stormPrevPtr = (stormPrevention_t*)calloc(1, NUM_PORTS * sizeof(stormPrevention_t));

    /* Base address initialization */
    ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg =
                    (ICSS_EmacBaseAddressHandle_T)calloc(1, sizeof(ICSS_EmacBaseAddrCfgParams));
    if(((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg == NULL)
    {
        return -1;
    }

    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;


    if(instance == 2)
    {
        emacBaseAddr->dataRam0BaseAddr = CSL_MPU_PRUSS2_U_DATA_RAM0_8KB_REGS;
        emacBaseAddr->dataRam1BaseAddr = CSL_MPU_PRUSS2_U_DATA_RAM1_8KB_REGS;
        emacBaseAddr->l3OcmcBaseAddr = CSL_MPU_OCMC_RAM1_REGS;
        emacBaseAddr->prussCfgRegs = CSL_MPU_PRUSS2_U_CFG_REGS;
        emacBaseAddr->prussIepRegs = CSL_MPU_PRUSS2_U_IEP_REGS;
        emacBaseAddr->prussIntcRegs = CSL_MPU_PRUSS2_U_INTC_REGS;
        emacBaseAddr->prussMiiMdioRegs = CSL_MPU_PRUSS2_U_MII_MDIO_REGS;
        emacBaseAddr->prussMiiRtCfgRegsBaseAddr = CSL_MPU_PRUSS2_U_MII_RT_CFG_REGS;
        emacBaseAddr->prussPru0CtrlRegs =  CSL_MPU_PRUSS2_U_PRU0_CTRL_REGS;
        emacBaseAddr->prussPru1CtrlRegs = CSL_MPU_PRUSS2_U_PRU1_CTRL_REGS;
        emacBaseAddr->sharedDataRamBaseAddr = CSL_MPU_PRUSS2_U_DATA_RAM_32KB_REGS;
        retVal = 0;
    }
    return retVal;
}

void MDIO_enableLinkInterrupt(uint32_t mdioBaseAddress,uint32_t phyInst,uint32_t phyNum,uint8_t linkSel)
{
    uint32_t PhySel;

    PhySel=phyNum;
    PhySel |=  0x40;
    if(MDIO_LINKSEL_ENABLE == linkSel)
        PhySel |= 0x80;

       HWREG(mdioBaseAddress + CSL_MDIO_USER_PHY_SEL_REG(0) + (phyInst*8)) = PhySel;
}

uint32_t EMACOpen(ICSS_EmacHandle icssEmacHandle)
{
    int32_t              i;
    uint32_t numPorts=0;
    uint32_t phyNum;
    uint32_t phyinst;
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask)
        numPorts = 2;
    else
        numPorts = 1;
    /*No need of MDIO init for the second instance*/
    if(ICSS_EMAC_MODE_MAC2 != (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask)
        CSL_MDIO_init((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
        SWITCH_DEFAULT_MDIOCLOCKFREQ, SWITCH_DEFAULT_MDIOBUSFREQ);
    /* Open all ports */
    for(i=0;i<numPorts; i++)
    {
        //ICSSMacOpen(i,icssEmacHandle);
        phyNum = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[i];
        phyinst = (i + phyCount);
        phyCount++;
        MDIO_enableLinkInterrupt((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,phyinst,phyNum,
                                                    MDIO_LINKSEL_DISABLE);

    }/* end of for loop over PORTS */

    return 0;
}

void AM57x_setup(void)
{
    int  numPorts= 4, fixTemp=0;

    if(numPorts==4)
    {
        //GPIO_PRU1_ETH0_RESETn
        PhyResetInfo[0].instance=5; //MCASP1_AXR4 - GPIO5_6
        PhyResetInfo[0].pin=6;
        PhyResetInfo[0].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR4;
        PhyResetInfo[0].baseAddr=CSL_MPU_GPIO5_REGS;

        //GPIO_PRU1_ETH1_RESETn
        PhyResetInfo[1].instance=5; //MCASP1_AXR5 - GPIO5_7
        PhyResetInfo[1].pin=7;
        PhyResetInfo[1].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR5;
        PhyResetInfo[1].baseAddr=CSL_MPU_GPIO5_REGS;

        //PRU1_ETH0_INTn
        PhyIntInfo[0].instance=3; //VIN2A_CLK0 - GPIO3_28 - Input
        PhyIntInfo[0].pin=28;
        PhyIntInfo[0].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_CLK0;
        PhyIntInfo[0].baseAddr=CSL_MPU_GPIO3_REGS;

        //PRU1_ETH1_INTn
        PhyIntInfo[1].instance=3; //VIN2A_DE0- GPIO3_29 - Input
        PhyIntInfo[1].pin=29;
        PhyIntInfo[1].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_DE0;
        PhyIntInfo[1].baseAddr=CSL_MPU_GPIO3_REGS;
    }

    //GPIO_PRU2_ETH0_RESETn
    PhyResetInfo[2].instance=5; //MCASP1_AXR6 - GPIO5_8
    PhyResetInfo[2].pin=8;
    PhyResetInfo[2].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR6;
    PhyResetInfo[2].baseAddr=CSL_MPU_GPIO5_REGS;

    //GPIO_PRU2_ETH1_RESETn
    PhyResetInfo[3].instance=5; //MCASP1_AXR7 - GPIO5_9
    PhyResetInfo[3].pin=9;
    PhyResetInfo[3].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_MCASP1_AXR7;
    PhyResetInfo[3].baseAddr=CSL_MPU_GPIO5_REGS;

    //PRU2_ETH0_INTn
    PhyIntInfo[2].instance=3; //VIN2A_FLD0- GPIO3_30 - Input
    PhyIntInfo[2].pin=30;
    PhyIntInfo[2].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_FLD0;
    PhyIntInfo[2].baseAddr=CSL_MPU_GPIO3_REGS;

    //PRU2_ETH1_INTn
    PhyIntInfo[3].instance=3; //VIN2A_HSYNC0- GPIO3_31 - Input
    PhyIntInfo[3].pin=31;
    PhyIntInfo[3].pinMux=CSL_CONTROL_CORE_PAD_IO_PAD_VIN2A_HSYNC0;
    PhyIntInfo[3].baseAddr=CSL_MPU_GPIO3_REGS;

    for(fixTemp=0;fixTemp<2;fixTemp++) //Temporary fix to run the initialisation twice to fix the second port failure
    {
        //reset the phys
        ManualPhyReset(numPorts);

        /*PHY Interrupt lines are configured as GPIO Input in order to avoid any
        spurious power down signal to TLK105L*/
        PhyIntConfig(numPorts);
  
        //call the ICSS PRU init function
        if(numPorts==4)
          pruss_iep_Initialization(1);
  
        pruss_iep_Initialization(2);
  
        *(unsigned int*)(0x4A003710) =(unsigned int)(0x000c000B);
  
        *(unsigned int*)(0x4A003730) =(unsigned int)(0x000c000B);
  
        //Init the MDIO
        if(numPorts==4)
          pruss_iep_MDIOInitialization(1);
  
        pruss_iep_MDIOInitialization(2);
  
        Delay(2000);
    }
}


void IcssEmacIntrInit(ICSS_EmacHandle icssEmacHandle)
{
    /* Rx Packet Interrupt , HOST2 is always Rx Packet Interrupt*/
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_150, CSL_XBAR_PRUSS2_IRQ_HOST2);

    /* Do the interrupt related configurations */
    gIcssEmacIntrParams.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gIcssEmacIntrParams.priority = 0x20U;

    /*
     * Assign the ISR to the function pointer to invoke when the
     * interrupt is raised.
     */
    gIcssEmacIntrParams.pFnIntrHandler = (void*)&ICSS_EmacRxPktCallback;
    gIcssEmacIntrParams.pUserParam = icssEmacHandle;


    /* Configure the interrupt Controller 182 is CSL_XBAR_INST_MPU_IRQ_150 + 32*/
    CSL_armGicConfigIntr(&gCpuIntrf, 182U, &gIcssEmacIntrParams);


   /* Link Interrupt , HOST 8 is always link interrupt*/
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_120, CSL_XBAR_PRUSS2_IRQ_HOST8);
    /* Do the interrupt related configurations */
    gIcssEmacIntrParamsLink.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gIcssEmacIntrParamsLink.priority = 0x20U;

    /*
     * Assign the ISR to the function pointer to invoke when the
     * interrupt is raised.
     */
    gIcssEmacIntrParamsLink.pFnIntrHandler = (void*)&ICSS_EmacLinkISR;
    gIcssEmacIntrParamsLink.pUserParam = icssEmacHandle;

     /* Configure the interrupt Controller 152 is CSL_XBAR_INST_MPU_IRQ_120 + 32*/
    CSL_armGicConfigIntr(&gCpuIntrf,152, &gIcssEmacIntrParamsLink);
}

int icss_emacMain(void)
{
    Board_IDInfo boardInfo;
    uint8_t firmwareLoad_done = FALSE;
    uint8_t count=0;
    int ret = 0;
    uint32_t pgVersion;
    ICSS_EmacTxArgument txArg;
    memset(&txArg, 0, sizeof(ICSS_EmacTxArgument));

    pgVersion = (HW_RD_REG32(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_ID_CODE) & 0xf0000000) >> 28;

    Board_getIDInfo(&boardInfo);
    pruIcssHandle = PRUICSS_create(pruss_config,(int) prussIcssInstance);
    AM57x_setup();

    /*Port I initializations*/
    emachandle = (ICSS_EmacHandle)calloc(1, sizeof(ICSS_EmacConfig));
    if(emachandle == NULL)
    {
        UART_printf("icss_emacMain: EMAC Handle Memory Allocation Failed!\n");
        ret = 1;
    }

    ICSS_EmacInitConfig* switchEmacCfg;
    switchEmacCfg = (ICSS_EmacInitConfig*)calloc(1,sizeof(ICSS_EmacInitConfig));
    if(switchEmacCfg == NULL)
    {
        UART_printf("icss_emacMain: EMAC Switch Config Memory Allocation Failed!\n");
        ret = 1;
    }
    
    if((emachandle != NULL) && (switchEmacCfg != NULL))
    {
        switchEmacCfg->phyAddr[0]=0;
        switchEmacCfg->portMask = ICSS_EMAC_MODE_MAC1;
        switchEmacCfg->ethPrioQueue = ICSS_EMAC_QUEUE1;



        switchEmacCfg->halfDuplexEnable = 1;
        switchEmacCfg->enableIntrPacing = ICSS_EMAC_ENABLE_PACING;
        switchEmacCfg->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
        switchEmacCfg->pacingThreshold = 100;
        switchEmacCfg->learningEn = 0;
       
        switchEmacCfg->macId = (uint8_t*)(&boardInfo.indEthMacID0);

        ret = ICSSEmacDRVInit(emachandle, 2);     // ICSS_M instance 0
        if(ret)
        {
            UART_printf("EMAC Driver Init Failed\n");
        }

        ((ICSS_EmacObject*)emachandle->object)->pruIcssHandle = pruIcssHandle;
        ((ICSS_EmacObject*)emachandle->object)->emacInitcfg = switchEmacCfg;


        PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
        ICSS_EmacInit(emachandle,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1);



        PRUICSS_pinMuxConfig(pruIcssHandle, 0x0); // PRUSS pinmuxing
        IcssEmacIntrInit(emachandle);
        EMACOpen(emachandle);

        /* Same flow as taskPruss */
        PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
        PRUICSS_pruDisable(pruIcssHandle, ICSS_EMAC_PORT_2-1);


    #if defined(SOC_AM572x) || defined(SOC_AM574x)
        if (pgVersion >= 2)
        {
            if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                    (uint32_t *) &pru_imem0_rev2_start,
                &pru_imem0_rev2_end - &pru_imem0_rev2_start))

            {
                if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                        (uint32_t *) &pru_imem1_rev2_start,
                    &pru_imem1_rev2_end - &pru_imem1_rev2_start))
                {
                    firmwareLoad_done = TRUE;
                }
            }
        }
#if 0
        else
        {
            if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                    (uint32_t *) &pru_imem0_rev1_start,
                &pru_imem0_rev1_end - &pru_imem0_rev1_start))

            {
                if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                        (uint32_t *) &pru_imem1_rev1_start,
                    &pru_imem1_rev1_end - &pru_imem1_rev1_start))

                {
                    firmwareLoad_done = TRUE;
                }
            }
        }
#endif
#else
         if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                 (uint32_t *) &pru_imem0_rev2_start,
             &pru_imem0_rev2_end - &pru_imem0_rev2_start))
        {
            if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                (uint32_t *) &pru_imem1_rev2_start,
                &pru_imem1_rev2_end - &pru_imem1_rev2_start))
            {
                firmwareLoad_done = TRUE;
            }
        }
#endif

        if( firmwareLoad_done)
        {
            PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_1-1);
            PRUICSS_pruEnable(pruIcssHandle, ICSS_EMAC_PORT_2-1);
        }

        /* wait for link to come up */
        while (!((ICSS_EmacObject*)emachandle->object)->linkStatus[0])
        {
            UART_printf("icss_emacMain: LINK IS DOWN, pluggin loopback cable\n");
            Delay(1000);
        }

        UART_printf("icss_emacMain: LINK IS UP\n");

        packetRcvd_port0 = 1;
        /* send the packet */
        for (count=0;count < PKT_TX_COUNT;count++)
        {
            {
                if(packetRcvd_port0 )
                {
                    txArg.icssEmacHandle = emachandle;
                    txArg.srcAddress = &test_pkt[0];
                    txArg.portNumber = 1;
                    txArg.queuePriority = 3;
                    txArg.lengthOfPacket = TEST_PKT_SIZE;
                    packetRcvd_port0 = 0;
                    ret = ICSS_EmacTxPacket(&txArg, NULL);
                    if (ret != 0) {
                        UART_printf("Error sending packet\n");
                        ret = 1;
                        break;
                    }

                    while(!packetRcvd_port0)
                    {
                        Delay(100);
                    }
                    if (!(memcmp(&packet_array[0], &test_pkt[0],TEST_PKT_SIZE)))
                    {
                        memset(&packet_array[0], 0, TEST_PKT_SIZE);
                        UART_printf("received pkt: %d\n", totalPktRcvd);
                        totalPktRcvd++;
                    }
                    else
                    {
                        UART_printf("Unit Test Failure, packet mismatch occured\n");
                        ret = 1;
                        break;
                    }
                }
            }
        }

        if (totalPktRcvd == PKT_TX_COUNT)
        {
            UART_printf("All tests have passed\n");
        }       
    }

    if(emachandle != NULL)
    {
        free(emachandle);
    }

    if(switchEmacCfg != NULL)
    {
        free(switchEmacCfg);
    }

    return(ret);
}

/**
 * \brief   This function does two operations:\n
 *          1> Copies an array which contains vector table values to the
 *             processor's vector table space.\n
 *          2> Then it calls the main() function.\n
 *
 * \param   None.
 *
 * \retval  None.
 *
 * \note    This function is the first function that needs to be called in a
 *          system. This should be set as the entry point in the linker script
 *          file if the ELF executable is to loaded via a debugger on the
 *          target. This function never returns, but gives control to the
 *          application entry point.
 **/
int main(void)
{
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG | 
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    
    /* Copy the vector table to desired location.  */
    CopyVectorTable();

   /* Configure system */
    systemInit();

   /* Calling the main */
    return icss_emacMain();
}
