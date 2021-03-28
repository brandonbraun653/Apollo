/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/csl/csl_mdio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/cslr_icss.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_bootcfgAux.h>

#include "ti/drv/icss_emac/icss_emacDrv.h"
#include <ti/csl/csl_pscAux.h>

#include "ti/drv/icss_emac/soc/k2g/icss_emacSoc.c"
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

#include <ti/drv/pruss/soc/k2g/pruicss_soc.c>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>


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
#include "iceK2G_ethernet_config.h"

#define PKT_TX_COUNT 5

#define SWITCH_DEFAULT_MDIOBUSFREQ                          (2200000u)
#define SWITCH_DEFAULT_MDIOCLOCKFREQ                        (200000000)

#define MDIO_LINKSEL_ENABLE            1
#define MDIO_LINKSEL_DISABLE           0

#define ICSS_EMAC_TEST_POLLMODE  (1)

PRUICSS_Handle pruIcss0Handle;
PRUICSS_Handle pruIcss1Handle;
ICSS_EmacHandle emac0Handle0;
ICSS_EmacHandle emac0Handle1;
ICSS_EmacHandle emac1Handle0;
ICSS_EmacHandle emac1Handle1;
volatile uint32_t packetRcvd_port0 = 0;
uint32_t totalPktRcvd = 0;

extern CSL_ArmGicDistIntrf distrIntrf;
extern CSL_ArmGicCpuIntrf gCpuIntrf;

CSL_ArmGicIntrParams_t gIcssEmacIntrParams;
CSL_ArmGicIntrParams_t gIcssEmacIntrParamsLink;

uint32_t pktReceived = 0;
uint32_t totalPktsRcvd = 0;

PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;

uint8_t lclMac[6];
uint8_t ICSS_EMAC_testLclMac[4][6] = {{0x01, 0xb2, 0xc1, 0xd4, 0xe4, 0xff},
                                      {0x01, 0xb3, 0xc2, 0xd4, 0xe4, 0xff},
                                      {0x01, 0xb4, 0xc3, 0xdd, 0xee, 0xff},
                                      {0x01, 0xb5, 0xc4, 0xd4, 0xe4, 0xff}};

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

#define PRUSS_INSTANCE_ONE 1
#define PRUSS_INSTANCE_TWO 2
#define PRUICSS_PORT_ONE 1
#define PRUICSS_PORT_TWO 2

typedef struct pruicssPortInfo {
    uint32_t linkIntr;
    uint32_t rxIntr;
    uint32_t txIntr;
	uint8_t  intrPacingCfg;
	uint32_t phyAddr;
} pruicssPortInfo;
pruicssPortInfo gPruicssPortInfo[2][2] =
{
	{{CSL_ARM_GIC_ICSSM0_HOST_INT6, CSL_ARM_GIC_ICSSM0_HOST_INT0, CSL_ARM_GIC_ICSSM0_HOST_INT2, ICSS_EMAC_ENABLE_PACING, BOARD_ICSS_EMAC_PORT0_PHY_ADDR},
	{CSL_ARM_GIC_ICSSM0_HOST_INT7, CSL_ARM_GIC_ICSSM0_HOST_INT1, CSL_ARM_GIC_ICSSM0_HOST_INT3, ICSS_EMAC_DISABLE_PACING, BOARD_ICSS_EMAC_PORT1_PHY_ADDR}},
	{{CSL_ARM_GIC_ICSSM1_HOST_INT6, CSL_ARM_GIC_ICSSM1_HOST_INT0, CSL_ARM_GIC_ICSSM1_HOST_INT2, ICSS_EMAC_ENABLE_PACING, BOARD_ICSS_EMAC_PORT2_PHY_ADDR},
	{CSL_ARM_GIC_ICSSM1_HOST_INT7, CSL_ARM_GIC_ICSSM1_HOST_INT1, CSL_ARM_GIC_ICSSM1_HOST_INT3, ICSS_EMAC_ENABLE_PACING, BOARD_ICSS_EMAC_PORT3_PHY_ADDR}},
};

/* Returns MAC ID for a specific PRU port */
void SOCCtrlGetPortMacAddr(uint32_t pruIntance, uint32_t portNum, uint8_t *pMacAddr)
{
	uint8_t index;
	
	index = 2*(pruIntance - 1) + (portNum - 1);
	
	pMacAddr[0U] = ICSS_EMAC_testLclMac[index][0];
	pMacAddr[1U] = ICSS_EMAC_testLclMac[index][1];
	pMacAddr[2U] = ICSS_EMAC_testLclMac[index][2];
	pMacAddr[3U] = ICSS_EMAC_testLclMac[index][3];
	pMacAddr[4U] = ICSS_EMAC_testLclMac[index][4];
	pMacAddr[5U] = ICSS_EMAC_testLclMac[index][5];
}

void Delay(uint32_t delay)
{
    volatile uint32_t delay1 = delay*10;
    while (delay1--) ;
}

void pruss_iep_Initialization(uint8_t prussn)
{
    uint32_t pruss_base=0;

    if(prussn==1)
        pruss_base = CSL_ICSS_0_CFG_REGS;
    else
        pruss_base = CSL_ICSS_1_CFG_REGS;

	/* Setup ICSS0_PRU0 in MII mode */
	HWREG(pruss_base + 0x08) &= ~0x3C000000;
	HWREG(pruss_base + 0x08) |= 0x8000003;
	/* Setup ICSS0_PRU1 in MII mode */
	HWREG(pruss_base + 0x0C) &= ~0x3C000000;
	HWREG(pruss_base + 0x0C) |= 0x8000003;

    HWREG(pruss_base + 0x04)=0x06; //NO_STANDBY

    Delay(50);
}

/* Tx completion callback */
void ICSS_EmacTxPktCallback(ICSS_EmacHandle ICSS_EmacSubSysHandle)
{    
	int32_t txIntrN   =  (((ICSS_EmacObject*)ICSS_EmacSubSysHandle->object)->emacInitcfg)->txIntNum;
	
	CSL_armGicClearIntr(&gCpuIntrf, txIntrN);
}

/* Rx completion callback */
void ICSS_EmacRxPktCallback(ICSS_EmacHandle ICSS_EmacSubSysHandle)
{
	int32_t     port_number;
    int32_t     queue_number;
    int32_t     morePkts;
    int32_t pLength;
    ICSS_EmacRxArgument rxArg;
	int32_t rxIntrN   =  (((ICSS_EmacObject*)ICSS_EmacSubSysHandle->object)->emacInitcfg)->rxIntNum;
	
    memset(&rxArg, 0, sizeof(ICSS_EmacRxArgument));
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
        packetRcvd_port0 = 1;
    }
	 CSL_armGicClearIntr(&gCpuIntrf, rxIntrN);
    if((((ICSS_EmacObject*)ICSS_EmacSubSysHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, 1 << 22);
    else
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, 1 << 10);
}

/* Fuction to clear Link IRQ events */
static void ICSS_EmacClearLinkIrq(ICSS_EmacHandle ICSS_EmacSubSysHandle)
{
    if((((ICSS_EmacObject*)ICSS_EmacSubSysHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, 1 << 21);
    else
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)ICSS_EmacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, 1 << 9);
}

static void ICSS_EmacClearIntr(PRUICSS_Handle handle)
{
	PRUICSS_HwAttrs    *hwAttrs;
	uint32_t baseaddr;
	uint32_t srsr;

	hwAttrs = (PRUICSS_HwAttrs*)handle->hwAttrs;
	baseaddr = hwAttrs->prussIntcRegBase;
	
	srsr = HWREG(baseaddr + CSL_ICSSINTC_SRSR0);
	HWREG(baseaddr + CSL_ICSSINTC_SECR0) = srsr;
	
	srsr = HWREG(baseaddr + CSL_ICSSINTC_SRSR1);
	HWREG(baseaddr + CSL_ICSSINTC_SECR1) = srsr;
}

uint8_t ICSSEmacDRVInit(ICSS_EmacHandle handle, uint8_t instance)
{
    uint8_t retVal = -1;

    /* LLD attributes callocs */
    handle->object = (ICSS_EmacObject*)calloc(1, sizeof(ICSS_EmacObject));
    handle->hwAttrs= (ICSS_EmacHwAttrs*)calloc(1, sizeof(ICSS_EmacHwAttrs));

    /* Callback callocs */
    ICSS_EmacCallBackObject* callBackObj = (ICSS_EmacCallBackObject*)calloc(1, sizeof(ICSS_EmacCallBackObject));

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

    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs*)handle->hwAttrs)->emacBaseAddrCfg;
    ICSS_EmacSocGetInitCfg((instance-1), emacBaseAddr );


    return retVal;
}

/* Enables MDIO link interrupt */
void MDIO_enableLinkInterrupt(uint32_t mdioBaseAddress,uint32_t phyInst,uint32_t phyNum,uint8_t linkSel)
{
    uint32_t PhySel;

    PhySel=phyNum;
    PhySel |=  0x40;
    if(MDIO_LINKSEL_ENABLE == linkSel)
        PhySel |= 0x80;

       HWREG(mdioBaseAddress + CSL_MDIO_USER_PHY_SEL_REG(0) + (phyInst*8)) = PhySel;
}

void configMDIOIntr(ICSS_EmacHandle icssEmacHandle, uint8_t port)
{
    uint32_t phyNum;
    uint32_t phyinst;

	phyinst = port - 1;
	phyNum  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[0];
	MDIO_enableLinkInterrupt((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,phyinst,phyNum,
												MDIO_LINKSEL_DISABLE);
}

/* Configures ARM GIC interrupts */
void IcssEmacIntrInit(ICSS_EmacHandle icssEmacHandle)
{
    HwiP_Handle rxHwiHandle;
    HwiP_Handle linkHwiHandle;
    HwiP_Handle txHwiHandle;

    static uint32_t cookie = 0;
    uint32_t linkIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum;

    uint32_t rxIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;

    uint32_t txIntrN =   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum;

    cookie = ICSS_EMAC_osalHardwareIntDisable();

    HwiP_Params hwiParams;

    ICSS_EMAC_osalHwiParamsInit(&hwiParams);

    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;


    hwiParams.triggerSensitivity =2; /* use trigger type edge */
    rxHwiHandle = ICSS_EMAC_osalRegisterInterrupt(rxIntrN, (HwiP_Fxn)ICSS_EmacRxPktCallback, &hwiParams);
    if (rxHwiHandle == NULL ){
        return;
    }

    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;
    linkHwiHandle = ICSS_EMAC_osalRegisterInterrupt(linkIntrN, (HwiP_Fxn)ICSS_EmacLinkISR, &hwiParams);
    if (linkHwiHandle == NULL) {
        return;
    }

    hwiParams.arg = (uintptr_t)icssEmacHandle;
    hwiParams.evtId = 0;
    hwiParams.priority = 20;
    txHwiHandle = ICSS_EMAC_osalRegisterInterrupt(txIntrN, (HwiP_Fxn)ICSS_EmacTxPktCallback, &hwiParams);
    if (txHwiHandle == NULL) {
        return;
    }
    
    ((ICSS_EmacObject*)icssEmacHandle->object)->txintHandle = txHwiHandle;
    ((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle = rxHwiHandle;
    ((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle = linkHwiHandle;

    ICSS_EMAC_osalHardwareIntRestore(cookie);
}

/* De-registering the interrupts and disabling global interrupts */
void IcssEmacIntrEnd(ICSS_EmacHandle icssEmacHandle)
{
    if (icssEmacHandle != NULL)
    {
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle));
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle));
        ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->txintHandle));
    }
}

/* This function enables the EMAC interrupts */
void IcssEmacIntrEnable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key = 0;
    if (icssEmacHandle != NULL)
    {
        key = ICSS_EMAC_osalHardwareIntDisable();
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum);
        ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum);
        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}

/* This function disables the EMAC interrupts */
void IcssEmacIntrDisable(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t key;
    if (icssEmacHandle != NULL)
    {
        key = ICSS_EMAC_osalHardwareIntDisable();

        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum);
        ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum);

        ICSS_EMAC_osalHardwareIntRestore(key);
    }
}

/* Gets the status of Rx packet availability */
uint32_t pru_get_rx_complete_status(PRUICSS_Handle handle, uint8_t pruNum)
{
	PRUICSS_HwAttrs    *hwAttrs;
	uint32_t baseaddr;
	uint8_t rxStatus;

	hwAttrs = (PRUICSS_HwAttrs*)handle->hwAttrs;
	baseaddr = hwAttrs->prussIntcRegBase;

	if(pruNum == 0)
	{
		rxStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (PORT1_RX_EOF_EVENT % 32)) & 0x1;
	}
	else
	{
		rxStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (PORT2_RX_EOF_EVENT % 32)) & 0x1;
	}

	return rxStatus;
}

/* Gets the link status */
uint32_t icssemac_get_link_status(PRUICSS_Handle handle, uint8_t pruNum)
{
	PRUICSS_HwAttrs    *hwAttrs;
	uint32_t baseaddr;
	uint8_t linkStatus;

	hwAttrs = (PRUICSS_HwAttrs*)handle->hwAttrs;
	baseaddr = hwAttrs->prussIntcRegBase;

	if(pruNum == 0)
	{
		linkStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (MII_LINK0_EVENT % 32)) & 0x1;
	}
	else
	{
		linkStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (MII_LINK1_EVENT % 32)) & 0x1;
	}

	return linkStatus;
}

/* Gets the link status */
uint32_t pru_get_link_status(PRUICSS_Handle handle, uint8_t pruNum)
{
	PRUICSS_HwAttrs    *hwAttrs;
	uint32_t baseaddr;
	uint8_t linkStatus;

	hwAttrs = (PRUICSS_HwAttrs*)handle->hwAttrs;
	baseaddr = hwAttrs->prussIntcRegBase;

	if(pruNum == 0)
	{
		linkStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (MII_LINK0_EVENT % 32)) & 0x1;
	}
	else
	{
		linkStatus = (HWREG(baseaddr + CSL_ICSSINTC_SRSR1) >> (MII_LINK1_EVENT % 32)) & 0x1;
	}

	return linkStatus;
}

/* Checks for the PRU ICSS link status */
uint32_t icssemac_check_link(ICSS_EmacHandle emacHandle)
{
    uint32_t linkCheckTime = 0;
    uint32_t linkStatus = 0;

#ifndef ICSS_EMAC_TEST_POLLMODE
    /* Wait for 3 secs for link to come up */
	linkCheckTime = 0;
	UART_printf("Waiting for LINK UP, Make sure to plugin loopback cable\n");
    while (!((ICSS_EmacObject*)emacHandle->object)->linkStatus[0])
    {
		BOARD_delay(10000);
		linkCheckTime++;
		if(linkCheckTime > 300)
		{
			break;
		}
    }

	if(linkCheckTime > 300)
	{
		/* Link interrupt timeout. Check if interrupt is not generated (observed while
		   running the test multiple times) or link is not UP */
		if(pru_get_link_status(((ICSS_EmacObject*)emacHandle->object)->pruIcssHandle, ICSS_EMAC_PORT_1-1))
		{
			ICSS_EmacLinkISR(emacHandle);
            return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 1;
	}

	ICSS_EmacClearLinkIrq(emacHandle);
	CSL_armGicClearIntr(&gCpuIntrf, ((ICSS_EmacObject*)emacHandle->object)->emacInitcfg->linkIntNum);
#else
    /* Wait for 3 secs for Port 0 link to come up */
    linkCheckTime = 0;
    while (!((ICSS_EmacObject*)emacHandle->object)->linkStatus[0])
    {
        BOARD_delay(10000);
        linkCheckTime++;
        if(linkCheckTime > 300)
        {
            break;
        }

        ICSS_EmacPollControl(emacHandle, ICSS_EMAC_POLL_MODE_LINK);
    }

    if((linkCheckTime < 300) && ((ICSS_EmacObject*)emacHandle->object)->linkStatus[0])
    {
        return 1;
    }
    else
    {
        linkStatus = CSL_MDIO_phyLinkStatus((((ICSS_EmacHwAttrs const *)emacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                                               (((ICSS_EmacObject*)emacHandle->object)->emacInitcfg)->phyAddr[0]);
        if (linkStatus)
        {
            ((ICSS_EmacObject*)emacHandle->object)->linkStatus[0] = 1U;
            return 1;
        }
    }
    return 0;

#endif
}

void pru_load_firmware(PRUICSS_Handle pruIcssHandle)
{
    /* Same flow as taskPruss */
    PRUICSS_pruDisable(pruIcssHandle, PRUICCSS_PRU0);
    PRUICSS_pruDisable(pruIcssHandle, PRUICCSS_PRU1);

    if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(0) ,0,
                            (uint32_t *) &pru_imem0_rev2_start,
                            &pru_imem0_rev2_end - &pru_imem0_rev2_start))

    {
        if(PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(1) ,0,
                                (uint32_t *) &pru_imem1_rev2_start,
                                &pru_imem1_rev2_end - &pru_imem1_rev2_start))

        {
            PRUICSS_pruReset(pruIcssHandle, PRUICCSS_PRU0);
            PRUICSS_pruReset(pruIcssHandle, PRUICCSS_PRU1);
            PRUICSS_pruEnable(pruIcssHandle, PRUICCSS_PRU0);
            PRUICSS_pruEnable(pruIcssHandle, PRUICCSS_PRU1);
        }
    }
}

/* Function to close the PRU module for proper restart while repeating the test */
uint32_t icssemac_pru_close(PRUICSS_Handle pruIcssHandle)
{
    PRUICSS_pruDisable(pruIcssHandle, PRUICCSS_PRU0);
    PRUICSS_pruDisable(pruIcssHandle, PRUICCSS_PRU1);
    PRUICSS_pruReset(pruIcssHandle, PRUICCSS_PRU0);
    PRUICSS_pruReset(pruIcssHandle, PRUICCSS_PRU1);
}

/* Function to clear the interrupts for proper restart while repeating the test */
uint32_t icssemac_clear_intr(ICSS_EmacHandle emacHandle)
{
	PRUICSS_pruIntcClear(((ICSS_EmacObject*)emacHandle->object)->pruIcssHandle);
	ICSS_EmacClearIntr(((ICSS_EmacObject*)emacHandle->object)->pruIcssHandle);
	CSL_armGicDisableIntr(&gCpuIntrf, ((ICSS_EmacObject*)emac0Handle0->object)->emacInitcfg->linkIntNum);
    CSL_armGicDisableIntr(&gCpuIntrf, ((ICSS_EmacObject*)emac0Handle0->object)->emacInitcfg->rxIntNum);
	CSL_armGicDisableIntr(&gCpuIntrf, ((ICSS_EmacObject*)emac0Handle0->object)->emacInitcfg->txIntNum);  
}

/* Function to configure ICSS EMAC instance 0 */
int icss_emac0Setup(void)
{
    uint8_t firmwareLoad_done = FALSE;
    uint8_t count=0;
	uint8_t port;
    int ret;
	PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
	uint32_t linkCheckTime = 0;
    uint8_t instance = PRUSS_INSTANCE_ONE;
	
	
	pruIcss0Handle = PRUICSS_create(pruss_config,(int) instance);

	pruss_iep_Initialization(instance);
	
	PRUICSS_pinMuxConfig(pruIcss0Handle, 0x0); // PRUSS pinmuxing
    
    emac0Handle0 = (ICSS_EmacHandle)calloc(1, sizeof(ICSS_EmacConfig));
	emac0Handle1 = (ICSS_EmacHandle)calloc(1, sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg0;
	ICSS_EmacInitConfig* switchEmacCfg1;
    switchEmacCfg0 = (ICSS_EmacInitConfig*)calloc(1,sizeof(ICSS_EmacInitConfig));
	switchEmacCfg1 = (ICSS_EmacInitConfig*)calloc(1,sizeof(ICSS_EmacInitConfig));
	
    /* Port 0 configurations */
	port = ICSS_EMAC_PORT_1;
    switchEmacCfg0->phyAddr[0] = gPruicssPortInfo[instance-1][port-1].phyAddr;
	switchEmacCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE;

	switchEmacCfg0->enableIntrPacing = gPruicssPortInfo[instance-1][port-1].intrPacingCfg;
	switchEmacCfg0->portMask = ICSS_EMAC_MODE_MAC1;
	switchEmacCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    switchEmacCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
	
    switchEmacCfg0->halfDuplexEnable = 1;
    switchEmacCfg0->pacingThreshold = 100;
    switchEmacCfg0->learningEn = 0;
    SOCCtrlGetPortMacAddr(instance, port, lclMac);
    switchEmacCfg0->macId = lclMac;

    switchEmacCfg0->linkIntNum = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].linkIntr);
    switchEmacCfg0->rxIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].rxIntr);
	switchEmacCfg0->txIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].txIntr);

    ICSSEmacDRVInit(emac0Handle0, instance);     // ICSS_M instance 0

    ((ICSS_EmacObject*)emac0Handle0->object)->pruIcssHandle = pruIcss0Handle;
    ((ICSS_EmacObject*)emac0Handle0->object)->emacInitcfg = switchEmacCfg0;
	
    ICSS_EmacInit(emac0Handle0,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1);

	/* Port 1 configurations */		
    port = ICSS_EMAC_PORT_2;
    switchEmacCfg1->phyAddr[0] = gPruicssPortInfo[instance-1][port-1].phyAddr;
	switchEmacCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE;

	switchEmacCfg1->enableIntrPacing = gPruicssPortInfo[instance-1][port-1].intrPacingCfg;
	switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
	switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;

    switchEmacCfg1->halfDuplexEnable = 1;
    switchEmacCfg1->pacingThreshold = 100;
    switchEmacCfg1->learningEn = 0;
    SOCCtrlGetPortMacAddr(instance, port, lclMac);
    switchEmacCfg1->macId = lclMac;

    switchEmacCfg1->linkIntNum = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].linkIntr);
    switchEmacCfg1->rxIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].rxIntr);
	switchEmacCfg1->txIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].txIntr);

    ICSSEmacDRVInit(emac0Handle1, instance);     // ICSS_M instance 0

    ((ICSS_EmacObject*)emac0Handle1->object)->pruIcssHandle = pruIcss0Handle;
    ((ICSS_EmacObject*)emac0Handle1->object)->emacInitcfg = switchEmacCfg1;

	ICSS_EmacInit(emac0Handle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2);

#ifndef ICSS_EMAC_TEST_POLLMODE
    IcssEmacIntrInit(emac0Handle1);
    IcssEmacIntrInit(emac0Handle0);
#endif
    configMDIOIntr(emac0Handle1, ICSS_EMAC_PORT_2);
    configMDIOIntr(emac0Handle0, ICSS_EMAC_PORT_1);
#ifndef ICSS_EMAC_TEST_POLLMODE
    IcssEmacIntrEnable(emac0Handle1);
    IcssEmacIntrEnable(emac0Handle0);
#endif

    return(0);
}

/* Function to configure ICSS EMAC instance 0 */
int icss_emac1Setup(void)
{
    uint8_t firmwareLoad_done = FALSE;
    uint8_t count=0;
	uint8_t port;
    int ret;
	PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
	ICSS_EmacHandle emachandle;
	uint32_t linkCheckTime = 0;
    uint8_t instance = PRUSS_INSTANCE_TWO;


	pruIcss1Handle = PRUICSS_create(pruss_config,(int) instance);

	pruss_iep_Initialization(instance);

	PRUICSS_pinMuxConfig(pruIcss1Handle, 0x0); // PRUSS pinmuxing

    emac1Handle0 = (ICSS_EmacHandle)calloc(1, sizeof(ICSS_EmacConfig));
	emac1Handle1 = (ICSS_EmacHandle)calloc(1, sizeof(ICSS_EmacConfig));

    ICSS_EmacInitConfig* switchEmacCfg0;
	ICSS_EmacInitConfig* switchEmacCfg1;
    switchEmacCfg0 = (ICSS_EmacInitConfig*)calloc(1,sizeof(ICSS_EmacInitConfig));
	switchEmacCfg1 = (ICSS_EmacInitConfig*)calloc(1,sizeof(ICSS_EmacInitConfig));

    /* Port 0 configurations */
	port = ICSS_EMAC_PORT_1;
    switchEmacCfg0->phyAddr[0] = gPruicssPortInfo[instance-1][port-1].phyAddr;
	switchEmacCfg0->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE;

	switchEmacCfg0->enableIntrPacing = gPruicssPortInfo[instance-1][port-1].intrPacingCfg;
	switchEmacCfg0->portMask = ICSS_EMAC_MODE_MAC1;
	switchEmacCfg0->ethPrioQueue = ICSS_EMAC_QUEUE1;
    switchEmacCfg0->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;
	
    switchEmacCfg0->halfDuplexEnable = 1;
    switchEmacCfg0->pacingThreshold = 100;
    switchEmacCfg0->learningEn = 0;
    SOCCtrlGetPortMacAddr(instance, port, lclMac);
    switchEmacCfg0->macId = lclMac;

    switchEmacCfg0->linkIntNum = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].linkIntr);
    switchEmacCfg0->rxIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].rxIntr);
	switchEmacCfg0->txIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].txIntr);

    ICSSEmacDRVInit(emac1Handle0, instance);     // ICSS_M instance 0

    ((ICSS_EmacObject*)emac1Handle0->object)->pruIcssHandle = pruIcss1Handle;
    ((ICSS_EmacObject*)emac1Handle0->object)->emacInitcfg = switchEmacCfg0;

	ICSS_EmacInit(emac1Handle0,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC1);

	/* Port 1 configurations */
    port = ICSS_EMAC_PORT_2;
    switchEmacCfg1->phyAddr[0] = gPruicssPortInfo[instance-1][port-1].phyAddr;
	switchEmacCfg1->ICSS_EmacTTSEnableCycPktInterrupt = ICSS_EMAC_TTS_CYC_INTERRUPT_DISABLE;

	switchEmacCfg1->enableIntrPacing = gPruicssPortInfo[instance-1][port-1].intrPacingCfg;
	switchEmacCfg1->portMask = ICSS_EMAC_MODE_MAC2;
	switchEmacCfg1->ethPrioQueue = ICSS_EMAC_QUEUE3;
    switchEmacCfg1->ICSS_EmacIntrPacingMode = ICSS_EMAC_INTR_PACING_MODE1;

    switchEmacCfg1->halfDuplexEnable = 1;
    switchEmacCfg1->pacingThreshold = 100;
    switchEmacCfg1->learningEn = 0;
    SOCCtrlGetPortMacAddr(instance, port, lclMac);
    switchEmacCfg1->macId = lclMac;

    switchEmacCfg1->linkIntNum = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].linkIntr);
    switchEmacCfg1->rxIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].rxIntr);
	switchEmacCfg1->txIntNum   = CSL_armGicGetGicIdForIrqInputLine(gPruicssPortInfo[instance-1][port-1].txIntr);

    ICSSEmacDRVInit(emac1Handle1, instance);     // ICSS_M instance 0

    ((ICSS_EmacObject*)emac1Handle1->object)->pruIcssHandle = pruIcss1Handle;
    ((ICSS_EmacObject*)emac1Handle1->object)->emacInitcfg = switchEmacCfg1;

	ICSS_EmacInit(emac1Handle1,&pruss_intc_initdata,ICSS_EMAC_MODE_MAC2);

#ifndef ICSS_EMAC_TEST_POLLMODE
    IcssEmacIntrInit(emac1Handle1);
    IcssEmacIntrInit(emac1Handle0);
#endif
    configMDIOIntr(emac1Handle1, ICSS_EMAC_PORT_2);
    configMDIOIntr(emac1Handle0, ICSS_EMAC_PORT_1);
#ifndef ICSS_EMAC_TEST_POLLMODE
    IcssEmacIntrEnable(emac1Handle1);
    IcssEmacIntrEnable(emac1Handle0);
#endif

    return(0);
}

/* Executes ICSS EMAC loopback test */
int icss_emacTest(void)
{
    uint8_t firmwareLoad_done = FALSE;
    uint8_t count=0;
	uint8_t port, instance;
    int32_t ret;
    ICSS_EmacTxArgument txArg;
	PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
	ICSS_EmacHandle emachandle;
    PRUICSS_Handle pruIcssHandle;
	uint32_t linkCheckTime = 0;

    memset(&txArg, 0, sizeof(ICSS_EmacTxArgument));

    icss_emac0Setup();
    icss_emac1Setup();
    
    pru_load_firmware(pruIcss0Handle);
    pru_load_firmware(pruIcss1Handle);

    UART_printf("Waiting for LINK UP, Make sure to plugin loopback cable\n");
    if(icssemac_check_link(emac0Handle0))
    {
        UART_printf("PRU_ICSS0 port 0 LINK IS UP!\n");
    }
    else
    {
        UART_printf("PRU_ICSS0 port 0 LINK TIMEOUT!!\n");
    }
    
    if(icssemac_check_link(emac0Handle1))
    {
        UART_printf("PRU_ICSS0 port 1 LINK IS UP!\n");
    }
    else
    {
        UART_printf("PRU_ICSS0 port 1 LINK TIMEOUT!!\n");
    }

    if(icssemac_check_link(emac1Handle0))
    {
        UART_printf("PRU_ICSS1 port 0 LINK IS UP!\n");
    }
    else
    {
        UART_printf("PRU_ICSS1 port 0 LINK TIMEOUT!!\n");
    }

    if(icssemac_check_link(emac1Handle1))
    {
        UART_printf("PRU_ICSS1 port 1 LINK IS UP!\n");
    }
    else
    {
        UART_printf("PRU_ICSS1 port 1 LINK TIMEOUT!!\n");
    }

    packetRcvd_port0 = 1;
	totalPktRcvd = 0;
    /* send the packet */

    for (instance = PRUSS_INSTANCE_ONE; instance <= PRUSS_INSTANCE_TWO; instance++)
    {
        for (port = ICSS_EMAC_PORT_1; port <= ICSS_EMAC_PORT_2; port++)
        {
            if(port == ICSS_EMAC_PORT_1)
            {
                if(instance == PRUSS_INSTANCE_ONE)
                {
                    pruIcssHandle = pruIcss0Handle;
                    emachandle = emac0Handle0;
                }
                else
                {
                    pruIcssHandle = pruIcss1Handle;
                    emachandle = emac1Handle0;
                }
            }
            else
            {
                if(instance == PRUSS_INSTANCE_ONE)
                {
                    pruIcssHandle = pruIcss0Handle;
                    emachandle = emac0Handle1;
                }
                else
                {
                    pruIcssHandle = pruIcss1Handle;
                    emachandle = emac1Handle1;
                }
            }

            totalPktRcvd = 0;
            UART_printf("\nSending Packets on PRU%d Port %d\n", (instance-1), (port-1));
            for (count = 0; count < PKT_TX_COUNT; count++)
            {
                UART_printf("Sending Pkt %d on port: %d, queue 3\n", count, port);
                {
                    if(packetRcvd_port0)
                    {
                        txArg.icssEmacHandle = emachandle;
                        txArg.srcAddress = &test_pkt[0];
                        txArg.portNumber = port;
                        txArg.queuePriority = 3;
                        txArg.lengthOfPacket = TEST_PKT_SIZE;
                        packetRcvd_port0 = 0;
                        ret = ICSS_EmacTxPacket(&txArg, NULL);
                        if (ret != 0) {
                            UART_printf("Error sending packet with return: %d\n", ret);
                            return (1);
                        }

                        while(!packetRcvd_port0)
                        {
                            if(pru_get_rx_complete_status(pruIcssHandle, port-1))
                            {
                                ICSS_EmacRxPktCallback(emachandle);
                            }

                            BOARD_delay(1000);
                        }

                        BOARD_delay(1000);
                        if (!(memcmp(&packet_array[0], &test_pkt[0],TEST_PKT_SIZE)))
                        {
                            memset(&packet_array[0], 0, TEST_PKT_SIZE);
                            UART_printf("Received pkt: %d\n", totalPktRcvd);
                            totalPktRcvd++;
                        }
                        else
                        {
                            UART_printf("Unit Test Failure, packet mismatch occured\n");
                            return (1);
                            break;
                        }
                    }
                }
            }
        }
    }

    if (totalPktRcvd == PKT_TX_COUNT)
    {
        UART_printf("All tests have passed\n");
    }

	/* Clear and disable the interrupts to repeat the test cleanly */
    ICSS_EmacDeInit(emac0Handle0, ICSS_EMAC_MODE_MAC1);
    ICSS_EmacDeInit(emac0Handle1, ICSS_EMAC_MODE_MAC2);
    ICSS_EmacDeInit(emac1Handle0, ICSS_EMAC_MODE_MAC1);
    ICSS_EmacDeInit(emac1Handle1, ICSS_EMAC_MODE_MAC2);
#ifndef ICSS_EMAC_TEST_POLLMODE    
    icssemac_clear_intr(emac0Handle0);
    icssemac_clear_intr(emac0Handle1);
    icssemac_clear_intr(emac1Handle0);
    icssemac_clear_intr(emac1Handle1);
#endif
    icssemac_pru_close(pruIcss0Handle);
    icssemac_pru_close(pruIcss1Handle);

    return(0);
}

/* Function to read ICSS Ethernet PHY status and strapping registers
   for debug purpose */
void getPhyRegDump(uint32_t baseAddr, uint32_t phyAddr)
{
    uint16_t regAddr;
    uint16_t regVal = 0;

    UART_printf("\n\n******************************************************\n");
    UART_printf("Register Dump for PHY Addr - 0x%04X\n", phyAddr);

    for (regAddr = 0; regAddr < BOARD_ICSS_EMAC_REG_DUMP_MAX; regAddr++)
    {
        CSL_MDIO_phyRegRead(baseAddr, phyAddr, regAddr, &regVal);
        UART_printf("PHY Register 0x%04X - 0x%04X\n", regAddr, regVal);
    }

    Mdio_PhyExtendedRegRead(baseAddr, phyAddr, BOARD_ICSS_EMAC_STRAP_STS1_ADDR, &regVal);
    UART_printf("PHY Register(STRAP1) 0x%04X - 0x%04X\n", BOARD_ICSS_EMAC_STRAP_STS1_ADDR, regVal);
    Mdio_PhyExtendedRegRead(baseAddr, phyAddr, BOARD_ICSS_EMAC_STRAP_STS2_ADDR, &regVal);
    UART_printf("PHY Register(STRAP2) 0x%04X - 0x%04X\n", BOARD_ICSS_EMAC_STRAP_STS2_ADDR, regVal);
    UART_printf("\n******************************************************\n\n");
}

int icss_emacMain(void)
{
	int ret = 0;

    UART_printf("\n\nReading ICSS Ethernet PHY Register Dump...\n");
    getPhyRegDump(CSL_ICSS_0_MII_MDIO_REGS, BOARD_ICSS_EMAC_PORT0_PHY_ADDR);
    getPhyRegDump(CSL_ICSS_0_MII_MDIO_REGS, BOARD_ICSS_EMAC_PORT1_PHY_ADDR);
    getPhyRegDump(CSL_ICSS_1_MII_MDIO_REGS, BOARD_ICSS_EMAC_PORT2_PHY_ADDR);
    getPhyRegDump(CSL_ICSS_1_MII_MDIO_REGS, BOARD_ICSS_EMAC_PORT3_PHY_ADDR);
    
    UART_printf("\n\nPRU ICSS Loopback Test\n");
	ret = icss_emacTest();
	UART_printf("\nPRU ICSS Loopback Test Completed!\n");
	
	return ret;
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
	int ret;

    DIAG_IntrInit();
#ifndef ICSS_EMAC_TEST_POLLMODE    
	CSL_A15_INIT_copyVectorTable();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO |
        BOARD_INIT_ICSS_ETH_PHY;
#else
    boardCfg = BOARD_INIT_UART_STDIO |
               BOARD_INIT_ICSS_ETH_PHY;
#endif
    Board_init(boardCfg);

    BOARD_delay(1000);

    /* Calling the main */
    ret = icss_emacMain();
		
	return ret;
}
