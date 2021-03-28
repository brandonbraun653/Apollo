/**
 *  \file   dmtimer.c
 *
 *  \brief  This file contains the device abstraction layer APIs for DMTimer.
 *          
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistribution of source code must retain the above copyright
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
#include "hw_types.h"

#include "dmtimer.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/**
* \brief Enumerates Values that can be used while checking status received from
*        function which returns posted write status.
*/
typedef enum dmtimerPostedWriteSts
{
    DMTIMER_POSTED_WRITE_STS_TMAR    = (DMTIMER_TWPS_W_PEND_TMAR_MASK),
    /**< Value used to check the write posted condition for TMAR register.*/
    DMTIMER_POSTED_WRITE_STS_TTGR    = (DMTIMER_TWPS_W_PEND_TTGR_MASK),
    /**< Value used to check the write posted condition for TTGR register.*/
    DMTIMER_POSTED_WRITE_STS_TLDR    = (DMTIMER_TWPS_W_PEND_TLDR_MASK),
    /**< Value used to check the write posted condition for TLDR register.*/
    DMTIMER_POSTED_WRITE_STS_TCRR    = (DMTIMER_TWPS_W_PEND_TCRR_MASK),
    /**< Value used to check the write posted condition for TCRR register.*/    
    DMTIMER_POSTED_WRITE_STS_TCLR    = (DMTIMER_TWPS_W_PEND_TCLR_MASK)
    /**< Value used to check the write posted condition for TCLR register.*/

}dmtimerPostedWriteSts_t;
/**
 * \brief   This macro will check for write POSTED status
 *
 * \param   reg - Register whose status has to be checked as defined by 
 *          # dmtimerPostedWriteSts_t      
 *          'reg' can be the following registers 
 *          DMTIMER_POSTED_WRITE_STS_TCLR - Timer Control register 
 *          DMTIMER_POSTED_WRITE_STS_TCRR - Timer Counter register 
 *          DMTIMER_POSTED_WRITE_STS_TLDR - Timer Load register 
 *          DMTIMER_POSTED_WRITE_STS_TTGR - Timer Trigger register 
 *          DMTIMER_POSTED_WRITE_STS_TMAR - Timer Match register 
 */
#define DMTIMER_WAIT_FOR_WRITE(baseAddr, reg)   \
    if(HW_RD_REG32(baseAddr + DMTIMER_TSICR) & DMTIMER_TSICR_POSTED_MASK)\
        while((reg & DMTIMERGetWritePostedStatus(baseAddr)));
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void DMTIMEREnable(uint32_t baseAddr, uint32_t enableDmtimer)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    if (TRUE == enableDmtimer)
    {
        /* Start the timer */
        HW_WR_FIELD32((baseAddr + DMTIMER_TCLR),
            DMTIMER_TCLR_ST,
            DMTIMER_TCLR_ST_START);
    }
    else
    {
        /* Stop the timer */
        HW_WR_FIELD32((baseAddr + DMTIMER_TCLR),
            DMTIMER_TCLR_ST,
            DMTIMER_TCLR_ST_STOP); 
    }    
}

void DMTIMERSetMode(uint32_t baseAddr, dmtimerMode_t modeCfg)
{
    uint32_t regVal = 0;
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    /* Clear the AR and CE field of TCLR */
    regVal = HW_RD_REG32(baseAddr + DMTIMER_TCLR);
    /* to clear the auto reload field - set the one shot mode*/
    HW_SET_FIELD(regVal, DMTIMER_TCLR_AR, DMTIMER_TCLR_AR_ONESHOT);
    HW_SET_FIELD(regVal, DMTIMER_TCLR_CE, DMTIMER_TCLR_CE_DISABLE);
    HW_WR_REG32((baseAddr + DMTIMER_TCLR), regVal);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    /* Set the timer mode in TCLR register */
    regVal = HW_RD_REG32(baseAddr + DMTIMER_TCLR);
    /* Now check the mode that has been sent as  the param  */
    /* this section can be optimized - but for a start this would do */
    switch (modeCfg)
    {
        /* case 1 : one shot with compare enabled */
        case DMTIMER_MODE_CFG_ONESHOT_CMP_ENABLE:
             HW_SET_FIELD(regVal, DMTIMER_TCLR_AR, DMTIMER_TCLR_AR_ONESHOT);
             HW_SET_FIELD(regVal, DMTIMER_TCLR_CE, DMTIMER_TCLR_CE_ENABLE);
             break;
         /* case 2 : one shot with compare disabled */
        case DMTIMER_MODE_CFG_ONESHOT_CMP_DISABLE:
             HW_SET_FIELD(regVal, DMTIMER_TCLR_AR, DMTIMER_TCLR_AR_ONESHOT);
             HW_SET_FIELD(regVal, DMTIMER_TCLR_CE, DMTIMER_TCLR_CE_DISABLE);
             break;
        /* case 3 : auto reload with compare enabled */
        case DMTIMER_MODE_CFG_AUTORLD_CMP_ENABLE:
             HW_SET_FIELD(regVal, DMTIMER_TCLR_AR, DMTIMER_TCLR_AR_AUTO);
             HW_SET_FIELD(regVal, DMTIMER_TCLR_CE, DMTIMER_TCLR_CE_ENABLE);
             break;
        /* case 4 - default: auto reload with compare disabled */
        default:
             HW_SET_FIELD(regVal, DMTIMER_TCLR_AR, DMTIMER_TCLR_AR_AUTO);
             HW_SET_FIELD(regVal, DMTIMER_TCLR_CE, DMTIMER_TCLR_CE_DISABLE);
             break;
    }
    HW_WR_REG32((baseAddr + DMTIMER_TCLR), regVal);
}

void DMTIMERPrescalerClkEnable(uint32_t baseAddr, uint32_t dividerRatio)
{
    uint32_t regVal = 0;
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    /* Clear the dividerRatio field of TCLR */
    regVal = HW_RD_REG32(baseAddr + DMTIMER_TCLR);
    /* this is a 3 bit field having no field definitions */
    regVal &= ~DMTIMER_TCLR_PTV_MASK;
    HW_WR_REG32((baseAddr + DMTIMER_TCLR), regVal);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR );

    /* Set the dividerRatio field and enable the pre-scaler clock */
    regVal = HW_RD_REG32(baseAddr + DMTIMER_TCLR);
    /* Set the prescaler enable bit */
    HW_SET_FIELD(regVal, DMTIMER_TCLR_PRE, DMTIMER_TCLR_PRE_ENABLE);
    /* Move the prescaler clock divider ratio */
    regVal |= (dividerRatio << DMTIMER_TCLR_PTV_SHIFT);
    HW_WR_REG32((baseAddr + DMTIMER_TCLR), regVal);

}

void DMTIMERPrescalerClkDisable(uint32_t baseAddr)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR );

    /* Disable Pre-scaler clock */
    HW_WR_FIELD32((baseAddr + DMTIMER_TCLR),
        DMTIMER_TCLR_PRE,
        DMTIMER_TCLR_PRE_DISABLE);
}

void DMTIMERSetCounterVal(uint32_t baseAddr, uint32_t counter)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr,DMTIMER_POSTED_WRITE_STS_TCRR );

    /* Set the counter value */
    HW_WR_REG32((baseAddr + DMTIMER_TCRR), counter);
}


uint32_t DMTIMERGetCounterVal(uint32_t baseAddr)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCRR);

    /* Read the counter value from TCRR */
    return (HW_RD_REG32(baseAddr + DMTIMER_TCRR));
}


void DMTIMERLoadReloadCount(uint32_t baseAddr, uint32_t reload)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TLDR);

    /* Load the register with the re-load value */
    HW_WR_REG32((baseAddr + DMTIMER_TLDR), reload);
}


uint32_t DMTIMERGetReloadCount(uint32_t baseAddr)
{
    /* Return the contents of TLDR */
    return (HW_RD_REG32(baseAddr + DMTIMER_TLDR));
}

void DMTIMERGpoConfig(uint32_t baseAddr, uint32_t gpoCfg)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    /* Clear the GPO_CFG field of TCLR */
    /* if the GPO_CFG field is cleared - PORGPOCFG drives 0 */
    HW_WR_FIELD32((baseAddr + DMTIMER_TCLR),
        DMTIMER_TCLR_GPO_CFG,
        DMTIMER_TCLR_GPO_CFG_DRIVE0);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    /* Write to the gpoCfg field of TCLR */
    /* Set the GPO_CFG field to whats passed as param */
    HW_WR_FIELD32((baseAddr + DMTIMER_TCLR), DMTIMER_TCLR_GPO_CFG, gpoCfg);

}

void DMTIMERSetCompareVal(uint32_t baseAddr, uint32_t compareVal)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TMAR);

    /* Write the compare value to TMAR */
    HW_WR_REG32((baseAddr + DMTIMER_TMAR), compareVal);
}

uint32_t DMTIMERGetCompareVal(uint32_t baseAddr)
{
    /* Return the TMAR value */
    return (HW_RD_REG32(baseAddr + DMTIMER_TMAR));
}

void DMTIMERIntrTrigger(uint32_t baseAddr, uint32_t intrMask)
{
    /* Trigger the events in IRQSTATUS_RAW register */
    HW_WR_REG32((baseAddr + DMTIMER_IRQSTS_RAW),(intrMask &
                                           (DMTIMER_INTR_MASK_MAT |
                                            DMTIMER_INTR_MASK_OVF |
                                            DMTIMER_INTR_MASK_TCAR)
                                            ));
}

uint32_t DMTIMERIntrRawStatus(uint32_t baseAddr)
{
    /* Return the status of IRQSTATUS_RAW register */
    return (HW_RD_REG32(baseAddr + DMTIMER_IRQSTS_RAW));
}

uint32_t DMTIMERIntrStatus(uint32_t baseAddr)
{
    /* Return the status of IRQSTATUS register */
    return (HW_RD_REG32(baseAddr + DMTIMER_IRQSTS));
}

void DMTIMERIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    /* Clear the interrupt status from IRQSTATUS register */
    HW_WR_REG32((baseAddr + DMTIMER_IRQSTS),(intrMask &
                                         (DMTIMER_INTR_MASK_TCAR|
                                          DMTIMER_INTR_MASK_OVF |
                                          DMTIMER_INTR_MASK_MAT)));
}

void DMTIMERIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    /* Enable the DMTimer interrupts represented by intrMask */
    HW_WR_REG32((baseAddr + DMTIMER_IRQEN_SET),(intrMask &
                                         (DMTIMER_INTR_MASK_TCAR |
                                          DMTIMER_INTR_MASK_OVF |
                                          DMTIMER_INTR_MASK_MAT)));
}

void DMTIMERIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    /* Disable the DMTimer interrupts represented by intrMask */
    HW_WR_REG32((baseAddr + DMTIMER_IRQEN_CLR),(intrMask &
                                         (DMTIMER_INTR_MASK_TCAR|
                                          DMTIMER_INTR_MASK_OVF |
                                          DMTIMER_INTR_MASK_MAT)));
}

void DMTIMERTriggerTcrrWrite(uint32_t baseAddr)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TTGR);

    /* Write a value to the register */
    HW_WR_REG32((baseAddr + DMTIMER_TTGR), DMTIMER_TTGR_VALUE_MASK);
}

uint32_t DMTIMERGetIntrEnableStatus(uint32_t baseAddr)
{
    /* Return the status of register IRQENABLE_SET */
    return ( HW_RD_REG32(baseAddr + DMTIMER_IRQEN_SET));
}

void DMTIMERResetEnable(uint32_t baseAddr, uint32_t enableReset)
{
    /* Clear the SFT field of TSICR */
    HW_WR_FIELD32((baseAddr + DMTIMER_TSICR),
        DMTIMER_TSICR_SFT,
        DMTIMER_TSICR_SFT_RESETDISABLE);

    /* Write the option sent by user to SFT field of TSICR */
    HW_WR_FIELD32((baseAddr + DMTIMER_TSICR), DMTIMER_TSICR_SFT, enableReset);
}

void DMTIMERReset(uint32_t baseAddr)
{
    /* Reset the DMTimer module */
    HW_WR_FIELD32((baseAddr + DMTIMER_TIOCP_CFG),
        DMTIMER_TIOCP_CFG_SOFTRESET,
        DMTIMER_TIOCP_CFG_SOFTRESET_INITIATE);

    /* Wait for reset to complete*/
    while(DMTIMER_TIOCP_CFG_SOFTRESET_ONGOING ==
        ((HW_RD_REG32(baseAddr + DMTIMER_TIOCP_CFG) &
          DMTIMER_TIOCP_CFG_SOFTRESET_MASK) >>
         DMTIMER_TIOCP_CFG_SOFTRESET_SHIFT));
}

void DMTIMERContextSave(uint32_t baseAddr, dmtimerContext_t *pContextPtr)
{
    pContextPtr->tldr = HW_RD_REG32(baseAddr + DMTIMER_TLDR);
    pContextPtr->tmar = HW_RD_REG32(baseAddr + DMTIMER_TMAR) ;
    pContextPtr->irqenableset = HW_RD_REG32(baseAddr + DMTIMER_IRQEN_SET);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCRR);

    pContextPtr->tcrr = HW_RD_REG32(baseAddr + DMTIMER_TCRR);
    pContextPtr->tclr = HW_RD_REG32(baseAddr + DMTIMER_TCLR);
}

void DMTIMERContextRestore(uint32_t baseAddr,  dmtimerContext_t *pContextPtr)
{
    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TLDR);

    HW_WR_REG32((baseAddr + DMTIMER_TLDR), pContextPtr->tldr);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TMAR);

    HW_WR_REG32((baseAddr + DMTIMER_TMAR), pContextPtr->tmar);
    HW_WR_REG32((baseAddr + DMTIMER_IRQEN_SET), pContextPtr->irqenableset);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCRR);

    HW_WR_REG32((baseAddr + DMTIMER_TCRR), pContextPtr->tcrr);

    /* Wait for previous write to complete */
    DMTIMER_WAIT_FOR_WRITE(baseAddr, DMTIMER_POSTED_WRITE_STS_TCLR);

    HW_WR_REG32((baseAddr + DMTIMER_TCLR), pContextPtr->tclr);
}

void DMTIMERPostedModeEnable(uint32_t baseAddr, uint32_t enablePostedMode)
{
    /* Clear the POSTED field of TSICR */
    HW_WR_FIELD32((baseAddr + DMTIMER_TSICR),
        DMTIMER_TSICR_POSTED,
        DMTIMER_TSICR_POSTED_INACTIVE);

    if (TRUE == enablePostedMode)
    {    
        /* Set posted mode as active in TSICR */
        HW_WR_FIELD32((baseAddr + DMTIMER_TSICR), DMTIMER_TSICR_POSTED, 
        DMTIMER_TSICR_POSTED_ACTIVE);
    }
    else
    {
        /* Set posted mode as inactive in TSICR */
        HW_WR_FIELD32((baseAddr + DMTIMER_TSICR), DMTIMER_TSICR_POSTED, 
        DMTIMER_TSICR_POSTED_INACTIVE);       
    }        
}

uint32_t DMTIMERGetWritePostedStatus(uint32_t baseAddr)
{
    /* Return the status of TWPS register */
    return (HW_RD_REG32(baseAddr + DMTIMER_TWPS));
}
