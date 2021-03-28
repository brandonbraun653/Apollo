/**
 *  \file   j7200/I2C_soc.c
 *
 *  \brief  J7200 SoC specific I2C hardware attributes.
 *
 *   This file contains the hardware attributes of I2C peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <string.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_clec.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/sciclient/sciclient.h>

#define I2C_INPUT_CLK        (96000000U)

/* DMSC SYSFW invalid I2C device ID */
#define I2C_TISCI_INVALID_DEV_ID       ((uint16_t)0xFFFFU)

/* CLEC input event # offset for GIC SPI */
#define I2C_CLEC_GIC_SPI_IN_EVT_OFFSET (1024U - 32U)

/* DMSC SYSFW C66x destination host int # for I2C0 */
#define I2C_TISCI_C66X_DST_HOST_IRQ0   (60U)

/* C7x INTC int # for I2C0 */
#define I2C_C7X_IRQ0                   (30U)

static int32_t I2C_configSocIntrPath(const void *pHwAttrs, bool setIntrPath);

/* I2C configuration structure */
I2C_HwAttrs i2cInitCfg[I2C_HWIP_MAX_CNT] =
{
    {
#if defined (BUILD_MPU)
        /* default configuration for I2C instance and MPU core on Main domain*/
        (uint32_t)CSL_I2C0_CFG_BASE,        /* baseAddr */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C0_POINTRPEND_0,  /* intNum */
        0,                                  /* eventId */
#endif
#if defined (BUILD_MCU)
        /*
         * default configuration for I2C instances and R5 cores on MCU domain
         * I2C_socInit() is called during initialization to change the default
         * configurations to use Main Domain's I2C instances if R5 is running
         * on Main domain
         */
        (uint32_t)CSL_MCU_I2C0_CFG_BASE,    /* baseAddr */
        CSLR_MCU_R5FSS0_CORE0_INTR_MCU_I2C0_POINTRPEND_0,
        0,                                  /* eventId */
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C0_CFG_BASE,       /* baseAddr */
        I2C_C7X_IRQ0,                      /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C0_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            /* default own slave addresses */
            0x70, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C1_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C1_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        (uint32_t)CSL_MCU_I2C1_CFG_BASE,
        CSLR_MCU_R5FSS0_CORE0_INTR_MCU_I2C1_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C1_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 1,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C1_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x71, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C2_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C2_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        0,
        0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C2_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 2,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C2_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x72, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C3_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C3_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        0,
        0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C3_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 3,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C3_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x73, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C4_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C4_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        0,
        0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C4_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 4,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C4_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x74, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C5_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C5_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        0,
        0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C5_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 5,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C5_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x75, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
    {
#if defined (BUILD_MPU)
        (uint32_t)CSL_I2C6_CFG_BASE,
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C6_POINTRPEND_0,
        0,
#endif
#if defined (BUILD_MCU)
        0,
        0,
        0,
#endif
#if defined (BUILD_C7X_1)
        /* default configuration for I2C instance and DSP core on Main domain*/
        (uint32_t)CSL_I2C6_CFG_BASE,        /* baseAddr */
        I2C_C7X_IRQ0 + 6,                   /* intNum */
        CSLR_COMPUTE_CLUSTER0_MSMC_1MB_GIC_SPI_I2C6_POINTRPEND_0 + I2C_CLEC_GIC_SPI_IN_EVT_OFFSET, /* eventId, input event # to CLEC */
#endif
        I2C_INPUT_CLK,
        (bool)true,
        {
            0x76, 0x0, 0x0, 0x0
        },
        I2C_configSocIntrPath
    },
};


/* I2C objects */
I2C_v1_Object I2cObjects[I2C_HWIP_MAX_CNT];


/* I2C configuration structure */
I2C_config_list I2C_config = {
    {
        &I2C_v1_FxnTable,
        &I2cObjects[0],
        &i2cInitCfg[0]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[1],
        &i2cInitCfg[1]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[2],
        &i2cInitCfg[2]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[3],
        &i2cInitCfg[3]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[4],
        &i2cInitCfg[4]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[5],
        &i2cInitCfg[5]
    },

    {
        &I2C_v1_FxnTable,
        &I2cObjects[6],
        &i2cInitCfg[6]
    },
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL}
};

/**
 * \brief  This API gets the SoC level of I2C intial configuration
 *
 * \param  index       I2C instance index.
 * \param  cfg       Pointer to I2C SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t I2C_socGetInitCfg(uint32_t index, I2C_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < I2C_HWIP_MAX_CNT)
    {
        *cfg = i2cInitCfg[index];
    }
    else
    {
        ret = (int32_t)(-1);
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of I2C intial configuration
 *
 * \param  index       I2C instance index.
 * \param  cfg       Pointer to I2C SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t I2C_socSetInitCfg(uint32_t index, const I2C_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < I2C_HWIP_MAX_CNT)
    {
        i2cInitCfg[index] = *cfg;
    }
    else
    {
        ret = (int32_t)(-1);
    }

    return ret;
}

#if defined (BUILD_MCU)
/**
 * \brief  This API update the default SoC level of configurations
 *         based on the core and domain
 *
 *         i2cInitCfg table configures MCU domain's I2C instances by
 *         default for R5, I2C_socInit() is called in I2C_init() to
 *         overwrite the defaut configurations with the configurations
 *         of Main domain's UART instances if R5 is on the Main domain
 *
 * \param  none
 *
 * \return none
 *
 */
void I2C_socInit(void);
void I2C_socInit(void)
{
    uint32_t         i;
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId != (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* Pulsar R5 core is on the Main domain */
        for (i = 0; i < I2C_HWIP_MAX_CNT; i++)
        {
            /* Configure the Main SS UART instances for Main SS Pulsar R5 */
            i2cInitCfg[i].baseAddr = (uint32_t)CSL_I2C0_CFG_BASE + (0x10000U * i);

            if (i < 2U)
            {
                /* Main domain's I2C0-1 are directly connected to the MAIN Pulsar VIMs */
                i2cInitCfg[i].intNum = CSLR_R5FSS0_CORE0_INTR_I2C0_POINTRPEND_0 + i;
            }
        }
    }
}
#endif

static int32_t I2C_configSocIntrPath(const void *pHwAttrs, bool setIntrPath)
{
   int32_t ret = I2C_STATUS_SUCCESS;

#if defined(BUILD_MCU)
    struct tisci_msg_rm_irq_set_req      rmIrqReq;
    struct tisci_msg_rm_irq_set_resp     rmIrqResp;
    struct tisci_msg_rm_irq_release_req  rmIrqRelease;
    uint16_t                             src_id;
    uint16_t                             src_index;
    uint16_t                             dst_id;
    CSL_ArmR5CPUInfo                     r5CpuInfo;
    int32_t                              retVal;
    I2C_HwAttrs const                   *hwAttrs = (I2C_HwAttrs const *)(pHwAttrs);

    if (hwAttrs->baseAddr == CSL_WKUP_I2C0_CFG_BASE)
    {
        /*
         * The interrupt path is established using the DMSC firmware
         * for I2C instance 0 on wakeup domin
         */
        src_id = TISCI_DEV_WKUP_I2C0;
        src_index = (uint16_t)hwAttrs->eventId;  /* set to 0 for non-event based interrupt */

        CSL_armR5GetCpuID(&r5CpuInfo);
        if (r5CpuInfo.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_1)
        {
            if(r5CpuInfo.cpuID == 0U)
            {
                dst_id = TISCI_DEV_R5FSS0_CORE0;
            }
            else
            {
                dst_id = TISCI_DEV_R5FSS0_CORE1;
            }
        }
        else if (r5CpuInfo.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_2)
        {
            if(r5CpuInfo.cpuID == 0U)
            {
                dst_id = TISCI_DEV_R5FSS1_CORE0;
            }
            else
            {
                dst_id = TISCI_DEV_R5FSS1_CORE1;
            }
        }
        else
        {
            ret = I2C_STATUS_ERROR;
        }

        if (ret == I2C_STATUS_SUCCESS)
        {
            if(setIntrPath)
            {
                (void)memset (&rmIrqReq, 0, sizeof(rmIrqReq));
                rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
                rmIrqReq.src_id = src_id;
                rmIrqReq.src_index = src_index;

                /* Set the destination interrupt */
                rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
                rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

                /* Set the destination based on the core */
                rmIrqReq.dst_id       = dst_id;
                rmIrqReq.dst_host_irq = (uint16_t)hwAttrs->intNum;
            }
            else
            {
                (void)memset (&rmIrqRelease,0,sizeof(rmIrqRelease));
                rmIrqRelease.secondary_host  = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
                rmIrqRelease.src_id = src_id;
                rmIrqRelease.src_index = src_index;

                /* Set the destination interrupt */
                rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
                rmIrqRelease.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

                /* Set the destination based on the core */
                rmIrqRelease.dst_id       = dst_id;
                rmIrqRelease.dst_host_irq = (uint16_t)hwAttrs->intNum;
            }

            /* Config event */
            if(setIntrPath)
            {
                retVal = Sciclient_rmIrqSet(
                            (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq,
                            &rmIrqResp,
                            SCICLIENT_SERVICE_WAIT_FOREVER);
             }
            else
            {
                retVal = Sciclient_rmIrqRelease(
                            (const struct tisci_msg_rm_irq_release_req *)&rmIrqRelease,
                             SCICLIENT_SERVICE_WAIT_FOREVER);
            }
            if ((int32_t)0 != retVal)
            {
               ret = I2C_STATUS_ERROR;
            }
        }
    }
#elif defined (BUILD_C7X_1)
    int32_t               retVal;
    I2C_HwAttrs const    *hwAttrs = (I2C_HwAttrs const *)(pHwAttrs);
    CSL_ClecEventConfig   cfgClec;
    CSL_CLEC_EVTRegs     *clecBaseAddr = (CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;

    /* Configure CLEC for I2C0 */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = TRUE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_CPU_ALL;
    cfgClec.extEvtNum         = 0;
    cfgClec.c7xEvtNum         = hwAttrs->intNum;
    retVal = CSL_clecConfigEvent(clecBaseAddr, hwAttrs->eventId, &cfgClec);
    if (retVal != CSL_PASS)
    {
        ret = I2C_STATUS_ERROR;
    }
#else
    pHwAttrs = pHwAttrs;
    setIntrPath = setIntrPath;
#endif

    return(ret);
}

