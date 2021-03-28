/*
 * Copyright (C) 2014-2018 Texas Instruments Incorporated - http://www.ti.com/
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
/** ============================================================================
 *  @file       ESPI_v2.h
 *
 *  @brief      ESPI driver implementation for a PRU ESPI controller
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/soc/ESPI_v2.h>
 *  @endcode
 *
 *  This ESPI driver implementation is designed to operate on a 
 *
 *
 *  ============================================================================
 */

#ifndef ESPI_V2_H
#define ESPI_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_icss.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/fw_mem_section.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/spi/soc/tispi_pruss_intc_mapping.h>

#include <ti/drv/spi/firmware/icss_espi/include/icss_espi.h>

#include <ti/osal/osal.h>

#if defined(SOC_AM335x)
#define	ESPI_PRU_PINMUX_GPI_MODE      (0x00000001U)
#define	ESPI_PRU_PINMUX_GPO_MODE      (0x00000002U)
#define	ESPI_PRU_GPI_INPUT_ENABLE     (0x00000020U)
#define	ESPI_PRU_GPI_SELECT_MASK      (0xFFFFFFD0U)
#define	ESPI_PRU_GPO_PULLUP_DISABLE   (0x00000008U)
#define	ESPI_PRU_GPO_SELECT_MASK      (0xFFFFFFF0U)
#elif defined(SOC_AM437x)
#define	ESPI_PRU_GPI_INPUT_ENABLE     (0x00040000U)
#define	ESPI_PRU_GPI_SELECT_MASK      (0xFFFEFFF0U)
#define	ESPI_PRU_GPO_PULLUP_DISABLE   (0x00010000U)
#define	ESPI_PRU_GPO_SELECT_MASK      (0xFFFBFFF0U)
#define	ESPI_PRU_PINMUX_GPI_MODE      (0x00000001U)
#define	ESPI_PRU_PINMUX_GPO_MODE      (0x00000002U)
#endif


#if defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM571x) || defined(SOC_K2G)
#define ESPI_ICSS_INTC_SECR0            (CSL_ICSSINTC_SECR0)
#elif defined(SOC_AM335x) || defined(SOC_AM437x)
#define ESPI_ICSS_INTC_SECR0            (CSL_ICSSM_INTC_SECR0)
#endif

  /* ESPI function table pointers */
  extern const SPI_FxnTable ESPI_Init_FxnTable_v2;
  extern const MCSPI_FxnTable ESPI_FxnTable_v2;

  /*!
   *  @brief  ICSS Instances
   */
  typedef enum ESPI_ICSS_INSTANCE_e {
    /*! Instance 0 */
    ESPI_ICSS_INSTANCE0 = 0,
    /*! Instance 1 */
    ESPI_ICSS_INSTANCE1 = 1,
    /*! Instance 2 */
    ESPI_ICSS_INSTANCE2 = 2,
    /*! Instance 2 */
    ESPI_ICSS_INSTANCE_NONE = 0xFF
  } ESPI_ICSS_INSTANCE;

  /*!
   *  @brief  ESPI FW Image Memory Ptr
   */
  typedef struct ICSS_Mem_Ptr_s {
    /* ESPI LLD specific objects */
    uint32_t*	dram0MemBufferStart;	/* pointer to .data memory buffer for PRU0 */
    uint32_t*	iram0MemBufferStart;	/* pointer to .data memory buffer for PRU0 */
    uint32_t*	dram0MemBufferEnd;	/* pointer to .data memory buffer for PRU0 */
    uint32_t*	iram0MemBufferEnd;	/* pointer to .data memory buffer for PRU0 */
    uint32_t*	dram1MemBufferStart;	/* pointer to .data memory buffer for PRU1 */
    uint32_t*	iram1MemBufferStart;	/* pointer to .data memory buffer for PRU1 */
    uint32_t*	dram1MemBufferEnd;	/* pointer to .data memory buffer for PRU1 */
    uint32_t*	iram1MemBufferEnd;	/* pointer to .data memory buffer for PRU1 */

  } ICSS_Mem_Ptr;


  /*!
   *  @brief      PRUICSS IO Pin Mux hardware attributes
   *
   *  PRU SOC Input/Output pin mux register structure
   */
  typedef struct ESPI_PRU_IOPinMuxAttrs_s {
    uint32_t    baseRegAddr;          /* Control Module Base register */
    uint8_t     pinNum;               /* PRU Pin Number for FW */
    uint8_t     inputModeVal;         /* PRU Pin value for GPI */
    uint8_t     outputModeVal;        /* PRU Pin value for GPO */

  } ESPI_PRU_IOPinMuxAttrs;  

  /*!
   *  @brief      ESPI GPIO pin information
   */
  typedef struct ESPI_GPIO_pinAttrs_s {
    uint8_t     port;              /* GPIO Port for Host interrupts */
    uint8_t     pinNum;               /* GPIO Pin Number for Host interrupts */
  } ESPI_GPIO_pinAttrs;

  /* GPIO Pin names */
  typedef enum ESPI_GPIO_PIN {
    ESPI_GPIO_PIN_RESET      = 0U,
    ESPI_GPIO_PIN_COUNT
  } ESPI_GPIO_PIN;
  
  /**<
   *  @brief  PRU Config Mode
   *
   *  The application must not access any member variables of this structure!
   */
  typedef struct PRU_funct_mode_s {
    /* ESPI LLD specific objects */
    /* ESPI_ConfigMode      pruConfig;         /\* PRU Running configuration *\/ */
    /* uint32_t            instanceCnt;       /\* Number of ESPI instance running *\/ */
    uint32_t            pruConfigAddr;     /* Configuration address for the particular PRU */
    PRUSS_PruCores      pruInstance;       /*! ESPI working PRU Instance number */
    void               *pruInstLock;
    PRUICSS_Handle      pruIcssHandle;     /* Handle to PRU Instance*/
    /* uintptr_t           handlePtr;      /\* Pointer to ESPI Instance handle *\/ */

  } PRU_funct_mode;

  /**<
   *  @brief  ICSS Config Mode
   *
   *  The application must not access any member variables of this structure!
   */
  typedef struct ICSS_funct_mode_s {
    /* LLD specific objects */
    PRU_funct_mode      pruMode[2];       /* PRU0/1 running mode of ICSS */

  } ICSS_funct_mode;

  typedef struct ESPI_v2_chObject_s {
    void* test;
  } ESPI_v2_chObject;
  
  /*!
   *  @brief  ESPI Software IP attributes
   */
  typedef struct ESPI_SwIPAttrs_s {
    uint32_t			baseAddr;	/*! ESPI Peripheral base address. */
    /* uint32_t			memMappedBaseAddr;	/\*! ESPI memory mapped mode base address *\/ */
    uint32_t                    configAddr;              /*! ESPI Peripheral configuration address */
    uint32_t                    intNum;                  /*! ESPI Peripheral interrupt vector id */
    uint32_t                    eventId;                 /*! ESPI Peripheral interrupt input id*/
#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x)
    uint32_t                    HostXbarNumber;          /*! ESPI Peripheral Host cross bar output id */
    CSL_XbarIrq                 PRUXbarNumber;           /*! ESPI Peripheral PRU cross bar input id */
#endif
    
    ESPI_ICSS_INSTANCE		icssInstance;	/*! ESPI working ICSS Instance number */
    PRUSS_PruCores		bitbangPru;	/*! Bit-Bang PRU core */
    PRUSS_PruCores		controlPru;	/*! Control PRU core */
    const ICSS_Mem_Ptr*		icssMemBuffer;	/*! Handle to PRU Instance */
    
    ESPI_PRU_IOPinMuxAttrs	d0OutputPin;	/*! ESPI output pin mux register for writing D0Out */
    ESPI_PRU_IOPinMuxAttrs	d1OutputPin;	/*! ESPI output pin mux register for writing D1Out */
    ESPI_PRU_IOPinMuxAttrs	d2OutputPin;	/*! ESPI output pin mux register for writing D2Out */
    ESPI_PRU_IOPinMuxAttrs	d3OutputPin;	/*! ESPI output pin mux register for writing D3Out */
    ESPI_PRU_IOPinMuxAttrs	alertOutputPin;	/*! ESPI output pin mux register for writing Alert */
    ESPI_PRU_IOPinMuxAttrs	enOutputPin;	/*! ESPI output pin mux register for writing En */

    ESPI_PRU_IOPinMuxAttrs	d0InputPin;	/*! ESPI input pin mux register for reading D0In */
    ESPI_PRU_IOPinMuxAttrs	d1InputPin;	/*! ESPI input pin mux register for reading D1In */
    ESPI_PRU_IOPinMuxAttrs	d2InputPin;	/*! ESPI input pin mux register for reading D2In */
    ESPI_PRU_IOPinMuxAttrs	d3InputPin;	/*! ESPI input pin mux register for reading D3In */
    ESPI_PRU_IOPinMuxAttrs	sclInputPin;	/*! ESPI input pin mux register for reading SCL */
    ESPI_PRU_IOPinMuxAttrs	csInputPin;	/*! ESPI input pin mux register for reading CS */

    ESPI_GPIO_pinAttrs		resetPin;	/*! ESPI GPIO pin for RESET interrupt */

    uint32_t			chNum		/*! ESPI Channel Number */;
  } ESPI_SwIPAttrs;

  /* Memory Read 32 */
#define ESPI_CYCLE_MEM_RD_32 0b00000000
  /* Memory Read 64 */
#define ESPI_CYCLE_MEM_RD_64 0b00000010
  /* Memory Write 32 */
#define ESPI_CYCLE_MEM_WR_32 0b00000001
  /* Memory Write 64 */
#define ESPI_CYCLE_MEM_WR_64 0b00000011
  /* Message */
#define ESPI_CYCLE_MSG 0b00010000
  /* Message with Data */
#define ESPI_CYCLE_MSG_DATA 0b00010001
  /* Successful Completion Without Data */
#define ESPI_CYCLE_SUCC_CMP_NODATA 0b00000110
  /* Successful Completion With Data (middle of split completion sequence) */
#define ESPI_CYCLE_SUCC_CMP_MID 0b00001001
  /* Successful Completion With Data (first of split completion sequence) */
#define ESPI_CYCLE_SUCC_CMP_FIRST 0b00001011
  /* Successful Completion With Data (last of split completion sequence) */
#define ESPI_CYCLE_SUCC_CMP_LAST 0b00001101
  /* Successful Completion With Data (only completion for split transaction) */
#define ESPI_CYCLE_SUCC_CMP_ONLY 0b00001111
  /* Unsuccessful Completion Without Data (middle of split completion sequence) */
#define ESPI_CYCLE_UNSUCC_CMP_MID 0b00001001
  /* Unsuccessful Completion Without Data (first of split completion sequence) */
#define ESPI_CYCLE_UNSUCC_CMP_FIRST 0b00001011
  /* Unsuccessful Completion Without Data (last of split completion sequence) */
#define ESPI_CYCLE_UNSUCC_CMP_LAST 0b00001101
  /* Unsuccessful Completion Without Data (only completion for split transaction) */
#define ESPI_CYCLE_UNSUCC_CMP_ONLY 0b00001111
  /* Short Transaction (not actually a cycle type, but useful nonetheless */
#define ESPI_CYCLE_SHORT 0b00001111

  /* OOB */
#define ESPI_CYCLE_OOB 0b00100001
    
  /* Flash Read */
#define ESPI_CYCLE_FLASH_READ 0b00000000
  /* Flash Read */
#define ESPI_CYCLE_FLASH_WRITE 0b00000001
  /* Flash Read */
#define ESPI_CYCLE_FLASH_ERASE 0b00000010
  
  /*!
   *  @brief
   *  An ::ESPI_Packet is used 
   *  
   */
  typedef struct espi_packet_s {
    uint8_t magicNum;	/* Magic number to ensure data integrity */
    uint16_t len;	/* Size of the packet (including CMD) */
    uint8_t cmd;	/* ESPI Packet CMD */
    //ESPI_Command cmd;	/* ESPI CMD code */
    //ESPI_Cycle_Type cycle;	/* ESPI cycle type */
    void* dataBuf;	/* Pointer to a data buffer */
  } ESPI_Packet;

  /*!
   *  @brief
   *  An ::ESPI_Transaction data structure is used with ESPI_transfer(). It indicates
   *  
   */
  typedef struct ESPI_Transaction_s {
    /* User input (write-only) fields */
    ESPI_Packet packet;
    void      *dataBuf;      /*!< void * to a buffer with data to be transmitted */

    /* User output (read-only) fields */
    SPI_Status status;     /*!< Status code set by SPI_transfer */

    /* Driver-use only fields */
  } ESPI_Transaction;
  
  /*!
   *  @brief  ESPI V2 driver object
   *
   *  The application must not access any member variables of this structure!
   */
  typedef struct ESPI_v2_Object_s {
    void *      mutex;                    /* instance lock */
    void *      transferComplete;         /* Transfer complete lock */
    void *      hwi;                      /* Hardware interrupt object */

    MCSPI_Params            espiParams;     /* input parameters */

    //void*               cmdAckSem;          /* Hwi object */
    //uint32_t            currentCmd;         /* stores the current command being passed */

    SPI_Transaction*      transaction;     /* Transaction structure */

    ESPI_Packet		packet;		/* Internal packet to keep track of data in transaction */

    bool                isOpen;         /* flag to indicate module is open */
    uint32_t            intStatusErr;       /* interrupt status error */

    void *		Ch0SemHandle;	/* Channel 0 Semaphore Handle */

    ICSS_funct_mode	icssMode;	/* ICSS mode */
  } ESPI_v2_Object;

#ifdef __cplusplus
}
#endif

#endif /* _ESPI_V2_H */
