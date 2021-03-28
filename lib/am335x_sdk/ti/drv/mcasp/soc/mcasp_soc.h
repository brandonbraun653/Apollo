/*
 * Mcasp_drv.h
 *
 * This file contains Application programming interface for the McASP driver and 
 * command/macro definitions used by the McASP driver.
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
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

/** 
 *  \section    Introduction
 *
 *  \subsection    xxx    Purpose and Scope
 *  The purpose of this document is to explain the McASP low level driver
 *  within the PDK Framework written with OSAL for SYSBIOS platform.
 *
 *
 *  \subsection    bbb    McASP Controller
 *  The multichannel audio serial port (McASP) functions as a general-purpose
 *  audio serial port optimized for the needs of multichannel audio
 *  applications. The McASP is useful for time-division multiplexed (TDM)
 *  stream, Inter-Integrated Sound (I2S) protocols, and intercomponent digital
 *  audio interface transmission (DIT). The McASP consists of transmit and
 *  receive sections that may operate synchronized, or completely independently
 *  with separate master clocks, bit clocks, and frame syncs, and using
 *  different transmit modes with different bit-stream formats. The McASP
 *  module also includes up to 16 serializers that can be individually enabled
 *  to either transmit or receive. In addition, all of the McASP pins can be
 *  configured as general-purpose input/output (GPIO) pins.
 *
 *  \subsection    ccc    SYS/BIOS System
 *  SYS/BIOS is a real time kernel provided by TI to use with its
 *  DSP processors.
 *
 *  \subsection    ddd   Compiler defines to add/remove features
 *
 *  Define to turn OFF parameter checking.
 *  Use -DPSP_DISABLE_INPUT_PARAMETER_CHECK when building library
 *
 *
 *  \subsection    References
 *    -# SYS/BIOS driver development <b>SPRU616.pdf</b>
 *
 */

 /**
 * \file        mcasp_soc.h
 *
 * \brief       McASP driver SOC interface definition file
 *
 *              This file contains the interfaces, data types and symbolic
 *              definitions that are needed by the application to utilize the
 *              SOC specific features of the McASP device driver.
 *
 *              (C) Copyright 2019, Texas Instruments, Inc
 *
 */
 
#ifndef MCASP_SOC_H
#define MCASP_SOC_H

#include "mcasp_types.h"
#include <ti/osal/osal.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_mcasp.h>

#if defined (SOC_AM65XX) || defined (SOC_J721E)
#include <ti/drv/udma/include/udma_types.h>
 #ifndef MCASP_UDMA_ENABLED
 #define MCASP_UDMA_ENABLED
 #endif
#else 
 #ifndef MCASP_EDMA_ENABLED
 #define MCASP_EDMA_ENABLED 
 #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This is to disable the Mux Configuration in the hwInfo.
 */
#define MCASP_INVALID_MUX_NUM         (MUXINTCP_CROSSBAR_MUXNUM_INVALID)
/* Possible values for Mux In/Out event numbers */
#define MCASP_INVALID_MUX_EVENTNUM    (-1)  /* Not applicable for SOC */
#define MCASP_UNASSIGNED_MUX_EVENTNUM (-2)  /* Valid field but Unassigned for SOC */

/* Possible values for CPU event number */
#define MCASP_INVALID_EVENTNUM    (-1)  /* Not applicable for the corepac */
#define MCASP_UNASSIGNED_EVENTNUM (-2)  /* Valid field but unassigned for the corepac */

/* Possible values for Host interrupt vector number */
#define MCASP_INVALID_INTNUM      (-1) /* Not applicable for the corepac */
#define MCASP_UNASSIGNED_INTNUM   (-2) /* Valid field but unassigned for the corepac */

#define MCASP_NUM_FREE_DESCS  (4)

#if defined(MCASP_UDMA_ENABLED)       

/**
 *  \brief NavSS configuration structure for AM6X
 *
 *  Mcasp structure to hold the instance specific information.
 */
 typedef struct Mcasp_dmaInfo_s {
/*!
 *  @brief  OSPI UDMA info structure
*/
   /* CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST
    * CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_MONO
    * CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR 
    */ 
    uint32_t descType ; 
    /*! UDMA TX channel handle */
    Udma_ChHandle    txChHandle;
    /*! UDMA RX channel handle */
    Udma_ChHandle    rxChHandle;
    /*! UDMA TX ring memory pointers */
    void            *txRingMem;
    /*! UDMA TX completion queue ring memory pointer */
    void            *cqTxRingMem;
    /*! UDMA TX tear down completion queue ring memory pointer */
    void            *tdCqTxRingMem;
    /*! UDMA RX ring memory pointers */
    void            *rxRingMem;
    /*! UDMA RX completion queue ring memory pointer */
    void            *cqRxRingMem;
    /*! UDMA RX tear down completion queue ring memory pointer */
    void            *tdCqRxRingMem;
    /*! Ring count */
    uint32_t        ringCnt;
    /*! UDMA TX PD memory pointers */
    void            *txHpdMem[MCASP_NUM_FREE_DESCS];
    /*! UDMA RX PD memory pointers */
    void            *rxHpdMem[MCASP_NUM_FREE_DESCS];
    /*! UDMA TX event handle */
    Udma_EventHandle txEventHandle;
    /*! UDMA TX tear down event handle */
    Udma_EventHandle tdTxEventHandle;
    /*! UDMA RX event handles */
    Udma_EventHandle rxEventHandle;
    /*! UDMA RX tear down event handles */
    Udma_EventHandle tdRxEventHandle;

} Mcasp_dmaInfo_t;

#endif
/**
 *  \brief HW info structure
 *
 *  Mcasp structure to hold the instance specific information.
 */
typedef struct Mcasp_HwInfo_s
{
    CSL_McaspRegs   *baseAddress;
    /**< base address of the mcasp instance        */

    CSL_AfifoRegs   *fifoAddress;
    /**< Fifo address of the mcasp instance        */

    CSL_AdataRegs   *dataAddress;
    /**< Mcasp data registers address              */

    Bool             ditSupport;
    /**< Dit support enabled in hardware or not    */

    uint16_t           numSerializers;
    /**<number of serializers supported by instance*/

    int32_t           cpuTxEventNumber;
    /**< hardware Tx event of the mcasp instance  */

    int32_t           cpuRxEventNumber;
    /**< hardware Rx event of the mcasp instance  */

    uint32_t           txDmaEventNumber;
    /**< TX DMA event number                       */

    uint32_t           rxDmaEventNumber;
    /**< RX DMA event number                       */

    int32_t           txIntNum;
    /**< Interrupt vector number Tx */

    int32_t           rxIntNum;
   /**< Interrupt vector number Rx */

   int32_t   muxNum;
   /**< SOC Mux Configuration for Interrupts  */

    int32_t   txMuxInEvent;
   /**< Mux-in Event number for Transmit Interrupts  */
    
    int32_t   txMuxOutEvent;
    /**< Mux-out Event number for Transmit Interrupts  */
    
    int32_t   rxMuxInEvent;
    /**< Mux-in Event number for Receive Interrupts  */
    
    int32_t   rxMuxOutEvent;
    /**< Mux-out Event number for Receive Interrupts  */

    uint32_t           pwrmLpscId;
    /**< LPSC number for this instance                                        */

    uint32_t           pscInstance;
    /**< Instance of the PSC which controls this module's instance            */
#if defined(MCASP_UDMA_ENABLED)    
    Mcasp_dmaInfo_t dmaInfo;
    /* DMA info used for UDMA configuration */
#endif
    void * dmaHandle;
    /* DMA handle to be provided at run-time via application */

}Mcasp_HwInfo;

#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || defined (SOC_DRA78x)
#define MCASP_CNT  (CSL_MCASP_PER_CNT )
#elif defined (SOC_K2G) || defined(SOC_OMAPL137)|| defined(SOC_OMAPL138)
#define MCASP_CNT  (CSL_MCASP_CNT) 
#elif defined (SOC_AM437x) || defined(SOC_AM335x)
#define MCASP_CNT  (2U)
#elif defined(SOC_AM65XX)
#define MCASP_CNT  (3U)
#elif defined(SOC_J721E)
#define MCASP_CNT  (12U)
#else
#error "Unsupported SOC !! "
#endif

/**< Function to get the SOC configuration
* params: mcaspNum: mcasp instance number (0-based)
* Returns: -1 if error happens */
int32_t Mcasp_socGetInitCfg(uint32_t mcaspNum, Mcasp_HwInfo *cfg);

/**< Function to set the SOC configuration as per the cfg
* params: mcaspNum: mcasp instance number (0-based)
* Returns: -1 if error happens */
int32_t Mcasp_socSetInitCfg(uint32_t mcaspNum, const Mcasp_HwInfo *cfg);

/**< The SOC level HwInfo structure */
extern Mcasp_HwInfo Mcasp_deviceInstInfo[MCASP_CNT];

/**< Function to initialize SOC level configuration */
extern void McaspDevice_init(void);

#ifdef __cplusplus
}
#endif

#endif /*MCASP_SOC_H */
