/**
 * @file icss_emacDrv.c
 * @brief Contains the Rx and Tx functions for packet processing on ARM including the ISR for two PRU
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

#include <stdint.h>
#ifdef __LINUX_USER_SPACE
#include <time.h>   /* for nanosleep() */
#endif
#if defined (SOC_AM65XX)
#include <ti/csl/csl_mdio.h>
#include <ti/csl/src/ip/icss/V2/cslr_icss_g.h>
uint32_t icssEmacIepCountOffset = CSL_ICSS_G_PR1_IEP1_SLV_COUNT_REG0;
#else
/* For ICSS intc, only need to include V1 version of header file. 
   What is required by the driver from these header files are register macro 
   and  field definition macros defines which have the same values
   across V0 and V1 versions of the IP*/
#include <ti/csl/src/ip/icss/V1/cslr_icss_intc.h>
#include <ti/csl/src/ip/icss/V1/cslr_icss_iep.h>
#include <ti/csl/src/ip/icss/V0/cslr_icssm_iep.h>

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
uint32_t icssEmacIepCountOffset = CSL_ICSSM_IEP_COUNT;
#else
#include <ti/csl/csl_mdioAux.h>
uint32_t icssEmacIepCountOffset = CSL_ICSSIEP_COUNT_REG0;
#endif
#endif
#include <ti/drv/pruss/pruicss.h>



#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/icss_emacCommon.h>
#include <ti/drv/icss_emac/icss_emacStatistics.h>
#include <ti/drv/icss_emac/icss_emacStormControl.h>
#include <ti/drv/icss_emac/icss_emacLearning.h>
#include <ti/drv/icss_emac/icss_emacFwLearning.h>
#include <ti/drv/icss_emac/icss_emacFwInit.h>
#include <ti/drv/icss_emac/src/icss_emacLoc.h>

#include <ti/osal/osal.h>

extern ICSS_EmacFwStaticMmap icss_emacFwStaticCfg[ICSS_EMAC_MAX_PRU_ICSS_INSTANCES];
extern ICSS_EmacFwDynamicMmap icss_emacFwDynamicCfg;


#ifdef __LINUX_USER_SPACE
extern void wait_interrupt(void *pruss_handle, unsigned int int_num, unsigned int fd);
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**Minimum supported size of Ethernet frame*/
#define ETHERNET_FRAME_SIZE_60 (60U)

typedef enum {
    ICSS_EMAC_INTR_SRC_LINK = 0,
    ICSS_EMAC_INTR_SRC_RX,
    ICSS_EMAC_INTR_SRC_TX,
    ICSS_EMAC_INTR_SRC_TTS
} ICSS_EmacIntrSrc_e;

#define PHY_LINK_STATUS                   (0x0004u)
#define PHY_BSR                           (1u)
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/** Variable containing list of implemented protocols*/
uint16_t numImplementedProtocols = NUM_PROTOCOLS_IMPLEMENTED;
/**list of identified protocol types, rest initialized to zero*/
uint16_t protocol_impl[MAX_NUM_PROTOCOL_IMPLEMENTED] = {IP4_PROT_TYPE, ARP_PROT_TYPE,0,0,0,0, 0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,
                                                        0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
/** port params for three ports, two physical and one for host*/
/*ICSS_EmacPortParams switchPort[3];*/
/**Number of collisions occured*/
int32_t num_of_collision_occured = 0;
/**Number of packets dropped as a result of collision not resolved*/
int32_t collision_pkt_dropped =0;
/** @brief User specific data HW Port 0 Link ISR*/

int32_t invalidLinkEvent = 0;
static inline void ICSS_EmacCalcTTSOffsets(ICSS_EmacHandle icssEmacHandle, ICSS_EmacTTSOffsets *pTTSOffset);
static inline void ICSS_EmacPollLink(ICSS_EmacHandle icssEmacHandle, uint32_t pollSource);
static inline void ICSS_EmacPollPkt(ICSS_EmacHandle icssEmacHandle);
static inline void ICSS_EmacClearTxIrq(ICSS_EmacHandle icssemacHandle);
static inline void ICSS_EmacClearTTSCycIrq(ICSS_EmacHandle icssemacHandle);
static inline void memcpy_local(void *dst, const void *src, size_t len);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  \name ICSS_EmacClearIrq
 *  @brief Clears interrupt Function. There are 2 possible sequence for clearing interrupt. 
 *         Failure to follow this sequence may result into race condition.
 *
 *         1. Level sensitive interrupt controllers: a) clear interrupt via SECR
 *
 *         2. Edge sensitive interrupt controllers: a) disable interrupt via EICR
 *                                                  b) clear interrupt via SECR
 *                                                  c) enable interrupt via EISR.
 *
 *  @param Handle: icss_emac handle
 *         intNum: interrupt number
 *
 *  @retval none
 *
 */
static inline void ICSS_EmacClearIrq(ICSS_EmacHandle icssemacHandle, uint32_t intNum);   /* for misra warning*/
static inline void ICSS_EmacClearIrq(ICSS_EmacHandle icssemacHandle, uint32_t intNum)
{
    if(32 > intNum)
    {
#if defined (_TMS320C6X) || defined (SOC_K2G)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_EICR),
                CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, intNum);
#endif
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0),
                CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, ((uint32_t)1U) << intNum);
#if defined (_TMS320C6X) || defined (SOC_K2G)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_EISR),
                CSL_ICSSINTC_SECR0_ENA_STATUS_31_0, intNum);
#endif
    }
    else
    {
#if defined (_TMS320C6X) || defined (SOC_K2G)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_EICR),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, intNum);
#endif
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, ((uint32_t)1U) << (intNum-(uint32_t)32U));
#if defined (_TMS320C6X) || defined (SOC_K2G)
        HW_WR_FIELD32(((((ICSS_EmacHwAttrs*)icssemacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_EISR),
                CSL_ICSSINTC_SECR1_ENA_STATUS_63_32, intNum);
#endif
    }
}

/**
 *  \name ICSS_EmacClearRxIrq
 *  @brief Clears Rx interrupt
 *
 *  @param none
 *
 *  @retval none
 *
 */
static inline void ICSS_EmacClearRxIrq(ICSS_EmacHandle icssemacHandle);   /* for misra warning*/
static inline void ICSS_EmacClearRxIrq(ICSS_EmacHandle icssemacHandle)
{
    if((((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2) {
        ICSS_EmacClearIrq(icssemacHandle, 21);
    } else {
        ICSS_EmacClearIrq(icssemacHandle, 20);
    }
}

#ifdef __LINUX_USER_SPACE
/* Private function to check the SECR0 register to see if the Tx interrupt is set */
static inline bool ICSS_EMAC_CheckIntStatusTx(void *handle) {
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle)handle;
    uint32_t intStatus = HW_RD_REG32(((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0));

    if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask == ICSS_EMAC_MODE_MAC1)
    {
        if(TX_COMPLETION0_PRU_EVT_MASK & intStatus) return TRUE;
    }
    else if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask == ICSS_EMAC_MODE_MAC2)
    {
        if(TX_COMPLETION1_PRU_EVT_MASK & intStatus) return TRUE;
    }
    return FALSE;
}

/* Private function to check the SECR0 register to see if the TTS interrupt is set */
static inline bool ICSS_EMAC_CheckIntStatusTTS(void *handle) {
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle)handle;
    uint32_t intStatus = HW_RD_REG32(((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0));

    if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask == ICSS_EMAC_MODE_MAC1)
    {
        if(TTS_CYC0_PRU_EVT_MASK & intStatus) return TRUE;
    }
    else if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask == ICSS_EMAC_MODE_MAC2)
    {
        if(TTS_CYC1_PRU_EVT_MASK & intStatus) return TRUE;
    }
    return FALSE;
}
#endif

/* Private function for a task function to call pend and clear an interrupt
 * if necessary; is OS specific:
 * TI-RTOS: pends on a semaphore
 * Linux: pends directly on an interrupt
 */

/* #define DEBUG_TIMING_PRUSS */
#ifdef DEBUG_TIMING_PRUSS
extern uint32_t int_arr_drv_port1[];
extern uint32_t int_arr_drv_port2[];
extern uint32_t index_port1, index_port2;
extern ICSS_EmacHandle ICSS_EMAC_testHandle2;
extern ICSS_EmacHandle ICSS_EMAC_testHandle3;
#endif

static inline void ICSS_EMAC_Pend(void *handle, int32_t interrupt_type); /* misra-c */
static inline void ICSS_EMAC_Pend(void *handle, int32_t interrupt_type) {
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle)handle;
    /* link = 0; rx = 1; tx = 2; tts = 3 */
#ifdef __LINUX_USER_SPACE
    int done = 0;
    switch (interrupt_type) {
    case ICSS_EMAC_INTR_SRC_LINK:
        wait_interrupt(((ICSS_EmacObject*)icssEmacHandle->object)->pruss_drv_handle,
                       (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum,
                        ((ICSS_EmacObject*)icssEmacHandle->object)->linkInt_fd);
        break;
    case ICSS_EMAC_INTR_SRC_RX:
        wait_interrupt(((ICSS_EmacObject*)icssEmacHandle->object)->pruss_drv_handle,
                      (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum,
                       ((ICSS_EmacObject*)icssEmacHandle->object)->rxInt_fd);
        ICSS_EmacClearRxIrq(icssEmacHandle);
        break;
    case ICSS_EMAC_INTR_SRC_TX:
        while (!done) {
            wait_interrupt(((ICSS_EmacObject*)icssEmacHandle->object)->pruss_drv_handle,
                          (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum,
                           ((ICSS_EmacObject*)icssEmacHandle->object)->txInt_fd);
            if(ICSS_EMAC_CheckIntStatusTx(icssEmacHandle)) {
                ICSS_EmacClearTxIrq(icssEmacHandle);
                done = 1;
            } else {
                linux_sleep_ns(1);
            }
        }
        break;
    case ICSS_EMAC_INTR_SRC_TTS:
        while (!done) {
            wait_interrupt(((ICSS_EmacObject*)icssEmacHandle->object)->pruss_drv_handle,
                          (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->txIntNum,
                           ((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycInt_fd);
            if(ICSS_EMAC_CheckIntStatusTTS(icssEmacHandle)) {
#ifdef DEBUG_TIMING_PRUSS
                if( icssEmacHandle == ICSS_EMAC_testHandle2)
                {
                    int_arr_drv_port1[index_port1++] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + icssEmacIepCountOffset);
                }

                if( icssEmacHandle == ICSS_EMAC_testHandle3)
                {
                    int_arr_drv_port2[index_port2++] = HW_RD_REG32((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs  + icssEmacIepCountOffset);
                }
#endif
                ICSS_EmacClearTTSCycIrq(icssEmacHandle);
                done = 1;
            } else {
                linux_sleep_ns(1);
            }
        }
        break;
    }

#else
    switch (interrupt_type) {
        case ICSS_EMAC_INTR_SRC_LINK:
            ICSS_EMAC_osalPendLock(((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle, SemaphoreP_WAIT_FOREVER);
            break;
        case ICSS_EMAC_INTR_SRC_RX:
            ICSS_EMAC_osalPendLock(((ICSS_EmacObject*)icssEmacHandle->object)->rxSemaphoreHandle, SemaphoreP_WAIT_FOREVER);
            break;
        case ICSS_EMAC_INTR_SRC_TX:
            ICSS_EMAC_osalPendLock(((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle, SemaphoreP_WAIT_FOREVER);
            break;
        case ICSS_EMAC_INTR_SRC_TTS:
            ICSS_EMAC_osalPendLock(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle, SemaphoreP_WAIT_FOREVER);
            break;
        default:
            break;
    }
#endif
}

void ICSS_EmacEnableRxInterrupt(ICSS_EmacHandle icssemacHandle);   /* for misra warning*/
void ICSS_EmacEnableRxInterrupt(ICSS_EmacHandle icssemacHandle)
{
    uint32_t intNum = ((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg->rxIntNum;
    ICSS_EMAC_osalHardwareInterruptEnable((int32_t)intNum);
}

void ICSS_EmacDisableRxInterrupt(ICSS_EmacHandle icssemacHandle);  /* for misra warning*/
void ICSS_EmacDisableRxInterrupt(ICSS_EmacHandle icssemacHandle)
{
    uint32_t intNum = ((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg->rxIntNum;
    ICSS_EMAC_osalHardwareInterruptDisable((int32_t)intNum);

}


/**
 *  \name ICSS_EmacClearTxIrq
 *  @brief Clears Tx Packet Completion interrupt
 *
 *  @param none
 *
 *  @retval none
 *
 */
static inline void ICSS_EmacClearTxIrq(ICSS_EmacHandle icssemacHandle)
{
    if((((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2) {
        ICSS_EmacClearIrq(icssemacHandle, 23);
    } else {
        ICSS_EmacClearIrq(icssemacHandle, 22);
    }
}

void ICSS_EmacEnableTxInterrupt(ICSS_EmacHandle icssemacHandle); /* for misra warnings*/
void ICSS_EmacEnableTxInterrupt(ICSS_EmacHandle icssemacHandle) {
    uint32_t intNum = ((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg->txIntNum;
    ICSS_EMAC_osalHardwareInterruptEnable((int32_t)intNum);
}

void ICSS_EmacDisableTxInterrupt(ICSS_EmacHandle icssemacHandle); /* for misra warnings*/
void ICSS_EmacDisableTxInterrupt(ICSS_EmacHandle icssemacHandle) {
    uint32_t intNum = ((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg->txIntNum;
    ICSS_EMAC_osalHardwareInterruptDisable((int32_t)intNum);

}

/**
 *  \name ICSS_EmacClearTTSCycIrq
 *  @brief Clears TTS Cyclic Packet Insertion Notification interrupt
 *
 *  @param none
 *
 *  @retval none
 *
 */
static inline void ICSS_EmacClearTTSCycIrq(ICSS_EmacHandle icssemacHandle)
{
    if((((ICSS_EmacObject*)icssemacHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_MAC2) {
        ICSS_EmacClearIrq(icssemacHandle, 25);
    } else {
        ICSS_EmacClearIrq(icssemacHandle, 24);
    }
}


/**
 *  \name ICSS_EmacTxInterruptHandler
 *  @brief Main TX interrupt service routine
 *          Handles TX Completion and TTS Cyclic Packet
 *          Insertion Notification interrupts
 *
 *  @param args arguments if any
 *
 *  @retval
 *       void
 *
 */
void ICSS_EmacTxInterruptHandler(void *args)
{
    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle)args;
    uint32_t intStatus;
    
    intStatus = HW_RD_REG32(((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0));
    if (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC1))
    {
        if(TX_COMPLETION0_PRU_EVT_MASK & intStatus)
        {
            ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle);
            ICSS_EmacClearTxIrq(icssEmacHandle);
        }
    
        if(TTS_CYC0_PRU_EVT_MASK & intStatus)
        {
            ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle);
            ICSS_EmacClearTTSCycIrq(icssEmacHandle);
        }
    }
    if (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC2))
    {
        if(TX_COMPLETION1_PRU_EVT_MASK & intStatus)
        {
            ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle);
            ICSS_EmacClearTxIrq(icssEmacHandle);
        }
    
        if(TTS_CYC1_PRU_EVT_MASK & intStatus)
        {
            ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle);
            ICSS_EmacClearTTSCycIrq(icssEmacHandle);
        }
    }
}

/**
 *  \name ICSS_EmacRxInterruptHandler
 *  @brief Main Rx interrupt service routine
 *
 *  @param args arguments if any
 *
 *  @retval
 *       void
 *
 */
void ICSS_EmacRxInterruptHandler(void *args)
{
    uint8_t pacingEnabled;
    uint8_t pacingMode;
    ICSS_EmacHandle handle = (ICSS_EmacHandle)args;
    ICSS_EmacClearRxIrq((ICSS_EmacHandle)args);

    pacingEnabled = (((ICSS_EmacObject*)handle->object)->emacInitcfg)->enableIntrPacing;

    pacingMode = (((ICSS_EmacObject*)handle->object)->emacInitcfg)->ICSS_EmacIntrPacingMode;
    /*disable Rx interrupt on ARM, PRU line stays high*/
    if(pacingEnabled == ICSS_EMAC_ENABLE_PACING) {
        ICSS_EmacDisableRxInterrupt(handle);

        if((pacingMode == ICSS_EMAC_INTR_PACING_MODE2) && (((ICSS_EmacObject*)handle->object)->rxPacingTimerHandle != NULL))
        {
            ICSS_EMAC_osalTimerStart((((ICSS_EmacObject*)handle->object)->rxPacingTimerHandle));
        }
     }

    ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)handle->object)->rxSemaphoreHandle);
}

/**
 *  \name ICSS_EMacOsRxTaskFnc
 *  @brief
 *      Function which pends on Rx semaphore.Gets the Rx packet info for processing
 *
 *  @param a0 arg 1
 *  @param a1 arg 2
 *
 *  @retval none
 *
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsRxTaskFnc(void *a0)
#else
void ICSS_EMacOsRxTaskFnc(uint32_t a0, uint32_t a1)
#endif
{
    uint8_t pacingEnabled;
    uint8_t pacingMode;
    ICSS_EmacHandle icssEmacHandle;
    icssEmacHandle = (ICSS_EmacHandle)a0;

    pacingEnabled = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->enableIntrPacing;
    pacingMode    = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->ICSS_EmacIntrPacingMode;

    while(1)
    {
        ICSS_EMAC_Pend(icssEmacHandle, ICSS_EMAC_INTR_SRC_RX);

        ICSS_EmacPollPkt(icssEmacHandle);
        if(pacingEnabled == ICSS_EMAC_ENABLE_PACING) 
        {
            /*Enable interrupts*/
            if(pacingMode == ICSS_EMAC_INTR_PACING_MODE1) 
            {
                ICSS_EmacEnableRxInterrupt(icssEmacHandle);
            }
            /* This should not be the case, if timer based pacing enabled, rxPacingTimerHandle should be non-NULL, but
                in case this to be the case, re-enable the rx interrupt*/
            if((pacingMode == ICSS_EMAC_INTR_PACING_MODE2) && (((ICSS_EmacObject*)icssEmacHandle->object)->rxPacingTimerHandle != NULL))
            {
                ICSS_EmacEnableRxInterrupt(icssEmacHandle);
            }
        }
    }
}
/**
 *  \name ICSS_EMacOsLinkTaskFnc
 *  @brief
 *      Function which pends on Link semaphore.Updated PHY status on Link change
 *
 *  @param a0 arg 1
 *  @param a1 arg 2
 *
 *  @retval none
 *
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsLinkTaskFnc(void *a0)
#else
void ICSS_EMacOsLinkTaskFnc(uint32_t a0, uint32_t a1)
#endif
{
    ICSS_EmacHandle icssEmacHandle;
    icssEmacHandle = (ICSS_EmacHandle)a0;

    while(1)
    {
        ICSS_EMAC_Pend(icssEmacHandle, ICSS_EMAC_INTR_SRC_LINK);
#ifdef __LINUX_USER_SPACE
        /* This is needed for Linux only since TI-RTOS has registered ICSS_EmacLinkISR()
           directly as an interrupt handler */
        ICSS_EmacLinkISR((void *) icssEmacHandle);
#endif
        if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
        {
            /*Update flags in memory*/
            ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_1, icssEmacHandle);
            /*Update flags in memory*/
            ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_2, icssEmacHandle);
        }
        else if(ICSS_EMAC_MODE_MAC1 == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
        {
            ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_1, icssEmacHandle);
        }
        else if(ICSS_EMAC_MODE_MAC2 == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
        {
            ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_2, icssEmacHandle);
        }
        else
        {
            invalidLinkEvent++;
        }

    }
}
/**
 *  \name ICSS_EmacInterruptPacingISR
 *  @brief ISR for Interrupt Pacing DM Timer
 *
 *  @param args arguments if any
 *
 *  @retval
 *       void
 *
 */
void ICSS_EmacInterruptPacingISR(void *args); /* for misra warning*/
void ICSS_EmacInterruptPacingISR(void *args)
{
    ICSS_EmacHandle icssEmacHandle;
    icssEmacHandle = (ICSS_EmacHandle)args;
    ICSS_EmacEnableRxInterrupt(icssEmacHandle);
}

/**
 *  @b Description
 *  @n
 *      API to queue a frame which has to be transmitted on the
 *      specified port queue
 *
 *  @param[in]  txArg defined at @ref ICSS_EmacTxArgument
 *  @param[in]  userArg custom Tx packet callback packet options only required for custom TxPacket implementations,
                default to NULL when calling ICSS_EmacTxPacket which is default Tx Packet API
 *  @retval     0 on scuess,  <0 on failure
 */
int32_t ICSS_EmacTxPacket(const ICSS_EmacTxArgument *txArg, void* userArg)

{
    int32_t ret=-((int32_t)1);
    const uint8_t*        macId;
    uint8_t txPort, trigTx1, trigTx2;

    ICSS_EmacHandle icssEmacHandle = txArg->icssEmacHandle;
    uint8_t portNumber= txArg->portNumber;
    uint8_t queuePriority = txArg->queuePriority;
    uint16_t lengthOfPacket = txArg->lengthOfPacket;


    int32_t ret_val = 0;

    macId = txArg->srcAddress;
    
        if (portNumber == ICSS_EMAC_PORT_0)    /* special case to use MAC learning */
        {
            /* get the Port number from MAC tables.. */
            txPort = findMAC(macId, ((ICSS_EmacObject*)(icssEmacHandle)->object)->macTablePtr);

            switch (txPort)
            {
                case 0U: /* need to send on both ports */
                    trigTx1 = 1U;
                    trigTx2 = 1U;
                    break;
                case 1U: /* ICSS_EMAC_PORT_1 */
                    trigTx1 = 1U;
                    trigTx2 = 0U;
                    break;
                case 2U: /* ICSS_EMAC_PORT_2 */
                    trigTx1 = 0U;
                    trigTx2 = 1U;
                    break;
                default:    /* ICSS_EMAC_PORT_0 */
                    trigTx1 = 1U;
                    trigTx2 = 0U;
                    break;
            }
            if(trigTx1 == 1U)
            {
                ret = ICSS_EmacTxPacketEnqueue(icssEmacHandle,
                                           txArg->srcAddress,
                                               (uint8_t)ICSS_EMAC_PORT_1, 
                                               queuePriority,
                                               lengthOfPacket);
            }
            if(trigTx2 == 1U)
            {
                if (ret == 0) {
                    ICSS_EmacTxPacketEnqueue( icssEmacHandle,
                                          txArg->srcAddress,
                                              (uint8_t)ICSS_EMAC_PORT_2,
                                              queuePriority,
                                              lengthOfPacket);
                } else {
                    ret = ICSS_EmacTxPacketEnqueue( icssEmacHandle,
                                                txArg->srcAddress,
                                                    (uint8_t)ICSS_EMAC_PORT_2,
                                                    queuePriority,
                                                    lengthOfPacket);
                }
            }

        }
        else
        {
            ret = ICSS_EmacTxPacketEnqueue(icssEmacHandle,
                                       txArg->srcAddress,
                                           portNumber,
                                           queuePriority,
                                           lengthOfPacket);
        }

        if(ret == 0)
        {
            ret_val = 0;
        }
        else
        {
            ret_val = -((int32_t)1);
        }

    return(ret_val);
}

/**
 *  \name     ICSS_EmacTTS
 *  @brief
 *          API to enable time triggered send for Queue 1 frames.
 *
 *  @param[in]  ttsConfig         EMAC TTS Configfuration structure (ICSS_EmacTTSConfig *).
 *  @retval     int8_t            0 on success, -1 on failure.
 */
int8_t ICSS_EmacTTS(const ICSS_EmacTTSConfig* ttsConfig)
{
    ICSSEMAC_Handle icssEmacHandle = NULL;
    uint8_t enableCycInterrupt = 0;
    uint8_t icssRevisionMajor = 0;
    uint8_t icssRevisionMinor = 0;
    uint64_t cycleStartTime = 0;
    uint64_t iepCounterVal = 0;
    uint8_t cycTxSOFStatus = 0;
    uint32_t iepRegsBase = 0;
    uint32_t cyclePeriod = 0;
    uint32_t pruDataMem = 0;
    uint32_t configTime = 0;
    uint8_t portNumber = 0;
    uint8_t statusTTS = 0;
    uint64_t* temp_64 = 0;
    uint32_t* temp_32 = 0;
    uint8_t* temp_8 = 0;
    int8_t ret = 0;
    ICSS_EmacTTSOffsets tTSOffsets;

    uint32_t temp_addr=0U;
    /*    Initialise TTS variables.    */
    icssEmacHandle = ttsConfig->icssEmacHandle;
    cycleStartTime = ttsConfig->cycleStartTime;
    cyclePeriod = ttsConfig->cyclePeriod;
    configTime = ttsConfig->configTime;
    portNumber = ttsConfig->portNumber;
    statusTTS = ttsConfig->statusTTS;
    cycTxSOFStatus = ttsConfig->cycTxSOFStatus;
    enableCycInterrupt = ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->ICSS_EmacTTSEnableCycPktInterrupt;
    /*    Checking parameters.    */
    if((ICSS_EMAC_PORT_1 != portNumber) && (ICSS_EMAC_PORT_2 != portNumber))
    {
        /*    Invalid portNumber.    */
        ret = -((int8_t)1);
        return ret;
    }

    if((ICSS_EMAC_TTS_ENABLE != statusTTS) && (ICSS_EMAC_TTS_DISABLE != statusTTS))
    {
        /*    Invalid statusTTS.    */
        ret = -((int8_t)1);
        return ret;
    }

    if((ICSS_EMAC_TTS_CYC_TXSOF_ENABLE != cycTxSOFStatus) && (ICSS_EMAC_TTS_CYC_TXSOF_DISABLE != cycTxSOFStatus))
    {
        /*    Invalid cycTxSOFStatus.    */
        ret = -((int8_t)1);
        return ret;
    }

        if(ICSS_EMAC_PORT_1 == portNumber) {
            pruDataMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
        }
        else    /*    ICSS_EMAC_PORT_2    */
        {
            pruDataMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
        }
    ICSS_EmacCalcTTSOffsets(icssEmacHandle, &tTSOffsets);

    if(ICSS_EMAC_TTS_DISABLE == statusTTS)
    {
        /*    Disable time triggered send.
         * Clearing bit 0, ICSS_EMAC_TTS_PRU_ENABLE; bit 3, TTS_CYC_TX_SOF_ENABLE.
         */
        temp_addr=pruDataMem + tTSOffsets.statusOffset;
        temp_8 = (uint8_t*)(temp_addr);
        (*temp_8) = (*temp_8) & ((uint8_t)(~(ICSS_EMAC_TTS_PRU_ENABLE_MASK | ICSS_EMAC_TTS_CYC_TX_SOF_MASK)));

        /*    Clear cycleStartTime, cyclePeriod and configTime.    */
        temp_addr=pruDataMem + tTSOffsets.cycleStartOffset;
        temp_64 = (uint64_t*)(temp_addr);
        (*temp_64) = 0;

        HW_WR_REG32((pruDataMem + tTSOffsets.cyclePeriodOffset),0U);

        HW_WR_REG32((pruDataMem + tTSOffsets.cfgTimeOffset), 0U);

        return ret;
    }

    /*    Clear previous status, missed_cycle_cnt, tx_sof_prev and cyc_tx_sof before enabling.    */
    HW_WR_REG32((pruDataMem + tTSOffsets.statusOffset), 0U);


    HW_WR_REG32((pruDataMem + tTSOffsets.missedCycleCntOffset), 0U);

    temp_addr=pruDataMem + tTSOffsets.prevTxSof;

    temp_64 = (uint64_t*)(temp_addr);
    (*temp_64) = 0;

    temp_addr=pruDataMem + tTSOffsets.cycTxSof;

    temp_64 = (uint64_t*)(temp_addr);
    (*temp_64) = 0;

    /*    Reading IEP Regs Base Address.    */
    iepRegsBase = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIepRegs;

    /*    Checking ICSS Version.
     *     This is being done in order to determine IEP timer type i.e., 32-bit timer or 64-bit timer.
     */
    icssRevisionMajor = ((ICSS_EmacObject *)icssEmacHandle->object)->icssRevisionMajor;
    icssRevisionMinor = ((ICSS_EmacObject *)icssEmacHandle->object)->icssRevisionMinor;

    /*    Checking Rev Major/Minor.    */
    if((icssRevisionMajor <= 0x2U) && (icssRevisionMinor < 0x1U))
    {
        /*    32-bit IEP Timer for ICSS v2.0 and below
         *     Reading IEP Counter Value
         */
        temp_addr = iepRegsBase + icssEmacIepCountOffset;
        temp_32 = (uint32_t*)(temp_addr);
        iepCounterVal = (uint64_t)(*temp_32);

        /*    cycleStartTime should not be greater than ICSS_EMAC_TTS_IEP_MAX_VAL    */
        if(cycleStartTime > (uint64_t)ICSS_EMAC_TTS_IEP_MAX_VAL)
        {
            cycleStartTime = cycleStartTime - ((uint64_t)ICSS_EMAC_TTS_IEP_MAX_VAL);
            if(0U == cycleStartTime)
            {
                cycleStartTime = (uint64_t)1U;
            }
        }

        /*    Checking if cycleStartTime provided has sufficient margin    */
        if(cycleStartTime < iepCounterVal)
        {
            if(((ICSS_EMAC_TTS_IEP_MAX_VAL - iepCounterVal) + cycleStartTime) < ICSS_EMAC_TTS_FIRST_CST_SAFETY_MARGIN)
            {
                ret = -((int8_t)1);
                return ret;
            }
        }
    }
    else
    {
        /*    64-bit IEP Timer for ICSS v2.1 and above
         *    Reading IEP Counter Value
         */
        temp_addr = iepRegsBase + icssEmacIepCountOffset;
        temp_64 = (uint64_t*)(temp_addr);
        iepCounterVal = (*temp_64);

        /*    Checking if cycleStartTime provided has sufficient margin    */
        if(cycleStartTime < iepCounterVal)
        {
            ret = -((int8_t)1);
            return ret;
        }
        else 
        {
            if((cycleStartTime - iepCounterVal) < ICSS_EMAC_TTS_FIRST_CST_SAFETY_MARGIN) 
            {
                ret = -((int8_t)1);
                return ret;
            }
        }
    }

    /*    Storing cycle start value.    */
    temp_addr = pruDataMem + tTSOffsets.cycleStartOffset;
    temp_64 = (uint64_t*)(temp_addr);
    *temp_64 = cycleStartTime;

    /*    Storing period value.    */
    HW_WR_REG32((pruDataMem + tTSOffsets.cyclePeriodOffset), cyclePeriod);
    /*    Initializing config time.    */
    HW_WR_REG32((pruDataMem + tTSOffsets.cfgTimeOffset), configTime);

    /*    Update TTS status register    */
    temp_addr = pruDataMem + tTSOffsets.statusOffset;
    temp_8 = (uint8_t*)(temp_addr);
    if(ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE == enableCycInterrupt)
    {
        *temp_8 = ((*temp_8) | (uint8_t)ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE_MASK);    /*	Setting bit 4, ICSS_EMAC_TTS_CYC_INTERRUPT_ENABLE.	*/
    }

    if(ICSS_EMAC_TTS_CYC_TXSOF_DISABLE == cycTxSOFStatus)
    {
        *temp_8 = ((*temp_8) | (uint8_t)ICSS_EMAC_TTS_PRU_ENABLE_MASK);    /*	Setting bit 0, ICSS_EMAC_TTS_PRU_ENABLE.	*/
    }
    else
    {
        *temp_8 = ((*temp_8) | (uint8_t)ICSS_EMAC_TTS_PRU_ENABLE_MASK | (uint8_t)ICSS_EMAC_TTS_CYC_TX_SOF_MASK);    /*	Setting bit 0, ICSS_EMAC_TTS_PRU_ENABLE; bit 3, TTS_CYC_TX_SOF_ENABLE.	*/
    }

    return ret;
}

/**
 *  \name     ICSS_EmacTTSGetStatus
 *  @brief
 *          API to query time triggered send details from PRU firmware.
 *
 *  @param[in]  ttsQuery         EMAC TTS Query structure (ICSS_EmacTTSQuery *).
 *  @retval     int8_t            0 on success, -1 on failure.
 */
int8_t ICSS_EmacTTSGetStatus(ICSS_EmacTTSQuery* ttsQuery)
{
    ICSSEMAC_Handle icssEmacHandle = NULL;
    uint32_t pruDataMem = 0;
    uint8_t portNumber = 0;
    uint32_t statusTTS = 0;
    uint64_t* temp_64 = 0;
    uint32_t* temp_32 = 0;
    int8_t ret = 0;
    uint32_t temp_addr = 0;
    ICSS_EmacTTSOffsets tTSOffsets;
    /*    Initialise TTS variables.    */
    icssEmacHandle = ttsQuery->icssEmacHandle;
    portNumber = ttsQuery->portNumber;

    /*    Checking parameters.    */
    if((ICSS_EMAC_PORT_1 != portNumber) && (ICSS_EMAC_PORT_2 != portNumber))
    {
        /*    Invalid portNumber.    */
        ret = -((int8_t)1);
    }
        else
        {
            if(ICSS_EMAC_PORT_1 == portNumber) 
            {
                pruDataMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
            }
            else    /*    ICSS_EMAC_PORT_2    */
            {
                pruDataMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
            }
             ICSS_EmacCalcTTSOffsets(icssEmacHandle, &tTSOffsets);
            temp_addr = pruDataMem + tTSOffsets.statusOffset;
            temp_32 = (uint32_t*)(temp_addr);
            statusTTS = (*temp_32);

            ttsQuery->statusTTS = (statusTTS & ICSS_EMAC_TTS_PRU_ENABLE_MASK);
            ttsQuery->missedCycle = ((statusTTS & ICSS_EMAC_TTS_MISSED_CYCLE_MASK) >> 1);

            temp_addr = pruDataMem + tTSOffsets.missedCycleCntOffset;
            temp_32 = (uint32_t*)(temp_addr);
            ttsQuery->missedCycleCounter = (*temp_32);
            ttsQuery->insertCycFrameNotification = ((statusTTS & ICSS_EMAC_TTS_INSERT_CYC_FRAME_MASK)>>2);
            ttsQuery->cycTxSOFStatus = ((statusTTS & ICSS_EMAC_TTS_CYC_TX_SOF_MASK)>>3);

            temp_addr = pruDataMem + tTSOffsets.cycTxSof;
            temp_64 = (uint64_t*)(temp_addr);
            ttsQuery->cycTxSOF = (*temp_64);
        }
    return ret;
}

/* Local Functions */
/**
 *  @brief  API to copy a packet from DDR to Tx Queue memory on L3 and synchronize with
 *  firmware
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  srcAddress    Base address of the buffer where the frame to be transmitted resides
 *  @param[in]  portNumber   Port on which frame has to be transmitted.
 *                            Valid values are:
                              1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority    Queue number in which frame will be
 *                               queued for transmission
 *  @param[in] lengthOfPacket   length of the frame in bytes
 *  @retval     0 on scuess,  <0 on failure
 */
int32_t ICSS_EmacTxPacketEnqueue (ICSS_EmacHandle icssEmacHandle,
                                  const uint8_t* srcAddress,
                                  uint8_t portNumber,
                                  uint8_t queuePriority,
                                  uint16_t lengthOfPacket)
{
    uint32_t buffer_offset_computed =0;
    uint32_t buffer_des = 0;
    uint16_t queue_wr_ptr =0;
    uint16_t wrk_queue_wr_ptr =0;
    uint16_t size = 0;
    uint16_t queue_rd_ptr =0;
    uint16_t num_of_bytes =0;
    uint16_t new_packet_length =0;
    uint32_t temp =0;
    uint16_t i =0;
    uint32_t collision_queue_selected =0;
    uint16_t collision_status =0;
    uint16_t col_queue_already_occupied =0;
    uint16_t original_length_of_packet =0;
    uint16_t packet_min_size_padding = 0;
    uint16_t remaining_valid_frame_data_length =0;
    uint8_t *macAddr;
    uint32_t pruSharedMem = 0;
    ICSS_EmacQueueParams *txQueue;
    ICSS_EmacHostStatistics_t* hostStatPtr;
    uint8_t linkStatus=0;

    uint8_t emacMode=0;
    uint16_t temp_var =0;
    uint32_t temp_addr = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    if((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_SWITCH)
    {
        emacMode =0;
    }
    else
    {
        emacMode =1U;
    }

    if(emacMode) { /*MAC Mode*/

        if(ICSS_EMAC_PORT_1 == portNumber) {
            pruSharedMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
        }
        if(ICSS_EMAC_PORT_2 == portNumber) {
            pruSharedMem = (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
        }
        linkStatus = ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[0];
        hostStatPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);
    }
    else
    {
        linkStatus = ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[portNumber-1U];
        hostStatPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);
        hostStatPtr += (portNumber - 1U);/*Switch mode. Points to correct structure depending on port*/
    }

    if((portNumber != ICSS_EMAC_PORT_1) && (portNumber != ICSS_EMAC_PORT_2))
    {
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_SWITCH_INVALID_PORT);
    }
    if(queuePriority > ((uint8_t)(pDynamicMMap->numQueues) - (uint8_t)1U))
    {
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_ERR_SWITCH_INVALID_PARAM);
    }
    if(lengthOfPacket > ICSS_EMAC_MAXMTU)
    {    
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_ERR_BADPACKET);
    }
    if(lengthOfPacket < ICSS_EMAC_MINMTU)
    {    
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_ERR_BADPACKET);
    }

    if(lengthOfPacket < ETHERNET_FRAME_SIZE_60)
    {
        original_length_of_packet = (uint16_t)lengthOfPacket;
        packet_min_size_padding =1U;
        lengthOfPacket = ETHERNET_FRAME_SIZE_60;
    }
    else
    {
        packet_min_size_padding = 0;
    }

    macAddr = (uint8_t*)srcAddress;

    if(linkStatus == 0U)
    {
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_ERR_TX_NO_LINK);
    }

    ICSS_EmacPortParams *sPort;
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[portNumber]);
    if(emacMode == 0U) { /*Switch Mode*/

         txQueue = &(sPort->queue[queuePriority]);
        /* Check whether Queue is busy.If yes then put the packet in the collision Queue. Set the busy_s bit because Host is always a Slave. */
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
        temp =  HWREG(temp_addr);
        collision_queue_selected =  (temp & 0x00000100U);  /* Check the "busy_m" bit */
        if(collision_queue_selected != 0U)
        {
           num_of_collision_occured = num_of_collision_occured +1;
           /* Queue is busy  .. put the packet in the collision Queue */
           txQueue = &(sPort->queue[ICSS_EMAC_COLQUEUE]);
            if(portNumber == ICSS_EMAC_PORT_1)
            {
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->colStatusAddr+ 1U);
                col_queue_already_occupied = HWREGB(temp_addr);
            }
            else
            {
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +  pStaticMMap->colStatusAddr + 2U);
                col_queue_already_occupied = HWREGB(temp_addr);
            }
            if(col_queue_already_occupied != 0)
            {
              hostStatPtr->txDroppedPackets++;
              collision_pkt_dropped ++;
              return ((int32_t)ICSS_EMAC_ERR_COLLISION_FAIL);   /*No space in collision queue */
            }
        }
        else
        {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
            /* Queue is Not Busy .. Acquire the Queue by setting "busy_s" bit */
            HWREGB(temp_addr) = 1U; /* Set the "busy_s" bit */
            /*Again check if host acquired the queue successfully by checking the busy_m bit */
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
            temp =  HWREG(temp_addr);
            collision_queue_selected =  (temp & 0x00000100U);  /* Check the "busy_m" bit */
            if(collision_queue_selected != 0U)
            {
                num_of_collision_occured = num_of_collision_occured +1;
                temp_addr = ( (((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr+ txQueue->queue_desc_offset + 4U);
                HWREGB(temp_addr) = 0; /* Clear the busy_s bit */
                /* Queue is busy  .. put the packet in the collision Queue */
                txQueue = &(sPort->queue[ICSS_EMAC_COLQUEUE]);
            }
        }
    } else { /*MAC Mode*/
        txQueue = &(sPort->queue[queuePriority]);
        /* Queue is Not Busy .. Acquire the Queue by setting "busy_s" bit */
        temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
        HWREGB(temp_addr) = 1U; /* Set the "busy_s" bit */

    }
    /*  Compute the buffer descriptor ..length is from bit 18 to 28 */
    buffer_des = (((uint32_t)(lengthOfPacket)) << 18U);

    if(emacMode == 0U) { /*Switch Mode*/
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset);
        /*  Read the write pointer from Queue descriptor */
        temp =  HWREG(temp_addr);
    } else {
        temp_addr = (pruSharedMem + txQueue->queue_desc_offset);
        temp =  HWREG(temp_addr);
    }

    queue_wr_ptr = ((uint16_t)(temp >> 16));
    queue_rd_ptr = ((uint16_t)(temp & 0x0000ffffU));

    wrk_queue_wr_ptr = (((uint16_t)(lengthOfPacket)) >> 5U);  /* Divide by 32 */
    wrk_queue_wr_ptr = (uint16_t)((wrk_queue_wr_ptr) << 2);  /* Multiply by 4 ..as one descriptor represents 32 bytes and BD takes 4 bytes */
    if((((uint32_t)(lengthOfPacket)) & 0x0000001fU) != 0U)
    {
         wrk_queue_wr_ptr = wrk_queue_wr_ptr + 4U;
    }

    /* Add to get the value of new queue write pointer */
    wrk_queue_wr_ptr = wrk_queue_wr_ptr + queue_wr_ptr;
    size = txQueue->queue_size;
    /*Check if queue is full and there is an wrap around */
    if(((queue_wr_ptr + 4U) % size) == 0U)
    {
        if(queue_rd_ptr == txQueue->buffer_desc_offset) /* Since queue is not starting from 0. */
        {
            txQueue->qStat.errCount++;
            if(emacMode == 0U) { /*Switch Mode*/
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
                HWREGB(temp_addr) = 0;
            } else {
                temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
                HWREGB(temp_addr) = 0U;
            }
            hostStatPtr->txDroppedPackets++;
            return ((int32_t)ICSS_EMAC_ERR_TX_OUT_OF_BD);   /* No space in queue */
        }
    }
    /* Check if the Queue is already full */
    if((queue_wr_ptr + 4U) == queue_rd_ptr)
    {
        txQueue->qStat.errCount++;
        if(emacMode == 0U) { /*Switch Mode*/
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr+ txQueue->queue_desc_offset + 4U);
            HWREGB(temp_addr) = 0;
        } else {
            temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
            HWREGB(temp_addr) = 0U;
        }
        hostStatPtr->txDroppedPackets++;
        return ((int32_t)ICSS_EMAC_ERR_TX_OUT_OF_BD);       /* No space in queue */
    }
    /* Three cases arise between wr_ptr and rd_ptr */
    if(queue_wr_ptr == queue_rd_ptr)
    {
        /*Check for wrap around */
        if(wrk_queue_wr_ptr >=  size)
        {
            wrk_queue_wr_ptr = (wrk_queue_wr_ptr % size);
            /*Add offset as queue doesn't start from 0. */
            wrk_queue_wr_ptr = wrk_queue_wr_ptr + txQueue->buffer_desc_offset;
        }
    }
    else if(queue_wr_ptr > queue_rd_ptr)
    {
        /*Check for wrap around */
        if(wrk_queue_wr_ptr >=  size)
        {
            wrk_queue_wr_ptr = (wrk_queue_wr_ptr % size);
            wrk_queue_wr_ptr = wrk_queue_wr_ptr + txQueue->buffer_desc_offset;
            if(wrk_queue_wr_ptr >= queue_rd_ptr)
            {
                txQueue->qStat.errCount++;
                if(emacMode == 0U) { /*Switch Mode*/
                    temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
                    HWREGB(temp_addr) = 0;
                } else {
                    temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
                    HWREGB(temp_addr) = 0U;
                }
                hostStatPtr->txDroppedPackets++;
                return ((int32_t)ICSS_EMAC_ERR_TX_OUT_OF_BD);      /* No space in queue */
            }
        }
    }
    else
    {
        if(wrk_queue_wr_ptr >= queue_rd_ptr)
        {
            txQueue->qStat.errCount++;
            if(emacMode == 0U) { /*Switch Mode*/
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
                HWREGB(temp_addr) = 0;
            } else {
                temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
                HWREGB(temp_addr) = 0U;
            }
            hostStatPtr->txDroppedPackets++;
            return ((int32_t)ICSS_EMAC_ERR_TX_OUT_OF_BD);                          /* No space in queue */
        }
    }
    /* Compute the offset of buffer descriptor in ICSS shared RAM */
    temp_var = (txQueue->buffer_offset) + ((queue_wr_ptr - txQueue->buffer_desc_offset)*((uint16_t)8U));
    buffer_offset_computed = (uint32_t)temp_var;    /* queue_wr_ptr points to currently available free buffer */
    /*  Add the offset of Tx Queues */
    buffer_offset_computed = buffer_offset_computed + pDynamicMMap->transmitQueuesBufferOffset;

    /* Check if queue wrap around has happened. If yes then data can't be stored sequentially. */
    if( (wrk_queue_wr_ptr < queue_wr_ptr) &&  (wrk_queue_wr_ptr != txQueue->buffer_desc_offset))
    {
        num_of_bytes = (size - queue_wr_ptr);
        num_of_bytes *= 8U;                    /* divide by 4 * 32! */
        /* check if Padding has to be done. If yes then Pad with Zero's to reach the minimum size for the ethernet frame. */
        if(packet_min_size_padding == 1U)
        {
            if( num_of_bytes <= original_length_of_packet)
            {
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
                memcpy_local((int32_t*)(temp_addr), (int32_t*) srcAddress, (size_t)num_of_bytes);
            }
            else
            {
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
                /* Copy the valid packet data first and then Pad with zero's.  */
                memcpy_local((int32_t*)(temp_addr), (int32_t*) srcAddress, (size_t)original_length_of_packet);
                /* Padd the remaining bytes with Zero's */
                for(i=0; i< (num_of_bytes - original_length_of_packet); i++)
                {
                    temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr+ ((uint32_t)buffer_offset_computed) + original_length_of_packet + i);
                    HWREGB(temp_addr) = 0;
                }
            }
        }
        else
        {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
            memcpy_local((int32_t*)(temp_addr), (int32_t*) srcAddress, (size_t)num_of_bytes);
        }
        new_packet_length = ((uint16_t)lengthOfPacket) - num_of_bytes;
        srcAddress = srcAddress + num_of_bytes;

        if(emacMode == 0U) { /*Switch Mode*/
            if(collision_queue_selected != 0) {
                buffer_offset_computed = buffer_offset_computed + num_of_bytes;
            } else {
                buffer_offset_computed = txQueue->buffer_offset;
                /*  Add the offset of Tx Queues */
                buffer_offset_computed = buffer_offset_computed + pDynamicMMap->transmitQueuesBufferOffset;
            }
        } else { /*MAC Mode*/
            buffer_offset_computed = txQueue->buffer_offset;
        }

        if( packet_min_size_padding == 1u)
        {
            if(original_length_of_packet <= num_of_bytes)
            {
                /* Pad all the remaining bytes with Zero's */
                for(i=0; i< new_packet_length; i++)
                {
                    temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed) + i);
                    HWREGB(temp_addr) = 0;
                }
            }
            else
            {
                /* Fill the frame data  */
                remaining_valid_frame_data_length = (original_length_of_packet- num_of_bytes);
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
                memcpy_local((int32_t*)(temp_addr),(int32_t*) srcAddress, (size_t)remaining_valid_frame_data_length);
                /*Pad the remaining bytes with Zero's */
                for(i=0; i< (new_packet_length - remaining_valid_frame_data_length); i++)
                {
                    temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed) + remaining_valid_frame_data_length+ i);
                    HWREGB(temp_addr) = 0;
                }
            }
        }    
        else
        {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
            memcpy_local((int32_t*)(temp_addr),(int32_t*) srcAddress, (size_t)new_packet_length);
        }
    }
    else
    {
        if( packet_min_size_padding  == 1u)
        {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
            memcpy_local((int32_t*)(temp_addr), (int32_t*)srcAddress, (size_t)original_length_of_packet);
            /* Padd the remaining bytes with Zero's */
            for(i=0; i< (((uint16_t)lengthOfPacket) - original_length_of_packet); i++)
            {
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed) + original_length_of_packet + i);
                HWREGB(temp_addr) = 0;
            }
        }
        else
        {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + ((uint32_t)buffer_offset_computed));
            memcpy_local((int32_t*)(temp_addr), (int32_t*)srcAddress, (size_t)lengthOfPacket);
        }
    }
    if(emacMode == 0U) { /*Switch Mode*/
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + ((uint32_t)queue_wr_ptr) );
        HWREG(temp_addr) = buffer_des;
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset +2U);
        /* Write new wr_ptr in the queue descriptor */
        HWREGH(temp_addr) = wrk_queue_wr_ptr;
    } else {
        temp_addr = (pruSharedMem + queue_wr_ptr );
        HWREG(temp_addr) = buffer_des;
        temp_addr = (pruSharedMem + txQueue->queue_desc_offset +2U);
        HWREGH(temp_addr) = wrk_queue_wr_ptr;
    }

    txQueue->qStat.rawCount++;

    if(emacMode == 0U) { /*Switch Mode*/
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + txQueue->queue_desc_offset + 4U);
        /* Release the Queue. Clear the "busy_s" bit .. even if collision queue was selected then below line won't have any impact. */
        HWREGB(temp_addr) = 0;
    } else {
        temp_addr = (pruSharedMem + txQueue->queue_desc_offset + 4U);
        HWREGB(temp_addr) = 0U;
    }

    if(emacMode == 0U) { /*Switch Mode*/
        /* If packet was put in collision queue then indiciate it to collision task */
        if(collision_queue_selected != 0)
        {
            if(portNumber ==ICSS_EMAC_PORT_1)
            {
                collision_status = ((uint16_t)queuePriority);
                collision_status = (uint16_t)((collision_status) << 1);
                collision_status = (collision_status | 0x0001U);
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +  pStaticMMap->colStatusAddr +1U);
                HWREGB(temp_addr) = (uint8_t)collision_status;
            }
            else
            {
                collision_status = ((uint16_t)queuePriority);
                collision_status = (uint16_t)((collision_status) << 1);
                collision_status = (collision_status | 0x0001U);
                temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +  pStaticMMap->colStatusAddr + 2U);
                HWREGB(temp_addr) = (uint8_t)collision_status;
            }
        }
    }

    ICSS_EmacUpdateTxStats(macAddr,(uint32_t)lengthOfPacket, hostStatPtr);
    return 0;
}

/**
 *  @b Description
 *  @n
 *       API to retrieve the information about the received frame which
 *       is then used to dequeue the frame from the host queues
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[out]  portNumber    Return pointer of port number where frame was received
 *  @param[out]  queueNumber   Return pointer of host queue where the received frame is queued

 *  @retval     Length of packet or 0 if no packet found
 */
int32_t ICSS_EmacRxPktInfo(ICSS_EmacHandle icssEmacHandle,
                           int32_t* portNumber,
                           int32_t* queueNumber)
{
    int32_t retVal;
    ICSS_EmacPktInfo rxPktInfo;

    retVal = ICSS_EmacRxPktInfo2(icssEmacHandle, &rxPktInfo);

    (*queueNumber) = rxPktInfo.queueNumber;
    (*portNumber) = rxPktInfo.portNumber;
    return retVal;
}


/**
 *  @b Description
 *  @n
 *       AP to retrieve the information about the received frame which
 *       is then used to dequeue the frame from the host queues.
 *       This version fo the API also allows for pointer to the 
 *       address of read buffer in L3 address space to be returned.
 *       This is an enhancement to the ICSS_EmacRxPktInfo API.
 * 
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[out]  pRxPktInfo    Return pointer of receive packet info which includes  
                        port number where frame was received,  host queue where the received frame is queued
                        and address of read buffer in L3 address space.

 *  @retval     Length of packet or 0 if no packet found
 */
int32_t ICSS_EmacRxPktInfo2(ICSS_EmacHandle icssEmacHandle,
                                                   ICSS_EmacPktInfo *pRxPktInfo)

{
    uint16_t queue_rd_ptr;
    uint16_t queue_wr_ptr;
    uint32_t rd_buf_desc=0;
    uint16_t rd_packet_length;
    int32_t packet_found =0;
    ICSS_EmacQueue *qDesc;

    uint8_t emacMode=0;
    uint32_t temp_addr = 0U;
    uint32_t temp_var1 = 0U;

    uint16_t shadow=0;
    uint32_t rd_buffer_l3_addr;
    uint16_t rd_buf_desc_num;
    ICSS_EmacQueueParams *rxQueue;
    ICSS_EmacPortParams *sPort;

    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);


    uint8_t initPrioQueue = (uint8_t)ICSS_EMAC_QUEUE1;
    uint8_t finalPrioQueue = (uint8_t)(pDynamicMMap->numQueues-1U);
    uint8_t i= (uint8_t)ICSS_EMAC_QUEUE1;

    switch((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask)
    {
        case ICSS_EMAC_MODE_SWITCH:
            emacMode =0;
            initPrioQueue = (uint8_t)ICSS_EMAC_QUEUE1;
            finalPrioQueue = (uint8_t)(pDynamicMMap->numQueues-1U);
            break;
        case ICSS_EMAC_MODE_MAC1:
            emacMode =1u;
            initPrioQueue = (uint8_t)ICSS_EMAC_QUEUE1;
            finalPrioQueue= (uint8_t)ICSS_EMAC_QUEUE2;
            break;
        case ICSS_EMAC_MODE_MAC2:
            emacMode =1u;
            initPrioQueue = (uint8_t)ICSS_EMAC_QUEUE3;
            finalPrioQueue= (uint8_t)ICSS_EMAC_QUEUE4;
            break;
        default:
            break;
    }

    i=initPrioQueue;

    while((packet_found == 0) && (i <= finalPrioQueue))
    {
        if(emacMode == 0U) { /*Switch Mode*/
            temp_var1 = ((uint32_t)(i))*8U;
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0QueueDescOffset + temp_var1);
            qDesc = (ICSS_EmacQueue *)(temp_addr);
        } else {
            temp_var1 = ((uint32_t)(i))*8U;
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + pDynamicMMap->hostQ1RxContextOffset + 64U+ temp_var1);
            qDesc = (ICSS_EmacQueue *)(temp_addr);
        }
        queue_wr_ptr = qDesc->wr_ptr;
        queue_rd_ptr = qDesc->rd_ptr;
        if(qDesc->overflow_cnt > 0)
        {
            sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_0]);
            sPort->queue[i].qStat.errCount += qDesc->overflow_cnt;  /* increment missed packets to error counter */
            qDesc->overflow_cnt = 0;    /* reset to zero as limited to 256 anyway */
        }
        if(queue_rd_ptr != queue_wr_ptr)
        {
            pRxPktInfo->queueNumber = (int32_t)i;
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + ((uint32_t)queue_rd_ptr));
            rd_buf_desc = HWREG(temp_addr);
            sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_0]);
             rxQueue = &(sPort->queue[i]);
            /* Take out the port number */
            temp_addr = ((0x00030000U & rd_buf_desc) >> 16U);
            pRxPktInfo->portNumber = (int32_t)(temp_addr);

	    if(ICSS_EMAC_FW_LEARNING_EN ==
	       (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->learningEn) {
	      /* Check firmware FDB lookup success */
	      temp_addr = ((0x00000040U & rd_buf_desc) >> 6U);
	      pRxPktInfo->fdbLookupSuccess = (uint32_t)(temp_addr);
	      /* Check firmware flood status */
	      temp_addr = ((0x00000080U & rd_buf_desc) >> 7U);
	      pRxPktInfo->flooded = (uint32_t)(temp_addr);
	    }

            /* Get the length */
            rd_packet_length = ((uint16_t)((0x1ffc0000U & rd_buf_desc) >> 18U));
            packet_found = 1;
            /*
             * Determine the address of the first buffer descriptor
             * from the rd_ptr.  First, check if the packet was
             * received in the collision queue or not.
             */
            shadow = (uint16_t)(((rd_buf_desc & 0x00004000U) >> 14));
            if(shadow != 0)
            {
                /* The data is in the collision buffer's */
                rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr+  pDynamicMMap->p0ColBufferOffset);
            }
            else
            {
                rd_buf_desc_num = (queue_rd_ptr -
                                     rxQueue->buffer_desc_offset) >> 2;
                rd_buffer_l3_addr = (uint32_t)(((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr
                                    + (rd_buf_desc_num * 32U)
                                    + rxQueue->buffer_offset));
            }
            pRxPktInfo->rdBufferL3Addr = rd_buffer_l3_addr;
            
        }
        i++;
    }
    /* Received IRQ but can't find the packet in any queue */
    if(packet_found == 0)
    {
        rd_packet_length = 0;
    }
    return (int32_t)rd_packet_length;
}

/**
 *  @b Description
 *  @n
 *      Retrieves a frame from a host queue and copies it
 *           in the allocated stack buffer
 *
 *  @param[in]  rxArg defined at @ref ICSS_EmacRxArgument
 *  @param[in]  userArg custom Rx packet callback packet options only required for custom RxPacket implementations,
                default to NULL when calling ICSS_EmacRxPktGet which is default Tx Packet API
 *  @retval     Length of the frame received in number of bytes or -1 on Failure
 */
int32_t ICSS_EmacRxPktGet(ICSS_EmacRxArgument *rxArg, void* userArg)

{
    uint16_t queue_rd_ptr;
    uint16_t queue_wr_ptr;
    uint16_t rd_buf_desc_num;
    uint32_t rd_buf_desc=0;
    uint16_t rd_packet_length;
    uint32_t rd_buffer_l3_addr;
    uint16_t size =0;
    uint16_t update_rd_ptr=0;
    uint16_t rx_num_of_bytes=0;
    uint16_t new_size =0;
    ICSS_EmacQueueParams *rxQueue;
    ICSS_EmacQueue *qDesc;
    uint16_t    shadow=0;

    uint8_t* srcMacId;
    uint8_t* destMacId;

    uint32_t fdbLookupSuccess;

    uint16_t *typeProt;
    uint16_t  typeProt1;
    uint16_t  typeProt2;

    uint8_t emacMode=0;

    uint32_t temp_addr = 0U;
    uint32_t temp_var1 = 0U;
    uint32_t temp_var2 = 0U;

    uint8_t ret_flag = 0U;
    int32_t ret_val = 0;

    ICSS_EmacHandle icssEmacHandle = rxArg->icssEmacHandle;
    uint32_t  destAddress = rxArg->destAddress;
    uint8_t queueNumber= rxArg->queueNumber;

    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
     ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
    uint32_t hostQDescOffset  = pDynamicMMap->hostQ1RxContextOffset + 64U;
    ICSS_EmacPortParams *sPort;
    if((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == ICSS_EMAC_MODE_SWITCH)
    {
        emacMode =0;
    }
    else
    {
        emacMode =1U;
    }

    HashTable_t *macTablePtr;
    ICSS_EmacHostStatistics_t* hostStatPtr;

    ICSS_EmacCallBackConfig* learningExcCallback;

#ifdef SWITCH_DEBUG
        genSeqOfEvents(RX_PACKET_GET);
#endif

    if(emacMode == 0U) { /*Switch Mode*/
        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr+ pStaticMMap->p0QueueDescOffset + (((uint32_t)(queueNumber))*8U));
        qDesc = (ICSS_EmacQueue *)(temp_addr);
    } else {
        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + hostQDescOffset + (((uint32_t)(queueNumber))*8U));
        qDesc = (ICSS_EmacQueue *)(temp_addr);
    }
    queue_wr_ptr = qDesc->wr_ptr;
    queue_rd_ptr = qDesc->rd_ptr;
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_0]);
    if(qDesc->overflow_cnt > 0)
    {
        sPort->queue[queueNumber].qStat.errCount += qDesc->overflow_cnt;        /* increment missed packets to error counter */
        qDesc->overflow_cnt = 0;
        /* reset to zero as limited to 256 anyway */
    }
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + ((uint32_t)queue_rd_ptr));
    rd_buf_desc = HWREG(temp_addr);
    rxQueue = &(sPort->queue[queueNumber]);

    if(emacMode == 0U) { /*Switch Mode*/
        /* Determine the address of the first buffer descriptor from the rd_ptr */
        /*Check if Packet was received in collision queue or not */
        shadow = ((uint16_t)((rd_buf_desc & 0x00004000U) >> 14U));
        if(shadow != 0)
        {
          /* Pick the data from collision buffer's */
            rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr+  pDynamicMMap->p0ColBufferOffset);
        } else  {
            rd_buf_desc_num = (queue_rd_ptr - rxQueue->buffer_desc_offset) >> 2;
            temp_var1 = (((uint32_t)(rd_buf_desc_num)) * 32U);
            temp_var2 = (rxQueue->buffer_offset);
            rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + temp_var1 + temp_var2);
        }
    } else {
        rd_buf_desc_num = (queue_rd_ptr - rxQueue->buffer_desc_offset) >> 2;
        temp_var1 = ((uint32_t)(rd_buf_desc_num)) * 32U;
        temp_var2 = (rxQueue->buffer_offset);
        rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + temp_var1 + temp_var2);
    }
    /* Take out the port number - it may have changed */
    rxArg->port = (0x00030000U & rd_buf_desc)>>16;

    temp_addr = (rd_buffer_l3_addr + 6U);
    srcMacId = (uint8_t*)(temp_addr);

    destMacId = (uint8_t*)rd_buffer_l3_addr;


    rd_packet_length = ((uint16_t)((0x1ffc0000U & rd_buf_desc) >> 18));

    size = (rd_packet_length >>2);
    if( (rd_packet_length & 0x00000003U) != 0U )
    {
        size = size + 1u;
    }

    /*Compute number of buffer desc required & update rd_ptr in queue */
    update_rd_ptr = ((rd_packet_length >> 5U)*4U) + queue_rd_ptr;
    if( (rd_packet_length & 0x0000001fU) != 0U) /* checks multiple of 32 else need to increment by 4 */
    {
        update_rd_ptr += 4U;
    }
    /*Check for wrap around */
    if(update_rd_ptr >= rxQueue->queue_size)
    {
        update_rd_ptr = update_rd_ptr - (rxQueue->queue_size - rxQueue->buffer_desc_offset);
    }
    if(rd_packet_length <= ICSS_EMAC_MAXMTU)        /* make sure we do not have too big packets */
    {
        /* Switch Mode */
        if(ICSS_EMAC_LEARNING_EN ==
	   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->learningEn) {

            learningExcCallback = (((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->learningExCallBack;
            macTablePtr = (HashTable_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->macTablePtr);
            updateHashTable(srcMacId, rxArg->port, macTablePtr,learningExcCallback);

        }
        /* Switch FW Mode */
	else if(ICSS_EMAC_FW_LEARNING_EN
		== (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->learningEn) {
	    /* Read source lookup success result from fw */
	    temp_addr = ((0x00000040U & rd_buf_desc) >> 6U);
	    fdbLookupSuccess = (uint32_t)(temp_addr);

	    /* Insert SRC addr to FDB when the firmware FDB lookup was unsuccessful */
	    if(0 == fdbLookupSuccess) {
	      fdbInsert(((ICSS_EmacObject*)icssEmacHandle->object)->fdb, *(MAC*)srcMacId, rxArg->port, false);
	    }	    
	}

        /* Copy the data from switch buffers to DDR */
        if( (update_rd_ptr < queue_rd_ptr) && (update_rd_ptr != rxQueue->buffer_desc_offset))
        {
            typeProt = (uint16_t*)rd_buffer_l3_addr + 6;
            typeProt1 = ((uint16_t)((*typeProt) << 8U));
            typeProt2 = ((uint16_t)((*typeProt) >> 8U));
            typeProt1 = typeProt1 | typeProt2;
            rx_num_of_bytes = (rxQueue->queue_size - queue_rd_ptr);
            rx_num_of_bytes = (rx_num_of_bytes >> 2);
            rx_num_of_bytes = (uint16_t)((rx_num_of_bytes) << 5);

            memcpy_local((int32_t*)destAddress, (int32_t*)rd_buffer_l3_addr, (size_t)rx_num_of_bytes);
            destAddress = destAddress + rx_num_of_bytes;
            new_size = rd_packet_length - rx_num_of_bytes;

            if(emacMode == 0U) { /*Switch Mode*/
                if(shadow != 0) {
                      rd_buffer_l3_addr = rd_buffer_l3_addr + rx_num_of_bytes;
                  } else {
                      rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + rxQueue->buffer_offset);
                  }
              } else {
                  rd_buffer_l3_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->l3OcmcBaseAddr + rxQueue->buffer_offset);
              }
              memcpy_local((int32_t*)destAddress, (int32_t*)rd_buffer_l3_addr, (size_t)new_size);
        }
        else
        {
            memcpy_local((int32_t*)destAddress, (int32_t*)rd_buffer_l3_addr, (size_t)rd_packet_length);
            typeProt = (uint16_t*)destAddress + 6;
            typeProt1 = ((uint16_t)((*typeProt) << 8U));
            typeProt2 = ((uint16_t)((*typeProt) >> 8U));
            typeProt1 = typeProt1 | typeProt2;
        }
    }
    else  /* wrong packet size (exceeds ICSS_EMAC_MAXMTU)*/
    {
        rxQueue->qStat.errCount++;
        ret_flag = 1U;
        ret_val = -((int32_t)1);
    }

    if(ret_flag == 0U)
    {
        if(emacMode == 0U) { /*Switch Mode*/
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0QueueDescOffset + (((uint32_t)(queueNumber))*8U));
            /* Write back to queue */
            HWREGH(temp_addr) = update_rd_ptr;
             /* Check if Host needs to change the wr_ptr for collision queue as well */
            if(shadow != 0)
            {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0ColQueueDescOffset);
                ICSS_EmacQueue *qDescCol = (ICSS_EmacQueue *)(temp_addr);
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0ColQueueDescOffset +2U);
                /*Write back to collision queue desc */
                HWREGH(temp_addr) = qDescCol->rd_ptr;
                
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +  pStaticMMap->colStatusAddr);
                HWREGB(temp_addr) = 0;
                
                /*Indicate to firmware the Collision queue has been emptied*/
                temp_var1 = temp_addr + 3U;
                HWREGB(temp_var1) = 0;

            }
        } else {
            temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + hostQDescOffset + (((uint32_t)(queueNumber))*8U));
            HWREGH(temp_addr) = update_rd_ptr;
        }
        rxQueue->qStat.rawCount++;

        rxArg->more = 0;
        if(emacMode == 0U) { /*Switch Mode*/
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->p0QueueDescOffset + (((uint32_t)(queueNumber))*8U));
            /* get new pointer data in case new packets received in meantime - experimental.. */
            qDesc = (ICSS_EmacQueue *)(temp_addr);
        } else {
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + hostQDescOffset + (((uint32_t)(queueNumber))*8U));
            qDesc = (ICSS_EmacQueue *)(temp_addr);
        }
        queue_wr_ptr = qDesc->wr_ptr;

        if(update_rd_ptr != queue_wr_ptr)
        {
            rxArg->more = 1;
        }

        hostStatPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);
        if(emacMode == 0U) /*In Switch Mode both the statistics structures are in single handle.Depending on port update the corresponding structure*/
        {
            hostStatPtr += (rxArg->port - 1);
        }
        ICSS_EmacUpdateRxStats(destMacId,(uint32_t)rd_packet_length, typeProt1, hostStatPtr);

        ret_val = (int32_t)rd_packet_length;
    }
    return (ret_val);
}


/* Local function for processing transmit packet completion*/
static inline void ICSS_EmacPollTxComplete(ICSS_EmacHandle icssEmacHandle); /* misra-c */
static inline void ICSS_EmacPollTxComplete(ICSS_EmacHandle icssEmacHandle)
{
    volatile uint32_t intStatus;
    intStatus = HW_RD_REG32(((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR0));


    if (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC1))
    {
        if(TX_COMPLETION0_PRU_EVT_MASK & intStatus)
        {
            ICSS_EmacClearTxIrq(icssEmacHandle);
             ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTx(icssEmacHandle,NULL);
        }

        if(TTS_CYC0_PRU_EVT_MASK & intStatus)
        {
            ICSS_EmacClearTTSCycIrq(icssEmacHandle);
            ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTTSCyc(icssEmacHandle,NULL);
        }
    }
    if (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC2))
    {
        if(TX_COMPLETION1_PRU_EVT_MASK & intStatus)
        {
            ICSS_EmacClearTxIrq(icssEmacHandle);
            ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTx(icssEmacHandle,NULL);
        }
    
        if(TTS_CYC1_PRU_EVT_MASK & intStatus)
        {
             ICSS_EmacClearTTSCycIrq(icssEmacHandle);
             ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTTSCyc(icssEmacHandle,NULL);
        }
    }
}

/**
 *  @b Description
 *  @n
 *      API to poll driver for received packets, and/or link status, and/or 
         tranmission complete notification.
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  mode bitmap indicating poll type(s)  @ref ICSS_EmacIntrPollMode_e
 *  @retval     0 on scuess,  <0 on failure
 */
void ICSS_EmacPollControl(ICSS_EmacHandle icssEmacHandle, uint32_t mode)
{

    if (mode & ICSS_EMAC_POLL_MODE_RX_PKT)
    {
        ICSS_EmacPollPkt(icssEmacHandle);
    }
    if (mode & ICSS_EMAC_POLL_MODE_LINK)
    {
        ICSS_EmacPollLink(icssEmacHandle, ICSS_EMAC_POLL_FROM_POLL_LINK);
    }
    if (mode & ICSS_EMAC_POLL_MODE_TX_COMPLETE)
    {
        ICSS_EmacPollTxComplete(icssEmacHandle);
    }
}
/**
 *  @b Description
 *  @n
 *      Finds the maximum fill level of the queue in terms of 32 byte blocks.
        For example, if there was only one 64 byte packet received when this
        API is called then it would return value of 2.
        It also returns number of times queue has overflown.
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found
 *  @param[in]  queueType   Rx/Tx Queue
 *  @param[out]  queueOverflowCount    Number of times queue has overflown

 *  @retval     The maximum fill level of the queue in terms of 32 byte blocks or
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacGetMaxQueueFillLevel(ICSS_EmacHandle icssEmacHandle,
                                      int32_t portNumber, 
                                      int32_t queuePriority, 
                                      uint8_t queueType,
                                      int32_t* queueOverflowCount)
{
    int32_t queueMaxFillLevel =0;
    uint32_t temp_addr = 0U;
    ICSS_EmacPortParams *sPort;

    int32_t ret_val = 0;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    if((portNumber != (int32_t)ICSS_EMAC_PORT_0) && 
       (portNumber != (int32_t)ICSS_EMAC_PORT_1) &&
       (portNumber != (int32_t)ICSS_EMAC_PORT_2))
    {    
        ret_val = ((int32_t)ICSS_EMAC_SWITCH_INVALID_PORT);
    }
    else
    {
       sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[portNumber]);
        if((queuePriority < (int32_t)ICSS_EMAC_QUEUE1) || (queuePriority >  ((int32_t)pDynamicMMap->numQueues-(int32_t)1)))
        {
            ret_val = ((int32_t)ICSS_EMAC_ERR_SWITCH_INVALID_PARAM);
        }
        else
        {
            ICSS_EmacQueueParams *queue_local = &(sPort->queue[queuePriority]);

            /*Read the max fill level for the queue */
            if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask) { /*Switch Mode*/
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + queue_local->queue_desc_offset + ICSS_EMAC_Q_MAX_FILL_LEVEL_OFFSET);
                queueMaxFillLevel =  (int32_t)HWREGB(temp_addr);
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                *queueOverflowCount = (int32_t)HWREGB(temp_addr);
            } else {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr + queue_local->queue_desc_offset + ICSS_EMAC_Q_MAX_FILL_LEVEL_OFFSET);
                queueMaxFillLevel =  (int32_t)HWREGB(temp_addr);
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr+ queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                *queueOverflowCount = (int32_t)HWREGB(temp_addr);
            }
            ret_val = queueMaxFillLevel;
        }
    }
    return ret_val;
}
/**
 *  @b Description
 *  @n returns the queueOverflowCount for a host/port queue
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found

 *  @retval     queueOverflowCount    Number of times queue has overflown
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacGetQueueOverflowCount(ICSS_EmacHandle icssEmacHandle,
                                      int32_t portNumber,
                                      int32_t queuePriority)
{
    uint32_t temp_addr = 0U;
    int32_t ret_val = 0, queueOverflowCount = 0;
    ICSS_EmacPortParams *sPort;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    if((portNumber != (int32_t)ICSS_EMAC_PORT_0) &&
       (portNumber != (int32_t)ICSS_EMAC_PORT_1) &&
       (portNumber != (int32_t)ICSS_EMAC_PORT_2))
    {
        ret_val = ((int32_t)ICSS_EMAC_SWITCH_INVALID_PORT);
    }
    else
    {
       sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[portNumber]);
       if((queuePriority < (int32_t)ICSS_EMAC_QUEUE1) || (queuePriority >  ((int32_t)pDynamicMMap->numQueues-(int32_t)1)))
        {
            ret_val = ((int32_t)ICSS_EMAC_ERR_SWITCH_INVALID_PARAM);
        }
        else
        {
            ICSS_EmacQueueParams *queue_local = &(sPort->queue[queuePriority]);

            /*Read the queueOverflowCount for the queue */
            if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask) { /*Switch Mode*/
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                queueOverflowCount = (int32_t)HWREGB(temp_addr);
            } else {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr+ queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                queueOverflowCount = (int32_t)HWREGB(temp_addr);
            }
            ret_val = queueOverflowCount;
        }
    }
    return ret_val;
}
/**
 *  @b Description
 *  @n clear the queueOverflowCount for a host/port queue
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance.
 *  @param[in]  portNumber    Port on which queue resides. Valid values are:
                              0 == PORT0, 1 == PORT1, 2 == PORT2
 *  @param[in]  queuePriority   Priority of the queue or queue number whose fill level has to be found

 *  @retval     ICSS_EMAC_SWITCH_SUCCESS    queueOverflowCount value cleared
 *              <0 if there was an error in the input parameters
 */
int32_t ICSS_EmacResetQueueOverflowCount(ICSS_EmacHandle icssEmacHandle,
                                      int32_t portNumber,
                                      int32_t queuePriority)
{
    uint32_t temp_addr = 0U;
    int32_t ret_val = 0;
    ICSS_EmacPortParams *sPort;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    if((portNumber != (int32_t)ICSS_EMAC_PORT_0) &&
       (portNumber != (int32_t)ICSS_EMAC_PORT_1) &&
       (portNumber != (int32_t)ICSS_EMAC_PORT_2))
    {
        ret_val = ((int32_t)ICSS_EMAC_SWITCH_INVALID_PORT);
    }
    else
    {
       sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[portNumber]);
        if(queuePriority > ((int32_t)(pDynamicMMap->numQueues) - (int32_t)1))
        {
            ret_val = ((int32_t)ICSS_EMAC_ERR_SWITCH_INVALID_PARAM);
        }
        else
        {
            ICSS_EmacQueueParams *queue_local = &(sPort->queue[queuePriority]);

            /*Reset the queueOverflowCount for the queue */
            if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask) { /*Switch Mode*/
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                HWREGB(temp_addr) = 0;
            } else {
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr+ queue_local->queue_desc_offset + ICSS_EMAC_Q_OVERFLOW_CNT_OFFSET);
                HWREGB(temp_addr) = 0;
            }
            ret_val = ((int32_t)ICSS_EMAC_SWITCH_SUCCESS);
        }
    }
    return ret_val;
}
/**
 *  \name ClearStatistics
 *  @brief  Function to clear queue statistics
 *
 *  @param none
 *  @retval none
 */
void ClearStatistics(ICSS_EmacHandle icssEmacHandle); /* for misra warning*/
void ClearStatistics(ICSS_EmacHandle icssEmacHandle)
{
    ICSS_EmacPortParams *sPort;

    uint32_t i, j;
    for (j=0U; j<3U; j++)
    {
        sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[j]);
        sPort->errCount = 0U;
        sPort->rawCount = 0U;
        for (i=0U; i<ICSS_EMAC_NUMQUEUES; i++)
        {
            sPort->queue[i].qStat.errCount = 0U;
            sPort->queue[i].qStat.rawCount = 0U;
        }
    }
}
void ICSS_EmacHostInit(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    ICSS_EmacPortParams *sPort;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
    uint32_t hostQDescOffset = pDynamicMMap->hostQ1RxContextOffset + 64U;
    
    ICSS_EmacCalcPort0BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);

    /* Initialize port 0*/
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_0]);
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
        sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
        sPort->queue[qCount].queue_desc_offset  = hostQDescOffset + (qCount * 8U);
        sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->rxHostQueueSize[qCount]) << 2) + (uint16_t)bdOffsets[qCount];        /* really the end of Queue */
    }

}

void ICSS_EmacMACInit(ICSS_EmacHandle icssEmacHandle, uint8_t portNum)
{
    uint32_t qCount = 0U;
    ICSS_EmacPortParams *sPort;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
    if(((uint8_t)(ICSS_EMAC_PORT_1)) == portNum) {
        /* Initialize port 1*/
        sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_1]);
        ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
        {
            sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount]; 
            sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
            sPort->queue[qCount].queue_desc_offset  = pDynamicMMap->portQueueDescOffset + (qCount * 8U);
            sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) + (uint16_t)bdOffsets[qCount];
        }
    }

    if(((uint8_t)(ICSS_EMAC_PORT_2)) == portNum) {
        /* Initialize port 2*/
        sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_2]);
        ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
        {
            sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
            sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
            sPort->queue[qCount].queue_desc_offset  = pDynamicMMap->portQueueDescOffset + (qCount * 8U);
            sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) + (uint16_t)bdOffsets[qCount];
        }
    }
}



int32_t ICSS_EmacPortInit(ICSS_EmacHandle icssEmacHandle); /* for misra warning*/
int32_t ICSS_EmacPortInit(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    ICSS_EmacPortParams *sPort;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    /* Clear counters */
    ClearStatistics(icssEmacHandle);
    /* Initialize port 0*/
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_0]);
    ICSS_EmacCalcPort0BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
        sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
        sPort->queue[qCount].queue_desc_offset  = pStaticMMap->p0QueueDescOffset + (qCount *8U);
        sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->rxHostQueueSize[qCount]) << 2U) + (uint16_t)bdOffsets[qCount];        /* really the end of Queue */
    }

    /* Initialize port 1*/
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_1]);
    ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
        sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
        sPort->queue[qCount].queue_desc_offset  = pStaticMMap->p0QueueDescOffset + (32U + qCount * 8U);
        sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) +  (uint16_t)bdOffsets[qCount];
    }
    
    /*Collision Queue */
    sPort->queue[ICSS_EMAC_COLQUEUE].buffer_offset           =  bufferOffsets[ICSS_EMAC_COLQUEUE];
    sPort->queue[ICSS_EMAC_COLQUEUE].buffer_desc_offset = bdOffsets[ICSS_EMAC_COLQUEUE];
    sPort->queue[ICSS_EMAC_COLQUEUE].queue_desc_offset  =  pStaticMMap->p0ColQueueDescOffset + 8U;
    sPort->queue[ICSS_EMAC_COLQUEUE].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->collisionQueueSize) << 2U) + (uint16_t)bdOffsets[ICSS_EMAC_COLQUEUE];

    /* Initialize port 2*/
    sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_2]);
    ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
    for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
        sPort->queue[qCount].buffer_desc_offset =  bdOffsets[qCount];
        sPort->queue[qCount].queue_desc_offset  = pStaticMMap->p0QueueDescOffset + (64U + qCount * 8U);
        sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) +  (uint16_t)bdOffsets[qCount];
    }

    /*Collision Queue */
    sPort->queue[ICSS_EMAC_COLQUEUE].buffer_offset           = bufferOffsets[ICSS_EMAC_COLQUEUE];
    sPort->queue[ICSS_EMAC_COLQUEUE].buffer_desc_offset =  bdOffsets[ICSS_EMAC_COLQUEUE];
    sPort->queue[ICSS_EMAC_COLQUEUE].queue_desc_offset  = pStaticMMap->p0ColQueueDescOffset + 16U;
    sPort->queue[ICSS_EMAC_COLQUEUE].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->collisionQueueSize) << 2U) +  (uint16_t)bdOffsets[ICSS_EMAC_COLQUEUE];

    return 0;
}


/**
*  @internal
*  @brief Function to re-initialize all Port Queue params
*
*  @param portNumber number of the port to flush
*  @retval None
*/
void macFlush(ICSS_EmacHandle icssEmacHandle, Int32 portNumber); /* for misra warning*/
void macFlush(ICSS_EmacHandle icssEmacHandle, Int32 portNumber)
{
    uint32_t qCount = 0U;
    ICSS_EmacPortParams *sPort;
    uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
    uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    switch(portNumber) {
        case (int32_t)ICSS_EMAC_PORT_1:
        sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_1]);
        /* Initialize port 1*/
        ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
        {
            sPort->queue[qCount].buffer_offset       = bufferOffsets[qCount];
            sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
            sPort->queue[qCount].queue_desc_offset  = pDynamicMMap->portQueueDescOffset + (qCount * 8U);
            sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) + (uint16_t)(bdOffsets[qCount]);
        }
        break;

    case (int32_t)ICSS_EMAC_PORT_2:
        /* Initialize port 2*/
        sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_2]);
        ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
        for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
        {
            sPort->queue[qCount].buffer_offset       =  bufferOffsets[qCount];
            sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
            sPort->queue[qCount].queue_desc_offset  = pDynamicMMap->portQueueDescOffset + (qCount * 8U);
            sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2U) + (uint16_t)(bdOffsets[qCount]);
        }
        break;

    default:
        break;
    }

}

/**
 *  @b Description
 *  @n
 *      API Function to re-initialize all Port Queue params
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  portNumber number of the port to flush
 *  @retval None
 */
void ICSS_EmacPortFlush(ICSS_EmacHandle icssEmacHandle, int32_t portNumber)
{
  uint32_t qCount = 0U;
  ICSS_EmacPortParams *sPort;
  uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES];
  uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES];
  ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
  ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

  switch ( portNumber )
  {
    case (int32_t)ICSS_EMAC_PORT_1:
      ICSS_EmacCalcPort1BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
      sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_1]);
      for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
      {
          sPort->queue[qCount].buffer_offset      = bufferOffsets[qCount];
          sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
          sPort->queue[qCount].queue_desc_offset  = pStaticMMap->p0QueueDescOffset + 32U + (qCount * 8U);
          sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2) + (uint16_t)bdOffsets[qCount];
      }

      sPort->queue[ICSS_EMAC_COLQUEUE].buffer_offset      = bufferOffsets[ICSS_EMAC_COLQUEUE];
      sPort->queue[ICSS_EMAC_COLQUEUE].buffer_desc_offset = bdOffsets[ICSS_EMAC_COLQUEUE];
      sPort->queue[ICSS_EMAC_COLQUEUE].queue_desc_offset  = pStaticMMap->p0ColQueueDescOffset + 8U;
      sPort->queue[ICSS_EMAC_COLQUEUE].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->collisionQueueSize) << 2) +  (uint16_t)bdOffsets[ICSS_EMAC_COLQUEUE];

      break;

    case (int32_t)ICSS_EMAC_PORT_2:
      sPort = &(((ICSS_EmacObject*)icssEmacHandle->object)->switchPort[ICSS_EMAC_PORT_2]);
      ICSS_EmacCalcPort2BufferOffset(icssEmacHandle, bufferOffsets,bdOffsets);
      for (qCount = 0U; qCount < pDynamicMMap->numQueues; qCount++)
      {
          sPort->queue[qCount].buffer_offset      = bufferOffsets[qCount];
          sPort->queue[qCount].buffer_desc_offset = bdOffsets[qCount];
          sPort->queue[qCount].queue_desc_offset  = pStaticMMap->p0QueueDescOffset + 64U + (qCount * 8U);
          sPort->queue[qCount].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->txQueueSize[qCount]) << 2) + (uint16_t)bdOffsets[qCount];
      }

      sPort->queue[ICSS_EMAC_COLQUEUE].buffer_offset      = bufferOffsets[ICSS_EMAC_COLQUEUE];
      sPort->queue[ICSS_EMAC_COLQUEUE].buffer_desc_offset = bdOffsets[ICSS_EMAC_COLQUEUE];
      sPort->queue[ICSS_EMAC_COLQUEUE].queue_desc_offset  = pStaticMMap->p0ColQueueDescOffset + 16U;
      sPort->queue[ICSS_EMAC_COLQUEUE].queue_size         = (uint16_t)(((uint16_t)pDynamicMMap->collisionQueueSize) << 2U) +  (uint16_t)bdOffsets[ICSS_EMAC_COLQUEUE];

      break;

    default:
      break;
  }
}
/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt receive packet callback function
 *
 *  @param[in]  hwIntRx    hardware interrupt receive packet callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntRx (ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntRx)
{
    ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntRx = hwIntRx;
}

/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt for Transmit packet complete by PRU-ICSS firmware
 *
 *  @param[in]  hwIntTx    hardware interrupt transmit packet complete callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntTx(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntTx)
{
    ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTx = hwIntTx;
}

/**
 *  @b Description
 *  @n
 *      API to register the hardware interrupt for TTS Cyclic Packet Insertion Notification by PRU-ICSS firmware
 *
 *  @param[in]  hwIntTTSCyc    hardware interrupt TTS cyclic packet insertion notification callback function
 *  @retval     none
 */
void ICSS_EmacRegisterHwIntTTSCyc(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack hwIntTTSCyc)
{
    /*    Check if TTS interrupt enable flag is set    */
    if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->ICSS_EmacTTSEnableCycPktInterrupt)
    {
        ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTTSCyc = hwIntTTSCyc;
    }
}

/* Local Function for OS specific initialization */
int8_t ICSS_EmacOSInit(ICSS_EmacHandle icssEmacHandle)
{
    int8_t ret_val = 0;

    uint8_t pacingEnabled;
    uint8_t pacingMode;
    SemaphoreP_Params semParams;

    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    semParams.name= "linkSemaphore";
    ((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle =  ICSS_EMAC_osalCreateBlockingLock(0,&semParams);
    if (((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle==NULL)
    {
        ret_val = -((int8_t)1);
    }

#ifndef __LINUX_USER_SPACE
    ICSS_EMAC_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    semParams.name= "rxSemaphore";

    ((ICSS_EmacObject*)icssEmacHandle->object)->rxSemaphoreHandle =  ICSS_EMAC_osalCreateBlockingLock(0,&semParams);


    if( ((((ICSS_EmacObject*)icssEmacHandle->object)->rxSemaphoreHandle) == NULL) || (((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle==NULL))
    {
        ret_val = -((int8_t)1);
    }
    else
    {
        ICSS_EMAC_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        semParams.name= "txSemaphore";
        ((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle =  ICSS_EMAC_osalCreateBlockingLock(0,&semParams);
        if(((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle==NULL)
        {
                ret_val = -((int8_t)1);
        }
        else
        {
#endif
            pacingEnabled = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->enableIntrPacing;
            pacingMode = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->ICSS_EmacIntrPacingMode;

            if((ICSS_EMAC_ENABLE_PACING == pacingEnabled) &&
               (ICSS_EMAC_INTR_PACING_MODE2 == pacingMode) &&
               (((ICSS_EmacObject*)icssEmacHandle->object)->rxPacingTimerHandle != NULL))
            {
                ICSS_EMAC_osalTimerStart(((ICSS_EmacObject*)icssEmacHandle->object)->rxPacingTimerHandle);
            }
#ifndef __LINUX_USER_SPACE
        }
    }
#endif

    if(-((int8_t)1) != ret_val)
    {
        /*    Check if TTS interrupt enable flag is set    */
        if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->ICSS_EmacTTSEnableCycPktInterrupt)
        {
            /*    Create TTS Cyclic Packet Notification Semaphore    */
            ICSS_EMAC_osalSemParamsInit(&semParams);
            semParams.mode = SemaphoreP_Mode_BINARY;
            semParams.name= "ttsCycSemaphore";
            ((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle =  ICSS_EMAC_osalCreateBlockingLock(0,&semParams);
            if(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle==NULL)
            {
                    ret_val = -((int8_t)1);
            }
        }
    }

    return ret_val;
}

/* Local Function for OS specific de-initialization */
int8_t ICSS_EmacOSDeInit(ICSS_EmacHandle icssEmacHandle)
{
    if (((ICSS_EmacObject*)icssEmacHandle->object)->rxSemaphoreHandle)
    {
        ICSS_EMAC_osalDeleteBlockingLock((SemaphoreP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->rxSemaphoreHandle));
    }

    if (((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle)
    {
        ICSS_EMAC_osalDeleteBlockingLock((SemaphoreP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->txSemaphoreHandle));
    }

    if (((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle)
    {
        ICSS_EMAC_osalDeleteBlockingLock((SemaphoreP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle));
    }

    if (((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle)
    {
        ICSS_EMAC_osalDeleteBlockingLock((SemaphoreP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->ttsCycSemaphoreHandle));
    }

    return 0;
}

void ICSS_EmacAddProtocolToList(uint16_t protocolType);   /* for misra warning*/
void ICSS_EmacAddProtocolToList(uint16_t protocolType)
{
    if(MAX_NUM_PROTOCOL_IMPLEMENTED > numImplementedProtocols) {
        protocol_impl[numImplementedProtocols] =  protocolType;
        numImplementedProtocols++;
    }
}

void ICSS_EmacUpdatePhyStatus(uint8_t portNum,ICSS_EmacHandle icssEmacHandle) 
{

    volatile uint8_t *portStatusPtr=NULL;
    volatile uint8_t portStatus = 0;
    uint8_t linkStatus=0;
    uint8_t prevlinkStatus=0;
    volatile uint32_t *phySpeedStatusPtr=NULL;
    uint8_t index=0;
    uint16_t phyStat=0;
    uint8_t duplexity=1U;
    uint16_t regStatusAdv=0;
    uint16_t regStatusPartner = 0;

    uint32_t temp_addr = 0U;
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask)
    {
        index= portNum-1U;
    }
    else
    {
        index= 0;
    }

    linkStatus = ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[index];
    prevlinkStatus =((ICSS_EmacObject*)icssEmacHandle->object)->prevlinkStatus[index];
    
    if(linkStatus ^ prevlinkStatus)
    {
        if(portNum == ((uint8_t)(ICSS_EMAC_PORT_1)))
        {
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->phySpeedOffset);
            phySpeedStatusPtr = (uint32_t*)(temp_addr);
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->portStatusOffset);
            portStatusPtr = (uint8_t*)(temp_addr);
        }

        if(portNum == ((uint8_t)(ICSS_EMAC_PORT_2)))
        {
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->phySpeedOffset);
            phySpeedStatusPtr = (uint32_t*)(temp_addr);
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr +  pStaticMMap->portStatusOffset);
            portStatusPtr = (uint8_t*)(temp_addr);
        }

        if(linkStatus)
        {
            CSL_MDIO_phyRegRead((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                               (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[index], PHY_AUTONEG_ADV, &regStatusAdv);

            CSL_MDIO_phyRegRead((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                               (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[index], PHY_LINK_PARTNER_ABLTY, &regStatusPartner);

            regStatusPartner &= regStatusAdv;

            if( regStatusPartner & PHY_REG_ADVERTISE_FD100 )
            {
                phyStat =  PHY_CONFIG_100FD;
            }
            else if( regStatusPartner & PHY_REG_ADVERTISE_HD100 )
            {
                phyStat = PHY_CONFIG_100HD;
            }
            else if( regStatusPartner & PHY_REG_ADVERTISE_FD10 )
            {
                phyStat = PHY_CONFIG_10FD;
            }
            else
            {
                phyStat =  PHY_CONFIG_10HD;
            }

            if(phySpeedStatusPtr != NULL)
            {
                switch(phyStat)
                {
                    case PHY_CONFIG_100FD:
                        *(phySpeedStatusPtr) = (uint32_t)Hundread_Mbps;
                        duplexity=1u;
                        break;
                    case PHY_CONFIG_100HD:
                        *(phySpeedStatusPtr) = (uint32_t)Hundread_Mbps;
                        duplexity=0;
                        break;
                    case PHY_CONFIG_10FD:
                        *(phySpeedStatusPtr) = (uint32_t)Ten_Mbps;
                        duplexity=1u;
                        break;
                    case PHY_CONFIG_10HD:
                        *(phySpeedStatusPtr) = (uint32_t)Ten_Mbps;
                        duplexity=0;
                        break;
                    default:
                        *(phySpeedStatusPtr) = (uint32_t)Hundread_Mbps;
                        duplexity=1u;    
                        break;
                }
            }
            if((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->halfDuplexEnable)
            {
                if(portStatusPtr != NULL)
                {
                    portStatus = *portStatusPtr;
                    /*set flags for HD*/
                    if(duplexity == 0U) {
                        portStatus |= (uint8_t)ICSS_EMAC_PORT_IS_HD_MASK;
                    }
                    else
                    {
                        portStatus &= ((uint8_t)~(ICSS_EMAC_PORT_IS_HD_MASK));
                    }

                    /*write back*/
                    *(portStatusPtr) = portStatus;
                }
            }
        }
        ((ICSS_EmacObject*)icssEmacHandle->object)->prevlinkStatus[index] = linkStatus;
    }
}

/**
* @brief Link change status interrupt for Port 0 and Port 1
*         calls a user callback if defined to provide link info to stack
*
* @param arg
*
* @retval none
*/
void ICSS_EmacLinkISR(void* arg) {

    ICSS_EmacHandle icssEmacHandle = (ICSS_EmacHandle)arg;
    ICSS_EmacPollLink(icssEmacHandle, ICSS_EMAC_POLL_FROM_ISR);
}

/**
* @brief Callback function to process protocol specific handler for link status ISR for Port 0
*
* @param callBack    Callback function pointer
* @param userArg    user specific parameter
*
* @retval none
*/
void ICSS_EmacRegisterPort0ISRCallback(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack callBack, void *userArg)
{
   ((ICSS_EmacObject*)icssEmacHandle->object)->port0ISRCall = callBack;
   ((ICSS_EmacObject*)icssEmacHandle->object)->port0ISRUser = userArg;
}

/**
* @brief Callback function to process protocol specific handler for link status ISR for Port 1
*
* @param callBack    Callback function pointer
* @param userArg    user specific parameter
*
* @retval none
*/
void ICSS_EmacRegisterPort1ISRCallback(ICSS_EmacHandle icssEmacHandle, ICSS_EmacCallBack callBack, void *userArg)
{
   ((ICSS_EmacObject*)icssEmacHandle->object)->port1ISRCall = callBack;
   ((ICSS_EmacObject*)icssEmacHandle->object)->port1ISRUser = userArg;
}



/**
* @brief Function to status of Phy Link
*
* @param mdioBaseAddr       mdio subsystem base address
* @param phyAddr            physical address
* @param retries            retry count
*
* @retval 1 if phy link up, 0 phy link down
*/
uint32_t ICSS_EmacPhyLinkStatusGet(uint32_t mdioBaseAddr,
                              uint32_t phyAddr,
                              volatile uint32_t retries)
{
    volatile uint16_t linkStatus;
    uint32_t ret_val = FALSE_VAL;
    retries++;
    while (retries)
    {
        /* First read the BSR of the PHY */
        CSL_MDIO_phyRegRead(mdioBaseAddr, phyAddr, PHY_BSR, (uint16_t*)&linkStatus);

        if(linkStatus & PHY_LINK_STATUS)
        {
            ret_val = TRUE_VAL;
            break;
        }

        retries--;
    }

    return ret_val;
}

/**
 *  \name ICSS_EMacOsTxTaskFnc
 *  @brief
 *      Function which pends on Tx semaphore.Invokes registered Tx Callback function
 *
 *  @param a0 arg 1
 *  @param a1 arg 2
 *
 *  @retval none
 *
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsTxTaskFnc(void *a0)
#else
void ICSS_EMacOsTxTaskFnc(uint32_t a0, uint32_t a1)
#endif
{
    ICSS_EmacHandle icssEmacHandle;
    icssEmacHandle = (ICSS_EmacHandle)a0;

    while(1)
    {
        ICSS_EMAC_Pend((void *)icssEmacHandle, ICSS_EMAC_INTR_SRC_TX);
        ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTx(icssEmacHandle,NULL);
     }
}
/**
 *  \name ICSS_EMacOsTTSCycTaskFnc
 *  @brief
 *      Function which pends on TTS Cyclic Packet Notification semaphore. Invokes registered TTS Cyclic Callback function
 *
 *  @param a0 arg 1
 *  @param a1 arg 2
 *
 *  @retval none
 *
 */
#ifdef __LINUX_USER_SPACE
void *ICSS_EMacOsTTSCycTaskFnc(void *a0)
#else
void ICSS_EMacOsTTSCycTaskFnc(uint32_t a0, uint32_t a1)
#endif
{
    ICSS_EmacHandle icssEmacHandle;
    icssEmacHandle = (ICSS_EmacHandle)a0;

       /*    Exit task if TTS interrupt enable flag is clear    */
    if(((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->ICSS_EmacTTSEnableCycPktInterrupt)
    {
        while(1)
        {
            ICSS_EMAC_Pend((void *)icssEmacHandle, ICSS_EMAC_INTR_SRC_TTS);
            ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntTTSCyc(icssEmacHandle,NULL);
        }
    }
}

/* Local function to calculate TTS offsets*/
static inline void ICSS_EmacCalcTTSOffsets(ICSS_EmacHandle icssEmacHandle, ICSS_EmacTTSOffsets *pTTSOffset)
{
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    pTTSOffset->cycleStartOffset = pStaticMMap->emacTtsConfigBaseOffset;
    pTTSOffset->cyclePeriodOffset = pTTSOffset->cycleStartOffset + 8U;
    pTTSOffset->cfgTimeOffset = pTTSOffset->cyclePeriodOffset + 4U;
    pTTSOffset->statusOffset =  pTTSOffset->cfgTimeOffset + 4U;
    pTTSOffset->missedCycleCntOffset = pTTSOffset->statusOffset + 4U;
    pTTSOffset->prevTxSof = pTTSOffset->missedCycleCntOffset + 4U;
    pTTSOffset->cycTxSof = pTTSOffset->prevTxSof + 8U;
}

/* Local function for polling link status. This can be called from ISR context or poll control API */
static inline void ICSS_EmacPollLink(ICSS_EmacHandle icssEmacHandle, uint32_t pollSource) 
{
    volatile uint8_t *portStatusPtr = NULL;
    volatile uint8_t portStatus = 0;
    volatile uint32_t linkStatus;
    volatile uint32_t *intStatusPtr;
    
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t ioctlvalue = 0;
    ICSS_EmacHostStatistics_t* hostStatPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    uint32_t temp_addr = 0U;
    uint32_t temp_val;
    bool linkStatusChange = FALSE;
    temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs + CSL_ICSSINTC_SECR1);
    /*Find out which port it is*/
    intStatusPtr = (uint32_t*)(temp_addr);
    if((((uint32_t)LINK0_PRU_EVT_MASK & *intStatusPtr) != 0U) && (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_SWITCH) || ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC1)))
    {
        /**Link 0 Port event*/
        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs + ICSS_MDIO_LINKINT_RAW_MASK_OFFSET);
        /*clear interrupt in MDIO*/
        HW_WR_REG32(temp_addr, 0x01U);
        /* Issue read to make sure value written has taken affect, if not re-read once again*/
        temp_val = HW_RD_REG32(temp_addr);
        if ((temp_val & 0x1U) != 0U)
        {
            HW_RD_REG32(temp_addr);
        }
        
        /*clear PRU-ICSS INTC interrupt*/
        ICSS_EmacClearIrq(icssEmacHandle, 41);

        hostStatPtr->linkBreak++;
        linkStatus = CSL_MDIO_phyLinkStatus((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                                   (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[0]);
                                                                   
        ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[0]=(uint8_t)linkStatus;

        temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->portStatusOffset);
        portStatusPtr = (uint8_t*)(temp_addr);

        if(linkStatus) {
            portStatus |= (uint8_t)(ICSS_EMAC_PORT_LINK_MASK);
            ioctlvalue = (uint8_t)(ICSS_EMAC_IOCTL_PORT_CTRL_ENABLE);
            ioctlParams.ioctlVal = &ioctlvalue;
            ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_1, (void*)&ioctlParams);
        } else {
            portStatus &= ((uint8_t)~(ICSS_EMAC_PORT_LINK_MASK));
            ioctlvalue = ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE;
            ioctlParams.ioctlVal = &ioctlvalue;
            ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_1, (void*)&ioctlParams);
        }

        if(portStatusPtr != NULL) 
        {
            /*write back*/
            *(portStatusPtr) = portStatus;
        }
        /*Protocol specific processing*/
        if(((ICSS_EmacObject*)icssEmacHandle->object)->port0ISRCall != NULL)
        {
           ((ICSS_EmacObject*)icssEmacHandle->object)->port0ISRCall((void *)linkStatus,((ICSS_EmacObject*)icssEmacHandle->object)->port0ISRUser);
        }
        linkStatusChange = TRUE;

    }
    if((((uint32_t)LINK1_PRU_EVT_MASK & *intStatusPtr) != 0U) && (((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_SWITCH) || ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->portMask == (uint8_t)ICSS_EMAC_MODE_MAC2)))
    {
            if(LINK1_PRU_EVT_MASK & *intStatusPtr) 
            { /**Link 1 Port event*/
    
            /**Link 1 Port event*/
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs + ICSS_MDIO_LINKINT_RAW_MASK_OFFSET);
            /*clear interrupt in MDIO*/
            HW_WR_REG32(temp_addr, 0x02U);
            /* Issue read to make sure value written has taken affect, if not re-read once again*/
            temp_val = HW_RD_REG32(temp_addr);            
            if ((temp_val & 0x2U) != 0U)
            {
                HW_RD_REG32(temp_addr);
            }
    
            /*clear PRU-ICSS INTC interrupt*/
            ICSS_EmacClearIrq(icssEmacHandle, 53);
            
            hostStatPtr->linkBreak++;
            if(ICSS_EMAC_MODE_SWITCH != ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask)
            {
                linkStatus = CSL_MDIO_phyLinkStatus((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                                       (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[0]);
                ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[0]=(uint8_t)linkStatus;
            }
            else
            {
                linkStatus = CSL_MDIO_phyLinkStatus((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                                       (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[1]);
                                                                       
                    ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[ICSS_EMAC_PORT_2-1U]=(uint8_t)linkStatus;
            }
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->portStatusOffset);
            portStatusPtr = (uint8_t*)(temp_addr);

            if(linkStatus)
            {
                portStatus |= ICSS_EMAC_PORT_LINK_MASK;
                ioctlvalue = ICSS_EMAC_IOCTL_PORT_CTRL_ENABLE;
                ioctlParams.ioctlVal = &ioctlvalue;
                ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            } 
            else 
            {
                portStatus &=  ((uint8_t)~((ICSS_EMAC_PORT_LINK_MASK)));
                ioctlvalue = ICSS_EMAC_IOCTL_PORT_CTRL_DISABLE;
                ioctlParams.ioctlVal = &ioctlvalue;
                ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL, (uint8_t)ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            }
    
            if(portStatusPtr != NULL)
            {
                /*write back*/
                *(portStatusPtr) = portStatus;
            }
            
            if(((ICSS_EmacObject*)icssEmacHandle->object)->port1ISRCall != NULL) 
            {
                ((ICSS_EmacObject*)icssEmacHandle->object)->port1ISRCall((void *)linkStatus,((ICSS_EmacObject*)icssEmacHandle->object)->port1ISRUser);
            }
            linkStatusChange = TRUE;
        }
    }

    if(linkStatusChange == TRUE)
    {
        if (pollSource == ICSS_EMAC_POLL_FROM_ISR)
        {
            ICSS_EMAC_osalPostLock(((ICSS_EmacObject*)icssEmacHandle->object)->linkSemaphoreHandle);
        }
        else
        {
            if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
            {
                /*Update flags in memory*/
                ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_1, icssEmacHandle);
                ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_2, icssEmacHandle);
            }
            else if(ICSS_EMAC_MODE_MAC1 == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
            {
                ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_1, icssEmacHandle);
            }
            else if(ICSS_EMAC_MODE_MAC2 == ((ICSS_EmacObject *) icssEmacHandle->object)->emacInitcfg->portMask)
            {
                ICSS_EmacUpdatePhyStatus(ICSS_EMAC_PORT_2, icssEmacHandle);
            }
            else
            {
                invalidLinkEvent++;
            }
        }
    }
}

/* Local function for receive packet polling*/
static inline void ICSS_EmacPollPkt(ICSS_EmacHandle icssEmacHandle)
{
    int16_t pLength;
    int32_t allQueuesEempty = 0;
    int8_t  dest_address[ICSS_EMAC_MAXMTU];
    uint16_t numPacketsInLoop = 0;
    ICSS_EmacRxArgument rxArg;
    ICSS_EmacPktInfo rxPktInfo;

    while((allQueuesEempty != 1) && (numPacketsInLoop <= ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->pacingThreshold)))
    {
        pLength = ((int16_t)(ICSS_EmacRxPktInfo2(icssEmacHandle, 
                                                                     &rxPktInfo)));
        if(pLength > 0)
        {
            /* Invoke  receive packet callback function */
            if((rxPktInfo.queueNumber >= ((ICSS_EmacObject*)(icssEmacHandle->object))->emacInitcfg->ethPrioQueue) 
				&& (((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntRx != NULL))
            {
                  ((ICSS_EmacObject*)icssEmacHandle->object)->icssEmacHwIntRx(&rxPktInfo.queueNumber,icssEmacHandle);
            }
            else
            {
                if( (((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle != NULL)
                    && ((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxRTCallBack != NULL)
                    && (((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxRTCallBack)->callBack != NULL))
                {
                    ((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxRTCallBack)->callBack(&rxPktInfo.queueNumber,
                            ((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxRTCallBack)->userArg);
                } 
                else
                {

                    if((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle != NULL)
                                    && ((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxCallBack != NULL)
                                    && (((((ICSS_EmacObject*)icssEmacHandle->object)->callBackHandle)->rxCallBack)->callBack != NULL))
                    {
                        rxArg.icssEmacHandle = icssEmacHandle;
                        rxArg.destAddress = (uint32_t)dest_address;
                        rxArg.more = 0;
                        rxArg.queueNumber = rxPktInfo.queueNumber;
                        rxArg.port=rxPktInfo.portNumber;
                        ((((ICSS_EmacObject *)icssEmacHandle->object)->callBackHandle)->rxCallBack)->callBack(&rxArg,NULL);   /* just dump the packet here so we do no stall the queues */
                    }
                }
            }
            numPacketsInLoop++;
        } 
        else 
        {
            allQueuesEempty =1;
        }
    }
}

#if defined (__TI_ARM_V7M4__) || defined(_TMS320C6X)
static inline void memcpy_local(void *dst, const void *src, size_t len)
{
    memcpy((int32_t*)dst, (int32_t*) src, (size_t)len);
}
#else
static inline void memcpy_local(void *dst, const void *src, size_t len)
{
         size_t i;

         if ((uintptr_t)dst % sizeof(long) == 0 &&
             (uintptr_t)src % sizeof(long) == 0 &&
             len % sizeof(long) == 0)
         {

                 long *d = dst;
                 const long *s = src;

                 for (i=0; i<len/sizeof(long); i++) {
                         d[i] = s[i];
                 }
         }
         else
         {
                 char *d = dst;
                 const char *s = src;

                 for (i=0; i<len; i++)
                 {
                         d[i] = s[i];
                 }
         }
 }

#endif
