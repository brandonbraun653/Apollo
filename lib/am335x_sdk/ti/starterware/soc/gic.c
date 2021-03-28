/**
 *  \file   gic.c
 *
 *  \brief  This file implements the GIC related API's.
 *
 *  Architecture of GIC: The GIC has one interrupt distributor which receives the
 *  interrupts from external devices and based on the configuration it passes to
 *  the CPU interface. The GIC has one CPU interface per CPU. The CPU interface
 *  base address is aliased, so that same address can be used to program from
 *  different CPU's. The CPU interface takes the interrupts send by distributor
 *  and sends the interrupts to CPU. The interrupts are grouped as,
 *
 *       0    - 15   -> Software Generated Interrupts
 *       16   - 31   -> Private Peripheral Interrupts
 *       32   - 1019 -> Shared Peripheral Interrupts
 *       1020 - 1023 -> Reserved
 *
 *  Interrupts 0-31 are private to each CPU and the registers to configure
 *  them are banked for each CPU.
 *
 *  GIC is capable of handling secure and non secure interrupts, which can be
 *  configured with the API's. It also supports SMP (Symmetric Multi Processing),
 *  but the current implementation doesn't support this..
 *
 *  For more info on GIC, please refer GIC architecture Specification.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "interrupt.h"
#include "hw_types.h"
#include "gic.h"
#include "hw_gic_distributor.h"
#include "hw_gic_cpu.h"
#include "error.h"
#include "cpu.h"
#include "console_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Macro to get mask for set-enable and clear-enable register bits */
#define GIC_DISTR_SET_CLR_MASK(intrNum)      (0x1 << ((intrNum) % 32))

#define GIC_DISTR_INT_CONF_MASK(intrNum)     (0x11 << ((intrNum) % 16))
#define GIC_DISTR_INT_CONF_SHIFT(intrNum)    ((intrNum) % 16)

#define GIC_CPU_INTF_MIN_PRI_ALL             ((GIC_CPU_INTF_MIN_PRI) ||       \
                                              (GIC_CPU_INTF_MIN_PRI << 8) ||  \
                                              (GIC_CPU_INTF_MIN_PRI << 16) || \
                                              (GIC_CPU_INTF_MIN_PRI << 24))

#define GIC_DISTR_DISABLE_INTR               (0xFFFFFFFF)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                         Function Declarations                              */
/* ========================================================================== */

void INTCCommonIntrHandler(void);

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static void IntDefaultHandler(uint32_t intrId, uint32_t cpuId,
                                                         void* pUserParam);
static void InitGicData(void);
static void InitGicDist(void);
static void InitGicCpu(uint32_t isCpuSecure);
static intrSupport_t isIntrSupported(uint32_t intrNum);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Array of function pointers to hold call back functions for Interrupt
 *         handlers. This list will be used for calling the call back functions
 *         of interrupts.
 */
static void (*pIntrHandlers[GIC_MAX_INTR_NO])(uint32_t intrId,
                                         uint32_t cpuId, void* pUserParam);

/** \brief Array to hold the user parameters passed during interrupt
 *         registration. The same will be passed to the corresponding interrupt
 *         handlers.
 */
static void* pUserParameter[GIC_MAX_INTR_NO];

/** \brief Counter to hold the number of spurious interrupt occurred. */
static uint32_t spuriousIntrCnt = 0;

/** \brief GIC data object. In multiprocessor system this variable should to
 *         be placed in shared memory area.
 */
static gicData_t    gicData;

/** \brief Flag to indicate if the interrupt controller is already 
           initialized. */
static uint32_t isIntcInitialized = FALSE;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * \brief   Initialize GIC controller.
 *            -   Initialize CPU interface and distributor bases
 *            -   Initialize distributor and CPU intf sub-modules
 **/
int32_t INTCInit(uint32_t isCpuSecure)
{
    int32_t status = S_PASS;
    gicData_t *gicInst = &gicData;
    
    if(FALSE == isIntcInitialized)
    {
        /* Set the base address of distributor and CPU intf sub-modules */
        gicInst->gicConfig.distBasePtr          = GicDistBaseGet();
        gicInst->gicConfig.cpuIntfBasePtr       = GicCpuIntfBaseGet();
        /* Set binary point register */
        gicInst->gicConfig.nonSecureBinaryPoint = GicNsBinaryPointGet();

        #if SMP_ENABLED
        /* Per CPU offset - This is needed for systems where multiple GIC's are
           integrated.
        */
        #endif

        /* Initialize GIC instance */
        InitGicData();

        /*
            If secure extension is supported configure the secure parameters as required.
            The values used here are default config values.
        */
        if ((TRUE == isCpuSecure) && (gicInst->isSecExtnSupp))
        {
            gicInst->secureConfig.secureBinaryPoint  = 0;
            gicInst->secureConfig.isSecBpForNonSec   = 0;
            gicInst->secureConfig.coreIntSel         = INTC_ARM_FIQ_MASK;
            gicInst->secureConfig.ackNonSecIntr      = 0;
            gicInst->secureConfig.enableNonSecurIntr = 0;
        }

        /*  Initialize distributor sub-module */
        InitGicDist();

        /*  Initialize CPU Interface sub-module */
        InitGicCpu(isCpuSecure);
        isIntcInitialized = TRUE;
    }
    return status;
}


int32_t INTCConfigIntr(uint32_t intrNum, intcIntrParams_t *pIntrParams,
                                                        uint32_t isCpuSecure)
{
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;
    uint32_t trigType = 0;
    uint32_t intrSecConf;
    intrSupport_t isIntrSupp;
    int32_t status = S_PASS;
#if SMP_ENABLED
    uint8_t procTarget = 0;
#endif

    /* Validate the parameters. SGI can't be configured */
    if ((intrNum > GIC_MAX_INTR_NO) ||
              (pIntrParams->priority > GIC_CPU_INTF_MIN_PRI) ||
              (pIntrParams->pFnIntrHandler == NULL) ||
              /* Priority value is not given in the levels supported */
              (pIntrParams->priority % gicInst->noPriorityStep != 0))
        status = E_INVALID_PARAM;

    /* Check if GIC supports security extension when CPU makes secure access */
    if (TRUE == isCpuSecure)
    {
        if (!gicInst->isSecExtnSupp)
            status = E_INVALID_OPERATION;
    }

#if SMP_ENABLED
    /* TODO: Add spin lock before further configurations */
#endif

    /* Check if this interrupt is supported */
    isIntrSupp = isIntrSupported(intrNum);
    if (GIC_INTR_NOT_SUPP == isIntrSupp)
        status = E_INTR_NOT_SUPP;

    /* Disable the interrupt before configuring. Disabling SGI interrupts is
       implementation defined. But if it is RAZ/WI, still the below code will
       hold good. This simplifies the software implementation.
    */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDICER(intrNum/32),
                                GIC_DISTR_SET_CLR_MASK(intrNum));

    /* Configure the interrupt as secure or non-secure */
    intrSecConf = HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDISR(intrNum/32));
    if (TRUE == pIntrParams->isIntrSecure)
        intrSecConf &= ~GIC_DISTR_SET_CLR_MASK(intrNum);
    else
        intrSecConf |= GIC_DISTR_SET_CLR_MASK(intrNum);

    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDISR(intrNum/32)), intrSecConf);

    /* Configure trigger type. SGI interrupts are read-only, PPI interrupts
       configurability is implementation defined.
    */
    /* Accept active-high, level-sensitive interrupts */
    if ( ((intrNum >= 16) && (intrNum < 32) && (isPpiTriggerConfigurable())) ||
                                    ((intrNum >= 32) && (intrNum < 1024)))
    {
        trigType = HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDICFR(intrNum/16));
        trigType &= ~GIC_DISTR_INT_CONF_MASK(intrNum);
        trigType |= pIntrParams->triggerType <<
                                             GIC_DISTR_INT_CONF_SHIFT(intrNum);

        HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDICFR(intrNum/16), trigType);
    }

    /* Set interrupt priority */
    HW_WR_REG8((distBaseAddr + GIC_DIST_PRIORITY_REG_B(intrNum)),
                                                        pIntrParams->priority);

#if SMP_ENABLED
    /* Set target processor which should receive this interrupt */
    procTarget = HW_RD_REG8(distBaseAddr + GIC_DIST_PROC_TARGET_REG_B(intrNum))
                                                     | pIntrParams->targetCpu;
    HW_WR_REG8(distBaseAddr + GIC_DIST_PROC_TARGET_REG_B(intrNum), procTarget);
#endif

    /* Register interrupt handler */
    pIntrHandlers[intrNum] = pIntrParams->pFnIntrHandler;
    pUserParameter[intrNum] = pIntrParams->pUserParam;

    /* Enable the interrupt (unmask). Disabling SGI interrupts is implementation
       defined. But if it is RAZ/WI, still the below code will hold good. This
       will simplify the software implementation.
    */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32),
                                            GIC_DISTR_SET_CLR_MASK(intrNum));

#if SMP_ENABLED
    /* TODO: Add spin unlock after all the configurations. Needed only for SMP */
#endif

    /* Enable interrupt in CPU. Enable IRQ and FIQ in Secure mode, and only
       IRQ in Non-Secure mode. */
    if (TRUE == isCpuSecure)
        CPUIntrEnable(INTC_ARM_IRQ_FIQ_MASK);
    else
        CPUIntrEnable(INTC_ARM_IRQ_MASK);

    return status;
}

int32_t INTCEnableIntr(uint32_t intrNum)
{
    gicData_t *gicInst = NULL;
    uint32_t distBaseAddr = 0;
    int32_t status = S_PASS;

    if (GIC_INTR_NOT_SUPP == isIntrSupported(intrNum))
        status = E_INTR_NOT_SUPP;

    gicInst = &gicData;
    distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    /*  Disable the interrupt */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32),
                                        GIC_DISTR_SET_CLR_MASK(intrNum));
    return status;
}

int32_t INTCDisableIntr(uint32_t intrNum)
{
    gicData_t *gicInst = NULL;
    uint32_t distBaseAddr = 0;
    int32_t status = S_PASS;

    if (GIC_INTR_NOT_SUPP == isIntrSupported(intrNum))
        status = E_INTR_NOT_SUPP;

    gicInst = &gicData;
    distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    /*  Disable the interrupt */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDICER(intrNum/32),
                                        GIC_DISTR_SET_CLR_MASK(intrNum));
    return status;
}

int32_t INTCEnableCpuIntr(uint32_t intrType)
{
    int32_t status = S_PASS;
    if ((INTC_ARM_IRQ_MASK == intrType) || (INTC_ARM_FIQ_MASK == intrType) ||
                                         (INTC_ARM_IRQ_FIQ_MASK == intrType))
    {
        CPUIntrEnable(intrType);
    }
    else
    {
        status = E_INVALID_PARAM;
    }
    return status;
}

uint32_t INTCDisableCpuIntr(void)
{
    return CPUIntrDisable();
}


/**
 * \brief   In the case of GIC, the normal interrupts need not be cleared,
 *          they will be cleared once the interrupts is taken. But for software
 *          interrupts, user need to call this API to clear the interrupt.
 **/
int32_t INTCClearIntr(uint32_t intrNum)
{
    intrSupport_t isIntrSupp;
    int32_t status = S_PASS;
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    /* Check if this interrupt is supported */
    isIntrSupp = isIntrSupported(intrNum);
    if (GIC_INTR_NOT_SUPP == isIntrSupp)
        status = E_INTR_NOT_SUPP;

    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDICPR(intrNum/32)),
                                                    (0x1 << (intrNum % 32)));

    return status;
}


int32_t INTCTriggerSWIntr(uint32_t intrNum)
{
    intrSupport_t isIntrSupp;
    int32_t status = S_PASS;
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    /* Check if this interrupt is supported */
    isIntrSupp = isIntrSupported(intrNum);
    if (GIC_INTR_NOT_SUPP == isIntrSupp)
        status = E_INTR_NOT_SUPP;

    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDISPR(intrNum/32)),
                                                    (0x1 << (intrNum % 32)));

    return status;
}


int32_t INTCTriggerIpcIntr(uint32_t intrNum, uint32_t cpuId)
{
    uint32_t sgiVal = 0;
    int32_t status = S_PASS;
    gicData_t *gicInst = NULL;
    uint32_t distBaseAddr = 0;

    /* Valid interrupt numbers are 0-15 */
    if (intrNum > 15)
        status = E_INVALID_PARAM;

    gicInst = &gicData;
    distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    sgiVal = (
        (GIC_SGI_TARGET_LIST << GIC_DISTR_ICDSGIR_TARGET_LIST_FILTER_SHIFT) |
        (cpuId << GIC_DISTR_ICDSGIR_CPU_TARGET_LIST_SHIFT) |
        (GIC_SGI_SATT_NON_SECURE << GIC_DISTR_ICDSGIR_SATT_SHIFT) |
        (intrNum << GIC_DISTR_ICDSGIR_SGI_INTID_SHIFT)
             );

    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDSGIR, sgiVal);

    return status;
}


int32_t INTCSaveContext(void)
{
    /* TODO */
    return 0;
}

int32_t INTCRestoreContext(void)
{
    /* TODO */
    return 0;
}

/**
 * \brief   This API is the common interrupt handler. On any interrupt this
 *          handler is called which will resolve and call the corresponding
 *          handler. At the end of interrupt handling, the EOI register is
 *          updated, so that each interrupt handler need not write to EOI.
 *
 *  Note:   The below method of calling common handler from IRQ/FIQ vector and
 *          then calling the specific interrupt handler involves function
 *          calling overhead. Since the processor will be running at higher
 *          frequencies the overhead is assumed to be negligible. Instead the
 *          specific interrupt handler can be called from IRQ/FIQ vector if the
 *          application requires lesser interrupt latency. But this will make
 *          the IRQ/FIQ vector tied to specific intr Controller, effectively
 *          reducing the portability of IRQ/FIQ vector code.
 *
 * \param   None
 *
 * \return  None
 **/
void INTCCommonIntrHandler(void)
{
    gicData_t *gicInst = &gicData;
    uint32_t cpuIntfBaseAddr = (uint32_t)gicInst->gicConfig.cpuIntfBasePtr;

    /*
        Security considerations need to be taken care by the application. If
        the security state of the CPU not matches with the active interrupt
        type special interrupt numbers 1022/1023 will be returned. It is the
        responsibility of the application to handle these interrupts.
    */
    uint32_t intrAckVal = HW_RD_REG32(cpuIntfBaseAddr + GIC_CPU_ICCIAR);
    uint32_t activeIntrId = intrAckVal & GIC_CPU_ICCIAR_ACK_INTID_MASK;
    uint32_t cpuId = (intrAckVal & GIC_CPU_ICCIAR_SOURCE_CPUID_MASK) >>
                            GIC_CPU_ICCIAR_SOURCE_CPUID_SHIFT;

    /* Save the current threshold value in stack */
    uint32_t prevPriMask = HW_RD_REG32(cpuIntfBaseAddr + GIC_CPU_ICCPMR);

    /*
        Get the active IRQ priority and set this priority as the threshold value,
        so that only interrupts with higher priority can interrupt the CPU when
        the current interrupt us being serviced.
    */
    HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCPMR),
                            HW_RD_REG32(cpuIntfBaseAddr + GIC_CPU_ICCRPR));

    /*
     * Enable IRQ and switch to system mode. Interrupt Service Routines will
     * execute in System Mode, so that nested interrupts can be handled.
     * Save user mode LR.
     */
    asm("    push    {r7}\n\t"
        "    mrs     r7, CPSR\n\t"
        "    orr     r7, r7, #0x1F\n\t"
        "    bic     r7, r7, #0x80\n\t"
        "    msr     CPSR, r7\n\t"
        "    STMFD   r13!, {r14}");

    /* Call the respective interrupt handler call back function */
    pIntrHandlers[activeIntrId](activeIntrId, cpuId,
                                                pUserParameter[activeIntrId]);

    /*
     * Disable IRQ and change back to IRQ mode.
     * Restore user mode LR.
     */
    asm("    LDMFD    r13!, {r14}\n\t"
        "    CPSID    i, 0x12\n\t"
        "    pop      {r7}");

    /* End of Interrupt - inform the CPU interface that ISR is completed */
    HW_WR_REG32(cpuIntfBaseAddr + GIC_CPU_ICCEOIR, intrAckVal);

    /* Reload original priority mask value */
    HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCPMR), prevPriMask);
}


/* -------------------------------------------------------------------------- */
/*                       Internal Function Definitions                        */
/* -------------------------------------------------------------------------- */

 /**
 * \brief   The Default Interrupt Handler.
 *          This is the default interrupt handler for all interrupts. The control
 *          would reach here if the interrupt is not configured. So to bring to
 *          users attention a message will be printed and wait infinitely.
 *
 * \param   intrId    Interrupt number which is active currently
 * \param   cpuId     CPU ID of the processor which generated the SGI (Software
 *                    Generated Interrupt). This is valid only in multi-proc
 *                    environment (SMP).
 *
 * \return  None
 *
 **/
static void IntDefaultHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    /* Keeping the print under a macro to avoid console utils dependency.
    ** To enable the print define the macro.
    */
    #ifndef DEBUG_PRINT
    /* TODO: Can be updated to print interrupt number also. */
    CONSOLEUtilsPuts("\r\nDefault Interrupt Handler: Unregistered interrupt occurred");
    #endif

    /* Increment spurious interrupt counter */
    spuriousIntrCnt++;
}


/**
 * \brief   Initialize GIC data object with information from implementation.
 *            -   Max Interrupts supported (DIST_CTR)
 *            -   Max Interrupts CPU interface supported
 *            -   Is secure extension supported
 *            -   Number of Lockable SPI interrupts
 *            -   Initialize default interrupt handlers for all interrupt ID's
 *
 * \param   None
 * \return  None
 *
 **/
static void InitGicData(void)
{
    uint32_t gicDistIcType = 0;
    uint32_t maskedValue = 0;
    uint32_t intrNum = 0;
    uint32_t PriorityStep = 0;
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    gicDistIcType = HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDICTR);

    /*  Get the number of interrupt lines supported */
    maskedValue = gicDistIcType & GIC_DISTR_ICDICTR_SPI_LINE_NUMBER_MASK;
    /*  From the mapping get the exact number of interrupts supported */
    maskedValue = (maskedValue + 1) * 32;
    /*  Check for max interrupts */
    if (maskedValue > 1020)
        maskedValue = 1020;
    gicInst->maxValidIntr = maskedValue;

    /* Get the number of CPU interfaces implemented */
    maskedValue = ((gicDistIcType & GIC_DISTR_ICDICTR_CPU_NUMBER_MASK) >>
                             GIC_DISTR_ICDICTR_CPU_NUMBER_SHIFT) + 1;
    /* Check for max no of CPU interface */
    if (maskedValue > GIC_MAX_CPU_NO)
        maskedValue = GIC_MAX_CPU_NO;
    gicInst->noCpuIntf = maskedValue;

    /* Check if Secure extn is supported by GIC */
    maskedValue = (gicDistIcType & GIC_DISTR_ICDICTR_DOMAIN_MASK) >>
                                GIC_DISTR_ICDICTR_DOMAIN_SHIFT;
    gicInst->isSecExtnSupp = maskedValue;

    /*
       Get the number of lockable SPI interrupts. If secure extn is not supported
       this value is NA
    */
    if (!gicInst->isSecExtnSupp)
    {
       gicInst->maxLockableSpi = 0;
    }
    else
    {
        /* If Secure extn is supported get the number of lockable SPI interrupts */
        gicInst->maxLockableSpi =
            (gicDistIcType & GIC_DISTR_ICDICTR_LSPI_MASK) >>
                                GIC_DISTR_ICDICTR_LSPI_SHIFT;
    }

    /* Find the priority levels implemented */
    for(intrNum = 0; intrNum < gicInst->maxValidIntr; intrNum++)
    {
        if (isIntrSupported(intrNum))
        {
            HW_WR_REG8((distBaseAddr + GIC_DIST_PRIORITY_REG_B(intrNum)), 0xFF);
            PriorityStep = HW_RD_REG8(distBaseAddr +
                            GIC_DIST_PRIORITY_REG_B(intrNum));

            /* Extract the priority level */
            gicInst->noPriorityStep = ((~PriorityStep) & 0x0F) + 1;
            break;
        }
    }

    /* Register the default handler for all interrupts */
    for(intrNum = 0; intrNum < gicInst->maxValidIntr; intrNum++)
    {
        pIntrHandlers[intrNum] = IntDefaultHandler;
        pUserParameter[intrNum] = 0;
    }

    /*
       Register handlers for interrupt ID's 1020-1023. GIC will implement these
       interrupts irrespective of the number of interrupts supported in the device.
    */
    for(intrNum = 1020; intrNum < 1024; intrNum++)
    {
        pIntrHandlers[intrNum] = IntDefaultHandler;
        pUserParameter[intrNum] = 0;
    }
}


/**
 * \brief   This function initializes the GIC Distributor sub-module
 *              - Disable the module
 *              - Configure all the SPI interrupts to
 *                  - set the priority of all SPI interrupts to lowest
 *                  - disable all the SPI interrupts
 *              - Enable the module
 *
 * \param   None
 * \return  None
 *
 **/
static void InitGicDist(void)
{
    gicData_t *gicInst = &gicData;
    uint32_t maxValidIntr = gicInst->maxValidIntr;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;
    uint32_t intrNum = 0;

    /*  Disable distributor sub-module */
    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDDCR), 0);

    /*  Initialize all SPI interrupts */

    /*  Configure priority on all SPI interrupts to the lowest priority */
    for (intrNum = 32; intrNum < maxValidIntr; intrNum += 4)
        HW_WR_REG32((distBaseAddr + GIC_DIST_PRIORITY_REG_B(intrNum)),
                                    GIC_CPU_INTF_MIN_PRI_ALL);

    /*  Disable all SPI interrupts */
    for (intrNum = 32; intrNum < maxValidIntr; intrNum += 32)
        HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDICER(intrNum / 32)),
                                        GIC_DISTR_DISABLE_INTR);

    /*  Enable distributor sub-module */
    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDDCR),
                            GIC_DISTR_ICDDCR_INTERRUPT_IN_EN_MASK);

}


/**
 * \brief   This function initializes the GIC CPU interface sub-module
 *              - Disable the SGI and PPI interrupts
 *              - Configure the priority of PPI and SGI interrupts
 *              - Configure the priority mask value to the lowest
 *              - Enable CPU interface to signal the interrupt
 *
 * \param   None
 * \return  None
 *
 **/
static void InitGicCpu(uint32_t isCpuSecure)
{
    uint32_t intrNum = 0;
    uint32_t ctrlConfigval = 0;
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;
    uint32_t cpuIntfBaseAddr = (uint32_t)gicInst->gicConfig.cpuIntfBasePtr;
    tGicSecConfig *secureConfig = &gicInst->secureConfig;

    /* Configure the priority of PPI and SGI interrupts (for primary GIC only) */
    /* Disable both SGI and PPI interrupts. Ability to disable SGI interrupts
       is implementation defined. But if it is RAZ/WI, still the below code
       will hold good. This will simplify the software implementation. */
    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDICER(0)), GIC_DISTR_DISABLE_INTR);
    for (intrNum = 0; intrNum < 32; intrNum += 4)
        HW_WR_REG32((distBaseAddr + GIC_DIST_PRIORITY_REG_B(intrNum)),
                    GIC_DISTR_DISABLE_INTR);

    /*
        Configure the priority mask to lowest value, so that all the priorities
        can be used. Based on the application need this can be modified apprioriately.
    */
    HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCPMR), GIC_CPU_INTF_MIN_PRI);

    /* Priority group configuration - Binary point register */
    if ((gicInst->isSecExtnSupp) && (isCpuSecure))
    {
        /* Secure BPR */
        HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCBPR),
                       secureConfig->secureBinaryPoint);
        /* Non-Secure BPR - Write to alias register in secure mode */
        HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCABPR),
                       gicInst->gicConfig.nonSecureBinaryPoint);
    }
    else
    {
        /* Non-Secure BPR */
        HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCBPR),
                       gicInst->gicConfig.nonSecureBinaryPoint);
    }

    /*
    *  Secure configurations.
    *  Note: Make sure the CPU is in secure state when configuring secure
    *  registers, otherwise you may get an abort.
    */
    if ((NULL != secureConfig) && (gicInst->isSecExtnSupp) && isCpuSecure)
    {
        /* Core interrupt selection (FIQ/IRQ) for secure interrupts */
        ctrlConfigval = (
            (secureConfig->isSecBpForNonSec << GIC_CPU_ICCICR_SBPR_SHIFT) |
            (secureConfig->coreIntSel << GIC_CPU_ICCICR_FIQEN_SHIFT) |
            (secureConfig->ackNonSecIntr << GIC_CPU_ICCICR_ACKCTL_SHIFT));
        /* Enable Secure interrupts in Secure mode */
        ctrlConfigval |= GIC_CPU_ICCICR_ENABLES_MASK;
        /* Enable NS interrupts in Secure mode */
        if (secureConfig->enableNonSecurIntr)
            ctrlConfigval |= GIC_CPU_ICCICR_ENABLENS_MASK;
    }
    else
    {
        /* Enable NS interrupts in Non-secure mode */
        ctrlConfigval = GIC_CPU_ICCICR_NS_ENABLE_MASK;
    }

    /* Enable CPU interface to signal the interrupt */
    HW_WR_REG32((cpuIntfBaseAddr + GIC_CPU_ICCICR), ctrlConfigval);
}

/**
 * \brief   This API checks if the interrupt is supported.
 *          GIC doesn't need to implement the interrupts in continous range.
 *          So each interrupt should be checked if it is supported.
 *          It also checks if the interrupt is permanently enabled.
 *
 *          If the processor implements the Security Extensions, Secure software
 *          determines which interrupts are visible to Non-secure software.
 *          So in such systems secure init must happen before NS configurations.
 *
 * \param   intrNum      - Interrupt number
 *
 * \return  intrSupport_t - return if the interrupt is supported
 **/
static intrSupport_t isIntrSupported(uint32_t intrNum)
{
    gicData_t *gicInst = &gicData;
    uint32_t distBaseAddr = (uint32_t)gicInst->gicConfig.distBasePtr;

    intrSupport_t intrSuppResult = GIC_INTR_NOT_SUPP;
    uint32_t prevEnableConfig = 0;
    uint32_t prevCtrlConfig = 0;

    if (intrNum >= gicInst->maxValidIntr)
        return E_INTR_NOT_SUPP;

    /* Disable forwarding of interrupts in distributor */
    prevCtrlConfig = HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDDCR);
    prevCtrlConfig &= ~GIC_DISTR_ICDDCR_INTERRUPT_IN_EN_MASK;
    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDDCR), prevCtrlConfig);

    /* Check if an interrupt is Supported or Not */
    prevEnableConfig = HW_RD_REG32(distBaseAddr +
                            GIC_DISTR_ICDISER(intrNum/32));
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32),
                                GIC_DISTR_SET_CLR_MASK(intrNum));
    if (HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32)) &&
                                GIC_DISTR_SET_CLR_MASK(intrNum))
    {
        intrSuppResult = GIC_INTR_SUPP;

        /*  Check if the interrupt is permanently supported */
        HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDICER(intrNum/32),
                                GIC_DISTR_SET_CLR_MASK(intrNum));
        if (HW_RD_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32)) &&
                                GIC_DISTR_SET_CLR_MASK(intrNum))
        {
            intrSuppResult = GIC_INTR_SUPP_ENABLED_ALWAYS;
        }
    }
    else
    {
        intrSuppResult = E_INTR_NOT_SUPP;
    }

    /* Clear all the interrupts in this register */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDICER(intrNum/32), 0xFFFFFFFF);
    /* Revert the original enable config, as it was while entering this
       function */
    HW_WR_REG32(distBaseAddr + GIC_DISTR_ICDISER(intrNum/32), prevEnableConfig);

    /* Enable forwarding of interrupts in distributor */
    HW_WR_REG32((distBaseAddr + GIC_DISTR_ICDDCR),
                       prevCtrlConfig | GIC_DISTR_ICDDCR_INTERRUPT_IN_EN_MASK);
    return intrSuppResult;
}
