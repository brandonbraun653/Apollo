/**
 *  \file   cache_mmu_app.h
 *
 *  \brief  This file contains the configurations, macros and function
 *          declarations needed for cache-mmu example.
 *
 *      APPLICATION CONFIGURATION:
 *      --------------------------
 *          Modules used:
 *              Cache
 *              MMU
 *              EDMA
 *              Uart
 *              Interrupt controller
 *
 *      APPLICATION USECASES:
 *      ---------------------
 *        This application demonstrates the following features.
 *
 *        1.CACHE INVALIDATE:
 *          This mode demonstrates the fact that with cache enabled, the updated
 *          data gets stored in cache and invalidation operation discards the
 *          updated data.
 *            1. Transfer the initial buffer data (from main mem) using CPU.
 *            2. Enable cache and update the buffer data (A-Z) and print them
 *               using CPU.
 *            3. Now invalidate the cache and print the data to show that
 *               invalidated data is discarded and the CPU sees old data (a-z).
 *
 *        2.CACHE CLEAN:
 *          This mode demonstrates the fact that with cache enabled, the
 *          data updated by CPU is stored in cache (write-back configuration).
 *          And the DMA transfer which happens from memory to peripheral FIFO
 *          is unaware of the changes made (by the CPU) in cache.
 *            1. Transfer the data (a-z) from memory to uart fifo using DMA
 *            2. Now update the data in array to A-Z (upper case). Since the
 *               cache is enabled (write-back) the updation will happen in cache
 *               only and the same will not be synchronized to memory.
 *            3. Now when the DMA transfers the array contents, still the older
 *               contents a-z from memory will be transferred.
 *            4. Clean the contents and initiate DMA transfer again, now the
 *               updated contents should get transferred.
 *
 *        3.CACHE LOCK & UNLOCK:
 *          This mode demonstrates the lock capability of cache.
 *            1. Lock the buffer on to cache, and update the data (to a-z)
 *            2. Try to force eviction by loading data more than L2 cache size
 *            3. Print the buffer data using DMA to make sure updated buffer data
 *               is not evicted to main memory.
 *            4. Now unlock the cache and load other data to evict the buffer
 *            5. Print the buffer data using DMA to make sure updated buffer data
 *               is evicted to main memory.
 *
 *        4.L2 AS SRAM:
 *          In this case L2 use as SRAM is demonstrated. SRAM is written and
 *          read back with some data and compared. The dynamic configuration
 *          change of L2 as SRAM or Cache is not allowed. Update the macro
 *          "L2_DEMO_AS_SRAM" in cacheDemo.h to select the feature.
 *
 *      RUNNING THE EXAMPLE:
 *      --------------------
 *          Connect the serial port and configure the terminal in host PC. Load
 *          and execute the application binary. The use of L2 as SRAM or cache
 *          is exclusive and can not be changed at runtime.
 *            1. The different features described above in APPLICATION USECASE
 *               are demonstrated one by one. Appropriate help messages are
 *               printed on the console.
 *
 *      LIMITATIONS:
 *      ------------
 *            In this example only few modules are used. So the o/p will be as
 *            mentioned above. In cases where more modules are used or threading
 *            is enabled the behaviour may not be as expected.
 *
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef CACHE_MMU_APP_H_
#define CACHE_MMU_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Interrupt mapping for AM43XX */
/* TODO: Remove these macros and use chipdb API's. */
#ifdef AM43XX_FAMILY_BUILD
    #define SYS_INT_EDMACOMPINT               (32U + 12U)
    #define SYS_INT_EDMAMPERR                 (32U + 13U)
    #define SYS_INT_EDMAERRINT                (32U + 14U)
#else /* if defined(AM43XX_FAMILY_BUILD) */
    #define SYS_INT_EDMACOMPINT               (12U)
    #define SYS_INT_EDMAMPERR                 (13U)
    #define SYS_INT_EDMAERRINT                (14U)
#endif /* if defined(AM43XX_FAMILY_BUILD) */

/** \brief DMA event mapping */
/* TODO: Remove these macros and use chipdb API's. */
#define EDMA3_CHA_UART0_TX                (26U)

/** \brief Demo selection macros */
#define L2_DEMO_AS_SRAM                   (0x1U)
#define L2_DEMO_AS_CACHE                  (0x2U)
#define CACHE_MMU_DEMO_CLEAN_INVAL        (0x4U)
#define CACHE_MMU_DEMO_LOCK               (0x8U)

/** \briefMemory test pattern */
#define L2_SRAM_TEST_PATTERN              (0xA5A5A5A5U)

/** \brief Demo configurations */
#define TX_DATA_LENGTH                    (26U)
#define DATA_BUFFER_SIZE                  (64U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

extern volatile uint32_t callBackFlag;
extern uint32_t uartBaseAddr;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API enables the edma module and configures the interrupt.
 *          Clears the error specific registers & initializes the Queue Number.
 *
 * \param   edmaccInstNum   EDMA channel control instance number.
 *
 * \retval  None
 **/
void EDMAInitialize(uint32_t edmaccInstNum);

/**
 * \brief   This API enables and configures the the uart module.
 *          It also configures the baud rate.
 *
 * \param   pBuffer       Start address of buffer to be transmitted.
 * \param   bufLength     Length of buffer to be transmitted.
 *
 * \retval  None
 **/
void CACHEAppUartTransfer(uint8_t* pBuffer, uint32_t bufLength);

/**
 * \brief   This API enables and configures the the uart module.
 *          It also configures the baud rate.
 *
 * \param   uartInstNum   Uart instance number.
 *
 * \retval  None
 **/
void CACHEAppUartInitialize(uint32_t uartInstNum);

/** \brief   This API demonstrates the usage of L2 as SRAM. It also does the
 *            memory pattern test.
 */
void CACHEAppL2SramDemo(void);

/** \brief   This API initializes the buffer with initial value. */
void CACHEAppInitBuffer(void);

/** \brief   This API demonstrates the cache invalidation operation. */
void CACHEAppInvalidateDemo(void);

/** \brief   This API demonstrates the cache clean operation. */
void CACHEAppCleanDemo(void);

/** \brief   This API demonstrates the cache lock operation. */
void CACHEAppLockDemo(void);

/** \brief   This API updates the buffer with caps or small case based on the
 *            parameter ('A' or 'a').
 *
 * \param   alphabet  'A' or 'a' - based on the value the buffer will be
 *                    updated with caps or small letters.
 */
void CACHEAppUpdateBuffer(uint8_t alphabet);

#ifdef __cplusplus
}
#endif
#endif /* CACHE_MMU_APP_H_ */
