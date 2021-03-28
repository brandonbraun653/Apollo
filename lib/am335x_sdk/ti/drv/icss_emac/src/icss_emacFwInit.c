/**
 * @file icss_emacFwInit.c
 * @brief Contains routines for initialization of PRU
 *
*/

/* Copyright (C) {2016-2019} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* Only need to include V1 version of header file. What is required
   by the driver from these header files are register macro and 
   field definition macros defines which have the same values
   across V0 and V1 versions of the IP*/
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_cfg.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_pru_ctrl.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_mii_rt.h>
#include <ti/csl/cslr_ecap.h>

#include <ti/drv/icss_emac/src/icss_emacLoc.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_vlan_mcast_filter_mmap.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_rx_int_pacing_mmap.h>

#include <ti/drv/icss_emac/icss_emacFwLearning.h>
#include <ti/drv/icss_emac/firmware/icss_switch/src/icss_stp_switch.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/**TX Minimum Inter packet gap*/
#define TX_MIN_IPG                        (0xb8U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/**Default MAC for PRU-ICSS and NDK use!*/
static uint8_t ifMAC[] = { 0x00, 0x31, 0xDE, 0x00, 0x00, 0x00};

/* ========================================================================== */
/*                          Local Function Definitions                              */
/* ========================================================================== */
static void PRUSSDRVPruCfgInit(ICSS_EmacHandle emacSubSysHandle);
static void PRUSSDRVPruMiiRtCfgInit(ICSS_EmacHandle emacSubSysHandle);

/* Static funtions for multicast filtering */
static int8_t ICSS_EmacMulticastFilterConfig(uintptr_t dataRamAddr,  uint8_t ioctlCmd , void* ioctlVal);
static void ICSS_EmacMCFilterFeatureCtrl(uintptr_t dataRamAddr, uint8_t ioctlCmd);
static void ICSS_EmacMCFilterUpdateMacId(uintptr_t dataRamAddr, uint8_t *multicastAddr, uint8_t command);
static void ICSS_EmacMulticastFilterOverrideHashmask(uintptr_t dataRamAddr, uint8_t *mask);

/* Static functions for vlan filtering */
static int8_t ICSS_EmacVlanFilterConfig(uintptr_t dataRamAddr,  uint8_t ioctlCmd , void* ioctlVal);
static void ICSS_EmacVLANFilterFeatureCtrl(uintptr_t dataRamAddr, uint8_t ioctlCmd);
static int8_t ICSS_EmacVLANFilterUpdateVID(uintptr_t dataRamAddr,  uint8_t ioctlCmd, uint16_t *vlanId);


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/* Command can take the values as under ioctlCmd and update the control under
*  firmware for VLAN filtering.
*/
static void ICSS_EmacVLANFilterFeatureCtrl(uintptr_t dataRamAddr, uint8_t ioctlCmd)
{
    uint8_t *vlanFilterCtrlByte = ((uint8_t *)(dataRamAddr +
                                         ICSS_EMAC_FW_VLAN_FILTER_CTRL_BITMAP_OFFSET));
    uint8_t ctrlVal = *vlanFilterCtrlByte;
    uint8_t mask;

    switch(ioctlCmd)
    {
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ENABLE_CMD:
             mask     = (uint8_t)( 1 << ICSS_EMAC_FW_VLAN_FILTER_CTRL_ENABLE_BIT);
             ctrlVal |= mask;
             break;
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_DISABLE_CMD:
             mask     = (uint8_t) ( 1 << ICSS_EMAC_FW_VLAN_FILTER_CTRL_ENABLE_BIT);
             ctrlVal &= ~(mask);
             break;
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_NAL_CMD:
             mask     = (uint8_t) ( 1 << ICSS_EMAC_FW_VLAN_FILTER_UNTAG_HOST_RCV_ALLOW_CTRL_BIT);
             ctrlVal |= (mask);
             break;
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_ALL_CMD:
             mask     = (uint8_t) ( 1 << ICSS_EMAC_FW_VLAN_FILTER_UNTAG_HOST_RCV_ALLOW_CTRL_BIT);
             ctrlVal &= ~(mask);
             break;

        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_NAL_CMD:
            mask     = (uint8_t) ( 1 << ICSS_EMAC_FW_VLAN_FILTER_PRIOTAG_HOST_RCV_ALLOW_CTRL_BIT);
            ctrlVal |= (mask);
            break;

        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_ALL_CMD:
            mask     = (uint8_t) ( 1 << ICSS_EMAC_FW_VLAN_FILTER_PRIOTAG_HOST_RCV_ALLOW_CTRL_BIT);
            ctrlVal &= ~(mask);
            break;

        default:
             break;
    }
    *vlanFilterCtrlByte = ctrlVal;

}

/* This function implements the updating (adding/removing) the VID for vlan filtering in the VLAN
 * filter table
 */
static int8_t ICSS_EmacVLANFilterUpdateVID(uintptr_t dataRamAddr,  uint8_t ioctlCmd, uint16_t *vlanId)
{
    int8_t      retVal = 0;
    uint8_t    *vlanTableBaseAddr = ((uint8_t *)(dataRamAddr +
                                       ICSS_EMAC_FW_VLAN_FLTR_TBL_BASE_ADDR));
    uint16_t     vid = *vlanId;
    uint8_t    *vlanTableBytePtr;
    uint16_t    vlanTargetByte;
    uint8_t     vlanTargetBit;

    if (vid  > ICSS_EMAC_FW_VLAN_FILTER_VID_MAX)
    {
        retVal = -1;
    }

    if (retVal == 0)
    {
        vlanTargetByte    = vid / 8;
        vlanTargetBit     = vid & 0x07;
        vlanTableBytePtr  = vlanTableBaseAddr + vlanTargetByte;
    
        if (ioctlCmd == ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ADD_VID_CMD)
        {
            *vlanTableBytePtr = *vlanTableBytePtr | (1 << vlanTargetBit);
        }
        else /* ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_REMOVE_VID_CMD */
        {
            *vlanTableBytePtr = *vlanTableBytePtr | (1 << vlanTargetBit);
            *vlanTableBytePtr = *vlanTableBytePtr ^ (1 << vlanTargetBit);
        }
    }

    return (retVal);

}

/* Implements the configuratino for VLAN filtering feature */
static int8_t ICSS_EmacVlanFilterConfig(uintptr_t dataRamAddr,  uint8_t ioctlCmd , void* ioctlVal)
{
    int8_t   retVal = 0;

    switch(ioctlCmd) {
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ENABLE_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_DISABLE_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_ALL_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_UNTAG_HOST_RCV_NAL_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_ALL_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_PRIOTAG_HOST_RCV_NAL_CMD:
            /* Set the appropriate control bit map in firmware to enable the feature */
            ICSS_EmacVLANFilterFeatureCtrl(dataRamAddr, ioctlCmd);
            break;
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_ADD_VID_CMD:
        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL_REMOVE_VID_CMD:
            retVal = ICSS_EmacVLANFilterUpdateVID(dataRamAddr, ioctlCmd, (uint16_t *)ioctlVal);
            break;

        default:
           retVal = -((int8_t)1);
           break;
    }
    return (retVal);
}


/* Command can take the following values:
 * ICSS_EMAC_FW_MULTICAST_FILTER_CTRL_DISABLED                               0x00
 * ICSS_EMAC_FW_MULTICAST_FILTER_CTRL_ENABLED                                0x01
*/
static void ICSS_EmacMCFilterFeatureCtrl(uintptr_t dataRamAddr,   uint8_t ioctlCmd)
{
    uint8_t *multicastTableControl = ((uint8_t *)(dataRamAddr +
                                         ICSS_EMAC_FW_MULTICAST_FILTER_CTRL_OFFSET));
    *multicastTableControl = ioctlCmd;
    return;
}

static void ICSS_EmacMulticastFilterOverrideHashmask(uintptr_t dataRamAddr, uint8_t *mask)
{
    uint8_t *multicastFilterMask;

    multicastFilterMask = ((uint8_t *)(dataRamAddr +
                                         ICSS_EMAC_FW_MULTICAST_FILTER_MASK_OFFSET));

    memcpy(multicastFilterMask , mask, ICSS_EMAC_FW_MULTICAST_FILTER_MASK_SIZE_BYTES);
    return;
}

/* multicastAddr (48 bit) & multicastFilterMask (48 bit) | XOR the result to obtain a hashVal
 *
 * Update the byte in multicast table as specified by command. Command can take 2 values:
 *          0 : allow packet to host | ADD_MULTICAST_MAC_ID
 *          1 : do not allow packet to host | REMOVE_MULTICAST_MAC_ID
 * */
static void ICSS_EmacMCFilterUpdateMacId(uintptr_t dataRamAddr, uint8_t *multicastAddr, uint8_t command)
{
    uint8_t *multicastTableBaseAddr = ((uint8_t *)(dataRamAddr +
                                       ICSS_EMAC_FW_MULTICAST_FILTER_TABLE));

    uint8_t *multicastTablePtr;

    uint8_t *multicastFilterMask = ((uint8_t *)(dataRamAddr +
                                    ICSS_EMAC_FW_MULTICAST_FILTER_MASK_OFFSET));
    uint8_t multicastAddrTemp[ICSS_EMAC_FW_MULTICAST_FILTER_MASK_SIZE_BYTES];
    uint8_t hashVal, i;

    /* compute the hashVal by XORing all 6 bytes of multicastAddr*/
    for(i = 0, hashVal = 0; i < ICSS_EMAC_FW_MULTICAST_FILTER_MASK_SIZE_BYTES; i++)
    {
        multicastAddrTemp[i] = multicastFilterMask[i] & multicastAddr[i];
        hashVal = hashVal ^ multicastAddrTemp[i];
    }

    multicastTablePtr = multicastTableBaseAddr + hashVal;

    if(command == ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ADD_MACID)
    {
        *multicastTablePtr = ICSS_EMAC_FW_MULTICAST_FILTER_HOST_RCV_ALLOWED;
    }

    else    /*ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID*/
    {
        *multicastTablePtr = ICSS_EMAC_FW_MULTICAST_FILTER_HOST_RCV_NOT_ALLOWED ;
    }

    return;
}

/* Implements the Multicast filtering Command */
static int8_t ICSS_EmacMulticastFilterConfig(uintptr_t dataRamAddr,  uint8_t ioctlCmd , void* ioctlVal)
{
    uint8_t *mcFilterPtr;
    uint8_t  isMaskSet;
    int8_t   retVal = 0;
    uint8_t   defaultMask[ICSS_EMAC_FW_MULTICAST_FILTER_MASK_SIZE_BYTES] = {
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL,
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL,
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL,
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL,
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL,
                               ICSS_EMAC_FW_MULTICAST_FILTER_INIT_VAL
                               };

    switch(ioctlCmd) {
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ENABLE:
            ICSS_EmacMCFilterFeatureCtrl(dataRamAddr, ICSS_EMAC_FW_MULTICAST_FILTER_CTRL_ENABLED);
            /* Check if Hash mask has been set already, else set to default value */
            mcFilterPtr = (uint8_t* ) (dataRamAddr + ICSS_EMAC_FW_MULTICAST_FILTER_OVERRIDE_STATUS);
            isMaskSet = *mcFilterPtr;
            if (isMaskSet == ICSS_EMAC_FW_MULTICAST_FILTER_MASK_OVERRIDE_NOT_SET)
            {
                ICSS_EmacMulticastFilterOverrideHashmask(dataRamAddr, defaultMask);
            }
            break;
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_DISABLE:
            ICSS_EmacMCFilterFeatureCtrl(dataRamAddr, ICSS_EMAC_FW_MULTICAST_FILTER_CTRL_DISABLED);
            break;
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_OVERRIDE_HASHMASK:
            ICSS_EmacMulticastFilterOverrideHashmask(dataRamAddr, (uint8_t*)ioctlVal);
            mcFilterPtr = (uint8_t* ) (dataRamAddr + ICSS_EMAC_FW_MULTICAST_FILTER_OVERRIDE_STATUS);
            /* Indicate Mask override is set */
            *mcFilterPtr = ICSS_EMAC_FW_MULTICAST_FILTER_MASK_OVERRIDE_SET;
            break;
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_ADD_MACID:
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL_REMOVE_MACID:
            ICSS_EmacMCFilterUpdateMacId(dataRamAddr, (uint8_t*)ioctlVal, ioctlCmd);
            break;
        default:
           retVal = -((int8_t)1);
           break;
    }
    return (retVal);
}

uint8_t ICSSHostConfig(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    uint16_t *pTemp16;
    uint32_t temp_addr = 0U;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    uint32_t hostQDescOffset = pDynamicMMap->hostQ1RxContextOffset + 64U;
    uint32_t hostQOffsetAddr =  pDynamicMMap->hostQ1RxContextOffset + 40U;

    /* queue lookup table */
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + ICSS_EMAC_DEFAULT_FW_QUEUE_SIZE_ADDR);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host (port 2) queue */
    for (qCount = 0; qCount < pDynamicMMap->numQueues; qCount++)
    {
        *pTemp16 = (uint16_t)(pDynamicMMap->rxHostQueueSize[qCount]);
        pTemp16++;
     }

    /********************** */
    /* Rx Context Initialize data for Host Port, (Q1,Q2,Q3,Q4) */
    /********************** */
     ICSS_EmacCalcPort0BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pDynamicMMap->hostQ1RxContextOffset);
    pTemp16 = (uint16_t *)(temp_addr);
    for (qCount = 0; qCount < pDynamicMMap->numQueues; qCount++)
    {
        *pTemp16 = (uint16_t)(bufferOffsets[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)(hostQDescOffset + (qCount * 8U));
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsets[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->rxHostQueueSize[qCount] * 4U) + bdOffsets[qCount] - 4U);
        pTemp16++;
    }

    /********************** */
    /* buffer offset table */
    /********************** */
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + hostQOffsetAddr);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host queue buffer */
    for (qCount = 0; qCount < pDynamicMMap->numQueues; qCount++)
    {
        *pTemp16 = (uint16_t)(bufferOffsets[qCount]);
        pTemp16++;
    }

    /************************** */
    /* buffer descriptor */
    /************************** */
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pDynamicMMap->hostQ1RxContextOffset + 32U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host buffer descriptor */
    for (qCount = 0; qCount < pDynamicMMap->numQueues; qCount++)
    {
        *pTemp16 = (uint16_t)(bdOffsets[qCount]);
        pTemp16++;
    }


    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pDynamicMMap->hostQ1RxContextOffset + 64U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 0 */
    for (qCount = 0; qCount < pDynamicMMap->numQueues; qCount++)
    {
        *pTemp16 = (uint16_t)(bdOffsets[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsets[qCount]);
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
    }

    ICSS_EmacHostInit(icssEmacHandle);

    return 0U;
}

/**
 *  \name  ICSSPromiscuousModeInit
 *  @brief  Function to enable promiscuous mode for ICSS
 *
 *  @param macAddr pointer to user defined MAC address in big endian format (network byte order)
 *
 *  \return 0 on success
 *
 */
int8_t ICSSPromiscuousModeInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);  /* for misra warning */ 
int8_t ICSSPromiscuousModeInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle)
{
    uint32_t *pTemp32=NULL;
    int8_t retVal = 0;
    uint32_t temp_addr = 0;

    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNum, ICSS_EMAC_FW_PROMISCOUS_MODE_FEATURE_CTRL);

    if(0 == retVal)
    {
        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pStaticMMap->promiscuousModeOffset);
        pTemp32 = (uint32_t *)(temp_addr);
       *pTemp32 = *pTemp32 | (((uint32_t)1U) << (portNum - ((uint8_t)1U)));
    }
    return retVal;
}
/**
 *  \name  ICSSPromiscuousModeDeInit
 *  @brief  Function to enable promiscuous mode for ICSS
 *
 *  @param macAddr pointer to user defined MAC address in big endian format (network byte order)
 *
 *  \return 0 on success
 *
 */
int8_t ICSSPromiscuousModeDeInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle);  /* for misra warning */ 
int8_t ICSSPromiscuousModeDeInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle)
{

    uint32_t *pTemp32=NULL;
    int8_t retVal = 0;
    uint32_t temp_addr = 0;

    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNum, ICSS_EMAC_FW_PROMISCOUS_MODE_FEATURE_CTRL);

    if(0 == retVal)
    {
        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pStaticMMap->promiscuousModeOffset);
        pTemp32 = (uint32_t *)(temp_addr);
       *pTemp32 = *pTemp32 & (~(((uint32_t)1U) << (portNum - ((uint8_t)1U))));
    }
    return retVal;
}
uint8_t ICSSMacConfig(uint8_t portNum, ICSS_EmacHandle icssEmacHandle) {
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t portVal = 0;
    uint16_t *pTemp16;
    uint8_t *pTemp8=NULL;
    uint8_t i;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t qCount = 0;
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);


    uint32_t dataRAM0BaseAddr = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
    uint32_t dataRAM1BaseAddr = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;

    uint32_t temp_addr = 0U;

    if((uint8_t)ICSS_EMAC_PORT_1 == portNum) {
        temp_addr = (dataRAM0BaseAddr + pStaticMMap->portMacAddr);
        pTemp8 = (uint8_t *)(temp_addr);
    }

    if((uint8_t)ICSS_EMAC_PORT_2 == portNum) {
        temp_addr = (dataRAM1BaseAddr + pStaticMMap->portMacAddr);
        pTemp8 = (uint8_t *)(temp_addr);
    }

    for (i=0; i<6U; i++)
    {
         ifMAC[i] = ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->macId)[i];
         if(pTemp8 != NULL)
         {
             *pTemp8 = ifMAC[i];
             pTemp8++;
         }
    }

    if((uint8_t)ICSS_EMAC_PORT_1 == portNum) {
        /********************** */
        /* Tx Context Initialize data. Port 1, (Q1,Q2,Q3,Q4 Qn) */
        ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        /********************** */
         temp_addr = (dataRAM0BaseAddr + pDynamicMMap->q1EmacTxContextOffset);
        pTemp16 = (uint16_t *)(temp_addr);
        
        /* Port 1 Queue 1 - Queue N (numQueues)*/
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
        {
            *pTemp16 = (uint16_t)(bufferOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 32U) + bufferOffsets[qCount]- 32U);
            pTemp16++;
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) + bdOffsets[qCount] - 4U);
            pTemp16++;
        }

        temp_addr = (dataRAM0BaseAddr + pDynamicMMap->portQueueDescOffset);
        pTemp16 = (uint16_t*)(temp_addr);
        /*Port1 */
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
        {
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = 0x0000;
            pTemp16++;
            *pTemp16 = 0x0000;
            pTemp16++;
        }
        portVal = ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE;
        ioctlParams.ioctlVal = &portVal;
        ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_1, (void*)&ioctlParams);

    }

    if((uint8_t)ICSS_EMAC_PORT_2 == portNum) {
        /********************** */
        /* Tx Context Initialize data. Port 2, (Q1,Q2,Q3,Q4,Qn) */
        /********************** */
        ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        temp_addr = (dataRAM1BaseAddr + pDynamicMMap->q1EmacTxContextOffset);
        pTemp16 = (uint16_t *)(temp_addr);
        /* Port 2Queue 1 - Queue N (numQueues)*/
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
        {
            *pTemp16 = (uint16_t)(bufferOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 32U) + bufferOffsets[qCount] - 32U);
            pTemp16++;
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) + bdOffsets[qCount] - 4U);
            pTemp16++;
        }

        temp_addr = (dataRAM1BaseAddr + pDynamicMMap->portQueueDescOffset);
        pTemp16 = (uint16_t *)(temp_addr);
        /*Port2 */
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
        {
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = (uint16_t)(bdOffsets[qCount]);
            pTemp16++;
            *pTemp16 = 0x0000;
            pTemp16++;
            *pTemp16 = 0x0000;
            pTemp16++;
        }

        portVal = ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE;
        ioctlParams.ioctlVal = &portVal;
        ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_2, (void*)&ioctlParams);
    }

    ICSS_EmacMACInit(icssEmacHandle, portNum);

    return 0U;

}
/**
 *  \name ICSSSwitchConfig
 *  @brief Function to Load ICSS Switch params to pru memory
 *
 *  @param none
 *
 *  \return 0 on success
 *
 */
uint8_t ICSSSwitchConfig(ICSS_EmacHandle icssEmacHandle);   /*for misra warning*/
uint8_t ICSSSwitchConfig(ICSS_EmacHandle icssEmacHandle) 
{
    uint32_t qCount = 0U;
    uint16_t *pTemp16;
    uint8_t * pTemp8;
    int32_t i;
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t portVal=0;

    uint8_t * charPtr1;
    uint8_t * charPtr2;

    uint32_t bufferOffsetsPort0[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsetsPort0[ICSS_EMAC_NUMQUEUES];
    uint32_t bufferOffsetsPort1[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsetsPort1[ICSS_EMAC_NUMQUEUES];
    uint32_t bufferOffsetsPort2[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsetsPort2[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    ICSS_EmacCalcPort0BufferOffset(icssEmacHandle, bufferOffsetsPort0,bdOffsetsPort0);

    uint32_t dataRAM0BaseAddr = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
    uint32_t dataRAM1BaseAddr = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;

    uint32_t temp = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;

    uint32_t temp_addr = 0U;

    /* queue lookup table */
    temp_addr = (temp + ICSS_EMAC_DEFAULT_FW_QUEUE_SIZE_ADDR);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host (port 2) queue */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(pDynamicMMap->rxHostQueueSize[qCount]);
        pTemp16++;
    }
    /* port 0 queue */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(pDynamicMMap->txQueueSize[qCount]);
        pTemp16++;
    }

    /* port 1 queue */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(pDynamicMMap->txQueueSize[qCount]);
        pTemp16++;
    }

    /********************** */
    /* Tx Context Initialize data. Port 1, (Q1,Q2,Q3,Q4,Qn) */
    ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsetsPort1,bdOffsetsPort1);
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 1 Queue 1 - Queue N (numQueues)*/
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort1[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 32U) + bufferOffsetsPort1[qCount] - 32U); 
        pTemp16++;
        *pTemp16 =  (uint16_t)(bdOffsetsPort1[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) + bdOffsetsPort1[qCount] - 4U);
        pTemp16++;
    }

    /********************** */
    /* Tx Context Initialize data. Port 2, (Q1,Q2,Q3,Q4,Qn) */
    /********************** */
     ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsetsPort2,bdOffsetsPort2);
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 32U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 2 Queue 1 - Queue N (numQueues)*/
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort2[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 32U) + bufferOffsetsPort2[qCount] - 32U); 
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsetsPort2[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) + bdOffsetsPort2[qCount] - 4U);
        pTemp16++;
    }

    /********************** */
    /* Collision Tx Context Initialize data. Port 1, (Q1) */
    /********************** */
    temp_addr =  (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 64U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 1 collision queue */
    *pTemp16 = (uint16_t)(bufferOffsetsPort1[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(bufferOffsetsPort1[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)((pDynamicMMap->collisionQueueSize * 32U) + bufferOffsetsPort1[ICSS_EMAC_COLQUEUE] - 32U);
    pTemp16++;
    
    /********************** */
    /* Collision Tx Context Initialize data. Port 2, (Q1) */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 72U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 2 collision queue */
    *pTemp16 = (uint16_t)(bufferOffsetsPort2[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(bufferOffsetsPort2[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)((pDynamicMMap->collisionQueueSize * 32U) + bufferOffsetsPort2[ICSS_EMAC_COLQUEUE] - 32U);
    pTemp16++;
    
    /********************** */
    /* Rx Context Initialize data for Host Port, (Q1,Q2,Q3,Q4,Qn) */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 80U);
    pTemp16 = (uint16_t *)(temp_addr);
   /* Host Port 1 Queue 1 - Queue N (numQueues)*/
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort0[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)(pStaticMMap->p0QueueDescOffset + (qCount * 8U));
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsetsPort0[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->rxHostQueueSize[qCount] * 4U) + bdOffsetsPort0[qCount] - 4U);
        pTemp16++;
    }
    /********************** */
    /* Rx Context Initialize data for Port 1, (Q1,Q2,Q3,Q4,Qn) */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 112U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Host Port 1 Queue 1  - Queue N (numQueues)*/
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort1[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)(pStaticMMap->p0QueueDescOffset + (32U + (qCount * 8U)));
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsetsPort1[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) +  bdOffsetsPort1[qCount] - 4U);
        pTemp16++;
    }

    /********************** */
    /* Rx Context Initialize data for Port 2, (Q1,Q2,Q3,Q4,Qn) */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 144U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Host Port 2 Queue 1  - Queue N (numQueues)*/
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort2[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)(pStaticMMap->p0QueueDescOffset + (64U + (qCount * 8U)));
        pTemp16++;
        *pTemp16 = (uint16_t)(bdOffsetsPort2[qCount]);
        pTemp16++;
        *pTemp16 = (uint16_t)((pDynamicMMap->txQueueSize[qCount] * 4U) + bdOffsetsPort2[qCount] - 4U);
        pTemp16++;
    }

    /********************** */
    /* Collision Rx Context Initialize for Host port */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 176U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 0 collision queue */
    *pTemp16 = (uint16_t)(bufferOffsetsPort0[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(bufferOffsetsPort0[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(pStaticMMap->p0ColQueueDescOffset);
    pTemp16++;
    *pTemp16 = (uint16_t)(bdOffsetsPort0[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)((pDynamicMMap->collisionQueueSize * 4U) + bdOffsetsPort0[ICSS_EMAC_COLQUEUE] - 4U);
    pTemp16++;
    
    /********************** */
    /* Collision Rx Context Initialize for Port 1 */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 188U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 1 collision queue */
    *pTemp16 =  (uint16_t)(bufferOffsetsPort1[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 =  (uint16_t)(bufferOffsetsPort1[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(pStaticMMap->p0ColQueueDescOffset + 8U);
    pTemp16++;
    *pTemp16 = (uint16_t)(bdOffsetsPort1[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)((pDynamicMMap->collisionQueueSize * 4U) + bdOffsetsPort1[ICSS_EMAC_COLQUEUE] - 4U);
    pTemp16++;
    
    /********************** */
    /* Collision Rx Context Initialize for Port 2 */
    /********************** */
    temp_addr = (temp + pDynamicMMap->p1Q1SwitchTxContextOffset + 200U);
    pTemp16 = (uint16_t *)(temp_addr);
    /* Port 2 collision queue */
    *pTemp16 =  (uint16_t)(bufferOffsetsPort2[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 =  (uint16_t)(bufferOffsetsPort2[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)(pStaticMMap->p0ColQueueDescOffset + 16U);
    pTemp16++;
    *pTemp16 = (uint16_t)(bdOffsetsPort2[ICSS_EMAC_COLQUEUE]);
    pTemp16++;
    *pTemp16 = (uint16_t)((pDynamicMMap->collisionQueueSize * 4U) + bdOffsetsPort2[ICSS_EMAC_COLQUEUE] - 4U);
    pTemp16++;

    /********************** */
    /* buffer offset table */
    /********************** */
    temp_addr = (temp + ICSS_EMAC_DEFAULT_FW_QUEUE_OFFSET_ADDR);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host queue buffer */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort0[qCount]);
        pTemp16++;
    }


    /* port 1 queue */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort1[qCount]);
        pTemp16++;
    }
    /* port 2 queue */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bufferOffsetsPort2[qCount]);
        pTemp16++;
    }

    /************************** */
    /* buffer descriptor */
    /************************** */
    temp_addr = (temp + ICSS_EMAC_DEFAULT_FW_QUEUE_DESCRIPTOR_OFFSET_ADDR);
    pTemp16 = (uint16_t *)(temp_addr);
    /* host buffer descriptor */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bdOffsetsPort0[qCount]);
        pTemp16++;
    }

    /* port 0 buffer descriptor */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bdOffsetsPort1[qCount]);
        pTemp16++;
    }
    /* port 1 buffer descriptor */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)(bdOffsetsPort2[qCount]);
        pTemp16++;
    }

    temp_addr = (dataRAM0BaseAddr + pStaticMMap->portMacAddr);
    charPtr1 = (uint8_t *)(temp_addr);
    temp_addr = (dataRAM1BaseAddr + pStaticMMap->portMacAddr);
    charPtr2 = (uint8_t *)(temp_addr);
    temp_addr = (dataRAM1BaseAddr + pStaticMMap->interfaceMacAddrOffset);
    pTemp8 = (uint8_t *)(temp_addr);

    for (i=0; i<6; i++)
    {
        ifMAC[i] = ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->macId)[i];
        *charPtr1 = ifMAC[i];
        charPtr1++;
        *charPtr2 = ifMAC[i];
        charPtr2++;
        *pTemp8 = ifMAC[i];
        pTemp8++;
    }
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0ColQueueDescOffset);
    pTemp16 = (uint16_t *)(temp_addr);

    *pTemp16 = (uint16_t)bdOffsetsPort0[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = (uint16_t)bdOffsetsPort0[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;
    *pTemp16 = (uint16_t)bdOffsetsPort1[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = (uint16_t)bdOffsetsPort1[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;
    *pTemp16 = (uint16_t)bdOffsetsPort2[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = (uint16_t)bdOffsetsPort2[ICSS_EMAC_COLQUEUE];
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;
    *pTemp16 = 0x0000;
    pTemp16++;

    /* Port 0 */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)bdOffsetsPort0[qCount];
        pTemp16++;
        *pTemp16 = (uint16_t)bdOffsetsPort0[qCount];
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
    }

    /*Port1 */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)bdOffsetsPort1[qCount];
        pTemp16++;
        *pTemp16 = (uint16_t)bdOffsetsPort1[qCount];
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
    }
    /*Port2  */
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount ++)
    {
        *pTemp16 = (uint16_t)bdOffsetsPort2[qCount];
        pTemp16++;
        *pTemp16 = (uint16_t)bdOffsetsPort2[qCount];
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
        *pTemp16 = 0x0000;
        pTemp16++;
    }

    portVal = ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE;
    ioctlParams.ioctlVal = &portVal;
    ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_1, (void*)&ioctlParams);
    ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_2, (void*)&ioctlParams);

    ICSS_EmacPortInit(icssEmacHandle);

    return 0U;
}

/**
 *  \name ICSSMemInit
 *  @brief Function to clear ICSS shared,pru memory and L3 ocmc ram
 *
 * @param pruIcssHandle Provides PRUSS memory map
 *
 *  \return 0 on success
 *
 */
uint8_t ICSSHostMemInit(ICSS_EmacHandle icssEmacHandle);  /*for misra warning*/ 
uint8_t ICSSHostMemInit(ICSS_EmacHandle icssEmacHandle) 
{
    uint32_t totalBufferPoolSize;

    /*clear all registers, clear all Shared RAM */
    uint32_t sharedDataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamSize;
    uint32_t *pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;
    ICSS_EmacMemInit(pTemp, sharedDataRamSize);

    /*clear all registers, clear all OCMC region for  buffer pools */
    totalBufferPoolSize = ICSS_EmacCalcTotalBufferPoolSize(icssEmacHandle);
    pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr;
    ICSS_EmacMemInit(pTemp, totalBufferPoolSize);

    return 0U;
}

/**
* @internal
* @brief  Function to clear ICSS shared,pru memory and L3 ocmc ram
*
* @param pruIcssHandle Provides PRUSS memory map
*
* @retval 0 on success
*/
void ICSSPortMemInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle); /*for misra warning*/ 
void ICSSPortMemInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle) 
{

    uint32_t *pTemp=NULL;
    uint32_t dataRamSize  = 0;

    if((uint8_t)ICSS_EMAC_PORT_1 == portNum)
    {
        dataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0Size;
        pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
    }
    if((uint8_t)ICSS_EMAC_PORT_2 == portNum)
     {
        dataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1Size;
        pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
    }
    /*clear Data Ram*/
    ICSS_EmacMemInit(pTemp, dataRamSize);

}
/**
 *  \name ICSSMemInit
 *  @brief Function to clear ICSS shared,pru memory and L3 ocmc ram
 *
 *  @param none
 *
 *  \return 0 on success
 *
 */
uint8_t ICSSMemInit(ICSS_EmacHandle icssEmacHandle);   /* for misra warning */ 
uint8_t ICSSMemInit(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t *pTemp;
    uint32_t shareDataRamSize;
    uint32_t dataRamSize;
    uint32_t ocmcRamSize;

    shareDataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamSize;
    pTemp = (uint32_t *) (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;

    /*clear all registers, clear all Shared RAM  */
       ICSS_EmacMemInit(pTemp, shareDataRamSize);

    /*clear data ram0 */
    dataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0Size;
    pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
    ICSS_EmacMemInit(pTemp, dataRamSize);


    /*clear data ram1*/
    dataRamSize =  (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1Size;
    pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
     ICSS_EmacMemInit(pTemp, dataRamSize);

    ocmcRamSize = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcSize;
    pTemp = (uint32_t *)(((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr;
    /*clear all registers, clear all OCMC (64K) */
    ICSS_EmacMemInit(pTemp, ocmcRamSize);

    return 0U;
}


/**
 *  \name  ICSSCommonInit
 *  @brief  Function to initialize and configure common parts of ICSS
 *
 *  @param macAddr pointer to user defined MAC address in big endian format (network byte order)
 *
 *  \return 0 on success
 *
 */
void ICSSICSS_EmacHostInit(ICSS_EmacHandle icssEmacHandle,const PRUICSS_IntcInitData *pruss_intc_initdata);  /* for misra warning */ 
void ICSSICSS_EmacHostInit(ICSS_EmacHandle icssEmacHandle,const PRUICSS_IntcInitData *pruss_intc_initdata)
{

    PRUICSS_Handle pruicssHandle = ((ICSS_EmacObject*)icssEmacHandle->object)->pruIcssHandle;
    ICSS_EmacBaseAddressHandle_T icssEmacBaseAddressHandle= ((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg;

    uint32_t temp_addr = 0U;

    ICSSHostMemInit(icssEmacHandle);
    ICSSHostConfig(icssEmacHandle);

    /* configure PRUSS register CFG */
    PRUSSDRVPruCfgInit(icssEmacHandle);

    /* configure PRUSS INTC */
    PRUICSS_pruIntcInit(pruicssHandle, pruss_intc_initdata);

    /* configure PRUSS register MII_RT */
    PRUSSDRVPruMiiRtCfgInit(icssEmacHandle);

    temp_addr = (icssEmacBaseAddressHandle->prussIepRegs + CSL_ICSSIEP_GLOBAL_CFG_REG);
    /*Enable IEP Counter*/
    HWREGH(temp_addr) = IEP_GLOBAL_CFG_REG_VAL;

}

int8_t ICSSMacInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle); /* for misra warning */ 
int8_t ICSSMacInit(uint8_t portNum, ICSS_EmacHandle icssEmacHandle) 
{

    PRUICSS_Handle pruicssHandle = ((ICSS_EmacObject*)icssEmacHandle->object)->pruIcssHandle;
    ICSS_EmacBaseAddressHandle_T icssEmacBaseAddressHandle= ((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg;

    uint32_t temp_addr = 0U;
    uint32_t sharedDataRamBase;
    uint32_t l3OcmcBase;

    PRUICSS_pruDisable(pruicssHandle, portNum-1U);

    ICSSPortMemInit(portNum, icssEmacHandle);

    ICSSMacConfig(portNum, icssEmacHandle);

    /* Addresses here need to be physical addresses as they are passed to ICSS, and in Linux case
     * icssEmacBaseAddressHandle->l3OcmcBaseAddr is a virtual address
     */
#ifdef __LINUX_USER_SPACE
    sharedDataRamBase = icssEmacBaseAddressHandle->sharedDataRamBaseAddr_phys;
    l3OcmcBase = icssEmacBaseAddressHandle->l3OcmcBaseAddr_phys;
#else
    sharedDataRamBase = icssEmacBaseAddressHandle->sharedDataRamBaseAddr;
    l3OcmcBase = icssEmacBaseAddressHandle->l3OcmcBaseAddr;
#endif

    temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
    /* Set in constant table C28 to ICSS Shared memory 0x10000 */
    HWREG(temp_addr) = (sharedDataRamBase & 0x000FFFFFU) >> 8U;
    temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
    HWREG(temp_addr) = (sharedDataRamBase & 0x000FFFFFU) >> 8U;
    temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
    /* Set in constant table C30 to shared RAM 0x40300000 */
    HWREG(temp_addr) = (l3OcmcBase & 0x00FFFF00U) >> 8U;
    temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
    HWREG(temp_addr) = (l3OcmcBase & 0x00FFFF00U) >> 8U;


    if((uint8_t)ICSS_EMAC_PORT_1 == portNum) {
        temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        /* Set in constant table C28 to ICSS Shared memory 0x10000 */
        HWREG(temp_addr) = (sharedDataRamBase & 0x000FFFFFU) >> 8U;
        temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
        /* Set in constant table C30 to shared RAM 0x40300000 */
        HWREG(temp_addr) = (l3OcmcBase & 0x00FFFF00U) >> 8U;
    }

    if((uint8_t)ICSS_EMAC_PORT_2 == portNum) {
        temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        HWREG(temp_addr) = (sharedDataRamBase & 0x000FFFFFU) >> 8U;
        temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
        HWREG(temp_addr) = (l3OcmcBase & 0x00FFFF00U) >> 8U;
    }

    temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
    HWREG(temp_addr) = 0x00000100U;
    temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
    HWREG(temp_addr) = 0x00000100U;

    return 0;

}
/* local function to LLD to enable/disable MDIO link interrupt */
void ICSS_EmacMdioIntrEnable(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle);
void ICSS_EmacMdioIntrEnable(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle)
{
    uint32_t phySel;
    uint32_t baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG((uint32_t)portNum-(uint32_t)1U) ;
    uint32_t phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[0];

    phySel=phyAddr;
    phySel |=  0x40U;
    
    HW_WR_REG32(baseAddr,phySel);
}

/* local function to LLD to enable/disable MDIO link interrupt */
void ICSS_EmacMdioIntrEnableSwitch(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle);
void ICSS_EmacMdioIntrEnableSwitch(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle)
{
    uint32_t phySel;
    uint32_t baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG((uint32_t)portNum-(uint32_t)1U);
    uint32_t phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[0];

    phySel=phyAddr;
    phySel |=  0x40U;

    HW_WR_REG32(baseAddr,phySel);

    baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG(portNum) ;
    phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[1];

    phySel=phyAddr;
    phySel |=  0x40U;

    HW_WR_REG32(baseAddr,phySel);
}

void ICSS_EmacMdioIntrDisable(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle);
void ICSS_EmacMdioIntrDisable(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle)
{
    uint32_t phySel;
    uint32_t baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG((uint32_t)portNum-(uint32_t)1U) ;
    uint32_t phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[0];

    phySel=phyAddr;
    phySel &=  ((uint8_t)~(0x40U));
    HW_WR_REG32(baseAddr,phySel);
}

void ICSS_EmacMdioIntrDisableSwitch(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle);
void ICSS_EmacMdioIntrDisableSwitch(uint8_t portNum, ICSS_EmacHandle emacSubSysHandle)
{
    uint32_t phySel;
    uint32_t baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG((uint32_t)portNum-(uint32_t)1U) ;
    uint32_t phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[0];

    phySel=phyAddr;
    phySel &=  ((uint8_t)~(0x40U));
    HW_WR_REG32(baseAddr,phySel);

    baseAddr = (((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs +CSL_MDIO_USER_PHY_SEL_REG(portNum) ;
    phyAddr = (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->phyAddr[1];

    phySel=phyAddr;
    phySel &=  ((uint8_t)~(0x40U));
    HW_WR_REG32(baseAddr,phySel);
}

/***********************************************************************************
 * FUNCTION PURPOSE: Initialize and configure ICSS EMAC
 ***********************************************************************************
 * DESCRIPTION: Initialize and configure PRUICSS EMAC
 ***********************************************************************************/
int8_t ICSS_EmacSwitchInit(ICSS_EmacHandle icssEmacHandle,
                           const PRUICSS_IntcInitData *pruss_intc_initdata)
{
    PRUICSS_Handle pruicssHandle = ((ICSS_EmacObject*)icssEmacHandle->object)->pruIcssHandle;
    ICSS_EmacBaseAddressHandle_T icssEmacBaseAddressHandle= ((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg;
    uint32_t icss_version = PRUICSS_getICSSVersion(pruicssHandle);

    uint32_t temp_addr = 0U;

    PRUICSS_pruDisable(pruicssHandle, 1U);
    PRUICSS_pruDisable(pruicssHandle, 0);

    ICSSMemInit(icssEmacHandle);
    ICSSSwitchConfig(icssEmacHandle);

    if (icss_version >= 0x201U)
    {
        temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        /* Set in constant table C28 to ICSS Shared memory 0x10000 */
        HWREG(temp_addr) = (icssEmacBaseAddressHandle->sharedDataRamBaseAddr & 0x0001FFFFU) >> 8U;
        temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        HWREG(temp_addr) = (icssEmacBaseAddressHandle->sharedDataRamBaseAddr & 0x0001FFFFU) >> 8U;

     }
    else
    {
        temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        /* Set in constant table C28 to ICSS Shared memory 0x10000 */
        HWREG(temp_addr) = (icssEmacBaseAddressHandle->sharedDataRamBaseAddr & 0x000FFFFFU) >> 8U;
        temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR0);
        HWREG(temp_addr) = (icssEmacBaseAddressHandle->sharedDataRamBaseAddr & 0x000FFFFFU) >> 8U;
        }

    temp_addr = (icssEmacBaseAddressHandle->prussPru0CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
    /* Set in constant table C30 to shared RAM 0x40300000 */
    HWREG(temp_addr) = (icssEmacBaseAddressHandle->l3OcmcBaseAddr & 0x00FFFF00U) >> 8U;
    temp_addr = (icssEmacBaseAddressHandle->prussPru1CtrlRegs + CSL_ICSSPRUCTRL_CTPPR1);
    HWREG(temp_addr) = (icssEmacBaseAddressHandle->l3OcmcBaseAddr & 0x00FFFF00U) >> 8U;

    
    /* configure PRUSS register CFG */
    PRUSSDRVPruCfgInit(icssEmacHandle);

    
    /* configure PRUSS INTC */
    PRUICSS_pruIntcInit(pruicssHandle, pruss_intc_initdata);

    /* configure PRUSS register MII_RT */
    PRUSSDRVPruMiiRtCfgInit(icssEmacHandle);
    /* Enable IEP Counter */
    temp_addr = (icssEmacBaseAddressHandle->prussIepRegs + CSL_ICSSIEP_GLOBAL_CFG_REG);
    HWREGH(temp_addr) = IEP_GLOBAL_CFG_REG_VAL;

    PRUICSS_pruDisable(pruicssHandle, 0);
    PRUICSS_pruDisable(pruicssHandle, 1U);

    return 0;
}

/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacFwIntrPacingEnable initialize firmware interrupt pacing
 *
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
*   @param[in]  timeout  timeout (in usec) for interrupt pacing
*
 *  @retval     
 */
uint8_t ICSS_EmacFwIntrPacingInit(ICSS_EmacHandle icssEmacHandle, uint8_t port)
{
    /* eCAP configuration : free running, auto wrap around*/
#ifdef __LINUX_USER_SPACE
    uint32_t ecapBaseAddr = (((ICSS_EmacHwAttrs *)(
                                  icssEmacHandle)->hwAttrs)->emacBaseAddrCfg)->ecapBaseAddr;
#else
    uint32_t ecapBaseAddr = (((ICSS_EmacHwAttrs *)(
                                  icssEmacHandle)->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr +
                            eCAP_BASE_OFFSET;
#endif
    /* Setup ctrl bits */
    HWREGH(ecapBaseAddr + CSL_ECAP_ECCTL2) = (uint32_t)(
                CSL_ECAP_ECCTL2_TSCTRSTOP_MASK | CSL_ECAP_ECCTL2_CAP_APWM_MASK);
    /* Set cap1 & cap2 to 0xFFFFFFFF */
    HWREG(ecapBaseAddr + CSL_ECAP_CAP1) = CSL_ECAP_TSCTR_TSCTR_MAX;
    HWREG(ecapBaseAddr + CSL_ECAP_CAP2) = CSL_ECAP_TSCTR_TSCTR_MAX;

    if (port == 0)
    {
        /*Disable interrupt pacing & adaptive logic by default*/
        *((uint8_t *)(((((ICSS_EmacHwAttrs *)
                         icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                      INTR_PAC_STATUS_OFFSET_PRU0)) = INTR_PAC_DIS_ADP_LGC_DIS;

        /*Set timer value to max possible*/
        *((uint32_t *)(((((ICSS_EmacHwAttrs *)
                          icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                       INTR_PAC_TMR_EXP_OFFSET_PRU0)) = CSL_ECAP_TSCTR_TSCTR_MAX;

        *((uint32_t *)(((((ICSS_EmacHwAttrs *)
                      icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                   INTR_PAC_PREV_TS_OFFSET_PRU0)) = INTR_PAC_PREV_TS_RESET_VAL;
    }
    else
    {
        /*Disable interrupt pacing & adaptive logic by default*/
        *((uint8_t *)(((((ICSS_EmacHwAttrs *)
                         icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                      INTR_PAC_STATUS_OFFSET_PRU1)) = INTR_PAC_DIS_ADP_LGC_DIS;
    
        *((uint32_t *)(((((ICSS_EmacHwAttrs *)
                          icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                       INTR_PAC_TMR_EXP_OFFSET_PRU1)) = CSL_ECAP_TSCTR_TSCTR_MAX;

        *((uint32_t *)(((((ICSS_EmacHwAttrs *)
                          icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr) +
                       INTR_PAC_PREV_TS_OFFSET_PRU1)) = INTR_PAC_PREV_TS_RESET_VAL;
    }

    return 0U;
}

/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacInit API to initialize and configure ICSS in MAC/Switch Mode
 *  @details API to initialize and configure ICSS in MAC/Switch Mode
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
 *  @param[in]  pruss_intc_initdata INTC mapping structure pointer
*   @param[in]  emacMode Switch mode or mac mode
*
 *  @retval     0 on sucess
 */
uint8_t ICSS_EmacInit(ICSS_EmacHandle icssEmacHandle,
                           const PRUICSS_IntcInitData *pruss_intc_initdata,uint8_t emacMode)
{
    uint8_t ret_val = 0U;

    uint8_t port = 0U;
    if (((ICSS_EmacObject*)icssEmacHandle->object)->fwMmapInitDone != ICSS_EMAC_FW_MMAP_INIT_DONE)
    {
        ICSS_EmacGetFwMMapInitConfigLocal(icssEmacHandle, 0U);
        ICSS_EmacGetFwMMapInitConfigLocal(icssEmacHandle, 1U);
        
    }

    switch(emacMode)
    {
        case ICSS_EMAC_MODE_SWITCH:
            ICSS_EmacSwitchInit(icssEmacHandle,pruss_intc_initdata);
            ICSS_EmacMdioIntrEnableSwitch(ICSS_EMAC_PORT_1,icssEmacHandle);
            port = ICSS_EMAC_MODE_SWITCH;
            break;
        case ICSS_EMAC_MODE_MAC1|ICSS_EMAC_MODE_DUALMAC:
            ICSSICSS_EmacHostInit(icssEmacHandle,pruss_intc_initdata);
            ICSSMacInit((uint8_t)ICSS_EMAC_PORT_1,icssEmacHandle);
            ICSS_EmacMdioIntrEnable(ICSS_EMAC_PORT_1,icssEmacHandle);
            port = ICSS_EMAC_PORT_1;
            break;
        case ICSS_EMAC_MODE_MAC1:
            ICSSICSS_EmacHostInit(icssEmacHandle,pruss_intc_initdata);
            ICSSMacInit((uint8_t)ICSS_EMAC_PORT_1,icssEmacHandle);
            ICSS_EmacMdioIntrEnable(ICSS_EMAC_PORT_1,icssEmacHandle);
            port = ICSS_EMAC_PORT_1;
            break;
        case ICSS_EMAC_MODE_MAC2|ICSS_EMAC_MODE_DUALMAC:
            ICSSICSS_EmacHostInit(icssEmacHandle,pruss_intc_initdata);
            ICSSMacInit((uint8_t)ICSS_EMAC_PORT_2,icssEmacHandle);
            ICSS_EmacMdioIntrEnable(ICSS_EMAC_PORT_2,icssEmacHandle);
            port = ICSS_EMAC_PORT_2;
            break;
        case ICSS_EMAC_MODE_MAC2:
            ICSSICSS_EmacHostInit(icssEmacHandle,pruss_intc_initdata);
            ICSSMacInit((uint8_t)ICSS_EMAC_PORT_2,icssEmacHandle);
            ICSS_EmacMdioIntrEnable(ICSS_EMAC_PORT_2,icssEmacHandle);
            port = ICSS_EMAC_PORT_2;
            break;
        default:
            ret_val = 0U;
            break;
    }

    if(ICSS_EMAC_MODE_SWITCH == emacMode)
    {
        ICSS_EmacInitLinkState(icssEmacHandle, 0U, port);
        ICSS_EmacInitLinkState(icssEmacHandle, 1U, port);
    }
    else
    {
        ICSS_EmacInitLinkState(icssEmacHandle, 0U,port);
    }
    /*Registering Default Rx and Tx Apis*/
    ((((ICSS_EmacObject *)icssEmacHandle->object)->callBackHandle)->rxCallBack)->callBack = (ICSS_EmacCallBack)&ICSS_EmacRxPktGet;
    ((((ICSS_EmacObject *)icssEmacHandle->object)->callBackHandle)->rxCallBack)->userArg = NULL;
    ((((ICSS_EmacObject *)icssEmacHandle->object)->callBackHandle)->txCallBack)->callBack = (ICSS_EmacCallBack)&ICSS_EmacTxPacket;
    ((((ICSS_EmacObject *)icssEmacHandle->object)->callBackHandle)->txCallBack)->userArg = NULL;

    /*Detect ICSS Revision*/
    uint32_t icssRevision = HW_RD_REG32((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussCfgRegs + CSL_ICSSCFG_REVID);
    ((ICSS_EmacObject *)icssEmacHandle->object)->icssRevisionMajor = ((icssRevision & ICSS_REVISION_MAJOR_MASK) >> 8);
    ((ICSS_EmacObject *)icssEmacHandle->object)->icssRevisionMinor = (icssRevision & ICSS_REVISION_MINOR_MASK);

    /*Init firmware interrupt pacing (disabled by default)*/
    ICSS_EmacFwIntrPacingInit(icssEmacHandle, (port - 1));

    ICSS_EmacOSInit(icssEmacHandle);

    return ret_val;
}
/**
 *  @ingroup icss_api_functions
 *  @brief   ICSS_EmacDeInit API to stop MAC/Switch Mode
 *
 *  @param[in]  ICSS_EmacHandle  handle to ICSS_EMAC instance
*   @param[in]  emacMode Switch mode or mac mode
*
 *  @retval     0 on sucess
 */
uint8_t ICSS_EmacDeInit(ICSS_EmacHandle icssEmacHandle,uint8_t emacMode)
{
    switch(emacMode)
    {
        case ICSS_EMAC_MODE_SWITCH:
            ICSS_EmacMdioIntrDisableSwitch(ICSS_EMAC_PORT_1,icssEmacHandle);
            break;
        case ICSS_EMAC_MODE_MAC1 | ICSS_EMAC_MODE_DUALMAC:
            ICSS_EmacMdioIntrDisable(ICSS_EMAC_PORT_1,icssEmacHandle);
            break;
        case ICSS_EMAC_MODE_MAC1:
            ICSS_EmacMdioIntrDisable(ICSS_EMAC_PORT_1,icssEmacHandle);
            break;
        case ICSS_EMAC_MODE_MAC2 | ICSS_EMAC_MODE_DUALMAC:
            ICSS_EmacMdioIntrDisable(ICSS_EMAC_PORT_2,icssEmacHandle);
            break;
        case ICSS_EMAC_MODE_MAC2:
            ICSS_EmacMdioIntrDisable(ICSS_EMAC_PORT_2,icssEmacHandle);
            break;
        default:
            break;
    } 
    ICSS_EmacOSDeInit(icssEmacHandle);
    return 0U;
}

/**
 *  \name ICSS_EmacIoctl
 *  @brief  IOCTL Function for ICSSEMAC LLD
 *
 *       This Function can be used to configure various ICSS EMAC Functionalities. The Supported features are
 *       1)Port Enable/Disable   2)StormControl 3)Learning configuration    4)Statistics module
 *       5)Time Triggered Send Enable/Disable   6)Time Triggered Send Status Query
 *       ioctlCommand and ioctlParams are to provided to configure the desired feature.
 *       This Api should be used once the ICSS EMAC LLD init is done.
 *
 *       1)Port Enable/Disable
 *          ioctlCommand                ICSS_EMAC_IOCTL_PORT_CTRL
 *          ioctlParams.ioctlVal        ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE   To disable Port
 *                                      ICSS_EMAC_IOCTL_PORT_CTRL_ENABLE    To enable Port
 *
 *       2)StormControl
 *          ioctlCommand                ICSS_EMAC_IOCTL_STORM_PREV_CTRL
 *          ioctlParams.command         ICSS_EMAC_STORM_PREV_CTRL_ENABLE        Enables Storm prevention
 *                                      ICSS_EMAC_STORM_PREV_CTRL_DISABLE       Disables Storm prevention
 *                                      ICSS_EMAC_STORM_PREV_CTRL_INIT          initialize storm prevention module
 *                                      ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS
 *                                      ICSS_EMAC_STORM_PREV_CTRL_RESET
 *       3)Learning configuration
 *          ioctlCommand                ICSS_EMAC_IOCTL_LEARNING_CTRL
 *          ioctlParams.command         ICSS_EMAC_LEARN_CTRL_UPDATE_TABLE       Update the learning table with new entry
 *                                      ICSS_EMAC_LEARN_CTRL_CLR_TABLE          Clear the learning table
 *                                      ICSS_EMAC_LEARN_CTRL_AGEING             Ages the learning table
 *                                      ICSS_EMAC_LEARN_CTRL_FIND_MAC           Find the port number valid for a MACID
 *                                      ICSS_EMAC_LEARN_CTRL_REMOVE_MAC         removes a particular MACID
 *                                      ICSS_EMAC_LEARN_CTRL_INC_COUNTER        Increment counter.To be done periodically
 *                                      ICSS_EMAC_LEARN_CTRL_INIT_TABLE         Initialize learning table
 *                                      ICSS_EMAC_LEARN_CTRL_SET_PORTSTATE      Control Port state
 *
 *       4)Statistics module
 *          ioctlCommand                ICSS_EMAC_IOCTL_STAT_CTRL_GET           Updates statistics structure in handle
 *          ioctlParams.command         ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR         Clear the statistics
 *
 *       5)Time Triggered Send Enable/Disable
 *          ioctlCommand                ICSS_EMAC_IOCTL_TTS_CTRL           		Enable/disable TTS based on ioctlParams
 *          ioctlParams.ioctlVal		ICSS_EmacTTSConfig*						Structure pointer with TTS init details
 *
 *       6)Time Triggered Send Status Query
 *          ioctlCommand                ICSS_EMAC_IOCTL_TTS_STATUS_CTRL         Query TTS status from PRU firmware.
 *          ioctlParams.ioctlVal		ICSS_EmacTTSQuery*						Structure elements will be updated based on result from PRU Firmware.
 *
 *  @param icssEmacHandle   [IN]  ICSS EMAC Handle
 *  @param ioctlCommand     [IN]  IOCTL Command
 *  @param portNo           [IN]  Port number
 *  @param ioctlParams      [IN]  IOCTL parameter
 *  \return  0 on success
 */
int8_t ICSS_EmacIoctl(ICSS_EmacHandle icssEmacHandle, uint32_t ioctlCommand, uint8_t portNo, void *ioctlParams)
{
    uint8_t* pControl;
    int8_t retVal = -((int8_t)1);
    ICSSEMAC_IoctlCmd* ioctlCmd = (ICSSEMAC_IoctlCmd*)ioctlParams;
    void *ioctlData = ioctlCmd->ioctlVal;
    ICSS_EmacTTSConfig* ttsConfig;
    ICSS_EmacTTSQuery* ttsQuery;
    uint32_t temp_addr = 0U;
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    switch (ioctlCommand)
    {
        case ICSS_EMAC_IOCTL_PROMISCUOUS_CTRL:
            if(1U == *((uint32_t*)ioctlData))
            {
                retVal = ICSSPromiscuousModeInit(portNo, icssEmacHandle);
            }
            else
            {
                retVal = ICSSPromiscuousModeDeInit(portNo, icssEmacHandle);
            }
            break;
        case ICSS_EMAC_IOCTL_PORT_CTRL:
            if((uint8_t)ICSS_EMAC_PORT_1 == portNo) {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->portControlAddr);
                pControl = (uint8_t*)(temp_addr);
                retVal = 0;
            }
            else if((uint8_t)ICSS_EMAC_PORT_2 == portNo) {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->portControlAddr);
                pControl = (uint8_t*)(temp_addr);
                retVal = 0;
            }
            else
            {
                break;
            }

            *pControl = (*((uint8_t *)ioctlData));
            break;
        case ICSS_EMAC_IOCTL_LEARNING_CTRL:
            switch(ioctlCmd->command) {
                case ICSS_EMAC_LEARN_CTRL_UPDATE_TABLE:
                    updateHashTable((uint8_t *)ioctlData,portNo,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr,(((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->learningExCallBack);
                    break;
                case ICSS_EMAC_LEARN_CTRL_CLR_TABLE:
                    if(portNo == (uint8_t)ICSS_EMAC_PORT_1)
                    {    
                        purgeTable(portNo,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    }
                    if(portNo == (uint8_t)ICSS_EMAC_PORT_2)
                    {    
                        purgeTable(portNo,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr+1);
                    }
                    break;
                case ICSS_EMAC_LEARN_CTRL_AGEING:
                    if(portNo == (uint8_t)ICSS_EMAC_PORT_1)
                    {    
                         ageingRoutine(portNo,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    }
                    if(portNo == (uint8_t)ICSS_EMAC_PORT_2)
                    {    
                         ageingRoutine(portNo,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr+1);
                    }
                    break;
                case ICSS_EMAC_LEARN_CTRL_FIND_MAC:/*/RETURN */
                    retVal = ((int8_t)(findMAC((uint8_t *)ioctlData,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr)));
                    break;
                case ICSS_EMAC_LEARN_CTRL_REMOVE_MAC:
                    removeMAC((uint8_t *)ioctlData,((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    break;
                case ICSS_EMAC_LEARN_CTRL_INC_COUNTER:
                    incrementCounter(((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    break;
                case ICSS_EMAC_LEARN_CTRL_INIT_TABLE:
                    initLearningTable(((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    break;
                case ICSS_EMAC_LEARN_CTRL_SET_PORTSTATE:
                    changePortState((portState)(*((uint8_t *)ioctlData)),((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
                    break;
                default:
                    retVal = -((int8_t)1);
                    break;
            }
            break;
        case ICSS_EMAC_IOCTL_FW_LEARNING_CTRL:
            switch(ioctlCmd->command) {
                case ICSS_EMAC_FW_LEARN_CTRL_UPDATE_TABLE:
                    fdbInsert(((ICSS_EmacObject*)icssEmacHandle->object)->fdb,
			      *(MAC*)ioctlData, portNo, false);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_INSERT_STATIC_MAC:
                    fdbInsert(((ICSS_EmacObject*)icssEmacHandle->object)->fdb,
			      *(MAC*)ioctlData, portNo, true);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_CLR_TABLE:
                    fdbPurge(((ICSS_EmacObject*)icssEmacHandle->object)->fdb);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_AGEING:
                    fdbAgeingRoutine(((ICSS_EmacObject*)icssEmacHandle->object)->fdb);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_FIND_MAC:/*/RETURN */
                    // Search FDB
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_REMOVE_MAC:
                    fdbDelete(((ICSS_EmacObject*)icssEmacHandle->object)->fdb,
			      *(MAC*)ioctlData);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_INC_COUNTER:		  		  
                    fdbIncrementAgeingCounter(((ICSS_EmacObject*)icssEmacHandle->object)->fdb);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_INIT_TABLE:		  
                    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + ICSS_EMAC_FW_FDB__BASE_OFFSET);
                    fdbInit(((ICSS_EmacObject*)icssEmacHandle->object)->fdb, temp_addr);
                    break;
                case ICSS_EMAC_FW_LEARN_CTRL_SET_PORTSTATE:
                    fdbUpdateStpState(((ICSS_EmacObject*)icssEmacHandle->object)->fdb,
				      portNo,
				      (*((uint8_t *)ioctlData)));
                    break;
                default:
                    retVal = -((int8_t)1);
                    break;
            }
            break;
        case ICSS_EMAC_IOCTL_STORM_PREV_CTRL:
            retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNo, ICSS_EMAC_FW_STORM_PREVENTIION_FEATURE_CTRL);
            if (retVal == 0)
            {
                switch(ioctlCmd->command) {
                    case ICSS_EMAC_STORM_PREV_CTRL_ENABLE:
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), BC_STORM_PREVENTION);
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), MC_STORM_PREVENTION);
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_DISABLE:
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS:
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), BC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), MC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_INIT:
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_RESET:
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, BC_STORM_PREVENTION);
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, MC_STORM_PREVENTION);
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_ENABLE_BC:
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), BC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_DISABLE_BC:
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS_BC:
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), BC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_INIT_BC:
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, BC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_RESET_BC:
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, BC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_ENABLE_MC:
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), MC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_DISABLE_MC:
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS_MC:
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), MC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_INIT_MC:
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, MC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_RESET_MC:
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, MC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_ENABLE_UC:
                        ICSS_EmacEnableStormPrevention(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_DISABLE_UC:
                        ICSS_EmacDisableStormPrevention(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_SET_CREDITS_UC:
                        setCreditValue((*((uint16_t *)ioctlData)), ((stormPrevention_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->stormPrevPtr)), UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_INIT_UC:
                        ICSS_EmacInitStormPreventionTable(portNo, icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    case ICSS_EMAC_STORM_PREV_CTRL_RESET_UC:
                        ICSS_EmacResetStormPreventionCounter(icssEmacHandle, UC_STORM_PREVENTION);
                        break;
                    default:
                        retVal = -((int8_t)1);
                        break;
                }
            }
            break;
        case ICSS_EMAC_IOCTL_STATS_CTRL:
            switch(ioctlCmd->command) {
                case ICSS_EMAC_IOCTL_STAT_CTRL_GET:
                    ICSS_EmacReadStats(portNo, icssEmacHandle);
                    break;
                case ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR:
                    PurgeStats(portNo, icssEmacHandle);
                    break;
                default:
                    retVal = -((int8_t)1);
                    break;
            }
            break;
        case ICSS_EMAC_IOCTL_TTS_CTRL:
            retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNo, ICSS_EMAC_FW_TTS_FEATURE_CTRL);
            if (retVal == 0)
            {
                ttsConfig = (ICSS_EmacTTSConfig*)ioctlCmd->ioctlVal;
                retVal = ICSS_EmacTTS(ttsConfig);
            }
            break;
        case ICSS_EMAC_IOCTL_TTS_STATUS_CTRL:
            retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNo, ICSS_EMAC_FW_TTS_FEATURE_CTRL);
            if (retVal == 0)
            {
                ttsQuery = (ICSS_EmacTTSQuery*)ioctlCmd->ioctlVal;
                retVal = ICSS_EmacTTSGetStatus(ttsQuery);
            }
            break;
        case ICSS_EMAC_IOCTL_MULTICAST_FILTER_CTRL:
            retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNo, ICSS_EMAC_FW_MULTICAST_FILTER_FEATURE_CTRL);
            if (retVal == 0)
            {
                if((uint8_t)ICSS_EMAC_PORT_1 == portNo)
                {
                    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr);
                    pControl = (uint8_t*)(temp_addr);
                    retVal = 0;
                }
                else if((uint8_t)ICSS_EMAC_PORT_2 == portNo) {
                    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr);
                    pControl = (uint8_t*)(temp_addr);
                    retVal = 0;
                }
                else
                {
                    retVal = -((int8_t)1);
                    break;
                }
                retVal = ICSS_EmacMulticastFilterConfig((uintptr_t) pControl,ioctlCmd->command,ioctlCmd->ioctlVal);
            }
            break;

        case ICSS_EMAC_IOCTL_VLAN_FILTER_CTRL:
            retVal = ICSS_EmacValidateFeatureSet(icssEmacHandle, portNo, ICSS_EMAC_FW_VLAN_FILTER_FEATURE_CTRL);
            if (retVal == 0)
            {
                if((uint8_t)ICSS_EMAC_PORT_1 == portNo)
                {
                    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr);
                    pControl = (uint8_t*)(temp_addr);
                    retVal = 0;
                }
                else if((uint8_t)ICSS_EMAC_PORT_2 == portNo) {
                    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr);
                    pControl = (uint8_t*)(temp_addr);
                    retVal = 0;
                }
                else
                {
                    retVal = -((int8_t)1);
                    break;
                }
                retVal = ICSS_EmacVlanFilterConfig((uintptr_t) pControl,ioctlCmd->command,ioctlCmd->ioctlVal);
            }
            break;

        default:
            retVal = -((int8_t)1);
            break;
    }
    return retVal;
}

/**
 *  \name PRUSSDRVPruCfgInit
 *  @brief function to configure PRUSS register
 *
 *  @param none
 *
 *  \return none
 */
static void PRUSSDRVPruCfgInit(ICSS_EmacHandle emacSubSysHandle)
{
    ICSS_EmacBaseAddressHandle_T icssEmacBaseAddressHandle= ((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg;
    PRUICSS_Handle pruicssHandle = ((ICSS_EmacObject*)emacSubSysHandle->object)->pruIcssHandle;
    uint32_t icss_version = PRUICSS_getICSSVersion(pruicssHandle);

    HW_WR_FIELD32(icssEmacBaseAddressHandle->prussCfgRegs,CSL_ICSSCFG_SYSCFG_IDLE_MODE , 1);

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_SYSCFG,
                        CSL_ICSSCFG_SYSCFG_STANDBY_INIT , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_SYSCFG,
                        CSL_ICSSCFG_SYSCFG_STANDBY_MODE , 1);

    if (icss_version >= 0x201U)
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_GPCFG0,
                            CSL_ICSSCFG_GPCFG0_PRU0_GPI_MODE , 3);
    
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_GPCFG1,
                            CSL_ICSSCFG_GPCFG1_PRU1_GPI_MODE , 3);

        /* Select ocp_clk for lower IEP Latency */
        PRUICSS_setIepClkSrc(pruicssHandle,1U);
    }
    else
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_GPCFG0,
                            CSL_ICSSCFG_GPCFG0_PRU0_GPI_MODE , 1);
    
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_GPCFG1,
                            CSL_ICSSCFG_GPCFG1_PRU1_GPI_MODE , 1);
    }
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_MII_RT,
            CSL_ICSSCFG_MII_RT_MII_RT_EVENT_EN , 1);

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussCfgRegs) + CSL_ICSSCFG_SPP,
                        CSL_ICSSCFG_SPP_XFR_SHIFT_EN , 1);
}

static void PRUSSDRVPruMiiRtCfgInit(ICSS_EmacHandle emacSubSysHandle)
{

    ICSS_EmacBaseAddressHandle_T icssEmacBaseAddressHandle= ((ICSS_EmacHwAttrs const *)emacSubSysHandle->hwAttrs)->emacBaseAddrCfg;
    PRUICSS_Handle pruicssHandle = ((ICSS_EmacObject*)emacSubSysHandle->object)->pruIcssHandle;
    uint32_t icss_version = PRUICSS_getICSSVersion(pruicssHandle);

    /* Configure the minimum inter packet gap for the Tx on bothe the ports */
    HW_WR_REG8((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TX_IPG0, TX_MIN_IPG);
    HW_WR_REG8((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TX_IPG1, TX_MIN_IPG);
    /* Configuration of Port 0 */
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
            CSL_ICSSMIIRT_RXCFG0_RX_ENABLE , 1);


    if (icss_version >= 0x201U)
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
                CSL_ICSSMIIRT_RXCFG0_RX_DATA_RDY_MODE_DIS , 1);
     }

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
            CSL_ICSSMIIRT_RXCFG0_RX_MUX_SEL , 0);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
            CSL_ICSSMIIRT_RXCFG0_RX_L2_EN , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
            CSL_ICSSMIIRT_RXCFG0_RX_CUT_PREAMBLE , 1);


    if (icss_version >= 0x201U)
    {
        /* Enable the clearing of RX_EOF from PRU R31 command */
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG0,
            CSL_ICSSMIIRT_RXCFG0_RX_L2_EOF_SCLR_DIS , 1);
    }




    /* Enable the output FIFO and set a delay of 0x40 in nibbles, route TX back to Port0 */
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_ENABLE , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_AUTO_PREAMBLE , 1);

    if (icss_version >= 0x201U)
    {
        /* Enable the 32 bit insert in Tx FIFO */
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_32_MODE_EN , 1);
    }

    /* need this change for tx pin swap in mii mode for SOC_AM65XX only*/
#if defined (ICSS_EMAC_MII_MODE) && defined (SOC_AM65XX)
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->portMask)
    { /*Switch mode*/
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
                CSL_ICSSMIIRT_TXCFG0_TX_MUX_SEL , 0);
    }
    else
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
                CSL_ICSSMIIRT_TXCFG0_TX_MUX_SEL , 1);
    }
#else
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->portMask)
    { /*Switch mode*/
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_MUX_SEL , 1);
    } 
    else 
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_MUX_SEL , 0);
    }
#endif


    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_START_DELAY , 0x40);

    if (icss_version >= 0x201U)
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG0,
            CSL_ICSSMIIRT_TXCFG0_TX_CLK_DELAY , 0x6);
    }

    /* Configuration of Port 1 */

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_ENABLE , 1);

    if (icss_version >= 0x201U)
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_DATA_RDY_MODE_DIS , 1);
    }

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_MUX_SEL , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_L2_EN , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_CUT_PREAMBLE , 1);

    if (icss_version >= 0x201U)
    {
        /* Enable the clearing of RX_EOF from PRU R31 command */
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_RXCFG1,
            CSL_ICSSMIIRT_RXCFG1_RX_L2_EOF_SCLR_DIS , 1);
    }


    /* Enable the output FIFO and set a delay of 0x40 in nibbles, route TX back to Port0 */
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
            CSL_ICSSMIIRT_TXCFG1_TX_ENABLE , 1);
    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
            CSL_ICSSMIIRT_TXCFG1_TX_AUTO_PREAMBLE , 1);

    if (icss_version >= 0x201U)
    {
        /* Enable the 32 bit insert in Tx FIFO */
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
            CSL_ICSSMIIRT_TXCFG1_TX_32_MODE_EN , 1);
    }

    /* need this change for tx pin swap in mii mode for SOC_AM65XX only*/
#if defined (ICSS_EMAC_MII_MODE) && defined (SOC_AM65XX)
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->portMask)
    { /*Switch mode*/
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
                CSL_ICSSMIIRT_TXCFG1_TX_MUX_SEL , 1);
    }
    else
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
                CSL_ICSSMIIRT_TXCFG1_TX_MUX_SEL , 0);
    }
#else
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)emacSubSysHandle->object)->emacInitcfg)->portMask)
    { /*Switch mode*/
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
                CSL_ICSSMIIRT_TXCFG1_TX_MUX_SEL , 0);
    }
    else
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
                CSL_ICSSMIIRT_TXCFG1_TX_MUX_SEL , 1);
    }
#endif

    HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
            CSL_ICSSMIIRT_TXCFG1_TX_START_DELAY , 0x40);

    if (icss_version >= 0x201U)
    {
        HW_WR_FIELD32((icssEmacBaseAddressHandle->prussMiiRtCfgRegsBaseAddr) + CSL_ICSSMIIRT_TXCFG1,
            CSL_ICSSMIIRT_TXCFG1_TX_CLK_DELAY , 0x6);

     }
}

