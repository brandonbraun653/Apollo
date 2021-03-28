/**
 *  \file   emac_ioctl.c
 *
 *  \brief  emac driver IOCTL implementaion for ICSSG IP
 *
*  This file contains helper functions to implement emac_ioctl API for ICSSG subsystem
 */

/*
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
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

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/
#include <stdint.h>

#include <ti/csl/soc.h>

#include "ti/csl/cslr_icss.h"

#include <ti/csl/csl_cpswitch.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/src/emac_osal.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>
#include "ti/drv/emac/src/v5/emac_drv_v5.h"
#include <ti/drv/emac/emac_ioctl.h>

extern EMAC_MCB_V5_T      emac_mcb;

extern void emac_hw_mem_write(uint32_t addr, const void *ptr, uint32_t element_count);
extern uint32_t *emac_util_get_R30_info(EMAC_IOctlR30Cmd cmd, uint32_t port, EMAC_IcssgInstance icssg);

extern int32_t
emac_udma_ring_dequeue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T     **pHostDescriptor
);


extern EMAC_DRV_ERR_E
emac_udma_ring_enqueue
(
    Udma_RingHandle ringHandle,
    EMAC_CPPI_DESC_T *pHostDescriptor,
    uint32_t            packetSize
);

extern uint16_t emac_util_fdb_helper(uintptr_t vlan_table, uint16_t vlan_id,  uint8_t mac[], uint8_t * p_fid);

#if defined (EMAC_INCOHERENT)
EMAC_IOCTL_CMD_T cmd1Icssg __attribute__ ((aligned (EMAC_CACHELINE_ALIGNMENT)));
EMAC_IOCTL_CMD_T cmd2Icssg __attribute__ ((aligned (EMAC_CACHELINE_ALIGNMENT)));
#else
EMAC_IOCTL_CMD_T cmd1Icssg;
EMAC_IOCTL_CMD_T cmd2Icssg;
#endif

uintptr_t emac_get_vlan_tbl_addr(uint32_t port_num)
{
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;

    emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
    pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
    return (emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->defaultVlanTblOffset);
}

void emac_get_vlan_id(uint32_t port_num, EMAC_IOCTL_FDB_ENTRY *pEntry)
{
    uintptr_t regAddr;

    if (pEntry->vlanId == EMAC_VLAN_UNTAGGED)
    {
        /* if EMAC_VLAN_UNTAGGED, get default vlanId */
        regAddr = emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_DF_VLAN;
        pEntry->vlanId = CSL_REG32_RD (regAddr);
    }
}

void emac_update_cmd(uint32_t port_num, uint32_t ioctlCmd, EMAC_IOCTL_CMD_T *pCmd,EMAC_IOCTL_PARAMS *pParams, EMAC_IOCTL_FDB_ENTRY *pEntry, uint32_t cmdType, uint16_t broadSideSlot, uint8_t fid)
{
    memset(pCmd, 0, sizeof(EMAC_IOCTL_CMD_T));

    pCmd->commandHeader = EMAC_FW_MGMT_CMD_HEADER;
    pCmd->commandType = cmdType;
    pCmd->seqNumber = pParams->seqNumber;
    pCmd->commandParam |= pParams->subCommand;

    if(port_num == 2)
    {
        pCmd->commandParam |= (1 << 4);
    }
    if (ioctlCmd == EMAC_IOCTL_FDB_ENTRY_CTRL)
    {
        switch (pParams->subCommand)
        {
            case EMAC_IOCTL_FDB_ENTRY_ADD:
            case EMAC_IOCTL_FDB_ENTRY_DELETE:
                if(pEntry)
                {
                    memcpy((void*)(&pCmd->spare[0]), (void*)(&pEntry->mac[0]), 4);
                    memcpy((void*)(&pCmd->spare[1]), (void*)(&pEntry->mac[4]), 2);
                    pCmd->spare[2] = broadSideSlot;
                    pCmd->spare[1] = pCmd->spare[1] | (fid << 16);
                    pCmd->spare[1] = pCmd->spare[1] | (pEntry->fdbEntry[port_num >> 1]<< 24);
                }
                break;
            case EMAC_IOCTL_FDB_ENTRY_DELETE_ALL:
                pCmd->spare[0] = 0x0;
                break;
            case EMAC_IOCTL_FDB_ENTRY_DELETE_ALL_AGEABLE:
                pCmd->spare[0] = 0x000000008;
                break;
            default:
                break;
        }
    }
}


void emac_ioctl_get_fw_config(uint32_t port_num, EMAC_PER_PORT_ICSSG_FW_CFG **pEmacFwCfg)
{
    emac_mcb.port_cb[port_num].getFwCfg(port_num,pEmacFwCfg);
}

EMAC_DRV_ERR_E  emac_ioctl_send_mgmt_msg(uint32_t port_num, EMAC_IOCTL_CMD_T* p_cmd, EMAC_CPPI_DESC_T* p_tx_cppi_desc);

/*
 *  ======== emac_ioctl_icss_add_mac ========
 */
void emac_ioctl_icss_add_mac (uint32_t port_num, uint8_t*  macAddr)
{
    int32_t macLo;
    int32_t macHi;
    int16_t temp;
    uintptr_t baseAddr;

    if (port_num < EMAC_CPSW_PORT_NUM)
    {
        baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
        macLo =  *((int32_t *) &macAddr[0]);
        temp =  *((int16_t *) &macAddr[4]);
        macHi = (int32_t) temp;
    
        if ((port_num % 2U) == 0U)
        {
            /* add mac */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_0, macLo); 
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_1, macHi); 
            /* enable filter */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU0, 0x22000000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0, 0x300U);
        
        }
        else
        {
            /* add mac */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_1, macHi);
            /* enable filter */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU1, 0x22000000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU1, 0x300U);
        }
    }
}
/*
 *  ======== emac_ioctl_icss_promiscous_ctrl ========
 */
void emac_ioctl_icss_promiscous_ctrl(uint32_t port_num, void*  ctrl)
{
    uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
    if(1U == *((uint32_t*)ctrl))
    {
        if ((port_num % 2U) == 0U)
        {
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_START_LEN_PRU0, 0x60000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_CFG_PRU0, 0x5555U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA0_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA1_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK0_PRU0, 0xFFFFFFFEU);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK1_PRU0, 0xFFFFU);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU0, 0x60010000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0, 0x300U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0, 0x0U);
        }
        else
        {
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_START_LEN_PRU1, 0x60000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_CFG_PRU1, 0x5555U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA0_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA1_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK0_PRU1, 0xFFFFFFFEU);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK1_PRU1, 0xFFFFU);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU1, 0x60010000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU1, 0x300U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU1, 0x0U);
        }
    }
    else
    {
         if ((port_num % 2U) == 0U)
        {
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_START_LEN_PRU0, 0x60000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_CFG_PRU0, 0x5555U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA0_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA1_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK0_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK1_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU0, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU0, 0x22000000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0, 0x300U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0, 0x0U);
        }
        else
        {
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_START_LEN_PRU1, 0x60000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_CFG_PRU1, 0x5555U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA0_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA1_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK0_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_0_DA_MASK1_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_AND_EN_PRU1, 0x0U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU1, 0x22000000U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU1, 0x300U);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU1, 0x0U);
        }
    }
}

/*
 *  ======== emac_ioctl_test_multi_flow ========
 */
void emac_ioctl_test_multi_flow(uint32_t port_num, void*  ctrl)
{
    uint32_t tempVal;
    int32_t macLo;
    int32_t macHi;
    int16_t temp;
    EMAC_MAC_ADDR_T * pMacAddr = (EMAC_MAC_ADDR_T*)ctrl;
    uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if ((port_num % 2U) == 0)
    {
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        /* Update filter with mac address */
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA0_PRU0, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA1_PRU0, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA_MASK0_PRU0, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA_MASK1_PRU0, 0);

        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU0);
        tempVal |= 0x20000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU0, tempVal);

        pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA0_PRU0, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA1_PRU0, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA_MASK0_PRU0, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA_MASK1_PRU0, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS1_OR_EN_PRU0);
        tempVal |= 0x40000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS1_OR_EN_PRU0, tempVal);

        pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA0_PRU0, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA1_PRU0, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA_MASK0_PRU0, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA_MASK1_PRU0, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS2_OR_EN_PRU0);
        tempVal |= 0x80000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS2_OR_EN_PRU0, tempVal);

        pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA0_PRU0, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA1_PRU0, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA_MASK0_PRU0, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA_MASK1_PRU0, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS3_OR_EN_PRU0);
        tempVal |= 0x100000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS3_OR_EN_PRU0, tempVal);

        /* Allow packet to be excepted */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU0);
        tempVal |= 0x1E0000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU0, tempVal);
    }
    else
    {
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA0_PRU1, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA1_PRU1, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA_MASK0_PRU1, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_1_DA_MASK1_PRU1, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU1);
        tempVal |= 0x20000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU1, tempVal);

        pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA0_PRU1, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA1_PRU1, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA_MASK0_PRU1, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_2_DA_MASK1_PRU1, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS1_OR_EN_PRU1);
        tempVal |= 0x40000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS1_OR_EN_PRU1, tempVal);

        pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA0_PRU1, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA1_PRU1, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA_MASK0_PRU1, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_3_DA_MASK1_PRU1, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS2_OR_EN_PRU1);
        tempVal |= 0x80000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS2_OR_EN_PRU1, tempVal);

       pMacAddr++;
        macLo =  *((int32_t *) &pMacAddr->addr[0]);
        temp =  *((int16_t *) &pMacAddr->addr[4]);
        macHi = (int32_t) temp;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA0_PRU1, macLo);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA1_PRU1, macHi);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA_MASK0_PRU1, 0);
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT1_4_DA_MASK1_PRU1, 0);
        /* Update the classi */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS3_OR_EN_PRU1);
        tempVal |= 0x100000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS3_OR_EN_PRU1, tempVal);

        /* Allow packet to be excepted */
        tempVal = CSL_REG32_RD(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU1);
        tempVal |= 0x1E0000;
        CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS4_OR_EN_PRU1, tempVal);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);

}

/* classifer  utilities*/
/*
 *  ======== emac_make_class_addr ========
 */
physptr_t emac_make_class_addr(physptr_t inst, physptr_t base, int32_t classi)
{
    physptr_t addr = inst+ base + classi*8;
    return addr;
}

/*
 *  ======== emac_make_class_cfg_addr ========
 */
physptr_t emac_make_class_cfg_addr(physptr_t inst, physptr_t base)
{
    physptr_t addr = inst + base + EMAC_CLASS_CFG1_OFF;
    return addr;
}

/*
 *  ======== emac_classifier_disable ========
 */
void emac_classifier_disable(uint32_t port_num)
{
    uint32_t classi;
    uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
    physptr_t addr;
    uint32_t temp;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    for(classi=0;classi<EMAC_NUM_CLASSIFIERS;classi++)
    {
        addr = emac_make_class_addr((physptr_t) baseAddr,((port_num % 2U) ==0)?CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU0: CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU1,classi);
        CSL_REG32_WR(addr+ EMAC_CLASS_AND_EN_OFF, 0x0);
        CSL_REG32_WR(addr+ EMAC_CLASS_OR_EN_OFF, 0x0);

        addr = emac_make_class_cfg_addr((physptr_t)baseAddr, ((port_num % 2U) ==0)? CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU0 : CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU1);
        temp = CSL_REG32_RD(addr+EMAC_CLASS_CFG2_OFF);
        temp &= ~(1U<< (classi+16U));
        temp &= ~(1U<< (classi));
        CSL_REG32_WR(addr+ EMAC_CLASS_CFG2_OFF, temp);
        temp = CSL_REG32_RD(addr);
        /* clear the bits */
        temp &= ~(0x3U << (classi*2U));
        temp |=    (0U << (classi *2U));
        CSL_REG32_WR(addr,temp);
        
        temp = CSL_REG32_RD(addr+EMAC_CLASS_GATE_OFF);
        /*clear the classi & allow masks */
        temp &= ~(0x60U );
        /*set rate & phase masks */
          temp |= (0x50U);
        CSL_REG32_WR(addr+EMAC_CLASS_GATE_OFF+classi*4, temp);

    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);
}

/*
 *  ======== emac_switch_vlan_init ========
 */
void emac_switch_vlan_init(uint32_t port_num,EMAC_OPEN_CONFIG_INFO_T *p_config)
{
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    EMAC_HwAttrs_V5 *hwAttrs = (EMAC_HwAttrs_V5*)p_config->hwAttrs;
    uint32_t vlanDefaultTblOffset;
    uint32_t regVal;
    uintptr_t regAddr;
    int32_t vlanEntry;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if((port_num % 2) ==0)
    {
        emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        vlanDefaultTblOffset = pSwitchFwCfg->defaultVlanTblOffset;

        /* Program Port VLAN in MMR */
        regAddr = hwAttrs->portCfg[port_num].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_DF_VLAN;
        regVal = 0;

        CSL_REG32_WR (regAddr, regVal);

        /*Proam VLAN TABLE address in MMR*/
        regAddr = hwAttrs->portCfg[port_num].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG1;
        regVal = CSL_REG32_RD (regAddr);
        CSL_REG32_FINS(regAddr,
                   ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG1_SMEM_VLAN_OFFSET,
                   CSL_ICSS_G_RAM_SLV_RAM_REGS_BASE + vlanDefaultTblOffset);

        regVal = CSL_REG32_RD (regAddr);
        /* Enable VLAN FDB in MMR */
        regAddr = hwAttrs->portCfg[port_num].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG2;
        regVal =CSL_REG32_RD (regAddr);

        regVal |= (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG2_FDB_PRU0_EN_SHIFT)| 
                  (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG2_FDB_PRU1_EN_SHIFT)| 
                  (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG2_FDB_HOST_EN_SHIFT)| 
                  (0x1 << CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_GEN_CFG2_FDB_VLAN_EN_SHIFT);

        CSL_REG32_WR (regAddr,regVal);
        
        regVal = CSL_REG32_RD (regAddr);

        /* Initialize VLAN-FID table to 0, do two entries at a time (4 byte) */
        for(vlanEntry=0; vlanEntry<2048; vlanEntry++) 
            CSL_REG32_WR((hwAttrs->portCfg[port_num].icssSharedRamBaseAddr+ vlanDefaultTblOffset) +vlanEntry*4, 0);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);
}


/*
 *  ======== emac_ioctl_vlan_ctrl_get_entry ========
 */
EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_get_entry(uint32_t port_num, void* ctrl)
{
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    uint16_t readEntry;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_IOCTL_VLAN_FID_ENTRY *pVlanTblEntry = (EMAC_IOCTL_VLAN_FID_ENTRY*)ctrl;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if (pVlanTblEntry->vlanId> (EMAC_VLAN_TBL_MAX_ENTRIES-1))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, invalid vlan id parameter: %d",port_num, pVlanTblEntry->vlanId);
        retVal = EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID;
    }
    else
    {
        if ((port_num & 1) == 0)
        {
            emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
            pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
            readEntry = CSL_REG16_RD((emac_mcb.port_cb[port_num].icssSharedRamBaseAddr+ pSwitchFwCfg->defaultVlanTblOffset) +pVlanTblEntry->vlanId*2);
            pVlanTblEntry->vlanFidPrams.hostMember  = readEntry& 0x1;
            pVlanTblEntry->vlanFidPrams.p1Member    = (readEntry & 0x2) >> 0x1;
            pVlanTblEntry->vlanFidPrams.p2Member    = (readEntry & 0x4) >> 0x2;
            pVlanTblEntry->vlanFidPrams.hostTagged  = (readEntry & 0x8) >> 0x3;
            pVlanTblEntry->vlanFidPrams.p1Tagged    = (readEntry & 0x10) >> 0x4;
            pVlanTblEntry->vlanFidPrams.p2Tagged    = (readEntry & 0x20) >> 0x5;
            pVlanTblEntry->vlanFidPrams.streamVid   = (readEntry & 0x40) >> 0x6;
            pVlanTblEntry->vlanFidPrams.floodToHost = (readEntry & 0x80) >> 0x7;
            pVlanTblEntry->vlanFidPrams.fid         = (readEntry & 0xff00) >> 0x8;
        }
   }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_vlan_ctrl_set_entry ========
 */
EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_entry(uint32_t port_num, void* ctrl)
{
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    uint16_t  vlanEntry;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    EMAC_IOCTL_VLAN_FID_ENTRY *pVlanTblEntry = (EMAC_IOCTL_VLAN_FID_ENTRY*)ctrl;

    if (pVlanTblEntry->vlanId> (EMAC_VLAN_TBL_MAX_ENTRIES-1))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, invalid vlan id parameter: %d",port_num, pVlanTblEntry->vlanId);
        retVal = EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID;
    }
    else
    {
        if ((port_num & 1) == 0)
        {
            emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
            pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
            vlanEntry = (pVlanTblEntry->vlanFidPrams.hostMember) | (pVlanTblEntry->vlanFidPrams.p1Member << 1) |
                     (pVlanTblEntry->vlanFidPrams.p2Member << 2)  | (pVlanTblEntry->vlanFidPrams.hostTagged << 3)|
                     (pVlanTblEntry->vlanFidPrams.p1Tagged << 4)  | (pVlanTblEntry->vlanFidPrams.p2Tagged << 5) |
                    (pVlanTblEntry->vlanFidPrams.streamVid << 6) | (pVlanTblEntry->vlanFidPrams.floodToHost << 7);
            
            vlanEntry  |=  (pVlanTblEntry->vlanFidPrams.fid<< 8);
            CSL_REG16_WR(( emac_mcb.port_cb[port_num].icssSharedRamBaseAddr+ pSwitchFwCfg->defaultVlanTblOffset) +pVlanTblEntry->vlanId*2, vlanEntry);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_vlan_ctrl_set_default_tbl ========
 */
void emac_ioctl_vlan_ctrl_set_default_tbl(uint32_t port_num, void* ctrl)
{
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    EMAC_IOCTL_VLAN_FID_PARAMS *pVlanTblEntryParams = (EMAC_IOCTL_VLAN_FID_PARAMS*)ctrl;
    uint32_t count;
    uint16_t vlanEntry;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if ((port_num & 1) == 0)
    {
        emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        vlanEntry = (pVlanTblEntryParams->hostMember) | (pVlanTblEntryParams->p1Member << 1) |
                        (pVlanTblEntryParams->p2Member << 2)  | (pVlanTblEntryParams->hostTagged << 3)|
                        (pVlanTblEntryParams->p1Tagged << 4)  | (pVlanTblEntryParams->p2Tagged << 5) |
                        (pVlanTblEntryParams->streamVid << 6) | (pVlanTblEntryParams->floodToHost << 7);

        vlanEntry  |=  (pVlanTblEntryParams->fid << 8);

        /* Initialize VLAN-FID table */
        for(count=0U; count < (EMAC_VLAN_TBL_MAX_ENTRIES-1U); count++)
        {
            CSL_REG16_WR(( emac_mcb.port_cb[port_num].icssSharedRamBaseAddr+ pSwitchFwCfg->defaultVlanTblOffset) +count*2U, vlanEntry);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);
}

/*
*  ======== emac_ioctl_vlan_ctrl_set_default_vlan_id_host_port ========
*/
EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_default_vlan_id_host_port(uint32_t port_num, void* ctrl)
{
    uintptr_t regAddr;
    uint32_t regVal=0;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    uint8_t tempByte1 = 0;
    uint8_t tempByte2 = 0;

    EMAC_IOCTL_VLAN_DEFAULT_ENTRY *vlanDefaultEntry= (EMAC_IOCTL_VLAN_DEFAULT_ENTRY*)ctrl;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if (vlanDefaultEntry->vlanId >= (EMAC_VLAN_TBL_MAX_ENTRIES-1) || ((vlanDefaultEntry->vlanId) == 0))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, invalid vlan id parameter: %d",port_num, vlanDefaultEntry->vlanId);
        retVal = EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID;
    }
    else
    {
        emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        /* Write Host default VLAN to memory. This is used directly to update MMR for inserting VLAN tag */
        /*Populate first byte which contains 3 bits of PCP + 1 bit of DEI and 4 bits of VLAN*/
        tempByte1 = (uint8_t)(vlanDefaultEntry->pcp << 5) | (uint8_t)((uint16_t)vlanDefaultEntry->vlanId >> 8);
        /*Populate second byte which contains 8 bits of VLAN*/
        tempByte2 = (uint8_t)((uint16_t)vlanDefaultEntry->vlanId & 0xFF);  /*Lower 8 bits*/
    
        /* Write Host default VLAN to memory. This is used directly to update MMR for inserting VLAN tag . DEI is 0*/
        /*OR the values*/
        regVal = (uint32_t)(0x0081) | ((uint32_t)tempByte1 << 16) | ((uint32_t)tempByte2 << 24);
    
        regAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort0DefaultVlanOffset;
        CSL_REG32_WR (regAddr, regVal);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
*  ======== emac_ioctl_vlan_ctrl_set_default_vlan_id ========
*/
EMAC_DRV_ERR_E emac_ioctl_vlan_ctrl_set_default_vlan_id(uint32_t port_num, void* ctrl)
{
    uintptr_t regAddr;
    uint32_t regVal=0;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    uint8_t tempByte1 = 0;
    uint8_t tempByte2 = 0;
    uint32_t prioMapOffset;
    EMAC_IOCTL_VLAN_DEFAULT_ENTRY *vlanDefaultEntry= (EMAC_IOCTL_VLAN_DEFAULT_ENTRY*)ctrl;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if (vlanDefaultEntry->vlanId >= (EMAC_VLAN_TBL_MAX_ENTRIES-1) || ((vlanDefaultEntry->vlanId) == 0))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, invalid vlan id parameter: %d",port_num, vlanDefaultEntry->vlanId);
        retVal = EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID;
    }
    else
    {
        emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        /* Program Port VLAN in HW MMR, SW1 and SW2 for both ICSSG instances*/
        regAddr = emac_mcb.port_cb[port_num].icssgCfgRegBaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FDB_DF_VLAN;
        CSL_REG32_WR (regAddr, vlanDefaultEntry->vlanId);

        /*Populate first byte which contains 3 bits of PCP + 1 bit of DEI and 4 bits of VLAN*/
        tempByte1 = (uint8_t)(vlanDefaultEntry->pcp << 5) | (uint8_t)((uint16_t)vlanDefaultEntry->vlanId >> 8);
        /*Populate second byte which contains 8 bits of VLAN*/
        tempByte2 = (uint8_t)((uint16_t)vlanDefaultEntry->vlanId & 0xFF);  /*Lower 8 bits*/
        
        /* Write Host default VLAN to memory. This is used directly to update MMR for inserting VLAN tag . DEI is 0*/
        /*OR the values*/
        regVal = (uint32_t)(0x0081) | ((uint32_t)tempByte1 << 16) | ((uint32_t)tempByte2 << 24);
        
        /* Update for host port */
        if(port_num == 0)
        {
            regAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort1DefaultVlanOffset;
        }
        else
        {
            regAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort2DefaultVlanOffset;
        }
        CSL_REG32_WR (regAddr, regVal);

        /* Update Deafult Queue number for untagged packet*/
        prioMapOffset = pSwitchFwCfg->prioMappingTableOffset;
        tempByte1 = CSL_REG8_RD(emac_mcb.port_cb[port_num].icssDram0BaseAddr + prioMapOffset + vlanDefaultEntry->pcp);
        if(port_num == 0)
        {
            regAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort1UntaggedQueue;
        }
        else
        {
            regAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort2UntaggedQueue;
        }
        CSL_REG8_WR (regAddr, tempByte1);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

EMAC_DRV_ERR_E emac_icssg_filter3_config (uint32_t port_num, uint32_t pruNum, uint32_t filterNum, EMAC_FILTER3_CONFIG* ftConfig)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

    uintptr_t icssg_filter_base, offsetToFt3Pattern = (CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT3_0_P0_PRU0-CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT3_0_START_PRU0);

    if (pruNum == 0)
        icssg_filter_base = baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT3_0_START_PRU0;
    else if (pruNum == 1)
        icssg_filter_base = baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_FT3_0_START_PRU1;
    else
        retVal = EMAC_DRV_RESULT_IOCTL_ERR;

    if (retVal == EMAC_DRV_RESULT_OK)
    {
        CSL_REG32_WR((icssg_filter_base+filterNum*32), ftConfig->ft3Start);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+4), ftConfig->ft3StartAuto);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+8), ftConfig->ft3StartOffset);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+12), ftConfig->ft3JmpOffset);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+16), ftConfig->ft3Len);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+20), ftConfig->ft3Config);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+24), ftConfig->ft3Type);
        CSL_REG32_WR((icssg_filter_base+filterNum*32+28), ftConfig->ft3TypeMask);
        CSL_REG32_WR((icssg_filter_base+filterNum*16+offsetToFt3Pattern), ftConfig->ft3PatternLow);
        CSL_REG32_WR((icssg_filter_base+filterNum*16+offsetToFt3Pattern+4), ftConfig->ft3PatternHigh);
        CSL_REG32_WR((icssg_filter_base+filterNum*16+offsetToFt3Pattern+8), ftConfig->ft3PatternMaskLow);
        CSL_REG32_WR((icssg_filter_base+filterNum*16+offsetToFt3Pattern+12), ftConfig->ft3PatternMaskHigh);
    }
    return retVal;
}

/*
 *  ======== emac_ioctl_port_prio_mapping_ctrl ========
 */
void emac_ioctl_port_prio_mapping_ctrl(uint32_t port_num, void*  ctrl)
{
    uint8_t index;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_INVALID_PORT;
    uintptr_t icssgBaseAddr;
    uint32_t prioMapOffset;
    uint8_t tempVal;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    EMAC_IOCTL_PORT_PRIO_MAP *pPrioMap;
    uint8_t untaggedQueueNum;
    uint32_t prioRegenMapOffset;

    uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
    uint32_t ft3Type = 0;
    uint32_t classSelect = 0;
    uint32_t orEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
    uint32_t andEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
    uint16_t orNvEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
    uint16_t andNvEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
    uint32_t gateConfig = 0x50;
    uint32_t tempReg = 0;
    EMAC_FILTER3_CONFIG ft3ConfigPcp = {0xc, 0, 0, 0, 0, 5, 0, 0xff1f0000, 0, 0, 0xffffffff, 0xffffffff};
    uint8_t pcp;
    uint8_t finalPrioQueueMap[EMAC_IOCTL_PRIO_MAX]={0};

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    if ((port_num == 0) || (port_num == 2U))
    {
        emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        prioMapOffset = pSwitchFwCfg->prioMappingTableOffset;

        pPrioMap = (EMAC_IOCTL_PORT_PRIO_MAP*)ctrl;
        icssgBaseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr;
        for (index = 0; index < EMAC_IOCTL_PRIO_MAX;index++)
        {
            tempVal = (uint8_t)pPrioMap->portPrioMap[index];
            CSL_REG8_WR(icssgBaseAddr + prioMapOffset + index, tempVal);
        }

        /* Re configure classifier to map incoming pcp to Queue. Take into account Prio regen config also */
        /*
            One-to-one mapping from PCP -> Traffic Class.
            Managed using FT3[0:7] and Classifier[0:7].
        */

        /* set up filter type 3's to match pcp bits */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            /*Setup FT3[0:7] to detect PCP0 - PCP7 */
            ft3Type = (uint32_t)((((uint32_t)pcp) << 21U) | 0x00000081U);
            ft3ConfigPcp.ft3Type = ft3Type;
            emac_icssg_filter3_config(port_num, 0, pcp, &ft3ConfigPcp);
        }

        /*Get the Queue mapping value from DRAM0 and calculate incoming PCP to Queue mapping*/
        emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        prioRegenMapOffset = pSwitchFwCfg->prioRegenTableOffset;

        for(pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            /* Get regenerated value for PCP = p*/
            tempVal = CSL_REG8_RD(icssgBaseAddr + prioRegenMapOffset + (pcp*4U));
            /*Shift PCP value by 5 to get the value*/
            tempVal = tempVal >> 5;

            finalPrioQueueMap[pcp] = (uint8_t)pPrioMap->portPrioMap[tempVal];
        }

        /* Build up the or lists */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            classSelect = finalPrioQueueMap[pcp];
            orEnable[classSelect] |= (1U << pcp);
        }

        /* now program classifier c */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX;pcp++ )
        {
            /* Configure OR Enable*/
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU0 + (8U*pcp)), orEnable[pcp]);
            /* Configure AND Enable */
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU0 + (8U*pcp)), andEnable[pcp]);
            tempReg = CSL_REG32_RD(baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0);
            tempReg &= ~(0x3U << (pcp * 2U));
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0), tempReg);
            /* Configure NV Enable */
            /* Configure NV Enable bits (1 bit in upper16, 1bit in lower16 */
            tempReg = CSL_REG32_RD(baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0);
            if (orNvEnable[pcp])
                tempReg |= 1U << (pcp + 16U);
            else
                tempReg &= ~(1U << (pcp + 16U));
            if (andNvEnable[pcp])
                tempReg |= 1U << (pcp);
            else
                tempReg &= ~(1U << (pcp));
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0), tempReg);
            /* Configure class gate */
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_GATES0_PRU0 + (4U * pcp)), gateConfig);
        }

        /* Update Deafult Queue number for untagged packet*/
        /*Read the configured PCP value*/
        if(port_num == 0)
        {
            baseAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort1DefaultVlanOffset;
        }
        else
        {
            baseAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort2DefaultVlanOffset;
        }
        tempVal = CSL_REG8_RD(baseAddr + 2); /*Read PCP value*/
        tempVal = tempVal >> 5; /*Shif to get the value in correct format*/
        untaggedQueueNum = pPrioMap->portPrioMap[tempVal];

        if(port_num == 0)
        {
            baseAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort1UntaggedQueue;
        }
        else
        {
            baseAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->switchPort2UntaggedQueue;
        }
        CSL_REG8_WR (baseAddr, untaggedQueueNum);
        retVal = EMAC_DRV_RESULT_OK;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",port_num);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    //return retVal;
}

/*
 *  ======== emac_switch_config_ft3_priority_tag ========
 */
void emac_switch_config_ft3_priority_tag(uint32_t port_num)
{
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    /* Program FT3[8] to detect priority tagged frames*/
    EMAC_FILTER3_CONFIG ft3ConfigPrioTagFrames =   {0xc, 0, 0, 0, 0, 5, 0x00000081, 0x00f00000, 0, 0, 0xffffffff, 0xffffffff};
    emac_icssg_filter3_config(port_num,0, 8, &ft3ConfigPrioTagFrames);
    emac_icssg_filter3_config(port_num,1, 8, &ft3ConfigPrioTagFrames);
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT",port_num);
}

/*
 *  ======== emac_ioctl_port_state_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_port_state_ctrl(uint32_t port_num, void* p_params)
{
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    int32_t currentState;
    uint32_t portLoc = 0;
    EMAC_CPPI_DESC_T *pCppiDescTx1, *pCppiDescTx2;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    emac_update_cmd(0, EMAC_IOCTL_PORT_STATE_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, NULL, EMAC_FW_MGMT_CMD_TYPE, 0, 0);
    emac_update_cmd(2, EMAC_IOCTL_PORT_STATE_CTRL, emac_mcb.ioctl_cb.pCmd2Icssg, pParams, NULL, EMAC_FW_MGMT_CMD_TYPE, 0, 0);

    currentState = emac_mcb.port_cb[port_num].emacState;

    if (port_num == 0)
    {
        portLoc = 0;
    }
    else if (port_num == 2)
    {
        portLoc =1;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",port_num);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        switch (pParams->subCommand)
        {
            case EMAC_IOCTL_PORT_STATE_DISABLE:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_DISABLE, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_DISABLE, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_BLOCKING:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_BLOCK, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_BLOCK, portLoc,EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
    
                break;
            case EMAC_IOCTL_PORT_STATE_FORWARD:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_FORWARD, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_FORWARD, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_FORWARD_WO_LEARNING:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_FORWARD_WO_LEARNING, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_FORWARD_WO_LEARNING, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_TAS_TRIGGER:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_TRIGGER, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_TRIGGER, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_TAS_ENABLE:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_ENABLE, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_ENABLE, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_TAS_RESET:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_RESET, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_RESET, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_STATE_TAS_DISABLE:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_DISABLE, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd2Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_TAS_DISABLE, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
             default:
                break;
        }
    
        /* make sure there is hw descriptor for boths ICSSG instances */
        if (emac_get_hw_cppi_tx_descs(0, 0,2U, 0, &pCppiDescTx1, &pCppiDescTx2))
        {
            emac_mcb.ioctl_cb.ioctlCount = 2;
            retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, pCppiDescTx1);
            if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
            {
                emac_free_hw_cppi_tx_desc(2U, 0, pCppiDescTx2);
                /* restore current state for the port */
                emac_mcb.port_cb[port_num].emacState = currentState;
                emac_mcb.ioctl_cb.ioctlCount = 0;
            }
            else
            {
                retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd2Icssg, pCppiDescTx2);
                if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
                {
                    UTILS_trace(UTIL_TRACE_LEVEL_UNEXPECTED, emac_mcb.drv_trace_cb, "port: %d, un-expected error, unable to sending MGMT message",port_num);
                    /* restore current state for the port */
                    emac_mcb.port_cb[port_num].emacState = currentState;
                    emac_mcb.ioctl_cb.ioctlCount = 0;
                }
            }
        }
        else
        {
            UTILS_trace(UTIL_TRACE_LEVEL_WARN, emac_mcb.drv_trace_cb, "port: %d, no tx free descriptors available",port_num);
            retVal = EMAC_DRV_RESULT_ERR_NO_FREE_DESC;
        }
    }

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_fdb_del_all ========
 */
EMAC_DRV_ERR_E emac_ioctl_fdb_del_all(uint32_t port_num, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_CPPI_DESC_T *pCppiDescTx1, *pCppiDescTx2;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    /* make sure there is hw descriptor for boths ICSSG instances */
    if (emac_get_hw_cppi_tx_descs(0, 0,2U, 0,  &pCppiDescTx1, &pCppiDescTx2))
    {
        emac_mcb.ioctl_cb.ioctlCount = 2;
        emac_update_cmd(0, EMAC_IOCTL_FDB_ENTRY_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, NULL, EMAC_FW_MGMT_FDB_CMD_TYPE, 0, 0);
        retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, pCppiDescTx1);
        if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            emac_free_hw_cppi_tx_desc(2U, 0, pCppiDescTx2);
            /* restore current state for the port */
            emac_mcb.ioctl_cb.ioctlCount = 0;
        }
        else
        {
            emac_update_cmd(2, EMAC_IOCTL_FDB_ENTRY_CTRL,  emac_mcb.ioctl_cb.pCmd2Icssg, pParams, NULL, EMAC_FW_MGMT_FDB_CMD_TYPE, 0, 0);
            retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd2Icssg, pCppiDescTx2);
            if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
            {
                UTILS_trace(UTIL_TRACE_LEVEL_UNEXPECTED, emac_mcb.drv_trace_cb, "port: %d, un-expected error when sending MGMT message",port_num);
                emac_mcb.ioctl_cb.ioctlCount = 0;
            }
        }
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_WARN, emac_mcb.drv_trace_cb, "port: %d, no tx free descriptors available error",port_num);
        retVal = EMAC_DRV_RESULT_ERR_NO_FREE_DESC;
    }
    
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_fdb_entry_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_fdb_entry_ctrl(uint32_t port_num, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_ERR_INVALID_VLAN_ID;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_CPPI_DESC_T *pCppiDescTx1, *pCppiDescTx2;

    EMAC_IOCTL_FDB_ENTRY *entry = (EMAC_IOCTL_FDB_ENTRY*)pParams->ioctlVal;
    uintptr_t vlanDefaultTblAddr;
    uint8_t fid;
    uint16_t broadSideSlot;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if ((entry->vlanId < (int16_t)(EMAC_VLAN_TBL_MAX_ENTRIES)) || (entry->vlanId == EMAC_VLAN_UNTAGGED))
    {
        vlanDefaultTblAddr = emac_get_vlan_tbl_addr(port_num);
        emac_get_vlan_id(port_num, entry);
        broadSideSlot = emac_util_fdb_helper( vlanDefaultTblAddr, entry->vlanId, entry->mac, &fid);
        emac_update_cmd(0, EMAC_IOCTL_FDB_ENTRY_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, entry, EMAC_FW_MGMT_FDB_CMD_TYPE, broadSideSlot, fid);

        /* make sure there is hw descriptor for boths ICSSG instances */
        if (emac_get_hw_cppi_tx_descs(0, 0,2U, 0, &pCppiDescTx1, &pCppiDescTx2))
        {
            emac_mcb.ioctl_cb.ioctlCount = 2;
            retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, pCppiDescTx1);
            if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
            {
                emac_free_hw_cppi_tx_desc(2U, 0, pCppiDescTx2);
                /* restore current state for the port */
                emac_mcb.ioctl_cb.ioctlCount = 0;
            }
            else
            {
                vlanDefaultTblAddr = emac_get_vlan_tbl_addr(port_num);
                emac_get_vlan_id(port_num, entry);
                broadSideSlot = emac_util_fdb_helper( vlanDefaultTblAddr, entry->vlanId, entry->mac, &fid);
                emac_update_cmd(2, EMAC_IOCTL_FDB_ENTRY_CTRL, emac_mcb.ioctl_cb.pCmd2Icssg, pParams, entry, EMAC_FW_MGMT_FDB_CMD_TYPE, broadSideSlot, fid);

                retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd2Icssg, pCppiDescTx2);
                if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
                {
                    /* restore current state for the port */
                    emac_mcb.ioctl_cb.ioctlCount = 0;
                }
            }
        }
        else
        {
            UTILS_trace(UTIL_TRACE_LEVEL_WARN, emac_mcb.drv_trace_cb, "port: %d, no tx free descriptors available error",port_num);
            retVal = EMAC_DRV_RESULT_ERR_NO_FREE_DESC;
        }
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, invalid vlan id parameter: %d",port_num, entry->vlanId);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_accept_frame_check_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_accept_frame_check_ctrl(uint32_t port_num, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    uint32_t portLoc = 0;
    uint32_t icssgInstance = 0;

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    emac_update_cmd(port_num, EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, NULL, EMAC_FW_MGMT_CMD_TYPE, 0, 0);

    if (port_num == 0)
    {
        portLoc = 0;
        icssgInstance = EMAC_ICSSG_0;
    }
    else if (port_num == 2)
    {
        portLoc =1;
        icssgInstance = EMAC_ICSSG_1;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",port_num);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        switch (pParams->subCommand)
        {
            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_VLAN_TAGGED:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_ACCEPT_TAGGED, portLoc, (EMAC_IcssgInstance)icssgInstance)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ONLY_UN_TAGGED_PRIO_TAGGED:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_ACCEPT_UNTAGGED_N_PRIO, portLoc, (EMAC_IcssgInstance)icssgInstance)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
    
                break;
            case EMAC_IOCTL_ACCEPTABLE_FRAME_CHECK_ALL_FRAMES:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_ACCEPT_ALL, portLoc, (EMAC_IcssgInstance)icssgInstance)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
             default:
                break;
        }
        emac_mcb.ioctl_cb.ioctlCount = 1;
        retVal = emac_ioctl_send_mgmt_msg(port_num, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);

        if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            emac_mcb.ioctl_cb.ioctlCount = 0;
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
    
}

/*
 *  ======== emac_ioctl_prio_regen_mapping_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_prio_regen_mapping_ctrl(uint32_t port_num, void*  ctrl)
{
    uint8_t index;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_INVALID_PORT;
    uintptr_t icssgBaseAddr;
    uint32_t prioRegenMapOffset;
    uint32_t prioMapOffset;
    uint32_t tempVal;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    EMAC_IOCTL_PRIO_REGEN_MAP *pPrioRegenMap;


    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    if ((port_num == 0) || (port_num == 2U))
    {
        pPrioRegenMap = (EMAC_IOCTL_PRIO_REGEN_MAP*)ctrl;

        /*
            One-to-one mapping from PCP -> Traffic Class.
            Managed using FT3[0:7] and Classifier[0:7].
        */
        uintptr_t baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
        uint32_t ft3Type = 0;
        uint32_t classSelect = 0;
        uint32_t orEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
        uint32_t andEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
        uint16_t orNvEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
        uint16_t andNvEnable[EMAC_IOCTL_PRIO_MAX] = {0,};
        uint32_t gateConfig = 0x50;
        uint32_t tempReg = 0;
        EMAC_FILTER3_CONFIG ft3ConfigPcp = {0xc, 0, 0, 0, 0, 5, 0, 0xff1f0000, 0, 0, 0xffffffff, 0xffffffff};
        uint8_t pcp;
        uint8_t finalPrioQueueMap[EMAC_IOCTL_PRIO_MAX]={0};

        /* set up filter type 3's to match pcp bits */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            /*Setup FT3[0:7] to detect PCP0 - PCP7 */
            ft3Type = (uint32_t)((((uint32_t)pcp) << 21U) | 0x00000081U);
            ft3ConfigPcp.ft3Type = ft3Type;
            emac_icssg_filter3_config(port_num, 0, pcp, &ft3ConfigPcp);
        }

        /*Get the Queue mapping value from DRAM0 and calculate incoming PCP to Queue mapping*/
        emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        prioMapOffset = pSwitchFwCfg->prioMappingTableOffset;
        icssgBaseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr;
        for(pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            finalPrioQueueMap[pcp] = CSL_REG8_RD(icssgBaseAddr + prioMapOffset + (pPrioRegenMap->prioRegenMap[pcp]));
        }
        /* Build up the or lists */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++)
        {
            classSelect = finalPrioQueueMap[pcp];
            orEnable[classSelect] |= (1U << pcp);
        }

        /* now program classifier c */
        for (pcp = 0U; pcp < EMAC_IOCTL_PRIO_MAX; pcp++ )
        {
            /* Configure OR Enable*/
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_OR_EN_PRU0 + (8U * pcp)), orEnable[pcp]);
            /* Configure AND Enable */
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS0_AND_EN_PRU0 + (8U * pcp)), andEnable[pcp]);
            tempReg = CSL_REG32_RD(baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0);
            tempReg &= ~(0x3U << (pcp * 2U));
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG1_PRU0), tempReg);
            /* Configure NV Enable */
            /* Configure NV Enable bits (1 bit in upper16, 1bit in lower16 */
            tempReg = CSL_REG32_RD(baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0);
            if (orNvEnable[pcp])
                tempReg |= 1U << (pcp + 16U);
            else
                tempReg &= ~(1U << (pcp + 16U));
            if (andNvEnable[pcp])
                tempReg |= 1U << (pcp);
            else
                tempReg &= ~(1U << (pcp));
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_CFG2_PRU0), tempReg);
            /* Configure class gate */
            CSL_REG32_WR((baseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_RX_CLASS_GATES0_PRU0 + (4U * pcp)), gateConfig);
        }

        emac_ioctl_get_fw_config(port_num, &pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
        prioRegenMapOffset = pSwitchFwCfg->prioRegenTableOffset;

        icssgBaseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr;
        for (index = 0; index < EMAC_IOCTL_PRIO_MAX;index++)
        {
            tempVal = (uint32_t)pPrioRegenMap->prioRegenMap[index];
            /*Shift PCP value by 5 so HW can save a cycle*/
            tempVal = tempVal << 5; 
            emac_hw_mem_write(icssgBaseAddr +prioRegenMapOffset + (index*4),(void*)&tempVal,1);
        }
        retVal = EMAC_DRV_RESULT_OK;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",port_num);
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}


/*
 *  ======== emac_ioctl_uc_flooding_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_uc_flooding_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    uint32_t portLoc = 0;
    uint32_t icssgInstance = 0;
    
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    emac_update_cmd(port_num, EMAC_IOCTL_UC_FLOODING_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, NULL, EMAC_FW_MGMT_CMD_TYPE, 0, 0);

    if (switch_port == EMAC_SWITCH_PORT1)
    {
        portLoc = 0;
        icssgInstance = EMAC_ICSSG_0;
    }
    else if (switch_port == EMAC_SWITCH_PORT2)
    {
        portLoc =1;
        icssgInstance = EMAC_ICSSG_1;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",switch_port);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }

    if (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        switch (pParams->subCommand)
        {
            case EMAC_IOCTL_PORT_UC_FLOODING_ENABLE:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_UC_FLOODING_ENABLE, portLoc, (EMAC_IcssgInstance)icssgInstance)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
            case EMAC_IOCTL_PORT_UC_FLOODING_DISABLE:
                memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_UC_FLOODING_DISABLE, portLoc, (EMAC_IcssgInstance)icssgInstance)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                break;
             default:
                break;
        }
        if(portLoc == 0)
        {
            retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
        }else
        {
            retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
        }
        
        if (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
        {
            emac_mcb.ioctl_cb.ioctlCount = 1;
        }
    }

    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_configure_interface_mac_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_configure_interface_mac_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    int32_t macLo;
    int32_t macHi;
    int16_t temp;
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_MAC_ADDR_T *entry = (EMAC_MAC_ADDR_T*)pParams->ioctlVal;
    uintptr_t baseAddr;

    uint8_t* macAddr = &(entry->addr[0]);
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    if((switch_port != EMAC_SWITCH_PORT0) && (switch_port != EMAC_SWITCH_PORT1) && (switch_port != EMAC_SWITCH_PORT2))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",switch_port);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }
    else
    {
        baseAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

        macLo =  *((int32_t *) &macAddr[0]);
        temp =  *((int16_t *) &macAddr[4]);
        macHi = (int32_t) temp;

        if(switch_port == EMAC_SWITCH_PORT1)
        {
            /* add mac */
            baseAddr = emac_mcb.port_cb[1].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_1, macHi);

            baseAddr = emac_mcb.port_cb[2].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_1, macHi);
        }
        if(switch_port == EMAC_SWITCH_PORT2)
        {
            /* add mac */
            baseAddr = emac_mcb.port_cb[1].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU1_1, macHi);

            baseAddr = emac_mcb.port_cb[2].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;

            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_PRU0_1, macHi);
        }
        if(switch_port == EMAC_SWITCH_PORT0) /*host port*/
        {
            baseAddr = emac_mcb.port_cb[1].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
            /* add mac */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_INTERFACE_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_INTERFACE_1, macHi);

            baseAddr = emac_mcb.port_cb[2].icssDram0BaseAddr + CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_REGS_BASE;
            /* add mac */
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_INTERFACE_0, macLo);
            CSL_REG32_WR(baseAddr+CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_G_CFG_REGS_G_MAC_INTERFACE_1, macHi);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;

}

/*
 *  ======== emac_ioctl_configure_cut_through_or_prempt_select_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_configure_cut_through_or_prempt_select_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    if((switch_port != EMAC_SWITCH_PORT1) && (switch_port != EMAC_SWITCH_PORT2))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",switch_port);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }
    else
    {
        uint8_t queue_num;
        uint8_t temp_byte;
        uintptr_t expressPremptiveQueueAddr;
        EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
        EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP *entry = (EMAC_IOCTL_PREMPT_OR_CUT_THROUGH_MAP*)pParams->ioctlVal;

        EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
        EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
        if (emac_mcb.port_cb[port_num].getFwCfg)
        {
            emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
            pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
            expressPremptiveQueueAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->expressPremptiveQueueOffset;
            for (queue_num = 0U; queue_num < EMAC_IOCTL_PRIO_MAX; queue_num++)
            {
                temp_byte = (entry->pcpPreemptMap[queue_num] << 4U) | (entry->pcpCutThroughMap[queue_num] << 7U);   /*as per bit order in descriptor flags. Helps save PRU cycles*/
                CSL_REG8_WR(expressPremptiveQueueAddr+(queue_num*4U), temp_byte);
            }
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;

}
/*
 *  ======== emac_ioctl_frame_premption_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_frame_premption_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_IOCTL_PREEMPTION_ENTRY *entry = (EMAC_IOCTL_PREEMPTION_ENTRY*)pParams->ioctlVal;
    EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
    EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
    uint32_t portLoc = 0;
    uintptr_t premptionTxEnabledStatusAddr, premptionTxActiveStatusAddr, premptionVerifyStateStatusAddr, premptionVerifyStateValueAddr, premptionMinFragSizeAddr, premptionMinFragAddAddr;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);

    emac_update_cmd(port_num, EMAC_IOCTL_FRAME_PREEMPTION_CTRL, emac_mcb.ioctl_cb.pCmd1Icssg, pParams, NULL, EMAC_FW_MGMT_CMD_TYPE, 0, 0);
    if (switch_port == EMAC_SWITCH_PORT1)
    {
        portLoc = 0;
    }
    else if (switch_port == EMAC_SWITCH_PORT2)
    {
        portLoc =1;
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",switch_port);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }
    if ((emac_mcb.port_cb[port_num].getFwCfg)  && (retVal == EMAC_DRV_RESULT_IOCTL_IN_PROGRESS))
    {
        emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
        pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;

        switch (pParams->subCommand)
        {
            case EMAC_IOCTL_PREEMPT_TX_ENABLE:
                emac_mcb.ioctl_cb.ioctlCount = 1;
                if(portLoc == 1)
                {
                    memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_PREMPT_TX_ENABLE, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                    retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
                }
                else
                {
                    memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_PREMPT_TX_ENABLE, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                    retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
                }
                if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
                {
                    emac_mcb.ioctl_cb.ioctlCount = 0;
                }
                else
                {
                    premptionTxEnabledStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionTxEnabledStatusOffset;
                    CSL_REG8_WR(premptionTxEnabledStatusAddr, 0x01);
                }
                break;
            case EMAC_IOCTL_PREEMPT_TX_DISABLE:
                emac_mcb.ioctl_cb.ioctlCount = 1;
                if(portLoc == 1)
                {
                    memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_PREMPT_TX_DISABLE, portLoc, EMAC_ICSSG_0)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                    retVal = emac_ioctl_send_mgmt_msg(0, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
                }
                else
                {
                    memcpy((void*)(emac_mcb.ioctl_cb.pCmd1Icssg->spare),(void*)(emac_util_get_R30_info(EMAC_PORT_PREMPT_TX_DISABLE, portLoc, EMAC_ICSSG_1)), sizeof(emac_mcb.ioctl_cb.pCmd1Icssg->spare));
                    retVal = emac_ioctl_send_mgmt_msg(2, emac_mcb.ioctl_cb.pCmd1Icssg, NULL);
                }
                if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
                {
                    emac_mcb.ioctl_cb.ioctlCount = 0;
                }
                else
                {
                    premptionTxEnabledStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionTxEnabledStatusOffset;
                    CSL_REG8_WR(premptionTxEnabledStatusAddr, 0x00);
                }
                break;
            case EMAC_IOCTL_PREEMPT_GET_TX_ENABLE_STATUS:
                premptionTxEnabledStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionTxEnabledStatusOffset;
                entry->premt_tx_enabled_status = CSL_REG8_RD(premptionTxEnabledStatusAddr);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case EMAC_IOCTL_PREEMPT_GET_TX_ACTIVE_STATUS:
                premptionTxActiveStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionTxActiveStatusOffset;
                entry->premt_tx_active_status = CSL_REG8_RD(premptionTxActiveStatusAddr);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case EMAC_IOCTL_PREEMPT_VERIFY_ENABLE:
                premptionVerifyStateStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionVerifyStateStatusOffset;
                CSL_REG8_WR(premptionVerifyStateStatusAddr, 0x01);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case EMAC_IOCTL_PREEMPT_VERIFY_DISABLE:
                premptionVerifyStateStatusAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionVerifyStateStatusOffset;
                CSL_REG8_WR(premptionVerifyStateStatusAddr, 0x00);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case EMAC_IOCTL_PREEMPT_GET_VERIFY_STATE:
                premptionVerifyStateValueAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionVerifyStateValueOffset;
                entry->premt_verify_state = (Preempt_Verify_States)(CSL_REG8_RD(premptionVerifyStateValueAddr));
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case EMAC_IOCTL_PREEMPT_GET_MIN_FRAG_SIZE_LOCAL:
                premptionMinFragSizeAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionMinFragSizeOffset;
                entry->premt_min_fragment_size = CSL_REG8_RD(premptionMinFragSizeAddr);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            case  EMAC_IOCTL_PREEMPT_SET_MIN_FRAG_SIZE_REMOTE:
                premptionMinFragAddAddr = emac_mcb.port_cb[port_num].icssDram0BaseAddr + pSwitchFwCfg->premptionMinFragAddOffset;
                CSL_REG16_WR(premptionMinFragAddAddr, ((entry->add_min_fragment_size)+1)*64);
                retVal = EMAC_DRV_RESULT_OK;
                break;
            default:
                break;
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_configure_special_frame_prio_ctrl ========
 */
EMAC_DRV_ERR_E emac_ioctl_configure_special_frame_prio_ctrl(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: ENTER",port_num);
    if((switch_port != EMAC_SWITCH_PORT1) && (switch_port != EMAC_SWITCH_PORT2))
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "invalid port number specified: %d, ",switch_port);
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }
    else
    {
        uintptr_t splPacketDefaultPrioAddr;
        EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
        EMAC_IOCTL_SPECIAL_FRAME_DEFAULT_PRIO *entry = (EMAC_IOCTL_SPECIAL_FRAME_DEFAULT_PRIO*)pParams->ioctlVal;
        EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
        EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
        if (emac_mcb.port_cb[port_num].getFwCfg)
        {
            emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
            pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
            splPacketDefaultPrioAddr = emac_mcb.port_cb[port_num].icssSharedRamBaseAddr + pSwitchFwCfg->splPacketDefaultPrioOffset;
            CSL_REG8_WR(splPacketDefaultPrioAddr, entry->specialFramePrio);
        }
    }
    UTILS_trace(UTIL_TRACE_LEVEL_INFO, emac_mcb.drv_trace_cb, "port: %d: EXIT with status: %d",port_num, retVal);
    return retVal;
}

/*
 *  ======== emac_ioctl_speed_duplexity_cfg ========
 */
EMAC_DRV_ERR_E emac_ioctl_speed_duplexity_cfg(uint32_t port_num, void* p_params)
{
    EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
    EMAC_DRV_ERR_E retVal;
    EMAC_IOCTL_CMD_T *pCmd = emac_mcb.ioctl_cb.pCmd1Icssg;

    memset(pCmd, 0, sizeof(EMAC_IOCTL_CMD_T));
    pCmd->commandHeader = EMAC_FW_MGMT_CMD_HEADER;
    pCmd->commandType = EMAC_FW_MGMT_SPEED_DUPLEXITY_CMD_TYPE;
    pCmd->seqNumber = pParams->seqNumber;
    pCmd->commandParam = (uint8_t)pParams->subCommand;

    emac_mcb.ioctl_cb.ioctlCount = 1;
    retVal = emac_ioctl_send_mgmt_msg(port_num, pCmd, NULL);
    if (retVal != EMAC_DRV_RESULT_IOCTL_IN_PROGRESS)
    {
        emac_mcb.ioctl_cb.ioctlCount = 0;
    }

    return retVal;
}

/*
 *  ======== emac_ioctl_send_mgmt_msg ========
 */
EMAC_DRV_ERR_E  emac_ioctl_send_mgmt_msg(uint32_t port_num, EMAC_IOCTL_CMD_T* p_cmd, EMAC_CPPI_DESC_T* p_tx_cppi_desc)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_IOCTL_IN_PROGRESS;
    EMAC_CPPI_DESC_T *pCppiDesc = NULL;
    Udma_ChHandle txChHandle;
    uint32_t ringNum =0;
    uint32_t cmdLen = sizeof(EMAC_IOCTL_CMD_T);
    txChHandle = emac_mcb.port_cb[port_num].txChHandle[0];
    uint32_t key;
    if (p_tx_cppi_desc != NULL)
    {
        pCppiDesc = p_tx_cppi_desc;
    }
    else
    {
        emac_get_hw_cppi_tx_desc(port_num, ringNum, &pCppiDesc);
    }
    if (pCppiDesc != NULL)
    {
        uint64_t bufPtr = (uint64_t) p_cmd;
        pCppiDesc->hostDesc.bufPtr    = bufPtr;
        pCppiDesc->hostDesc.orgBufPtr = bufPtr;
        pCppiDesc->hostDesc.orgBufLen = cmdLen;
        pCppiDesc->hostDesc.bufInfo1  = cmdLen;
        pCppiDesc->appPtr = NULL;

        /* set packet type to MGMT */
        pCppiDesc->hostDesc.pktInfo2 |= EMAC_FW_MGMT_PKT;
        CSL_FINS (pCppiDesc->hostDesc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN, cmdLen);

        if (emac_udma_ring_enqueue (Udma_chGetFqRingHandle(txChHandle), pCppiDesc, cmdLen) != EMAC_DRV_RESULT_OK)
        {
            key = EMAC_osalHardwareIntDisable();
            pCppiDesc->nextPtr = emac_mcb.port_cb[port_num].txReadyDescs[ringNum];
            emac_mcb.port_cb[port_num].txReadyDescs[ringNum] = pCppiDesc;
            EMAC_osalHardwareIntRestore(key);
            retVal = EMAC_DRV_RESULT_ERR_UDMA_RING_ENQUEUE;
            UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, UDMA ring enqueue failure for sending MGMT message",port_num);
        }
    }
    else
    {
        UTILS_trace(UTIL_TRACE_LEVEL_ERR, emac_mcb.drv_trace_cb, "port: %d, NO TX free descriptor availalble for sending MGMT message",port_num);
        retVal = EMAC_DRV_RESULT_ERR_NO_FREE_DESC;
    }
    return retVal;
} /* emac_ioctl_send_mgmt_msg */

/*
 *  ======== emac_ioctl_configure_fdb_ageing_interval ========
 */
EMAC_DRV_ERR_E emac_ioctl_configure_fdb_ageing_interval(uint32_t port_num, uint32_t switch_port, void* p_params)
{
    EMAC_DRV_ERR_E retVal = EMAC_DRV_RESULT_OK;
    
    if((switch_port != EMAC_SWITCH_PORT1) && (switch_port != EMAC_SWITCH_PORT2))
    {
        retVal = EMAC_DRV_RESULT_INVALID_PORT;
    }
    if(retVal == EMAC_DRV_RESULT_OK)
    {
        uintptr_t fdbAgeingIntervalAddr;
        uint32_t numFDBBuckets =0;
        
        EMAC_IOCTL_PARAMS *pParams = (EMAC_IOCTL_PARAMS*) p_params;
        EMAC_IOCTL_FDB_AGEING_INTERVAL *entry = (EMAC_IOCTL_FDB_AGEING_INTERVAL*)pParams->ioctlVal;
        EMAC_PER_PORT_ICSSG_FW_CFG *pEmacFwCfg;
        EMAC_ICSSG_SWITCH_FW_CFG *pSwitchFwCfg;
        if (emac_mcb.port_cb[port_num].getFwCfg)
        {
            emac_mcb.port_cb[port_num].getFwCfg(port_num,&pEmacFwCfg);
            pSwitchFwCfg = (EMAC_ICSSG_SWITCH_FW_CFG*) pEmacFwCfg->pFwPortCfg;
            /*Calculate number of buckets*/
            numFDBBuckets = pSwitchFwCfg->fdbSize / pSwitchFwCfg->numFdbBucketEntries;

            fdbAgeingIntervalAddr = emac_mcb.port_cb[port_num].icssDram1BaseAddr + pSwitchFwCfg->fdbAgeingTimeoutOffset;
            /*The actual value written to memory is ageing timeout divided by number of buckets
              because in firmware we iterate per bucket not for entire FDB. See NRT design doc for more details*/
            CSL_REG64_WR(fdbAgeingIntervalAddr, entry->fdbAgeingInterval/(uint64_t)numFDBBuckets);
        }
    }
    return retVal;
}

/* Nothing past this point */

