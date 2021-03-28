/**
 *  \file   OSPI_v0.c
 *
 *  \brief  OSPI IP Version 0 specific driver APIs implementation.
 *
 *   This file contains the driver APIs for OSPI controller.
 */

/*
 * Copyright (C) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/src/v0/OSPI_v0.h>
#include <ti/drv/spi/src/SPI_osal.h>

#define OSPI_DAC_WRITE_TIMEOUT      (500000U)
#define OSPI_CHECK_IDLE_DELAY       (10U)
#define OSPI_CALIBRATE_DELAY        (20U)
#define OSPI_XIP_SETUP_DELAY        (250U)

/* OSPI AM57x functions */
static void       OSPI_close_v0(SPI_Handle handle);
static void       OSPI_init_v0(SPI_Handle handle);
static SPI_Handle OSPI_open_v0(SPI_Handle handle, const SPI_Params *params);
static bool       OSPI_transfer_v0(SPI_Handle handle,
                                   SPI_Transaction *transaction);
static int32_t    OSPI_primeTransfer_v0(SPI_Handle handle,
                                        SPI_Transaction *transaction);
static void       OSPI_transferCallback_v0(SPI_Handle handle,
                                           SPI_Transaction *msg);
static int32_t    OSPI_control_v0(SPI_Handle handle, uint32_t cmd, const void *arg);
static void       OSPI_transferCancel_v0(SPI_Handle handle);
static void       OSPI_hwiFxn_v0(uintptr_t arg);
static int32_t    OSPI_waitIdle(SPI_Handle handle, uint32_t timeOut);
static int32_t    OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs);
static int32_t    OSPI_read_v0(SPI_Handle handle, SPI_Transaction *transaction);
static int32_t    OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint32_t                      cmd,
                               uint8_t                      *rxBuf,
                               uint32_t                      rxLen);
static int32_t    OSPI_write_v0(SPI_Handle handle, SPI_Transaction *transaction);
static int32_t    OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                                const uint8_t                *cmdBuf,
                                uint32_t                      cmdLen,
                                const uint8_t                *txBuf,
                                uint32_t                      txLen);
static int32_t    OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                       uint32_t *rdLevel);
static int32_t    OSPI_ind_xfer_mode_read_v0(SPI_Handle handle,
                                             SPI_Transaction *transaction);
static int32_t    OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs);
static int32_t    OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                        uint32_t *sramLvl);
static int32_t    OSPI_ind_xfer_mode_write_v0(SPI_Handle handle,
                                              SPI_Transaction *transaction);
static int32_t    OSPI_dac_xfer_mode_read_v0(SPI_Handle handle,
                                             const SPI_Transaction *transaction);
static int32_t    OSPI_dac_xfer_mode_write_v0(SPI_Handle handle,
                                              const SPI_Transaction *transaction);
static int32_t    OSPI_cmd_mode_write_v0(SPI_Handle handle,
                                         const SPI_Transaction *transaction);
static int32_t    OSPI_cmd_mode_read_v0(SPI_Handle handle,
                                        SPI_Transaction *transaction);

typedef enum OSPI_intrPollMode_s
{
    SPI_OPER_MODE_BLOCKING = 0U,  /*! Interrupt based blocking mode */
    SPI_OPER_MODE_POLLING,        /*! Non interrupt based blocking mode */
    SPI_OPER_MODE_CALLBACK        /*! Interrupt based call back mode */
} OSPI_intrPollMode;



/* SPI function table for OSPI AM57x implementation */
const SPI_FxnTable OSPI_FxnTable_v0 =
{
    &OSPI_close_v0,
    &OSPI_control_v0,
    &OSPI_init_v0,
    &OSPI_open_v0,
    &OSPI_transfer_v0,
    &OSPI_transferCancel_v0,
    NULL
};

/*
 *  ======== OSPI_close_v0 ========
 */
static void OSPI_close_v0(SPI_Handle handle)
{
    OSPI_v0_Object        *object = NULL;
    OSPI_v0_HwAttrs const *hwAttrs = NULL;

    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_v0_Object *)handle->object;
        hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

        /* disable the interrupts */
        CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                           CSL_OSPI_INTR_MASK_ALL,
                           FALSE);

        /* Destruct the Hwi */
        if(object->hwi != NULL)
        {
            /* Destruct the Hwi */
            (void)SPI_osalHardwareIntDestruct(object->hwi, (int32_t)hwAttrs->eventId);
            object->hwi = NULL;
        }

        /* Destruct the instance lock */
        (void)SPI_osalDeleteBlockingLock(object->mutex);

        /* Destruct the transfer completion lock */
        if((uint32_t)SPI_OPER_MODE_BLOCKING == object->intrPollMode)
        {
            (void)SPI_osalDeleteBlockingLock(object->transferComplete);
        }

#ifdef SPI_DMA_ENABLE
        if (hwAttrs->dmaEnable == (bool)true)
        {
            OSPI_dmaFreeChannel(handle);
        }
#endif

        /* Open flag is set false */
        object->isOpen = (bool)false;
    }

    return;
}

/*
 *  ======== OSPI_hwiFxn_v0 ========
 *  Hwi interrupt handler to service the OSPI peripheral
 *
 *  The handler is a generic handler for a OSPI object.
 */
static void OSPI_hwiFxn_v0(uintptr_t arg)
{
    uint32_t               intrStatus;
    OSPI_v0_Object        *object = NULL;
    OSPI_v0_HwAttrs const *hwAttrs = NULL;
    uint32_t               sramLevel, rdBytes, wrBytes;

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_v0_Object *)(((SPI_Handle)arg)->object);
    hwAttrs = (OSPI_v0_HwAttrs const *)(((SPI_Handle)arg)->hwAttrs);

    /* Read the interrupt status register */
    intrStatus = CSL_ospiIntrStatus((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));

    if (object->readBufIdx != NULL_PTR)
    {
		/* Indirect read operation */
        if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
        {
            if(object->readCountIdx != 0U)
            {
                while ((bool)true)
                {
                    sramLevel = CSL_ospiGetSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), 1U);
                    if (sramLevel == 0U)
                    {
                        break;
                    }
                    rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                    rdBytes = (rdBytes > object->readCountIdx) ? object->readCountIdx : rdBytes;

                    /* Read data from FIFO */
                    CSL_ospiReadFifoData(hwAttrs->dataAddr, object->readBufIdx, rdBytes);

                    object->readBufIdx += rdBytes;
                    object->readCountIdx -= rdBytes;
                }

                if ((object->readCountIdx > 0U) &&
                    (object->readCountIdx < (CSL_OSPI_SRAM_WARERMARK_RD_LVL * CSL_OSPI_FIFO_WIDTH)))
                {
                    while((bool)true)
                    {
                        sramLevel = CSL_ospiGetSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), 1U);
                        rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                        if (rdBytes >= object->readCountIdx)
                        {
                            break;
                        }
                    }
                    rdBytes = object->readCountIdx;
                    CSL_ospiReadFifoData(hwAttrs->dataAddr, object->readBufIdx, rdBytes);
                    object->readBufIdx += rdBytes;
                    object->readCountIdx -= rdBytes;
                }
            }

            if((object->readCountIdx == 0U) || ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U))
            {
                /* Clear indirect read operation complete status */
                CSL_ospiClrIndReadComplete((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));

                /* disable and clear the interrupts */
                CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                    CSL_OSPI_INTR_MASK_ALL,
                                    FALSE);
                CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                  CSL_OSPI_INTR_MASK_ALL);

                /* Call the call back function */
                object->ospiParams.transferCallbackFxn((SPI_Handle)arg, NULL);
            }
            else
            {
                /* Clear interrupt status */
                CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), intrStatus);
            }
        }
    }
    else
    {
		/* Indirect write operation */
        if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
        {
            if (object->writeCountIdx != 0U)
            {
                sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                            CSL_ospiGetSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), 0U);

                wrBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                wrBytes = (wrBytes > object->writeCountIdx) ? object->writeCountIdx : wrBytes;

                /* Write data to FIFO */
                CSL_ospiWriteFifoData(hwAttrs->dataAddr, object->writeBufIdx, wrBytes);

                object->writeBufIdx += wrBytes;
                object->writeCountIdx -= wrBytes;

                sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                            CSL_ospiGetSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), 0U);

                if ((object->writeCountIdx > 0U) &&
                    (object->writeCountIdx <= (sramLevel * CSL_OSPI_FIFO_WIDTH)))
                {
                    wrBytes = object->writeCountIdx;
                    CSL_ospiWriteFifoData(hwAttrs->dataAddr, object->writeBufIdx, wrBytes);
                    object->writeBufIdx += wrBytes;
                    object->writeCountIdx -= wrBytes;
                }
            }

            if ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U)
            {
                /* Clear indirect write operation complete status */
                CSL_ospiClrIndWriteComplete((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));

                /* disable and clear the interrupts */
                CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                    CSL_OSPI_INTR_MASK_ALL,
                                    FALSE);
                CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                  CSL_OSPI_INTR_MASK_ALL);

                /* Call the call back function */
                object->ospiParams.transferCallbackFxn((SPI_Handle)arg, NULL);
            }
            else
            {
                /* Clear interrupt status */
                CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), intrStatus);
            }
        }
    }
}

/*
 *  ======== OSPI_init_v0 ========
 */
static void OSPI_init_v0(SPI_Handle handle)
{
    if (handle != NULL)
    {
        /* Mark the object as available */
        ((OSPI_v0_Object *)(handle->object))->isOpen = (bool)false;
    }
}

static void OSPI_delay(uint32_t delay);
static void OSPI_delay(uint32_t delay)
{
    volatile uint32_t i = delay;

    while (i > 0U)
    {
        i = i - 1U;
    }
}

static int32_t OSPI_waitIdle(SPI_Handle handle, uint32_t timeOut)
{
    OSPI_v0_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint32_t               retry = 0U;
    int32_t                retVal = (int32_t)(-1);
    uint32_t               timeOutVal = timeOut;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    while (timeOutVal != 0U)
    {
        if (CSL_ospiIsIdle((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)) != 0U)
        {
            retry++;
            if (retry == 3U)
            {
                retVal = 0;
                break;
            }
        }
        else
        {
            retry = 0U;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        timeOutVal--;
    }

    return (retVal);
}

/*
 *  ======== OSPI_configPhy ========
 */
#define OSPI_PHY_DLL_ELEM_DELAY_PERIOD   (80U)  /* worst delay element periord in ps */
static void OSPI_configPhy(SPI_Handle handle, const void *pDelay);
static void OSPI_configPhy(SPI_Handle handle, const void *pDelay)
{
#if !defined(j721e_sim)
    OSPI_v0_HwAttrs const   *hwAttrs = NULL;
    uint32_t                 numDelayElems;

    /* Get the pointer to the hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    numDelayElems = (1000000U / (hwAttrs->funcClk / 1000000U)) / OSPI_PHY_DLL_ELEM_DELAY_PERIOD;
    CSL_ospiConfigPhy((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                      numDelayElems,
                      (const uint32_t *)pDelay);
#endif
    OSPI_delay(OSPI_CALIBRATE_DELAY);
}

/*
 *  ======== OSPI_open_v0 ========
 */
static SPI_Handle OSPI_open_v0(SPI_Handle handle, const SPI_Params *params)
{
    SemaphoreP_Params        semParams;
    uintptr_t                key;
    SPI_Handle               retHandle = handle;
    OSPI_v0_Object          *object = NULL;
    OSPI_v0_HwAttrs const   *hwAttrs = NULL;
	OsalRegisterIntrParams_t interruptRegParams;
    int32_t                  retFlag = 0;
    uint32_t                 numAddrBytes;

    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_v0_Object *)handle->object;
        hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

        /* Determine if the device index was already opened */
        key = SPI_osalHardwareIntDisable();
    }

    if ((handle == NULL) || (object->isOpen == (bool)true))
    {
        if (handle != NULL)
        {
            SPI_osalHardwareIntRestore(key);
            retHandle = NULL;
        }
    }
    else
    {
        /* Mark the handle as being used */
        object->isOpen = (bool)true;
        SPI_osalHardwareIntRestore(key);

        /* Store the OSPI parameters */
        if (params == NULL) {
            /* No params passed in, so use the defaults */
            SPI_Params_init(&(object->ospiParams));
        }
        else {
            /* Copy the params contents */
            object->ospiParams = *params;
        }

        /* Copy the controller mode from hardware attributes to object */
        object->ospiMode  = (uint32_t)hwAttrs->operMode;
        object->xferLines = (uint32_t)hwAttrs->xferLines;
        object->hwi       = NULL;

        /* Extract OSPI operating mode based on hwAttrs and input parameters */
        if(SPI_MODE_BLOCKING == object->ospiParams.transferMode)
        {
            if (((bool)true == hwAttrs->intrEnable) && ((bool)false == hwAttrs->dacEnable))
            {
                /* interrupt is only used in indirect access mode */
                object->intrPollMode = (uint32_t)SPI_OPER_MODE_BLOCKING;
            }
#ifdef SPI_DMA_ENABLE
            else if (((bool)true == hwAttrs->dmaEnable) && ((bool)true == hwAttrs->dacEnable))
            {
                /* DMA mode is only used in direct access mode */
                object->intrPollMode = (uint32_t)SPI_OPER_MODE_BLOCKING;
            }
#endif
            else
            {
                object->intrPollMode = (uint32_t)SPI_OPER_MODE_POLLING;
            }
        }
        else
        {
            object->intrPollMode = (uint32_t)SPI_OPER_MODE_CALLBACK;
        }

        /* interrupt mode only enabled in indirect access controller mode */
        if (((bool)true == hwAttrs->intrEnable) && ((bool)false == hwAttrs->dacEnable))
        {
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            interruptRegParams.corepacConfig.name=NULL;
#ifndef __TI_ARM_V7R5__
            interruptRegParams.corepacConfig.priority=0x8U;
#else
            interruptRegParams.corepacConfig.priority=0x20U;
#endif
            interruptRegParams.corepacConfig.corepacEventNum = (int32_t)hwAttrs->eventId;
            interruptRegParams.corepacConfig.intVecNum = (int32_t)hwAttrs->intrNum; /* Host Interrupt vector */
            interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))(&OSPI_hwiFxn_v0);
            interruptRegParams.corepacConfig.arg = (uintptr_t)handle;

            (void)SPI_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
            if(object->hwi == NULL) {
                OSPI_close_v0(handle);
                retHandle = NULL;
                retFlag = 1;
            }
        }

        if(retFlag == 0)
        {
            /*
             * Construct thread safe handles for this OSPI peripheral
             * Semaphore to provide exclusive access to the OSPI peripheral
             */
            SPI_osalSemParamsInit(&semParams);
            semParams.mode = SemaphoreP_Mode_BINARY;
            object->mutex = SPI_osalCreateBlockingLock(1U, &semParams);

            /*
             * Store a callback function that posts the transfer complete
             * semaphore for synchronous mode
             */
            if (object->intrPollMode == (uint32_t)SPI_OPER_MODE_BLOCKING)
            {
                /*
                 * Semaphore to cause the waiting task to block for the OSPI
                 * to finish
                 */
                object->transferComplete = SPI_osalCreateBlockingLock(0, &semParams);

                /* Store internal callback function */
                object->ospiParams.transferCallbackFxn = &OSPI_transferCallback_v0;
            }
            if(object->intrPollMode == (uint32_t)SPI_OPER_MODE_CALLBACK)
            {
                /* Check to see if a callback function was defined for async mode */
                if (object->ospiParams.transferCallbackFxn == NULL)
                {
                    OSPI_close_v0(handle);
                    retHandle = NULL;
                    retFlag = 1;
                }
            }

            if(retFlag == 0)
            {
                object->transaction = NULL;

    #ifdef SPI_DMA_ENABLE
                if (hwAttrs->dmaEnable == (bool)true)
                {
                    (void)OSPI_dmaConfig(handle);
                }
    #endif
                /* Disable DAC */
                CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

                /* Disable DTR protocol */
                CSL_ospiDtrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

                if (hwAttrs->xipEnable == (bool)false)
                {
                    /* Disable XIP */
                    CSL_ospiXipEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
                }

                /* Disable OSPI controller */
                CSL_ospiEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

                /* Wait until Serial Interface and OSPI pipeline is IDLE. */
                if (OSPI_waitIdle(handle, OSPI_DAC_WRITE_TIMEOUT) != (int32_t)0U)
                {
                    OSPI_close_v0(handle);
                    retHandle = NULL;
                    retFlag = 1;
                }
            }
        }

        if(retFlag == 0)
        {
            /* Chip select setup */
            CSL_ospiSetChipSelect((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                  hwAttrs->chipSelect,
                                  CSL_OSPI_DECODER_SELECT4);

            /* Set clock mode */
            CSL_ospiSetClkMode((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                               hwAttrs->frmFmt);

            /* Disable the adapted loopback clock circuit */
            CSL_ospiLoopbackClkEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                      FALSE);

            /* Delay Setup */
            CSL_ospiSetDevDelay((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                hwAttrs->devDelays);

            /* Set default baud rate divider value */
            if (hwAttrs->phyEnable)
            {
                CSL_ospiSetPreScaler((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                     CSL_OSPI_BAUD_RATE_DIVISOR(2U));
            }
            else
            {
                /* Disable high speed mode when PHY is disabled */
                CSL_ospiSetPreScaler((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                     CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);

                /* Disable PHY mode */
                CSL_ospiPhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

                /* Disable PHY pipeline mode */
                CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
            }

            if (hwAttrs->dtrEnable)
            {
                numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
            }
            else
            {
                numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3;
            }

            /* Set device size cofigurations */
            CSL_ospiSetDevSize((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                               numAddrBytes,
                               hwAttrs->pageSize,
                               hwAttrs->blkSize);

            /* Set indirect trigger address register */
            if (hwAttrs->dacEnable)
            {
                CSL_ospiSetIndTrigAddr((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                       0x4000000);
            }
            else
            {
                CSL_ospiSetIndTrigAddr((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                       0);
            }

            /* Disable write completion auto polling */
            CSL_ospiSetWrCompAutoPolling((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                         CSL_OSPI_WRITE_COMP_AUTO_POLLING_ENABLE);

            /* Set SRAM partition configuration */
            CSL_ospiSetSramPartition((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                     CSL_OSPI_SRAM_PARTITION_DEFAULT);

            /* disable and clear the interrupts */
            CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                CSL_OSPI_INTR_MASK_ALL,
                                FALSE);
            CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                              CSL_OSPI_INTR_MASK_ALL);

            if (hwAttrs->dacEnable)
            {
                CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
            }
            else
            {
                CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
            }

            CSL_ospiSetDataReadCapDelay((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                        hwAttrs->rdDataCapDelay);
            CSL_ospiSetCsSotDelay((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                  hwAttrs->csSotDelay);
            /* Enable OSPI controller */
            CSL_ospiEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
        }
    }
    return(retHandle);
}

/*
 *  ======== OSPI_primeTransfer_v0 =======
 */
static int32_t OSPI_primeTransfer_v0(SPI_Handle handle,
                                     SPI_Transaction *transaction)
{
    OSPI_v0_Object        *object = NULL;
    OSPI_v0_HwAttrs const *hwAttrs = NULL;
    int32_t                retVal = 0;

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_v0_Object *)handle->object;
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    /* Disable and clear the interrupts */
    CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                        CSL_OSPI_INTR_MASK_ALL,
                        FALSE);
    CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                      CSL_OSPI_INTR_MASK_ALL);

    /* Interrupt mode */
    if(object->intrPollMode != (uint32_t)SPI_OPER_MODE_POLLING)
    {
        CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                           CSL_OSPI_INTR_MASK_ALL,
                           TRUE);
    }

    /* Identify the direction of transfer (whether read/write) */
    if((uint32_t)SPI_TRANSACTION_TYPE_READ == object->transactionType)
    {
        retVal = (OSPI_read_v0(handle, transaction));
    }
    else if((uint32_t)SPI_TRANSACTION_TYPE_WRITE == object->transactionType)
    {
        retVal = (OSPI_write_v0(handle, transaction));
    }
    else
    {
        transaction->status = SPI_TRANSFER_CANCELED;
		retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                    uint32_t *rdLevel)
{
    uint32_t retry = OSPI_DAC_WRITE_TIMEOUT;
    uint32_t sramLevel;
    int32_t  retVal = 0;
    while(retry != 0U)
    {
        sramLevel = CSL_ospiGetSramLvl(pReg, 1U);
        if (sramLevel != 0U)
        {
            *rdLevel = sramLevel;
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        retVal = 0;
    }
    else
    {
        retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_waitIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t retry = OSPI_DAC_WRITE_TIMEOUT;
    int32_t  retVal;

    /* Check flash indirect read controller status */
    while (retry != 0U)
    {
        if (CSL_ospiIndReadComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        /* Clear indirect completion status */
        CSL_ospiClrIndReadComplete(pRegs);
        retVal = 0;
    }
    else
    {
        retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_ind_xfer_mode_read_v0(SPI_Handle handle,
                                          SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    OSPI_v0_Object        *object;       /* OSPI object */
    uint8_t               *pDst;         /* Destination address */
    uint32_t               count;        /* transaction length */
    uint32_t               offset;       /* OSPI flash offset address */
    uint32_t               remaining;
    uint32_t               sramLevel = 0, rdBytes = 0;
    uint32_t               retFlag = 0U;
    int32_t                retVal = 0;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32_t)((uintptr_t)transaction->arg); /* NOR Flash offset address to read */
    pDst = (uint8_t *)transaction->rxBuf;
    count = (uint32_t)transaction->count;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_v0_Object *)handle->object;

    /* Disable DAC mode */
    CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

    if (hwAttrs->phyEnable == (bool)true)
    {
        /* Enable PHY pipeline mode for read */
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
    }

    /* Set read address in indirect mode */
    CSL_ospiIndSetStartAddr((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                            offset,
                            TRUE);
    CSL_ospiIndReadExecute((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), count);

    if ((uint32_t)SPI_OPER_MODE_POLLING == object->intrPollMode)
    {
        remaining = count;
        while(remaining > 0U)
        {
            /* Wait indirect read SRAM fifo has data */
            if (OSPI_waitReadSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                     &sramLevel) != (int32_t)0U)
            {
                retFlag = 1U;
                retVal = (int32_t)(-1);
                transaction->status=SPI_TRANSFER_FAILED;
                break;
            }

            rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
            rdBytes = (rdBytes > remaining) ? remaining : rdBytes;

            /* Read data from FIFO */
            CSL_ospiReadFifoData(hwAttrs->dataAddr, pDst, rdBytes);

            pDst += rdBytes;
            remaining -= rdBytes;
        }
        if(retFlag == 0U)
        {
            if (OSPI_waitIndReadComplete((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)) != (int32_t)0U)
            {
                retFlag = 1U;
                retVal = (int32_t)(-1);
                transaction->status=SPI_TRANSFER_FAILED;
            }
        }
    }
#if defined (__aarch64__) || defined (__TI_ARM_V7R4__)
    CSL_archMemoryFence();
#endif

    return (retVal);
}

static uint8_t OSPI_getDeviceStatus(SPI_Handle handle);
static uint8_t OSPI_getDeviceStatus(SPI_Handle handle)
{
    OSPI_v0_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    OSPI_v0_Object        *object;  /* OSPI object */
    uint8_t                status = 0xff;

    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_v0_Object *)handle->object;

    (void)OSPI_cmdRead((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                       object->rdStatusCmd,
                       &status,
                       1);

    return (status);
}

static bool OSPI_waitDeviceReady(SPI_Handle handle, uint32_t timeOut);
static bool OSPI_waitDeviceReady(SPI_Handle handle, uint32_t timeOut)
{
    bool         retVal = (bool)false;
    uint8_t      status;
    uint32_t     timeOutVal = timeOut;

    while (timeOutVal != 0U)
    {
        status = OSPI_getDeviceStatus(handle);
        if ((status & 1U) == 0U)
        {
            retVal = (bool)true;
            break;
        }
        timeOutVal--;
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
    }

    return (retVal);
}

static int32_t OSPI_dac_xfer_mode_read_v0(SPI_Handle handle,
                                          const SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint8_t               *pSrc;         /* Source address */
    uint8_t               *pDst;         /* Destination address */
    uint32_t               offset;       /* OSPI flash offset address */
    uint32_t               i;
    uint32_t               size;
    uint32_t               remainSize;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32_t)((uintptr_t)transaction->arg); /* OSPI Flash offset address to read */
    pDst = (uint8_t *)transaction->rxBuf;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

#ifdef SPI_DMA_ENABLE
    if (hwAttrs->dmaEnable == (bool)true)
    {
        if (hwAttrs->phyEnable == (bool)true)
        {
            /* Enable PHY pipeline mode for read */
            CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
        }
        OSPI_dmaTransfer(handle, transaction);
    }
    else
#endif
    {
        pSrc = (uint8_t *)(hwAttrs->dataAddr + offset);
        remainSize = (uint32_t)transaction->count & 3U;
        size = (uint32_t)transaction->count - remainSize;
        /* Transfer the data in 32-bit size */
        for (i = 0U; i < size; i += 4U)
        {
            CSL_REG32_WR(pDst + i, CSL_REG32_RD(pSrc + i));
#if defined (__aarch64__)
            CSL_archMemoryFence();
#endif
        }
        /* Transfer the remaining data in 8-bit size */
        for (i = 0; i < remainSize; i++)
        {
            CSL_REG8_WR(pDst + size + i, CSL_REG8_RD(pSrc + size + i));
#if defined (__aarch64__)
            CSL_archMemoryFence();
#endif
        }
    }

    return (0);
}

static int32_t OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t retry = OSPI_DAC_WRITE_TIMEOUT;
    int32_t  retVal = 0;
    uint32_t idleFlag = FALSE;

    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    /* Start to execute flash read/write command */
    CSL_ospiFlashExecCmd(pRegs);

    while (retry != 0U)
    {
        /* Check the command execution status */
        if (CSL_ospiFlashExecCmdComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry == 0U)
    {
        retVal = (int32_t)(-1);
    }

    idleFlag = FALSE;
    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    return (retVal);
}

static int32_t OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32_t                      cmd,
                            uint8_t                      *rxBuf,
                            uint32_t                      rxLen)
{
    uint32_t regVal;
    uint32_t rdLen;
    int32_t  retVal;
    uint8_t *pBuf = rxBuf;

    (void)CSL_ospiCmdRead(pRegs, cmd, rxLen);
    retVal = OSPI_flashExecCmd(pRegs);
    if (retVal == 0)
    {
        regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_LOWER_REG);

        /* Put the read value into rxBuf */
        rdLen = (rxLen > 4U) ? 4U : rxLen;
        (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        pBuf += rdLen;

        if (rxLen > 4U) {
            regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_UPPER_REG);
            rdLen = rxLen - rdLen;
            (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        }
    }
    return (retVal);
}

static int32_t OSPI_cmd_mode_read_v0(SPI_Handle handle,
                                     SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs;    /* OSPI hardware attributes */
    uint8_t               *cmd;

    cmd = (uint8_t *)transaction->txBuf;
    /* Get the pointer to the hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    return (OSPI_cmdRead((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                            (uint32_t)cmd[0],
                            (uint8_t *)transaction->rxBuf,
                            (uint32_t)transaction->count - CSL_OSPI_CMD_LEN_DEFAULT));
}


static int32_t OSPI_read_v0(SPI_Handle handle, SPI_Transaction *transaction)
{
    OSPI_v0_Object *object;
    int32_t         retVal = (int32_t)(-1);

    object = (OSPI_v0_Object *)handle->object;

    if((uint32_t)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
    {
        retVal = (OSPI_ind_xfer_mode_read_v0(handle, transaction));
    }
    else if((uint32_t)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
    {
        retVal = (OSPI_dac_xfer_mode_read_v0(handle, transaction));
    }
    else if((uint32_t)OSPI_OPER_MODE_CFG == object->ospiMode)
    {
        retVal = (OSPI_cmd_mode_read_v0(handle, transaction));
    }
    else
    {
        transaction->status=SPI_TRANSFER_CANCELED;
    }

    return(retVal);
}

static int32_t OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                     uint32_t *sramLvl)
{
    uint32_t retry = CSL_OSPI_REG_RETRY;
    uint32_t sramLevel;
    int32_t  retVal = 0;

    while(retry != 0U)
    {
        sramLevel = CSL_ospiGetSramLvl(pReg, 0);
        if (sramLevel <= CSL_OSPI_SRAM_WATERMARK_WR_LVL)
        {
			*sramLvl = sramLevel;
            break;
        }
        (void)SPI_osalDelay(CSL_OSPI_POLL_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        retVal = 0;
    }
    else
    {
        retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t retry = OSPI_DAC_WRITE_TIMEOUT;
    int32_t  retVal;

    /* Check flash indirect write controller status */
    while (retry != 0U)
    {
        if (CSL_ospiIsIndWriteComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        /* Clear indirect completion status */
        CSL_ospiClrIndWriteComplete(pRegs);
        retVal = 0;
    }
    else
    {
        retVal = (int32_t)(-1);
    }
    return(retVal);
}

static int32_t OSPI_ind_xfer_mode_write_v0(SPI_Handle handle,
                                           SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    OSPI_v0_Object        *object;       /* OSPI object */
    uint8_t               *pSrc;         /* Destination address */
    uint32_t               count;        /* transaction length */
    uint32_t               offset;       /* OSPI flash offset address */
    uint32_t               remaining;
    uint32_t               sramLevel, wrBytes;
    uint32_t               retFlag = 0;
    int32_t                retVal = 0;

    object = (OSPI_v0_Object *)handle->object;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32_t)((uintptr_t)transaction->arg); /* NOR Flash offset address to write */
    pSrc = (uint8_t*)transaction->txBuf;
    count = (uint32_t)transaction->count;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_v0_Object *)handle->object;

    /* Disable DAC mode */
    CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

    /* Set write address in indirect mode */
    CSL_ospiIndSetStartAddr((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                            offset,
                            FALSE);
    CSL_ospiIndWriteExecute((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), count);

    if ((uint32_t)SPI_OPER_MODE_POLLING == object->intrPollMode)
    {
        /* Wait Indirect Write  SRAM fill level below the threshold */
        if (OSPI_waitWriteSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                  &sramLevel) != (int32_t)0U)
        {
            retFlag = 1U;
            retVal = (int32_t)(-1);
            transaction->status=SPI_TRANSFER_FAILED;
        }
        else
        {
            remaining = count;
            while(remaining > 0U)
            {
                /* Wait indirect write SRAM fifo level below watermark */
                if (OSPI_waitWriteSramLvl((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                          &sramLevel) != (int32_t)0U)
                {
                    retFlag = 1U;
                    retVal = (int32_t)(-1);
                    break;
                }

                wrBytes = (CSL_OSPI_SRAM_PARTITION_WR - sramLevel) * CSL_OSPI_FIFO_WIDTH;
                wrBytes = (wrBytes > remaining) ? remaining : wrBytes;

                /* Write data to FIFO */
                CSL_ospiWriteFifoData(hwAttrs->dataAddr, pSrc, wrBytes);

                pSrc += wrBytes;
                remaining -= wrBytes;
            }

            if(retFlag == 0U)
            {
                if (OSPI_waitIndWriteComplete((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)) != (int32_t)0U)
                {
                    retFlag = 1U;
                    retVal = (int32_t)(-1);
                }
            }
        }
    }

    if(retFlag == 1U)
    {
        transaction->status=SPI_TRANSFER_FAILED;
        CSL_ospiIndWriteCancel((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));
    }
    return (retVal);
}

static int32_t OSPI_dac_xfer_mode_write_v0(SPI_Handle handle,
                                           const SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint8_t               *pSrc;         /* Source address */
    uint32_t               offset;       /* OSPI flash offset address */
    uint32_t               i;
    uint8_t               *pDst;         /* Destination address */
    uint32_t               size;
    uint32_t               remainSize;
    int32_t                retVal = 0;
    uint32_t               wrWord;
    uint32_t               wrByte;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32_t)((uintptr_t)transaction->arg); /* OSPI Flash offset address to write */
    pSrc = (uint8_t *)transaction->txBuf;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    /* Disable PHY pipeline mode */
    CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

#ifdef SPI_DMA_ENABLE
    if (hwAttrs->dmaEnable == (bool)true)
    {
        OSPI_dmaTransfer(handle, transaction);
    }
    else
#endif
    {
        pDst = (uint8_t *)(hwAttrs->dataAddr + offset);
        remainSize = (uint32_t)transaction->count & 3U;
        size = (uint32_t)transaction->count - remainSize;
        /* Transfer the data in 32-bit size */
        for (i = 0U; i < size; i += 4U)
        {
            wrWord = CSL_REG32_RD(pSrc + i);
            CSL_REG32_WR(pDst + i, wrWord);
            if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT))
            {
                retVal = (int32_t)(0);
            }
            else
            {
                retVal = (int32_t)(-1);
            }
        }
        if (retVal == (int32_t)(0))
        {
            /* Transfer the remaining data in 8-bit size */
            for (i = 0; i < remainSize; i++)
            {
                wrByte = CSL_REG8_RD(pSrc + size + i);
                CSL_REG8_WR(pDst + size + i, wrByte);
                if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT))
                {
                    retVal = 0;
                }
                else
                {
                    retVal = (int32_t)(-1);
                }
            }
        }
    }
    return (retVal);
}

static int32_t OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                             const uint8_t                *cmdBuf,
                             uint32_t                      cmdLen,
                             const uint8_t                *txBuf,
                             uint32_t                      txLen)
{
    (void)CSL_ospiCmdWrite(pRegs, cmdBuf, cmdLen, txBuf, txLen);
    return (OSPI_flashExecCmd(pRegs));
}

static int32_t OSPI_cmd_mode_write_v0(SPI_Handle handle,
                                      const SPI_Transaction *transaction)
{
    OSPI_v0_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    uint8_t               *txBuf;
    uint32_t               dataLen;
    uint32_t               cmdLen;
    int32_t                retVal = 0;

    txBuf = (uint8_t *)transaction->txBuf;
    dataLen = (uint32_t)((uintptr_t)transaction->arg);
    cmdLen = (uint32_t)transaction->count - dataLen;
    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    if (dataLen != 0U)
    {
        retVal = (OSPI_cmdWrite((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                 txBuf,
                                 cmdLen,
                                 &txBuf[cmdLen],
                                 dataLen));
    }
    else
    {
        retVal = (OSPI_cmdWrite((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                 txBuf,
                                 cmdLen,
                                 NULL,
                                 0));
    }
    return (retVal);
}


static int32_t OSPI_write_v0(SPI_Handle handle, SPI_Transaction *transaction)
{
    OSPI_v0_Object  *object;
    int32_t          retVal = (int32_t)(-1);

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_v0_Object *)handle->object;

    if((uint32_t)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
    {
        retVal = (OSPI_ind_xfer_mode_write_v0(handle, transaction));
    }
    else if((uint32_t)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
    {
        retVal = (OSPI_dac_xfer_mode_write_v0(handle, transaction));
    }
    else if((uint32_t)OSPI_OPER_MODE_CFG == object->ospiMode)
    {
        retVal = (OSPI_cmd_mode_write_v0(handle, transaction));
    }
    else
    {
        transaction->status=SPI_TRANSFER_CANCELED;
    }
    return (retVal);
}


/*
 *  ======== OSPI_transfer_v0 ========
 */
static bool OSPI_transfer_v0(SPI_Handle handle, SPI_Transaction *transaction)
{
    bool                   ret = (bool)false; /* return value */
    OSPI_v0_HwAttrs const *hwAttrs;     /* OSPI hardware attributes */
    OSPI_v0_Object        *object;      /* OSPI object */
    uintptr_t              key;
    int32_t                xferRet;

    /* Check if anything needs to be written or read */
    if ((handle != NULL) && (transaction != NULL) && (0U != (uint32_t)transaction->count))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_v0_Object *)handle->object;
        hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

        /* Check if a transfer is in progress */
        key = SPI_osalHardwareIntDisable();
        if (object->transaction != NULL)
        {
            SPI_osalHardwareIntRestore(key);
            /* Transfer is in progress */
            transaction->status = SPI_TRANSFER_CANCELED;
        }
        else
        {
            /* Save the pointer to the transaction */
            object->transaction = transaction;

            /* Acquire the lock for this particular I2C handle */
            (void)SPI_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

            /* Book keeping of transmit and receive buffers. */
            object->writeBufIdx = (uint8_t *)transaction->txBuf;
            object->writeCountIdx = (uint32_t)transaction->count;
            object->readBufIdx =  (uint8_t *)transaction->rxBuf;
            object->readCountIdx = (uint32_t)transaction->count;

             /*
             * OSPI_primeTransfer_v0 is a longer process and
             * protection is needed from the OSPI interrupt
             */
            if ((uint32_t)SPI_OPER_MODE_POLLING != object->intrPollMode)
            {
                SPI_osalHardwareIntrEnable((int32_t)hwAttrs->intrNum, (int32_t)hwAttrs->eventId);
            }

            xferRet = OSPI_primeTransfer_v0(handle, transaction);
            SPI_osalHardwareIntRestore(key);

            if (xferRet == 0)
            {
                if (object->intrPollMode == (uint32_t)SPI_OPER_MODE_BLOCKING)
                {
                    ret = (bool)true;
                    if (object->ospiMode == (uint32_t)OSPI_OPER_MODE_IND_XFER)
                    {
                        /* In indirect transfer mode, wait for the lock
                           posted form the word completion interrupt */
                        (void)SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
                    }
#ifdef SPI_DMA_ENABLE
                    if ((object->ospiMode == (uint32_t)OSPI_OPER_MODE_DAC_XFER) && (hwAttrs->dmaEnable == (bool)true))
                    {
                        /* in direct transfer mode with DMA enabled, wait for the lock
                           posted form the word completion interrupt */
                        (void)SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
                        if((uint32_t)SPI_TRANSACTION_TYPE_WRITE == object->transactionType)
                        {
                            ret = OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT);
                        }
                    }
#endif
                    /* transfer is completed and semaphore is posted. */
                }
                else
                {
                    /* Always return true if in Asynchronous mode */
                    ret = (bool)true;
                }
                transaction->status = SPI_TRANSFER_COMPLETED;
                /* Release the lock for this particular SPI handle */

                (void)SPI_osalPostLock(object->mutex);
            }
            else
            {
                transaction->status=SPI_TRANSFER_FAILED;
            }

            if (object->intrPollMode != (uint32_t)SPI_OPER_MODE_CALLBACK)
            {
                object->transaction = NULL;
            }
        }
    }
    else
    {
        if (transaction != NULL)
        {
            transaction->status = SPI_TRANSFER_CANCELED;
        }
    }

    /* Return the number of bytes transferred by the I2C */
    return (ret);
}

/*
 *  ======== OSPI_transferCallback_v0 ========
 */
static void OSPI_transferCallback_v0(SPI_Handle handle, SPI_Transaction *msg)
{
    OSPI_v0_Object        *object;  /* OSPI object */

    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (OSPI_v0_Object *)handle->object;

        /* Indicate transfer complete */
        (void)SPI_osalPostLock(object->transferComplete);
        msg = msg;
    }

}

static int32_t OSPI_configDdr(SPI_Handle handle, uint32_t cmd, uint32_t addr, uint32_t data);
static int32_t OSPI_configDdr(SPI_Handle handle, uint32_t cmd, uint32_t addr, uint32_t data)
{
    OSPI_v0_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    int32_t                retVal;

    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    CSL_ospiFlashStig((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), cmd, addr, data);
    retVal = OSPI_flashExecCmd((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));
    if (retVal == 0)
    {
        if (hwAttrs->dacEnable)
        {
            CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
        }
        else
        {
            CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
        }

        /* Enable DTR protocol */
        if (hwAttrs->dtrEnable == (bool)true)
        {
            CSL_ospiDtrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
        }
        else
        {
            CSL_ospiDtrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
        }
    }

    return (retVal);
}

static int32_t OSPI_enableXip (SPI_Handle handle, uint32_t cmd, uint32_t addr, uint32_t data)
{
    OSPI_v0_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    int32_t                retVal;

    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    /* Disable Direct Access Controller */
    CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

    /* Configure Flash Command Control Register to issue VCR write to FLASH memory to enable/disable XIP mode */
    CSL_ospiFlashStig((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), cmd, addr, data);
    retVal = OSPI_flashExecCmd((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr));
    if (retVal == 0)
    {
        OSPI_delay(OSPI_XIP_SETUP_DELAY);

        /* Clear the XIP mode bits in the Mode Bit Configuration Register. */
        CSL_ospiSetModeBits((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), 0x00);

        /* Enable the local controllers XIP mode */
        CSL_ospiXipEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
    }

    /* Re-enable the Direct Access Controller */
    CSL_ospiDacEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
    return (retVal);
}

/*
 *  ======== OSPI_control_v0 ========
 */
static int32_t OSPI_control_v0(SPI_Handle handle, uint32_t cmd, const void *arg)
{
    OSPI_v0_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    OSPI_v0_Object        *object;  /* OSPI object */
    int32_t                retVal = SPI_STATUS_ERROR;
    const uint32_t        *ctrlData = (const uint32_t *)arg;
    uint32_t               nvcrCmd;
    uint32_t               addr;
    uint32_t               data;

    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (OSPI_v0_Object *)handle->object;
        hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

        switch (cmd)
        {
            case SPI_V0_CMD_XFER_OPCODE:
            {
                object->transferCmd = *ctrlData;
                ctrlData++;
                CSL_ospiConfigRead((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                   object->transferCmd,
                                   object->xferLines,
                                   object->rdDummyClks);
                object->transferCmd = *ctrlData;
                ctrlData++;
                CSL_ospiWriteSetup((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                                   object->transferCmd,
                                   object->xferLines);
                object->rdStatusCmd = *ctrlData;
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_XFER_MODE_RW:
            {
                object->transactionType = *ctrlData;
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_SET_CFG_MODE:
            {
                object->ospiMode = (uint32_t)OSPI_OPER_MODE_CFG;
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_SET_XFER_MODE:
            {
                if (hwAttrs->dacEnable)
                {
                    object->ospiMode = (uint32_t)OSPI_OPER_MODE_DAC_XFER;
                }
                else
                {
                    object->ospiMode = (uint32_t)OSPI_OPER_MODE_IND_XFER;
                }
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_SET_XFER_LINES:
            {
                object->xferLines = *ctrlData;
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_RD_DUMMY_CLKS:
            {
                object->rdDummyClks = *ctrlData;
                retVal = SPI_STATUS_SUCCESS;
                break;
            }

            case SPI_V0_CMD_CFG_PHY:
            {
                if (hwAttrs->phyEnable == (bool)true)
                {
#if !defined(j721e_sim)
                    OSPI_configPhy(handle, arg);
#endif
                    retVal = SPI_STATUS_SUCCESS;
                }
                else
                {
                    retVal = SPI_STATUS_ERROR;
                }
                break;
            }

            case SPI_V0_CMD_ENABLE_DDR:
            case SPI_V0_CMD_ENABLE_SDR:
            {
                nvcrCmd = *ctrlData;
                ctrlData++;
                addr   = *ctrlData;
                ctrlData++;
                data   = *ctrlData;
                retVal = OSPI_configDdr(handle, nvcrCmd, addr, data);
                break;
            }

            case SPI_V0_CMD_CFG_XIP:
            {
                if (hwAttrs->xipEnable == (bool)true) {
                    nvcrCmd = *ctrlData;
                    ctrlData++;
                    addr = *ctrlData;
                    ctrlData++;
                    data = *ctrlData;

                    (void)OSPI_enableXip(handle, nvcrCmd , addr, data);
                }
                /* Enable PHY pipeline mode for read */
                CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);
                break;
            }

            default:
                retVal = SPI_STATUS_UNDEFINEDCMD;
            break;
        }
    }

    return retVal;
}


/*
 *  ======== OSPI_transferCancel_v0 ========
 */
static void OSPI_transferCancel_v0(SPI_Handle handle)
{
    (void)handle;
    return;
}
