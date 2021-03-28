/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       pruicss.h
 *
 *  @brief      pruicss driver interface
 *
 *  The pruss header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/pruss/pruss.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_PRUICSS__include
#define ti_drivers_PRUICSS__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <ti/drv/pruss/soc/pruicss_soc.h>

#define PRUICSS_NUM_PRU_HOSTS           (10U)
#define PRUICSS_NUM_PRU_CHANNELS        (10U)
#define PRUICSS_NUM_PRU_SYS_EVTS        (64U)
#define PRUICSS_MAX_WAIT_EVENTS         (10U)

#define PRUICSS_PRU0_DATARAM            (0U)
#define PRUICSS_PRU1_DATARAM            (1U)
#define PRUICSS_PRU0_IRAM               (2U)
#define PRUICSS_PRU1_IRAM               (3U)
#define PRUICSS_SHARED_DATARAM          (4U)
#define    PRUICSS_CFG                  (5U)
#define    PRUICSS_UART                 (6U)
#define    PRUICSS_IEP                  (7U)
#define    PRUICSS_ECAP                 (8U)
#define    PRUICSS_MII_RT               (9U)
#define    PRUICSS_MDIO                 (10U)

/**< Invalid Intc Mux number, intc Mux not used if assigned PRUSS_INVALID_INTC_MUX_NUM */
#define PRUSS_INVALID_INTC_MUX_NUM      ((uint32_t)0xffff)

/** \brief Interrupt handler   */
typedef void (*PRUICSSDRV_IRQ_HANDLER)(void* buf);
typedef struct  PRUICSS_Config_s          *PRUICSS_Handle;

/*!
 *  @brief    PRUICSS Constant Table Register Entries
 */
typedef enum PRUICSS_ConstTblEntry_s
{
   PRUICCSS_ConstTblEntryC24,
   PRUICCSS_ConstTblEntryC25,
   PRUICCSS_ConstTblEntryC26,
   PRUICCSS_ConstTblEntryC27,
   PRUICCSS_ConstTblEntryC28,
   PRUICCSS_ConstTblEntryC29,
   PRUICCSS_ConstTblEntryC30,
   PRUICCSS_ConstTblEntryC31,
   PRUICCSS_ConstTblEntryMax
}PRUICSS_ConstTblEntry;

/***********************************************************************
*  Macros to support dynamic chip detecting feature
***********************************************************************/
typedef void *(*prussdrv_function_handler) (void * buf);

/*!
 *  @brief      PRUICSS system to channel map
 *
 */
typedef struct PRUICSS_SysevtToChannelMap_s
{
    uint8_t sysevt;   /*System event number */
    uint8_t channel;  /*Channel number */

    uint8_t polarity;  /*Interrupt polarity [ 0 - active low , 1 - active high ] */

    uint8_t type;  /*Interrupt type [ 0 - level or pulse interrupt , 1 - edge interrupt ] */
}PRUICSS_SysevtToChannelMap;

/*!
 *  @brief      PRUICSS channel to host map
 *
 */
typedef struct PRUICSS_ChannelToHostMap_s
 {
     int16_t channel;
     int16_t host;
 }PRUICSS_ChannelToHostMap;

/*!
 *  @brief      PRUICSS Interrupt controller initialisation data structure
 *
 */
 typedef struct PRUICSS_IntcInitData_s
 {
     /*Enabled SYSEVTs - Range:0..63
     {-1} indicates end of list*/
     int8_t sysevts_enabled[PRUICSS_NUM_PRU_SYS_EVTS];
      /*SysEvt to Channel map. SYSEVTs - Range:0..63 Channels -Range: 0..9
     {-1, -1} indicates end of list*/
     PRUICSS_SysevtToChannelMap sysevt_to_channel_map[PRUICSS_NUM_PRU_SYS_EVTS];
     /*Channel to Host map.Channels -Range: 0..9  HOSTs - Range:0..9
     {-1, -1} indicates end of list*/
     PRUICSS_ChannelToHostMap channel_to_host_map[PRUICSS_NUM_PRU_CHANNELS];
     /*10-bit mask - Enable Host0-Host9 {Host0/1:PRU0/1, Host2..9 : PRUEVT_OUT0..7)*/
     uint32_t host_enable_bitmask;
 }PRUICSS_IntcInitData;

/*!
 *  @brief     brief PRUICSS Global configuration
 *
 */
typedef struct PRUICSS_Config_s {

    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;
} PRUICSS_Config;

extern  PRUICSS_Config pruss_config[];

/*!
 *  @brief     brief PRUICSS IRQ handlers mapping
 *
 */
typedef struct PRUICSS_IrqFunMap_s
{
    PRUICSSDRV_IRQ_HANDLER  irqHandler;
    /**< Interrupt handler*/
    void*                   semHandle;
    /**< Binary semaphore to wait on */
    void*                   handle;
}PRUICSS_IrqFunMap;

/**
 *  \brief PRU Firmware binary header
 *
 */
typedef struct PRUICSS_FirmwareBinHeader_s
{

    uint32_t    image_size;
    /**< Image size */
    uint32_t    load_addr;
    /**< Address to which this binary need to be loaded */
    uint32_t    run_addr;
    /**< Address at which the execution should start */
}PRUICSS_FirmwareBinHeader;

/*!
 *  @brief PRUICSS interrupt config structure 
 *
 *  Default interrrupt configuration parametetrs
 */
typedef struct PRUICSS_IntrCfg_s
{
     uint32_t               pruEvtoutNum;  /**< PRU Event number */
     uint8_t                waitEnable;         /**< Flag specifying whether application can wait on this interrupt
                                                using PRUICSSPruWaitEvent function */
    PRUICSSDRV_IRQ_HANDLER  irqHandler; /**< Pointer to a function which will be called on interrupt.*/
    /**< DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t                intNum;
    /**< CorePac specific Event ID, input to CorePac interrupt controller */
    uint32_t                eventId;
     /**< intc mux number, Keystone inc mux is Chip Interrupt Controller
       if assigned -1, system resource manager will decide the mux num */
    int32_t                 intcMuxNum;
     /**< intc mux input event ID, for Keystone, it is the input event to CIC
       if assigned -1, system resource manager will decide the mux input event ID */
    int32_t                 intcMuxInEvent;
     /**< intc mux output event ID, for Keystone, it is the Host interrupt num
       if assigned -1, system resource manager will decide the mux output event ID */
    int32_t                 intcMuxOutEvent;

 }PRUICSS_IntrCfg;

typedef enum PRUICSS_Return_e
{
  PRUICSS_RETURN_FAILURE = -(int32_t)1,
  PRUICSS_RETURN_SUCCESS = 0

}PRUICSS_Return;

/**
 * @brief   This function creates the handle for the PRUICSS instance \n
 *
 * @param   config   configuration structure of PRUICSS.
 * @param   instance PRUICSS instance no.
 *
 * @return  PRUICSS handle. \n
 */
PRUICSS_Handle  PRUICSS_create(PRUICSS_Config *config ,int32_t instance);

/**
 * @brief   This function Executes the program in the specified PRU \n
 *
 * @param     handle    Pruss's driver handle
 * @param   pruNum    PRU instance number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruExecProgram(PRUICSS_Handle handle,int32_t pruNum );
/**
 * @brief   Routine to
 *
 * @param   handle              Pruss's driver handle
 * @param   pru_instance        PRU instance number
 * @param   spi_offset          Offset on SPI flash to where this need to be flashed
 *
 *
 * @return  None.
 *
 **/
int8_t PRUICSS_loadBinary (PRUICSS_Handle handle, uint8_t pru_instance,uint32_t spi_offset);

/**
 * @brief  This function waits for a System event to happen \n
 *
 * @param   handle              Pruss's driver handle
 * @param   pruEvtoutNum        The AINTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruWaitEvent(PRUICSS_Handle handle,uint32_t pruEvtoutNum );

/**
 * @brief  This function does Interrupt-Channel-host mapping.
 *
 * @param   handle     Pruss's driver handle
 * @param   prussintc_init_data   The pointer to structure containing mapping information.
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruIntcInit(PRUICSS_Handle handle, const PRUICSS_IntcInitData * prussintc_init_data);

/**
 * \brief  This function generates and INTC event, waits for AINTC event and
 *           clears an INTC event \n
 *
 * @param   handle         Pruss's driver handle
 * @param   sendEventNum   Event number.\n
 * @param   pruEvtoutNum   PRU Event number.\n
 * @param   ackEventNum    Acknowlodegement event number.\n
 *
 * \return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruSendWaitCearEvent(PRUICSS_Handle handle,uint32_t sendEventNum,
                                        uint32_t pruEvtoutNum,
                                        uint32_t ackEventNum
                                        );
/**
 * @brief  This function Registers an Interrupt Handler for an event.\n
 *
 * @param   handle          Pruss's driver handle
 *
 * @param   pruEvtoutNum    The ARM side event number.\n
 *
 * @param   intrNum         Interrupt number of MPU/C66x
 *
 * @param   eventNum        Event number of PRUICSS
 *
 * @param   waitEnable      Flag specifying whether application can wait on this interrupt
 *                            using PRUICSSPruWaitEvent function
 *
 * @param   irqHandler      Pointer to a function which will be called on interrupt.\n
 *
 *
 * \return  0 in case of successful registration, -1 otherwise. \n
 */
int32_t PRUICSS_registerIrqHandler(PRUICSS_Handle handle,uint32_t pruEvtoutNum,
                           int32_t intrNum,
                           int32_t eventNum,
                           uint8_t waitEnable,
                           PRUICSSDRV_IRQ_HANDLER irqHandler);

/**
 * @brief  This function Registers an Interrupt Handler for an event.\n
 *
 * @param   handle     Pruss's driver handle
 *
 *
 * @param    intrCfg        pointer to interrupt configuration parameter
 *
 * \return  0 in case of successful registration, -1 otherwise. \n
 */
int32_t PRUICSS_registerIrqHandler2(PRUICSS_Handle handle,
                                    PRUICSS_IntrCfg const *  intrCfg);


/**
 * @brief  This function sets the buffer pointer for PRU. The contents of this buffer will be \n
 *         loaded to IRAM.\n
 *
 * @param   handle      Pruss's driver handle
 * @param   pruNum      The PRU number.\n
 * @param   buffer      Pointer to buffer.\n
 * @param   numBytes    Number of bytes in the buffer.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_setPRUBuffer(PRUICSS_Handle handle,
                         uint32_t pruNum,
                         void *buffer,
                         uint32_t numBytes);

/**
 * @brief   Configure PIN_MUX_SEL
 *
 * @param   handle     Pruss's driver handle
 * @param    regVal        value to be written
 *
 * @return  None.
 *
 **/
void PRUICSS_pinMuxConfig(PRUICSS_Handle handle, uint64_t regVal);


/*The following are the static functions to be moved to .c file.*/

/**
 * @brief    Resets PRU: \n
 *
 * @param   handle      Pruss's driver handle
 * @param   pruNum      PRU instance number[0 or 1].
 *
 * @return   0 in case of successful reset, -1 otherwise.
 **/
int32_t PRUICSS_pruReset(PRUICSS_Handle handle ,uint8_t pruNum);
/**
 * @brief    Disables PRU: \n
 *
 * @param   handle      Pruss's driver handle
 * @param   pruNum      PRU instance number[0 or 1].
 *
 * @return   0 in case of successful disable, -1 otherwise.
 **/
int32_t PRUICSS_pruDisable(PRUICSS_Handle handle,uint8_t pruNum);

/**
 * @brief    Enables PRU: \n
 *
 * @param   handle      Pruss's driver handle
 * @param   pruNum      PRU instance number[0 or 1].
 *
 * @return   0 in case of successful enable, -1 otherwise.
 **/
int32_t PRUICSS_pruEnable(PRUICSS_Handle handle,uint8_t pruNum);
/**
 * @brief    Enables PRU Cycle Counter: \n
 *
 * @param   handle     Pruss's driver handle
 * @param   pruNum     PRU instance number[0 or 1].
 *
 * @return   0 in case of successful enable, -1 otherwise.
 **/
int32_t PRUICSS_pruCounterEnable(PRUICSS_Handle handle,uint8_t pruNum);
/**
 *
 *  @brief   This function writes the given data to PRU memory
 *
 * @param    handle         Pruss's driver handle
 * @param    pruMem         PRU Memory Macro
 * @param    wordoffset     Offset at which the write will happen.
 * @param    source_mem     Source memory[ Array of uint32_tegers ]
 * @param    bytelength     Total number of bytes to be writen
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                    word length written or 0 on error.
 *
 **/
int32_t PRUICSS_pruWriteMemory(PRUICSS_Handle handle,
                           uint32_t pruMem,
                           uint32_t wordoffset,
                           const uint32_t *source_mem,
                           uint32_t bytelength);
/**
 *
 *  @brief   This function reads from PRU memory and stores in block of memory
 *
 * @param     handle        Pruss's driver handle
 * @param     pruMem        PRU Memory Macro
 * @param     wordoffset    Offset at which the read will happen.
 * @param     dest_mem      Destination memory[ Array of uint32_tegers ]
 * @param     bytelength    Total number of bytes to be read
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                    word length read or 0 on error.
 *
 **/
int32_t PRUICSS_pruReadMemory(
        PRUICSS_Handle handle,
        uint32_t pruMem,
        uint32_t wordoffset,
        uint32_t *dest_mem,
        uint32_t bytelength
        );
/**
 *
 *  @brief   This function initializes the PRU memory to zero
 *
 * @param    handle     Pruss's driver handle
 * @param    pruMem     PRU Memory Macro
 *
 * pruMem can have the following values
 *      PRU_ICSS_SHARED_RAM\n
 *      PRU_ICSS_DATARAM(n) where n is the PRU number\n
 *      PRU_ICSS_IRAM(n) where n = 0 for PRU0,n = 1 for PRU1, n = 2 for RTU0, n = 3 for RTU1, maintaing this for backward compabitility , should use macros below\n
 *      PRU_ICSS_IRAM_PRU(n) where n = 0 for PRU0,n = 1 for PRU1\n
 *      PRU_ICSS_IRAM_RTU(n) where n = 0 for RTU0,n = 1 for RTU1\n
 *      PRU_ICSS_IRAM_TXPRU(n) where n = 0 for TXPRU0,n = 1 for TXPRU1
 * @return                    word length written or 0 on error.
 *
 **/
int32_t PRUICSS_pruInitMemory(PRUICSS_Handle handle,
                           uint32_t pruMem
                                       );

/**
 * @brief  This function Generates an INTC event \n
 *
 * @param   handle     Pruss's driver handle
 * @param   eventnum   The INTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 **/
int32_t PRUICSS_pruSendEvent(PRUICSS_Handle handle,uint32_t eventnum);


/**
 * @brief   his function clears an INTC event \n
 *
 * @param   handle     Pruss's driver handle
 * @param   eventnum   The INTC Event number.\n
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 **/
int32_t PRUICSS_pruClearEvent(PRUICSS_Handle handle,uint32_t eventnum);

/**
 * @brief   This function returns the address of PRU components.
 *
 * @param   handle      Pruss's driver handle
 * @param   pru_ram_id  PRU components' Id. \n
 * @param   address     Memory to which address to be copied. \n
 *
 * @return 0 in case of success, -1 otherwise. \n
 **/
int32_t PRUICSS_mapPruMem(PRUICSS_Handle handle,uint32_t pru_ram_id, void **address);

/**
 * @brief   This function returns the base address of peripheral IO modules.
 *
 * @param   per_id   Peripheral Module's Id.
 *
 * @param   handle      Pruss's driver handle
 * @param   address     Memory to which address to be copied. \n
 *
 * @return 0 in case of success, -1 otherwise. \n
 **/
int32_t PRUICSS_mapPeripheralIO(PRUICSS_Handle handle,uint32_t per_id, void **address);

void PRUICSS_enableOCPMasterAccess(PRUICSS_Handle handle );

/**
 * @brief    Detects the Chip Type \n
 *
 */
uint32_t PRUICSS_detectHWVersion(void);
/**
 * @brief   Get PRU ICSS version \n
 *
 * @param   handle     Pruss's driver handle
 *
 * @return  PRU ICSS version
 **/
uint32_t PRUICSS_getICSSVersion(PRUICSS_Handle handle);
/**
 * \brief  This API gets the SoC level of PRUICSS intial configuration
 *
 * \param  cfg       Pointer to PRUICSS SOC initial config.
 *
 * \return 0 success
 *
 */
int32_t PRUICSS_socGetInitCfg( PRUICSS_Config **cfg);

/**
 * \brief  This API sets the SoC level of PRUICSS intial configuration
 *
 * \param  cfg       Pointer to PRUICSS SOC initial config.
 *
 * \return           0 success
 *
 */
int32_t PRUICSS_socSetInitCfg(PRUICSS_Config const *cfg);

/**
 * @brief  This function clears all Interrupt-Channel-host mapping.
 *
 * @param   handle                Pruss's driver handle
 *
 * @return  0 in case of successful transition, -1 otherwise. \n
 */
int32_t PRUICSS_pruIntcClear(PRUICSS_Handle handle);

/**
 * \brief  This API updates the constant table  for specified constant table entry
             which have write permissions.
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum PRU number[0 or 1] for which constant table is being updated.
 * @param    constantTblEntry contant table entry being updated
 * @param    constantTblVal contant table value to be written
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setConstantTblEntry(PRUICSS_Handle handle, uint8_t pruNum, int32_t constantTblEntry, uint32_t constantTblVal);

/**
 * \brief  This API configures the General Purpose Mux Selector field of
 *          the General Purpose Config Register (PRUSS_GPCFG)
 *
 * @param    handle     Pruss's driver handle
 * @param    pruNum PRU number[0 or 1].
 * @param    mode PRU-ICSS wrap mux selection
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setGpMuxSel(PRUICSS_Handle handle, uint8_t pruNum, uint32_t mode);

/**
 * \brief  This API configures the source of the IEP clock to be either
 *          IEP CLK as the source or Interface Bus CLK as the source (such as OCP/ICLK/VCLK)
 *          This is accomplished by updating the IEP clock field of the General Purpose Config 
 *          Register (PRUSS_GPCFG)
 *
 * @param    handle     Pruss's driver handle
 * @param    source source of the IEP clock (0 == IEP CLK, 1 == OCP/ICLK/VCLK)
 *
 * \return           0 success, -1 on error
 *
 */
int32_t PRUICSS_setIepClkSrc(PRUICSS_Handle handle,  uint32_t source);


/**
 *
 *  @brief   This function writes the given data to PRU instruction memory
 *
 * @param     handle        Pruss's driver handle
 * @param     core          PRU core
 * @param     wordoffset    Offset at which the write will happen.
 * @param     source_mem    Source memory[ Array of uint32_tegers ]
 * @param     bytelength    Total number of bytes to be writen
 *
 * @return                    word length written or 0 on error.
 *
 **/
int32_t PRUICSS_pruWriteImem( PRUICSS_Handle handle,
                                      uint32_t core,
                                      uint32_t wordoffset,
                                      const uint32_t *source_mem,
                                      uint32_t bytelength );

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_PRUICSS__include */
