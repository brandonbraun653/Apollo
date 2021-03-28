/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_mcu_ctrl_mmr.h
*/
#ifndef CSLR_MCU_CTRL_MMR_H_
#define CSLR_MCU_CTRL_MMR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_MCU_CTRL_MMR_CFG0_REGS_BASE                                     (0x00000000U)


/**************************************************************************
* Hardware Region  : MMRs in region 0
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* PID register */
    volatile uint32_t MMR_CFG0;
    volatile uint32_t MMR_CFG1;
    volatile uint8_t  Resv_256[244];
    volatile uint32_t IPC_SET0;
    volatile uint32_t IPC_SET1;
    volatile uint8_t  Resv_288[24];
    volatile uint32_t IPC_SET8;
    volatile uint8_t  Resv_384[92];
    volatile uint32_t IPC_CLR0;
    volatile uint32_t IPC_CLR1;
    volatile uint8_t  Resv_416[24];
    volatile uint32_t IPC_CLR8;
    volatile uint8_t  Resv_512[92];
    volatile uint32_t MAC_ID0;
    volatile uint32_t MAC_ID1;
    volatile uint8_t  Resv_4104[3584];
    volatile uint32_t LOCK0_KICK0;               /*  - KICK0 component */
    volatile uint32_t LOCK0_KICK1;               /*  - KICK1 component */
    volatile uint32_t INTR_RAW_STATUS;           /* Interrupt Raw Status/Set Register */
    volatile uint32_t INTR_ENABLED_STATUS_CLEAR;   /* Interrupt Enabled Status/Clear register */
    volatile uint32_t INTR_ENABLE;               /* Interrupt Enable register */
    volatile uint32_t INTR_ENABLE_CLEAR;         /* Interrupt Enable Clear register */
    volatile uint32_t EOI;                       /* EOI register */
    volatile uint32_t FAULT_ADDRESS;             /* Fault Address register */
    volatile uint32_t FAULT_TYPE_STATUS;         /* Fault Type Status register */
    volatile uint32_t FAULT_ATTR_STATUS;         /* Fault Attribute Status register */
    volatile uint32_t FAULT_CLEAR;               /* Fault Clear register */
    volatile uint8_t  Resv_4352[204];
    volatile uint32_t CLAIMREG_P0_R0_READONLY;   /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R1_READONLY;   /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R2_READONLY;   /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R3_READONLY;   /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R4_READONLY;   /* Claim bits for Partition 0 */
    volatile uint8_t  Resv_8192[3820];
    volatile uint32_t PID_PROXY;                 /* PID register */
    volatile uint32_t MMR_CFG0_PROXY;
    volatile uint32_t MMR_CFG1_PROXY;
    volatile uint8_t  Resv_8448[244];
    volatile uint32_t IPC_SET0_PROXY;
    volatile uint32_t IPC_SET1_PROXY;
    volatile uint8_t  Resv_8480[24];
    volatile uint32_t IPC_SET8_PROXY;
    volatile uint8_t  Resv_8576[92];
    volatile uint32_t IPC_CLR0_PROXY;
    volatile uint32_t IPC_CLR1_PROXY;
    volatile uint8_t  Resv_8608[24];
    volatile uint32_t IPC_CLR8_PROXY;
    volatile uint8_t  Resv_8704[92];
    volatile uint32_t MAC_ID0_PROXY;
    volatile uint32_t MAC_ID1_PROXY;
    volatile uint8_t  Resv_12296[3584];
    volatile uint32_t LOCK0_KICK0_PROXY;         /*  - KICK0 component */
    volatile uint32_t LOCK0_KICK1_PROXY;         /*  - KICK1 component */
    volatile uint32_t INTR_RAW_STATUS_PROXY;     /* Interrupt Raw Status/Set Register */
    volatile uint32_t INTR_ENABLED_STATUS_CLEAR_PROXY;   /* Interrupt Enabled Status/Clear register */
    volatile uint32_t INTR_ENABLE_PROXY;         /* Interrupt Enable register */
    volatile uint32_t INTR_ENABLE_CLEAR_PROXY;   /* Interrupt Enable Clear register */
    volatile uint32_t EOI_PROXY;                 /* EOI register */
    volatile uint32_t FAULT_ADDRESS_PROXY;       /* Fault Address register */
    volatile uint32_t FAULT_TYPE_STATUS_PROXY;   /* Fault Type Status register */
    volatile uint32_t FAULT_ATTR_STATUS_PROXY;   /* Fault Attribute Status register */
    volatile uint32_t FAULT_CLEAR_PROXY;         /* Fault Clear register */
    volatile uint8_t  Resv_12544[204];
    volatile uint32_t CLAIMREG_P0_R0;            /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R1;            /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R2;            /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R3;            /* Claim bits for Partition 0 */
    volatile uint32_t CLAIMREG_P0_R4;            /* Claim bits for Partition 0 */
    volatile uint8_t  Resv_16432[3868];
    volatile uint32_t MSMC_CFG;
    volatile uint8_t  Resv_16448[12];
    volatile uint32_t MCU_ENET_CTRL;
    volatile uint8_t  Resv_16480[28];
    volatile uint32_t MCU_SPI1_CTRL;
    volatile uint8_t  Resv_16496[12];
    volatile uint32_t MCU_I3C0_CTRL0;
    volatile uint32_t MCU_I3C0_CTRL1;
    volatile uint32_t MCU_I3C1_CTRL0;
    volatile uint32_t MCU_I3C1_CTRL1;
    volatile uint32_t MCU_I2C0_CTRL;
    volatile uint8_t  Resv_16544[28];
    volatile uint32_t MCU_FSS_CTRL;
    volatile uint8_t  Resv_16560[12];
    volatile uint32_t MCU_ADC0_CTRL;
    volatile uint32_t MCU_ADC1_CTRL;
    volatile uint8_t  Resv_16896[328];
    volatile uint32_t MCU_TIMER0_CTRL;
    volatile uint32_t MCU_TIMER1_CTRL;
    volatile uint32_t MCU_TIMER2_CTRL;
    volatile uint32_t MCU_TIMER3_CTRL;
    volatile uint32_t MCU_TIMER4_CTRL;
    volatile uint32_t MCU_TIMER5_CTRL;
    volatile uint32_t MCU_TIMER6_CTRL;
    volatile uint32_t MCU_TIMER7_CTRL;
    volatile uint32_t MCU_TIMER8_CTRL;
    volatile uint32_t MCU_TIMER9_CTRL;
    volatile uint8_t  Resv_17024[88];
    volatile uint32_t MCU_TIMERIO0_CTRL;
    volatile uint32_t MCU_TIMERIO1_CTRL;
    volatile uint32_t MCU_TIMERIO2_CTRL;
    volatile uint32_t MCU_TIMERIO3_CTRL;
    volatile uint32_t MCU_TIMERIO4_CTRL;
    volatile uint32_t MCU_TIMERIO5_CTRL;
    volatile uint32_t MCU_TIMERIO6_CTRL;
    volatile uint32_t MCU_TIMERIO7_CTRL;
    volatile uint32_t MCU_TIMERIO8_CTRL;
    volatile uint32_t MCU_TIMERIO9_CTRL;
    volatile uint8_t  Resv_20488[3424];
    volatile uint32_t LOCK1_KICK0;               /*  - KICK0 component */
    volatile uint32_t LOCK1_KICK1;               /*  - KICK1 component */
    volatile uint8_t  Resv_20736[240];
    volatile uint32_t CLAIMREG_P1_R0_READONLY;   /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R1_READONLY;   /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R2_READONLY;   /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R3_READONLY;   /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R4_READONLY;   /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R5_READONLY;   /* Claim bits for Partition 1 */
    volatile uint8_t  Resv_24624[3864];
    volatile uint32_t MSMC_CFG_PROXY;
    volatile uint8_t  Resv_24640[12];
    volatile uint32_t MCU_ENET_CTRL_PROXY;
    volatile uint8_t  Resv_24672[28];
    volatile uint32_t MCU_SPI1_CTRL_PROXY;
    volatile uint8_t  Resv_24688[12];
    volatile uint32_t MCU_I3C0_CTRL0_PROXY;
    volatile uint32_t MCU_I3C0_CTRL1_PROXY;
    volatile uint32_t MCU_I3C1_CTRL0_PROXY;
    volatile uint32_t MCU_I3C1_CTRL1_PROXY;
    volatile uint32_t MCU_I2C0_CTRL_PROXY;
    volatile uint8_t  Resv_24736[28];
    volatile uint32_t MCU_FSS_CTRL_PROXY;
    volatile uint8_t  Resv_24752[12];
    volatile uint32_t MCU_ADC0_CTRL_PROXY;
    volatile uint32_t MCU_ADC1_CTRL_PROXY;
    volatile uint8_t  Resv_25088[328];
    volatile uint32_t MCU_TIMER0_CTRL_PROXY;
    volatile uint32_t MCU_TIMER1_CTRL_PROXY;
    volatile uint32_t MCU_TIMER2_CTRL_PROXY;
    volatile uint32_t MCU_TIMER3_CTRL_PROXY;
    volatile uint32_t MCU_TIMER4_CTRL_PROXY;
    volatile uint32_t MCU_TIMER5_CTRL_PROXY;
    volatile uint32_t MCU_TIMER6_CTRL_PROXY;
    volatile uint32_t MCU_TIMER7_CTRL_PROXY;
    volatile uint32_t MCU_TIMER8_CTRL_PROXY;
    volatile uint32_t MCU_TIMER9_CTRL_PROXY;
    volatile uint8_t  Resv_25216[88];
    volatile uint32_t MCU_TIMERIO0_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO1_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO2_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO3_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO4_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO5_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO6_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO7_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO8_CTRL_PROXY;
    volatile uint32_t MCU_TIMERIO9_CTRL_PROXY;
    volatile uint8_t  Resv_28680[3424];
    volatile uint32_t LOCK1_KICK0_PROXY;         /*  - KICK0 component */
    volatile uint32_t LOCK1_KICK1_PROXY;         /*  - KICK1 component */
    volatile uint8_t  Resv_28928[240];
    volatile uint32_t CLAIMREG_P1_R0;            /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R1;            /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R2;            /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R3;            /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R4;            /* Claim bits for Partition 1 */
    volatile uint32_t CLAIMREG_P1_R5;            /* Claim bits for Partition 1 */
    volatile uint8_t  Resv_32784[3832];
    volatile uint32_t MCU_CLKOUT0_CTRL;
    volatile uint8_t  Resv_32792[4];
    volatile uint32_t MCU_EFUSE_CLKSEL;
    volatile uint8_t  Resv_32800[4];
    volatile uint32_t MCU_MCAN0_CLKSEL;
    volatile uint32_t MCU_MCAN1_CLKSEL;
    volatile uint8_t  Resv_32816[8];
    volatile uint32_t MCU_OSPI0_CLKSEL;
    volatile uint32_t MCU_OSPI1_CLKSEL;
    volatile uint8_t  Resv_32832[8];
    volatile uint32_t MCU_ADC0_CLKSEL;
    volatile uint32_t MCU_ADC1_CLKSEL;
    volatile uint8_t  Resv_32848[8];
    volatile uint32_t MCU_ENET_CLKSEL;
    volatile uint8_t  Resv_32896[44];
    volatile uint32_t MCU_R5_CORE0_CLKSEL;
    volatile uint32_t MCU_R5_CORE1_CLKSEL;
    volatile uint8_t  Resv_33024[120];
    volatile uint32_t MCU_TIMER0_CLKSEL;
    volatile uint32_t MCU_TIMER1_CLKSEL;
    volatile uint32_t MCU_TIMER2_CLKSEL;
    volatile uint32_t MCU_TIMER3_CLKSEL;
    volatile uint32_t MCU_TIMER4_CLKSEL;
    volatile uint32_t MCU_TIMER5_CLKSEL;
    volatile uint32_t MCU_TIMER6_CLKSEL;
    volatile uint32_t MCU_TIMER7_CLKSEL;
    volatile uint32_t MCU_TIMER8_CLKSEL;
    volatile uint32_t MCU_TIMER9_CLKSEL;
    volatile uint8_t  Resv_33152[88];
    volatile uint32_t MCU_RTI0_CLKSEL;
    volatile uint32_t MCU_RTI1_CLKSEL;
    volatile uint8_t  Resv_33216[56];
    volatile uint32_t MCU_USART_CLKSEL;
    volatile uint8_t  Resv_36872[3652];
    volatile uint32_t LOCK2_KICK0;               /*  - KICK0 component */
    volatile uint32_t LOCK2_KICK1;               /*  - KICK1 component */
    volatile uint8_t  Resv_37120[240];
    volatile uint32_t CLAIMREG_P2_R0_READONLY;   /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R1_READONLY;   /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R2_READONLY;   /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R3_READONLY;   /* Claim bits for Partition 2 */
    volatile uint8_t  Resv_40976[3840];
    volatile uint32_t MCU_CLKOUT0_CTRL_PROXY;
    volatile uint8_t  Resv_40984[4];
    volatile uint32_t MCU_EFUSE_CLKSEL_PROXY;
    volatile uint8_t  Resv_40992[4];
    volatile uint32_t MCU_MCAN0_CLKSEL_PROXY;
    volatile uint32_t MCU_MCAN1_CLKSEL_PROXY;
    volatile uint8_t  Resv_41008[8];
    volatile uint32_t MCU_OSPI0_CLKSEL_PROXY;
    volatile uint32_t MCU_OSPI1_CLKSEL_PROXY;
    volatile uint8_t  Resv_41024[8];
    volatile uint32_t MCU_ADC0_CLKSEL_PROXY;
    volatile uint32_t MCU_ADC1_CLKSEL_PROXY;
    volatile uint8_t  Resv_41040[8];
    volatile uint32_t MCU_ENET_CLKSEL_PROXY;
    volatile uint8_t  Resv_41088[44];
    volatile uint32_t MCU_R5_CORE0_CLKSEL_PROXY;
    volatile uint32_t MCU_R5_CORE1_CLKSEL_PROXY;
    volatile uint8_t  Resv_41216[120];
    volatile uint32_t MCU_TIMER0_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER1_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER2_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER3_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER4_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER5_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER6_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER7_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER8_CLKSEL_PROXY;
    volatile uint32_t MCU_TIMER9_CLKSEL_PROXY;
    volatile uint8_t  Resv_41344[88];
    volatile uint32_t MCU_RTI0_CLKSEL_PROXY;
    volatile uint32_t MCU_RTI1_CLKSEL_PROXY;
    volatile uint8_t  Resv_41408[56];
    volatile uint32_t MCU_USART_CLKSEL_PROXY;
    volatile uint8_t  Resv_45064[3652];
    volatile uint32_t LOCK2_KICK0_PROXY;         /*  - KICK0 component */
    volatile uint32_t LOCK2_KICK1_PROXY;         /*  - KICK1 component */
    volatile uint8_t  Resv_45312[240];
    volatile uint32_t CLAIMREG_P2_R0;            /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R1;            /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R2;            /* Claim bits for Partition 2 */
    volatile uint32_t CLAIMREG_P2_R3;            /* Claim bits for Partition 2 */
    volatile uint8_t  Resv_49152[3824];
    volatile uint32_t MCU_LBIST_CTRL;
    volatile uint32_t MCU_LBIST_PATCOUNT;
    volatile uint32_t MCU_LBIST_SEED0;
    volatile uint32_t MCU_LBIST_SEED1;
    volatile uint32_t MCU_LBIST_SPARE0;
    volatile uint32_t MCU_LBIST_SPARE1;
    volatile uint32_t MCU_LBIST_STAT;
    volatile uint32_t MCU_LBIST_MISR;
    volatile uint8_t  Resv_49792[608];
    volatile uint32_t MCU_LBIST_SIG;
    volatile uint8_t  Resv_53256[3460];
    volatile uint32_t LOCK3_KICK0;               /*  - KICK0 component */
    volatile uint32_t LOCK3_KICK1;               /*  - KICK1 component */
    volatile uint8_t  Resv_53504[240];
    volatile uint32_t CLAIMREG_P3_R0_READONLY;   /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R1_READONLY;   /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R2_READONLY;   /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R3_READONLY;   /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R4_READONLY;   /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R5_READONLY;   /* Claim bits for Partition 3 */
    volatile uint8_t  Resv_57344[3816];
    volatile uint32_t MCU_LBIST_CTRL_PROXY;
    volatile uint32_t MCU_LBIST_PATCOUNT_PROXY;
    volatile uint32_t MCU_LBIST_SEED0_PROXY;
    volatile uint32_t MCU_LBIST_SEED1_PROXY;
    volatile uint32_t MCU_LBIST_SPARE0_PROXY;
    volatile uint32_t MCU_LBIST_SPARE1_PROXY;
    volatile uint32_t MCU_LBIST_STAT_PROXY;
    volatile uint32_t MCU_LBIST_MISR_PROXY;
    volatile uint8_t  Resv_57984[608];
    volatile uint32_t MCU_LBIST_SIG_PROXY;
    volatile uint8_t  Resv_61448[3460];
    volatile uint32_t LOCK3_KICK0_PROXY;         /*  - KICK0 component */
    volatile uint32_t LOCK3_KICK1_PROXY;         /*  - KICK1 component */
    volatile uint8_t  Resv_61696[240];
    volatile uint32_t CLAIMREG_P3_R0;            /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R1;            /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R2;            /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R3;            /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R4;            /* Claim bits for Partition 3 */
    volatile uint32_t CLAIMREG_P3_R5;            /* Claim bits for Partition 3 */
    volatile uint8_t  Resv_65536[3816];
    volatile uint32_t DV_REG0;
    volatile uint32_t DV_REG1;
    volatile uint32_t DV_REG2;
    volatile uint32_t DV_REG3;
    volatile uint32_t DV_REG4;
    volatile uint32_t DV_REG5;
    volatile uint32_t DV_REG6;
    volatile uint32_t DV_REG7;
    volatile uint8_t  Resv_66048[480];
    volatile uint32_t DV_REG0_SET;
    volatile uint32_t DV_REG1_SET;
    volatile uint32_t DV_REG2_SET;
    volatile uint32_t DV_REG3_SET;
    volatile uint8_t  Resv_66304[240];
    volatile uint32_t DV_REG0_CLR;
    volatile uint32_t DV_REG1_CLR;
    volatile uint32_t DV_REG2_CLR;
    volatile uint32_t DV_REG3_CLR;
    volatile uint8_t  Resv_69640[3320];
    volatile uint32_t LOCK4_KICK0;               /*  - KICK0 component */
    volatile uint32_t LOCK4_KICK1;               /*  - KICK1 component */
    volatile uint8_t  Resv_69888[240];
    volatile uint32_t CLAIMREG_P4_R0_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R1_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R2_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R3_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R4_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R5_READONLY;   /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R6_READONLY;   /* Claim bits for Partition 4 */
    volatile uint8_t  Resv_73728[3812];
    volatile uint32_t DV_REG0_PROXY;
    volatile uint32_t DV_REG1_PROXY;
    volatile uint32_t DV_REG2_PROXY;
    volatile uint32_t DV_REG3_PROXY;
    volatile uint32_t DV_REG4_PROXY;
    volatile uint32_t DV_REG5_PROXY;
    volatile uint32_t DV_REG6_PROXY;
    volatile uint32_t DV_REG7_PROXY;
    volatile uint8_t  Resv_74240[480];
    volatile uint32_t DV_REG0_SET_PROXY;
    volatile uint32_t DV_REG1_SET_PROXY;
    volatile uint32_t DV_REG2_SET_PROXY;
    volatile uint32_t DV_REG3_SET_PROXY;
    volatile uint8_t  Resv_74496[240];
    volatile uint32_t DV_REG0_CLR_PROXY;
    volatile uint32_t DV_REG1_CLR_PROXY;
    volatile uint32_t DV_REG2_CLR_PROXY;
    volatile uint32_t DV_REG3_CLR_PROXY;
    volatile uint8_t  Resv_77832[3320];
    volatile uint32_t LOCK4_KICK0_PROXY;         /*  - KICK0 component */
    volatile uint32_t LOCK4_KICK1_PROXY;         /*  - KICK1 component */
    volatile uint8_t  Resv_78080[240];
    volatile uint32_t CLAIMREG_P4_R0;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R1;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R2;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R3;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R4;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R5;            /* Claim bits for Partition 4 */
    volatile uint32_t CLAIMREG_P4_R6;            /* Claim bits for Partition 4 */
} CSL_mcu_ctrl_mmr_cfg0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MCU_CTRL_MMR_CFG0_PID                                           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0                                      (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1                                      (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0                                      (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1                                      (0x00000104U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8                                      (0x00000120U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0                                      (0x00000180U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1                                      (0x00000184U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8                                      (0x000001A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0                                       (0x00000200U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1                                       (0x00000204U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0                                   (0x00001008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1                                   (0x0000100CU)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS                               (0x00001010U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR                     (0x00001014U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE                                   (0x00001018U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR                             (0x0000101CU)
#define CSL_MCU_CTRL_MMR_CFG0_EOI                                           (0x00001020U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS                                 (0x00001024U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS                             (0x00001028U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS                             (0x0000102CU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR                                   (0x00001030U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_READONLY                       (0x00001100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_READONLY                       (0x00001104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_READONLY                       (0x00001108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_READONLY                       (0x0000110CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_READONLY                       (0x00001110U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY                                     (0x00002000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY                                (0x00002004U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY                                (0x00002008U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY                                (0x00002100U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY                                (0x00002104U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY                                (0x00002120U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY                                (0x00002180U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY                                (0x00002184U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY                                (0x000021A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_PROXY                                 (0x00002200U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_PROXY                                 (0x00002204U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_PROXY                             (0x00003008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_PROXY                             (0x0000300CU)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY                         (0x00003010U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY               (0x00003014U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY                             (0x00003018U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY                       (0x0000301CU)
#define CSL_MCU_CTRL_MMR_CFG0_EOI_PROXY                                     (0x00003020U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_PROXY                           (0x00003024U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY                       (0x00003028U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY                       (0x0000302CU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_PROXY                             (0x00003030U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0                                (0x00003100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1                                (0x00003104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2                                (0x00003108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3                                (0x0000310CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4                                (0x00003110U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG                                      (0x00004030U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL                                 (0x00004040U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL                                 (0x00004060U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0                                (0x00004070U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1                                (0x00004074U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0                                (0x00004078U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1                                (0x0000407CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL                                 (0x00004080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL                                  (0x000040A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL                                 (0x000040B0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL                                 (0x000040B4U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL                               (0x00004200U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL                               (0x00004204U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL                               (0x00004208U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL                               (0x0000420CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL                               (0x00004210U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL                               (0x00004214U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL                               (0x00004218U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL                               (0x0000421CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL                               (0x00004220U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL                               (0x00004224U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL                             (0x00004280U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL                             (0x00004284U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL                             (0x00004288U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL                             (0x0000428CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL                             (0x00004290U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL                             (0x00004294U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL                             (0x00004298U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL                             (0x0000429CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL                             (0x000042A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL                             (0x000042A4U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0                                   (0x00005008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1                                   (0x0000500CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_READONLY                       (0x00005100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_READONLY                       (0x00005104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_READONLY                       (0x00005108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_READONLY                       (0x0000510CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_READONLY                       (0x00005110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_READONLY                       (0x00005114U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY                                (0x00006030U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY                           (0x00006040U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_PROXY                           (0x00006060U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY                          (0x00006070U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY                          (0x00006074U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY                          (0x00006078U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY                          (0x0000607CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_PROXY                           (0x00006080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY                            (0x000060A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY                           (0x000060B0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY                           (0x000060B4U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_PROXY                         (0x00006200U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY                         (0x00006204U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_PROXY                         (0x00006208U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY                         (0x0000620CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_PROXY                         (0x00006210U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY                         (0x00006214U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_PROXY                         (0x00006218U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY                         (0x0000621CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_PROXY                         (0x00006220U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY                         (0x00006224U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_PROXY                       (0x00006280U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_PROXY                       (0x00006284U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_PROXY                       (0x00006288U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_PROXY                       (0x0000628CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_PROXY                       (0x00006290U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_PROXY                       (0x00006294U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_PROXY                       (0x00006298U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_PROXY                       (0x0000629CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_PROXY                       (0x000062A0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_PROXY                       (0x000062A4U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_PROXY                             (0x00007008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_PROXY                             (0x0000700CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0                                (0x00007100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1                                (0x00007104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2                                (0x00007108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3                                (0x0000710CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4                                (0x00007110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5                                (0x00007114U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL                              (0x00008010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL                              (0x00008018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL                              (0x00008020U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL                              (0x00008024U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL                              (0x00008030U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL                              (0x00008034U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL                               (0x00008040U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL                               (0x00008044U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL                               (0x00008050U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL                           (0x00008080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL                           (0x00008084U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL                             (0x00008100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL                             (0x00008104U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL                             (0x00008108U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL                             (0x0000810CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL                             (0x00008110U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL                             (0x00008114U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL                             (0x00008118U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL                             (0x0000811CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL                             (0x00008120U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL                             (0x00008124U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL                               (0x00008180U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL                               (0x00008184U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL                              (0x000081C0U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0                                   (0x00009008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1                                   (0x0000900CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_READONLY                       (0x00009100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_READONLY                       (0x00009104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_READONLY                       (0x00009108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_READONLY                       (0x0000910CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY                        (0x0000A010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_PROXY                        (0x0000A018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_PROXY                        (0x0000A020U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_PROXY                        (0x0000A024U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY                        (0x0000A030U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY                        (0x0000A034U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_PROXY                         (0x0000A040U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_PROXY                         (0x0000A044U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY                         (0x0000A050U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_PROXY                     (0x0000A080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_PROXY                     (0x0000A084U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_PROXY                       (0x0000A100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_PROXY                       (0x0000A104U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_PROXY                       (0x0000A108U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_PROXY                       (0x0000A10CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_PROXY                       (0x0000A110U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_PROXY                       (0x0000A114U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_PROXY                       (0x0000A118U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_PROXY                       (0x0000A11CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_PROXY                       (0x0000A120U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_PROXY                       (0x0000A124U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY                         (0x0000A180U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY                         (0x0000A184U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_PROXY                        (0x0000A1C0U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_PROXY                             (0x0000B008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_PROXY                             (0x0000B00CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0                                (0x0000B100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1                                (0x0000B104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2                                (0x0000B108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3                                (0x0000B10CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL                                (0x0000C000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT                            (0x0000C004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0                               (0x0000C008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1                               (0x0000C00CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0                              (0x0000C010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1                              (0x0000C014U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT                                (0x0000C018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR                                (0x0000C01CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG                                 (0x0000C280U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0                                   (0x0000D008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1                                   (0x0000D00CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_READONLY                       (0x0000D100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_READONLY                       (0x0000D104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_READONLY                       (0x0000D108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_READONLY                       (0x0000D10CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_READONLY                       (0x0000D110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_READONLY                       (0x0000D114U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY                          (0x0000E000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY                      (0x0000E004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PROXY                         (0x0000E008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PROXY                         (0x0000E00CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY                        (0x0000E010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_PROXY                        (0x0000E014U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY                          (0x0000E018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_PROXY                          (0x0000E01CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_PROXY                           (0x0000E280U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_PROXY                             (0x0000F008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_PROXY                             (0x0000F00CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0                                (0x0000F100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1                                (0x0000F104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2                                (0x0000F108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3                                (0x0000F10CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4                                (0x0000F110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5                                (0x0000F114U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0                                       (0x00010000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1                                       (0x00010004U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2                                       (0x00010008U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3                                       (0x0001000CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4                                       (0x00010010U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5                                       (0x00010014U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6                                       (0x00010018U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7                                       (0x0001001CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET                                   (0x00010200U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET                                   (0x00010204U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET                                   (0x00010208U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET                                   (0x0001020CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR                                   (0x00010300U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR                                   (0x00010304U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR                                   (0x00010308U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR                                   (0x0001030CU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0                                   (0x00011008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1                                   (0x0001100CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_READONLY                       (0x00011100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_READONLY                       (0x00011104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_READONLY                       (0x00011108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_READONLY                       (0x0001110CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_READONLY                       (0x00011110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_READONLY                       (0x00011114U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_READONLY                       (0x00011118U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_PROXY                                 (0x00012000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_PROXY                                 (0x00012004U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_PROXY                                 (0x00012008U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_PROXY                                 (0x0001200CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_PROXY                                 (0x00012010U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_PROXY                                 (0x00012014U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_PROXY                                 (0x00012018U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_PROXY                                 (0x0001201CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_PROXY                             (0x00012200U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_PROXY                             (0x00012204U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_PROXY                             (0x00012208U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_PROXY                             (0x0001220CU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_PROXY                             (0x00012300U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_PROXY                             (0x00012304U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_PROXY                             (0x00012308U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_PROXY                             (0x0001230CU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_PROXY                             (0x00013008U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_PROXY                             (0x0001300CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0                                (0x00013100U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1                                (0x00013104U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2                                (0x00013108U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3                                (0x0001310CU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4                                (0x00013110U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5                                (0x00013114U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6                                (0x00013118U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MINOR_MASK                            (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MINOR_SHIFT                           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MINOR_MAX                             (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_CUSTOM_MASK                           (0x000000C0U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_CUSTOM_SHIFT                          (0x00000006U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_CUSTOM_MAX                            (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MAJOR_MASK                            (0x00000700U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MAJOR_SHIFT                           (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MAJOR_MAX                             (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MISC_MASK                             (0x0000F800U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MISC_SHIFT                            (0x0000000BU)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MISC_MAX                              (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MSB16_MASK                            (0xFFFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MSB16_SHIFT                           (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PID_MSB16_MAX                             (0x0000FFFFU)

/* MMR_CFG0 */

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_SPEC_REV_MASK                        (0x0000FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_SPEC_REV_SHIFT                       (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_SPEC_REV_MAX                         (0x0000FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_CFG_REV_MASK                         (0xFFFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_CFG_REV_SHIFT                        (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_CFG_REV_MAX                          (0x0000FFFFU)

/* MMR_CFG1 */

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PARTITIONS_MASK                      (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PARTITIONS_SHIFT                     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PARTITIONS_MAX                       (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_EN_MASK                        (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_EN_SHIFT                       (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_EN_MAX                         (0x00000001U)

/* IPC_SET0 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SET_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SET_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SET_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SRC_SET_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SRC_SET_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_IPC_SRC_SET_MAX                      (0x0FFFFFFFU)

/* IPC_SET1 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SET_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SET_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SET_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SRC_SET_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SRC_SET_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_IPC_SRC_SET_MAX                      (0x0FFFFFFFU)

/* IPC_SET8 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SET_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SET_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SET_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SRC_SET_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SRC_SET_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_IPC_SRC_SET_MAX                      (0x0FFFFFFFU)

/* IPC_CLR0 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_CLR_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_CLR_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_CLR_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_SRC_CLR_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_SRC_CLR_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_IPC_SRC_CLR_MAX                      (0x0FFFFFFFU)

/* IPC_CLR1 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_CLR_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_CLR_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_CLR_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_SRC_CLR_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_SRC_CLR_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_IPC_SRC_CLR_MAX                      (0x0FFFFFFFU)

/* IPC_CLR8 */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_CLR_MASK                         (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_CLR_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_CLR_MAX                          (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_SRC_CLR_MASK                     (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_SRC_CLR_SHIFT                    (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_IPC_SRC_CLR_MAX                      (0x0FFFFFFFU)

/* MAC_ID0 */

#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_MACID_LO_MASK                         (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_MACID_LO_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_MACID_LO_MAX                          (0xFFFFFFFFU)

/* MAC_ID1 */

#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_MACID_HI_MASK                         (0x0000FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_MACID_HI_SHIFT                        (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_MACID_HI_MAX                          (0x0000FFFFU)

/* LOCK0_KICK0 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_LOCK0_KICK0_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_LOCK0_KICK0_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_LOCK0_KICK0_MAX                   (0xFFFFFFFFU)

/* LOCK0_KICK1 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_LOCK0_KICK1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_LOCK0_KICK1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_LOCK0_KICK1_MAX                   (0xFFFFFFFFU)

/* INTR_RAW_STATUS */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROT_ERR_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROT_ERR_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROT_ERR_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_ADDR_ERR_MASK                 (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_ADDR_ERR_SHIFT                (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_ADDR_ERR_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_KICK_ERR_MASK                 (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_KICK_ERR_SHIFT                (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_KICK_ERR_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ERR_MASK                (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ERR_SHIFT               (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ERR_MAX                 (0x00000001U)

/* INTR_ENABLED_STATUS_CLEAR */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_MASK (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_SHIFT (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_MASK (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_SHIFT (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_MASK (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_SHIFT (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_MAX (0x00000001U)

/* INTR_ENABLE */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROT_ERR_EN_MASK                  (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROT_ERR_EN_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROT_ERR_EN_MAX                   (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_ADDR_ERR_EN_MASK                  (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_ADDR_ERR_EN_SHIFT                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_ADDR_ERR_EN_MAX                   (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_KICK_ERR_EN_MASK                  (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_KICK_ERR_EN_SHIFT                 (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_KICK_ERR_EN_MAX                   (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ERR_EN_MASK                 (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ERR_EN_SHIFT                (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ERR_EN_MAX                  (0x00000001U)

/* INTR_ENABLE_CLEAR */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_MASK        (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_SHIFT       (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_MAX         (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_MASK        (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_SHIFT       (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_MAX         (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_MASK        (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_SHIFT       (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_MAX         (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_MASK       (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_SHIFT      (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_MAX        (0x00000001U)

/* EOI */

#define CSL_MCU_CTRL_MMR_CFG0_EOI_EOI_VECTOR_MASK                           (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_EOI_EOI_VECTOR_SHIFT                          (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_EOI_EOI_VECTOR_MAX                            (0x000000FFU)

/* FAULT_ADDRESS */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_FAULT_ADDR_MASK                 (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_FAULT_ADDR_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_FAULT_ADDR_MAX                  (0xFFFFFFFFU)

/* FAULT_TYPE_STATUS */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_TYPE_MASK             (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_TYPE_SHIFT            (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_TYPE_MAX              (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_NS_MASK               (0x00000040U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_NS_SHIFT              (0x00000006U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_FAULT_NS_MAX                (0x00000001U)

/* FAULT_ATTR_STATUS */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_PRIVID_MASK           (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_PRIVID_SHIFT          (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_PRIVID_MAX            (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_ROUTEID_MASK          (0x000FFF00U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_ROUTEID_SHIFT         (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_ROUTEID_MAX           (0x00000FFFU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_XID_MASK              (0xFFF00000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_XID_SHIFT             (0x00000014U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_FAULT_XID_MAX               (0x00000FFFU)

/* FAULT_CLEAR */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_FAULT_CLR_MASK                    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_FAULT_CLR_SHIFT                   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_FAULT_CLR_MAX                     (0x00000001U)

/* CLAIMREG_P0_R0_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_READONLY_CLAIMREG_P0_R0_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_READONLY_CLAIMREG_P0_R0_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_READONLY_CLAIMREG_P0_R0_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P0_R1_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_READONLY_CLAIMREG_P0_R1_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_READONLY_CLAIMREG_P0_R1_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_READONLY_CLAIMREG_P0_R1_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P0_R2_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_READONLY_CLAIMREG_P0_R2_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_READONLY_CLAIMREG_P0_R2_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_READONLY_CLAIMREG_P0_R2_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P0_R3_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_READONLY_CLAIMREG_P0_R3_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_READONLY_CLAIMREG_P0_R3_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_READONLY_CLAIMREG_P0_R3_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P0_R4_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_READONLY_CLAIMREG_P0_R4_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_READONLY_CLAIMREG_P0_R4_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_READONLY_CLAIMREG_P0_R4_READONLY_MAX (0xFFFFFFFFU)

/* PID_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MINOR_PROXY_MASK                (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MINOR_PROXY_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MINOR_PROXY_MAX                 (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_CUSTOM_PROXY_MASK               (0x000000C0U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_CUSTOM_PROXY_SHIFT              (0x00000006U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_CUSTOM_PROXY_MAX                (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MAJOR_PROXY_MASK                (0x00000700U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MAJOR_PROXY_SHIFT               (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MAJOR_PROXY_MAX                 (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MISC_PROXY_MASK                 (0x0000F800U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MISC_PROXY_SHIFT                (0x0000000BU)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MISC_PROXY_MAX                  (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MSB16_PROXY_MASK                (0xFFFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MSB16_PROXY_SHIFT               (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_PID_PROXY_PID_MSB16_PROXY_MAX                 (0x0000FFFFU)

/* MMR_CFG0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_SPEC_REV_PROXY_MASK   (0x0000FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_SPEC_REV_PROXY_SHIFT  (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_SPEC_REV_PROXY_MAX    (0x0000FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_CFG_REV_PROXY_MASK    (0xFFFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_CFG_REV_PROXY_SHIFT   (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG0_PROXY_MMR_CFG0_CFG_REV_PROXY_MAX     (0x0000FFFFU)

/* MMR_CFG1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PARTITIONS_PROXY_MASK (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PARTITIONS_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PARTITIONS_PROXY_MAX  (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PROXY_EN_PROXY_MASK   (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PROXY_EN_PROXY_SHIFT  (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MMR_CFG1_PROXY_MMR_CFG1_PROXY_EN_PROXY_MAX    (0x00000001U)

/* IPC_SET0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SET_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SET_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SET_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SRC_SET_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SRC_SET_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET0_PROXY_IPC_SET0_IPC_SRC_SET_PROXY_MAX (0x0FFFFFFFU)

/* IPC_SET1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SET_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SET_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SET_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SRC_SET_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SRC_SET_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET1_PROXY_IPC_SET1_IPC_SRC_SET_PROXY_MAX (0x0FFFFFFFU)

/* IPC_SET8_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SET_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SET_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SET_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SRC_SET_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SRC_SET_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_SET8_PROXY_IPC_SET8_IPC_SRC_SET_PROXY_MAX (0x0FFFFFFFU)

/* IPC_CLR0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_CLR_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_CLR_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_CLR_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_SRC_CLR_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_SRC_CLR_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR0_PROXY_IPC_CLR0_IPC_SRC_CLR_PROXY_MAX (0x0FFFFFFFU)

/* IPC_CLR1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_CLR_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_CLR_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_CLR_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_SRC_CLR_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_SRC_CLR_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR1_PROXY_IPC_CLR1_IPC_SRC_CLR_PROXY_MAX (0x0FFFFFFFU)

/* IPC_CLR8_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_CLR_PROXY_MASK    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_CLR_PROXY_SHIFT   (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_CLR_PROXY_MAX     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_SRC_CLR_PROXY_MASK (0xFFFFFFF0U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_SRC_CLR_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_IPC_CLR8_PROXY_IPC_CLR8_IPC_SRC_CLR_PROXY_MAX (0x0FFFFFFFU)

/* MAC_ID0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_PROXY_MAC_ID0_MACID_LO_PROXY_MASK     (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_PROXY_MAC_ID0_MACID_LO_PROXY_SHIFT    (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID0_PROXY_MAC_ID0_MACID_LO_PROXY_MAX      (0xFFFFFFFFU)

/* MAC_ID1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_PROXY_MAC_ID1_MACID_HI_PROXY_MASK     (0x0000FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_PROXY_MAC_ID1_MACID_HI_PROXY_SHIFT    (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MAC_ID1_PROXY_MAC_ID1_MACID_HI_PROXY_MAX      (0x0000FFFFU)

/* LOCK0_KICK0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_PROXY_LOCK0_KICK0_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_PROXY_LOCK0_KICK0_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0_PROXY_LOCK0_KICK0_PROXY_MAX       (0xFFFFFFFFU)

/* LOCK0_KICK1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_PROXY_LOCK0_KICK1_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_PROXY_LOCK0_KICK1_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1_PROXY_LOCK0_KICK1_PROXY_MAX       (0xFFFFFFFFU)

/* INTR_RAW_STATUS_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROT_ERR_PROXY_MASK     (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROT_ERR_PROXY_SHIFT    (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROT_ERR_PROXY_MAX      (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ADDR_ERR_PROXY_MASK     (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ADDR_ERR_PROXY_SHIFT    (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_ADDR_ERR_PROXY_MAX      (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_KICK_ERR_PROXY_MASK     (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_KICK_ERR_PROXY_SHIFT    (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_KICK_ERR_PROXY_MAX      (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROXY_ERR_PROXY_MASK    (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROXY_ERR_PROXY_SHIFT   (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_RAW_STATUS_PROXY_PROXY_ERR_PROXY_MAX     (0x00000001U)

/* INTR_ENABLED_STATUS_CLEAR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROT_ERR_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROT_ERR_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROT_ERR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_ADDR_ERR_PROXY_MASK (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_ADDR_ERR_PROXY_SHIFT (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_ADDR_ERR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_KICK_ERR_PROXY_MASK (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_KICK_ERR_PROXY_SHIFT (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_KICK_ERR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROXY_ERR_PROXY_MASK (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROXY_ERR_PROXY_SHIFT (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLED_STATUS_CLEAR_PROXY_ENABLED_PROXY_ERR_PROXY_MAX (0x00000001U)

/* INTR_ENABLE_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROT_ERR_EN_PROXY_MASK      (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROT_ERR_EN_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROT_ERR_EN_PROXY_MAX       (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ADDR_ERR_EN_PROXY_MASK      (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ADDR_ERR_EN_PROXY_SHIFT     (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_ADDR_ERR_EN_PROXY_MAX       (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_KICK_ERR_EN_PROXY_MASK      (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_KICK_ERR_EN_PROXY_SHIFT     (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_KICK_ERR_EN_PROXY_MAX       (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROXY_ERR_EN_PROXY_MASK     (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROXY_ERR_EN_PROXY_SHIFT    (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_PROXY_PROXY_ERR_EN_PROXY_MAX      (0x00000001U)

/* INTR_ENABLE_CLEAR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROT_ERR_EN_CLR_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROT_ERR_EN_CLR_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROT_ERR_EN_CLR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ADDR_ERR_EN_CLR_PROXY_MASK (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ADDR_ERR_EN_CLR_PROXY_SHIFT (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_ADDR_ERR_EN_CLR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_KICK_ERR_EN_CLR_PROXY_MASK (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_KICK_ERR_EN_CLR_PROXY_SHIFT (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_KICK_ERR_EN_CLR_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROXY_ERR_EN_CLR_PROXY_MASK (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROXY_ERR_EN_CLR_PROXY_SHIFT (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_INTR_ENABLE_CLEAR_PROXY_PROXY_ERR_EN_CLR_PROXY_MAX (0x00000001U)

/* EOI_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_EOI_PROXY_EOI_VECTOR_PROXY_MASK               (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_EOI_PROXY_EOI_VECTOR_PROXY_SHIFT              (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_EOI_PROXY_EOI_VECTOR_PROXY_MAX                (0x000000FFU)

/* FAULT_ADDRESS_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_PROXY_FAULT_ADDR_PROXY_MASK     (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_PROXY_FAULT_ADDR_PROXY_SHIFT    (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ADDRESS_PROXY_FAULT_ADDR_PROXY_MAX      (0xFFFFFFFFU)

/* FAULT_TYPE_STATUS_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_TYPE_PROXY_MASK (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_TYPE_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_TYPE_PROXY_MAX  (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_NS_PROXY_MASK   (0x00000040U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_NS_PROXY_SHIFT  (0x00000006U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_TYPE_STATUS_PROXY_FAULT_NS_PROXY_MAX    (0x00000001U)

/* FAULT_ATTR_STATUS_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_PRIVID_PROXY_MASK (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_PRIVID_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_PRIVID_PROXY_MAX (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_ROUTEID_PROXY_MASK (0x000FFF00U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_ROUTEID_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_ROUTEID_PROXY_MAX (0x00000FFFU)

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_XID_PROXY_MASK  (0xFFF00000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_XID_PROXY_SHIFT (0x00000014U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_ATTR_STATUS_PROXY_FAULT_XID_PROXY_MAX   (0x00000FFFU)

/* FAULT_CLEAR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_PROXY_FAULT_CLR_PROXY_MASK        (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_PROXY_FAULT_CLR_PROXY_SHIFT       (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_FAULT_CLEAR_PROXY_FAULT_CLR_PROXY_MAX         (0x00000001U)

/* CLAIMREG_P0_R0 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_CLAIMREG_P0_R0_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_CLAIMREG_P0_R0_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R0_CLAIMREG_P0_R0_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P0_R1 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_CLAIMREG_P0_R1_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_CLAIMREG_P0_R1_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R1_CLAIMREG_P0_R1_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P0_R2 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_CLAIMREG_P0_R2_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_CLAIMREG_P0_R2_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R2_CLAIMREG_P0_R2_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P0_R3 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_CLAIMREG_P0_R3_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_CLAIMREG_P0_R3_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R3_CLAIMREG_P0_R3_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P0_R4 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_CLAIMREG_P0_R4_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_CLAIMREG_P0_R4_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P0_R4_CLAIMREG_P0_R4_MAX             (0xFFFFFFFFU)

/* MSMC_CFG */

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_32B_ADDR_EN_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_32B_ADDR_EN_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_32B_ADDR_EN_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_MEM_INIT_DIS_MASK                    (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_MEM_INIT_DIS_SHIFT                   (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_MEM_INIT_DIS_MAX                     (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_SIZE_MASK                 (0x003F0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_SIZE_SHIFT                (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_SIZE_MAX                  (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_GRAN_MASK                 (0x3F000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_GRAN_SHIFT                (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_INTRLV_GRAN_MAX                  (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_ASSYM_EMIF_SEL_MASK              (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_ASSYM_EMIF_SEL_SHIFT             (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_DDR_ASSYM_EMIF_SEL_MAX               (0x00000001U)

/* MCU_ENET_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_MODE_SEL_MASK                   (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_MODE_SEL_SHIFT                  (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_MODE_SEL_MAX                    (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_RGMII_ID_MODE_MASK              (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_RGMII_ID_MODE_SHIFT             (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_RGMII_ID_MODE_MAX               (0x00000001U)

/* MCU_SPI1_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_SPI1_LINKDIS_MASK               (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_SPI1_LINKDIS_SHIFT              (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_SPI1_LINKDIS_MAX                (0x00000001U)

/* MCU_I3C0_CTRL0 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_INSTANCE_MASK              (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_INSTANCE_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_INSTANCE_MAX               (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_ROLE_MASK                      (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_ROLE_SHIFT                     (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_ROLE_MAX                       (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_MFR_ID_MASK                (0x7FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_MFR_ID_SHIFT               (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PID_MFR_ID_MAX                 (0x00007FFFU)

/* MCU_I3C0_CTRL1 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_IDLE_TIME_MASK             (0x0003FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_IDLE_TIME_SHIFT            (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_IDLE_TIME_MAX              (0x0003FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_MASK            (0xFF000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_SHIFT           (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_MAX             (0x000000FFU)

/* MCU_I3C1_CTRL0 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_INSTANCE_MASK              (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_INSTANCE_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_INSTANCE_MAX               (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_ROLE_MASK                      (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_ROLE_SHIFT                     (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_ROLE_MAX                       (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_MFR_ID_MASK                (0x7FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_MFR_ID_SHIFT               (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PID_MFR_ID_MAX                 (0x00007FFFU)

/* MCU_I3C1_CTRL1 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_IDLE_TIME_MASK             (0x0003FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_IDLE_TIME_SHIFT            (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_IDLE_TIME_MAX              (0x0003FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_MASK            (0xFF000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_SHIFT           (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_MAX             (0x000000FFU)

/* MCU_I2C0_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_HS_MCS_EN_MASK                  (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_HS_MCS_EN_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_HS_MCS_EN_MAX                   (0x00000001U)

/* MCU_FSS_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SEG_MASK                 (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SEG_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SEG_MAX                  (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SIZE_MASK                (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SIZE_SHIFT               (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S0_BOOT_SIZE_MAX                 (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SEG_MASK                 (0x003F0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SEG_SHIFT                (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SEG_MAX                  (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SIZE_MASK                (0x01000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SIZE_SHIFT               (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_S1_BOOT_SIZE_MAX                 (0x00000001U)

/* MCU_ADC0_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_TRIG_SEL_MASK                   (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_TRIG_SEL_SHIFT                  (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_TRIG_SEL_MAX                    (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_GPI_MODE_EN_MASK                (0x00010000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_GPI_MODE_EN_SHIFT               (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_GPI_MODE_EN_MAX                 (0x00000001U)

/* MCU_ADC1_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_TRIG_SEL_MASK                   (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_TRIG_SEL_SHIFT                  (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_TRIG_SEL_MAX                    (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_GPI_MODE_EN_MASK                (0x00010000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_GPI_MODE_EN_SHIFT               (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_GPI_MODE_EN_MAX                 (0x00000001U)

/* MCU_TIMER0_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_CAP_SEL_MAX                   (0x0000000FU)

/* MCU_TIMER1_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CAP_SEL_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CASCADE_EN_MASK               (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CASCADE_EN_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_CASCADE_EN_MAX                (0x00000001U)

/* MCU_TIMER2_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_CAP_SEL_MAX                   (0x0000000FU)

/* MCU_TIMER3_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CAP_SEL_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CASCADE_EN_MASK               (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CASCADE_EN_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_CASCADE_EN_MAX                (0x00000001U)

/* MCU_TIMER4_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_CAP_SEL_MAX                   (0x0000000FU)

/* MCU_TIMER5_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CAP_SEL_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CASCADE_EN_MASK               (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CASCADE_EN_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_CASCADE_EN_MAX                (0x00000001U)

/* MCU_TIMER6_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_CAP_SEL_MAX                   (0x0000000FU)

/* MCU_TIMER7_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CAP_SEL_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CASCADE_EN_MASK               (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CASCADE_EN_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_CASCADE_EN_MAX                (0x00000001U)

/* MCU_TIMER8_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_CAP_SEL_MAX                   (0x0000000FU)

/* MCU_TIMER9_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CAP_SEL_MASK                  (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CAP_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CAP_SEL_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CASCADE_EN_MASK               (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CASCADE_EN_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_CASCADE_EN_MAX                (0x00000001U)

/* MCU_TIMERIO0_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO1_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO2_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO3_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO4_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO5_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO6_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO7_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO8_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* MCU_TIMERIO9_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_OUT_SEL_MASK                (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_OUT_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_OUT_SEL_MAX                 (0x0000000FU)

/* LOCK1_KICK0 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_LOCK1_KICK0_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_LOCK1_KICK0_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_LOCK1_KICK0_MAX                   (0xFFFFFFFFU)

/* LOCK1_KICK1 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_LOCK1_KICK1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_LOCK1_KICK1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_LOCK1_KICK1_MAX                   (0xFFFFFFFFU)

/* CLAIMREG_P1_R0_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_READONLY_CLAIMREG_P1_R0_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_READONLY_CLAIMREG_P1_R0_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_READONLY_CLAIMREG_P1_R0_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P1_R1_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_READONLY_CLAIMREG_P1_R1_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_READONLY_CLAIMREG_P1_R1_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_READONLY_CLAIMREG_P1_R1_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P1_R2_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_READONLY_CLAIMREG_P1_R2_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_READONLY_CLAIMREG_P1_R2_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_READONLY_CLAIMREG_P1_R2_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P1_R3_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_READONLY_CLAIMREG_P1_R3_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_READONLY_CLAIMREG_P1_R3_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_READONLY_CLAIMREG_P1_R3_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P1_R4_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_READONLY_CLAIMREG_P1_R4_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_READONLY_CLAIMREG_P1_R4_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_READONLY_CLAIMREG_P1_R4_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P1_R5_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_READONLY_CLAIMREG_P1_R5_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_READONLY_CLAIMREG_P1_R5_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_READONLY_CLAIMREG_P1_R5_READONLY_MAX (0xFFFFFFFFU)

/* MSMC_CFG_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_32B_ADDR_EN_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_32B_ADDR_EN_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_32B_ADDR_EN_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_MEM_INIT_DIS_PROXY_MASK (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_MEM_INIT_DIS_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_MEM_INIT_DIS_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_SIZE_PROXY_MASK (0x003F0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_SIZE_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_SIZE_PROXY_MAX (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_GRAN_PROXY_MASK (0x3F000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_GRAN_PROXY_SHIFT (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_INTRLV_GRAN_PROXY_MAX (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_ASSYM_EMIF_SEL_PROXY_MASK (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_ASSYM_EMIF_SEL_PROXY_SHIFT (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MSMC_CFG_PROXY_MSMC_CFG_DDR_ASSYM_EMIF_SEL_PROXY_MAX (0x00000001U)

/* MCU_ENET_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_MODE_SEL_PROXY_MASK (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_MODE_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_MODE_SEL_PROXY_MAX (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_RGMII_ID_MODE_PROXY_MASK (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_RGMII_ID_MODE_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL_PROXY_MCU_ENET_CTRL_RGMII_ID_MODE_PROXY_MAX (0x00000001U)

/* MCU_SPI1_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_PROXY_MCU_SPI1_CTRL_SPI1_LINKDIS_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_PROXY_MCU_SPI1_CTRL_SPI1_LINKDIS_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_SPI1_CTRL_PROXY_MCU_SPI1_CTRL_SPI1_LINKDIS_PROXY_MAX (0x00000001U)

/* MCU_I3C0_CTRL0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_INSTANCE_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_INSTANCE_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_INSTANCE_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_ROLE_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_ROLE_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_ROLE_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_MFR_ID_PROXY_MASK (0x7FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_MFR_ID_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL0_PROXY_MCU_I3C0_CTRL0_PID_MFR_ID_PROXY_MAX (0x00007FFFU)

/* MCU_I3C0_CTRL1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_IDLE_TIME_PROXY_MASK (0x0003FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_IDLE_TIME_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_IDLE_TIME_PROXY_MAX (0x0003FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_PROXY_MASK (0xFF000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_PROXY_SHIFT (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C0_CTRL1_PROXY_MCU_I3C0_CTRL1_BUS_AVAIL_TIME_PROXY_MAX (0x000000FFU)

/* MCU_I3C1_CTRL0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_INSTANCE_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_INSTANCE_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_INSTANCE_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_ROLE_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_ROLE_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_ROLE_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_MFR_ID_PROXY_MASK (0x7FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_MFR_ID_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL0_PROXY_MCU_I3C1_CTRL0_PID_MFR_ID_PROXY_MAX (0x00007FFFU)

/* MCU_I3C1_CTRL1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_IDLE_TIME_PROXY_MASK (0x0003FFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_IDLE_TIME_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_IDLE_TIME_PROXY_MAX (0x0003FFFFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_PROXY_MASK (0xFF000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_PROXY_SHIFT (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I3C1_CTRL1_PROXY_MCU_I3C1_CTRL1_BUS_AVAIL_TIME_PROXY_MAX (0x000000FFU)

/* MCU_I2C0_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_PROXY_MCU_I2C0_CTRL_HS_MCS_EN_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_PROXY_MCU_I2C0_CTRL_HS_MCS_EN_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_I2C0_CTRL_PROXY_MCU_I2C0_CTRL_HS_MCS_EN_PROXY_MAX (0x00000001U)

/* MCU_FSS_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SEG_PROXY_MASK (0x0000003FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SEG_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SEG_PROXY_MAX (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SIZE_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SIZE_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S0_BOOT_SIZE_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SEG_PROXY_MASK (0x003F0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SEG_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SEG_PROXY_MAX (0x0000003FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SIZE_PROXY_MASK (0x01000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SIZE_PROXY_SHIFT (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_FSS_CTRL_PROXY_MCU_FSS_CTRL_S1_BOOT_SIZE_PROXY_MAX (0x00000001U)

/* MCU_ADC0_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_TRIG_SEL_PROXY_MASK (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_TRIG_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_TRIG_SEL_PROXY_MAX (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_GPI_MODE_EN_PROXY_MASK (0x00010000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_GPI_MODE_EN_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CTRL_PROXY_MCU_ADC0_CTRL_GPI_MODE_EN_PROXY_MAX (0x00000001U)

/* MCU_ADC1_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_TRIG_SEL_PROXY_MASK (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_TRIG_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_TRIG_SEL_PROXY_MAX (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_GPI_MODE_EN_PROXY_MASK (0x00010000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_GPI_MODE_EN_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CTRL_PROXY_MCU_ADC1_CTRL_GPI_MODE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMER0_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_PROXY_MCU_TIMER0_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_PROXY_MCU_TIMER0_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CTRL_PROXY_MCU_TIMER0_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMER1_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CASCADE_EN_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CASCADE_EN_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CTRL_PROXY_MCU_TIMER1_CTRL_CASCADE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMER2_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_PROXY_MCU_TIMER2_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_PROXY_MCU_TIMER2_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CTRL_PROXY_MCU_TIMER2_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMER3_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CASCADE_EN_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CASCADE_EN_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CTRL_PROXY_MCU_TIMER3_CTRL_CASCADE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMER4_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_PROXY_MCU_TIMER4_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_PROXY_MCU_TIMER4_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CTRL_PROXY_MCU_TIMER4_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMER5_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CASCADE_EN_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CASCADE_EN_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CTRL_PROXY_MCU_TIMER5_CTRL_CASCADE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMER6_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_PROXY_MCU_TIMER6_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_PROXY_MCU_TIMER6_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CTRL_PROXY_MCU_TIMER6_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMER7_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CASCADE_EN_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CASCADE_EN_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CTRL_PROXY_MCU_TIMER7_CTRL_CASCADE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMER8_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_PROXY_MCU_TIMER8_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_PROXY_MCU_TIMER8_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CTRL_PROXY_MCU_TIMER8_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMER9_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CAP_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CAP_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CAP_SEL_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CASCADE_EN_PROXY_MASK (0x00000100U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CASCADE_EN_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CTRL_PROXY_MCU_TIMER9_CTRL_CASCADE_EN_PROXY_MAX (0x00000001U)

/* MCU_TIMERIO0_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_PROXY_MCU_TIMERIO0_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_PROXY_MCU_TIMERIO0_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO0_CTRL_PROXY_MCU_TIMERIO0_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO1_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_PROXY_MCU_TIMERIO1_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_PROXY_MCU_TIMERIO1_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO1_CTRL_PROXY_MCU_TIMERIO1_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO2_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_PROXY_MCU_TIMERIO2_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_PROXY_MCU_TIMERIO2_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO2_CTRL_PROXY_MCU_TIMERIO2_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO3_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_PROXY_MCU_TIMERIO3_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_PROXY_MCU_TIMERIO3_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO3_CTRL_PROXY_MCU_TIMERIO3_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO4_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_PROXY_MCU_TIMERIO4_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_PROXY_MCU_TIMERIO4_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO4_CTRL_PROXY_MCU_TIMERIO4_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO5_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_PROXY_MCU_TIMERIO5_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_PROXY_MCU_TIMERIO5_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO5_CTRL_PROXY_MCU_TIMERIO5_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO6_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_PROXY_MCU_TIMERIO6_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_PROXY_MCU_TIMERIO6_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO6_CTRL_PROXY_MCU_TIMERIO6_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO7_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_PROXY_MCU_TIMERIO7_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_PROXY_MCU_TIMERIO7_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO7_CTRL_PROXY_MCU_TIMERIO7_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO8_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_PROXY_MCU_TIMERIO8_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_PROXY_MCU_TIMERIO8_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO8_CTRL_PROXY_MCU_TIMERIO8_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* MCU_TIMERIO9_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_PROXY_MCU_TIMERIO9_CTRL_OUT_SEL_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_PROXY_MCU_TIMERIO9_CTRL_OUT_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMERIO9_CTRL_PROXY_MCU_TIMERIO9_CTRL_OUT_SEL_PROXY_MAX (0x0000000FU)

/* LOCK1_KICK0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_PROXY_LOCK1_KICK0_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_PROXY_LOCK1_KICK0_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0_PROXY_LOCK1_KICK0_PROXY_MAX       (0xFFFFFFFFU)

/* LOCK1_KICK1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_PROXY_LOCK1_KICK1_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_PROXY_LOCK1_KICK1_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1_PROXY_LOCK1_KICK1_PROXY_MAX       (0xFFFFFFFFU)

/* CLAIMREG_P1_R0 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_CLAIMREG_P1_R0_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_CLAIMREG_P1_R0_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R0_CLAIMREG_P1_R0_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P1_R1 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_CLAIMREG_P1_R1_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_CLAIMREG_P1_R1_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R1_CLAIMREG_P1_R1_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P1_R2 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_CLAIMREG_P1_R2_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_CLAIMREG_P1_R2_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R2_CLAIMREG_P1_R2_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P1_R3 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_CLAIMREG_P1_R3_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_CLAIMREG_P1_R3_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R3_CLAIMREG_P1_R3_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P1_R4 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_CLAIMREG_P1_R4_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_CLAIMREG_P1_R4_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R4_CLAIMREG_P1_R4_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P1_R5 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_CLAIMREG_P1_R5_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_CLAIMREG_P1_R5_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P1_R5_CLAIMREG_P1_R5_MAX             (0xFFFFFFFFU)

/* MCU_CLKOUT0_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_SEL_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_SEL_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_EN_MASK                  (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_EN_SHIFT                 (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_CLK_EN_MAX                   (0x00000001U)

/* MCU_EFUSE_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_CLK_SEL_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_CLK_SEL_MAX                  (0x00000001U)

/* MCU_MCAN0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_CLK_SEL_MASK                 (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_CLK_SEL_MAX                  (0x00000003U)

/* MCU_MCAN1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_CLK_SEL_MASK                 (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_CLK_SEL_MAX                  (0x00000003U)

/* MCU_OSPI0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_CLK_SEL_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_CLK_SEL_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_MASK             (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_SHIFT            (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_MAX              (0x00000001U)

/* MCU_OSPI1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_CLK_SEL_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_CLK_SEL_MAX                  (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_MASK             (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_SHIFT            (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_MAX              (0x00000001U)

/* MCU_ADC0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_CLK_SEL_MASK                  (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_CLK_SEL_MAX                   (0x00000003U)

/* MCU_ADC1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_CLK_SEL_MASK                  (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_CLK_SEL_MAX                   (0x00000003U)

/* MCU_ENET_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_RMII_CLK_SEL_MASK             (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_RMII_CLK_SEL_SHIFT            (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_RMII_CLK_SEL_MAX              (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_CPTS_CLKSEL_MASK              (0x00000F00U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_CPTS_CLKSEL_SHIFT             (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_CPTS_CLKSEL_MAX               (0x0000000FU)

/* MCU_R5_CORE0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_CLK_SEL_MASK              (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_CLK_SEL_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_CLK_SEL_MAX               (0x00000001U)

/* MCU_R5_CORE1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_CLK_SEL_MASK              (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_CLK_SEL_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_CLK_SEL_MAX               (0x00000001U)

/* MCU_TIMER0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER2_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER3_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER4_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER5_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER6_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER7_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER8_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_TIMER9_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_CLK_SEL_MASK                (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_CLK_SEL_SHIFT               (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_CLK_SEL_MAX                 (0x00000007U)

/* MCU_RTI0_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL_MASK                  (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL_MAX                   (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_WRTLOCK_MASK                  (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_WRTLOCK_SHIFT                 (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_WRTLOCK_MAX                   (0x00000001U)

/* MCU_RTI1_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_MASK                  (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_MAX                   (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_WRTLOCK_MASK                  (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_WRTLOCK_SHIFT                 (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_WRTLOCK_MAX                   (0x00000001U)

/* MCU_USART_CLKSEL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_CLK_SEL_MASK                 (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_CLK_SEL_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_CLK_SEL_MAX                  (0x00000001U)

/* LOCK2_KICK0 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_LOCK2_KICK0_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_LOCK2_KICK0_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_LOCK2_KICK0_MAX                   (0xFFFFFFFFU)

/* LOCK2_KICK1 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_LOCK2_KICK1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_LOCK2_KICK1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_LOCK2_KICK1_MAX                   (0xFFFFFFFFU)

/* CLAIMREG_P2_R0_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_READONLY_CLAIMREG_P2_R0_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_READONLY_CLAIMREG_P2_R0_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_READONLY_CLAIMREG_P2_R0_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P2_R1_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_READONLY_CLAIMREG_P2_R1_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_READONLY_CLAIMREG_P2_R1_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_READONLY_CLAIMREG_P2_R1_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P2_R2_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_READONLY_CLAIMREG_P2_R2_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_READONLY_CLAIMREG_P2_R2_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_READONLY_CLAIMREG_P2_R2_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P2_R3_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_READONLY_CLAIMREG_P2_R3_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_READONLY_CLAIMREG_P2_R3_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_READONLY_CLAIMREG_P2_R3_READONLY_MAX (0xFFFFFFFFU)

/* MCU_CLKOUT0_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_SEL_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_EN_PROXY_MASK (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_EN_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_CLKOUT0_CTRL_PROXY_MCU_CLKOUT0_CTRL_CLK_EN_PROXY_MAX (0x00000001U)

/* MCU_EFUSE_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_PROXY_MCU_EFUSE_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_PROXY_MCU_EFUSE_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_EFUSE_CLKSEL_PROXY_MCU_EFUSE_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

/* MCU_MCAN0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_PROXY_MCU_MCAN0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_PROXY_MCU_MCAN0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN0_CLKSEL_PROXY_MCU_MCAN0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000003U)

/* MCU_MCAN1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_PROXY_MCU_MCAN1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_PROXY_MCU_MCAN1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_MCAN1_CLKSEL_PROXY_MCU_MCAN1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000003U)

/* MCU_OSPI0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_PROXY_MASK (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI0_CLKSEL_PROXY_MCU_OSPI0_CLKSEL_LOOPCLK_SEL_PROXY_MAX (0x00000001U)

/* MCU_OSPI1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_PROXY_MASK (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_OSPI1_CLKSEL_PROXY_MCU_OSPI1_CLKSEL_LOOPCLK_SEL_PROXY_MAX (0x00000001U)

/* MCU_ADC0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_PROXY_MCU_ADC0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_PROXY_MCU_ADC0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_PROXY_MCU_ADC0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000003U)

/* MCU_ADC1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_PROXY_MCU_ADC1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000003U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_PROXY_MCU_ADC1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_PROXY_MCU_ADC1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000003U)

/* MCU_ENET_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_RMII_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_RMII_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_RMII_CLK_SEL_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_CPTS_CLKSEL_PROXY_MASK (0x00000F00U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_CPTS_CLKSEL_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CLKSEL_PROXY_MCU_ENET_CLKSEL_CPTS_CLKSEL_PROXY_MAX (0x0000000FU)

/* MCU_R5_CORE0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_PROXY_MCU_R5_CORE0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_PROXY_MCU_R5_CORE0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE0_CLKSEL_PROXY_MCU_R5_CORE0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

/* MCU_R5_CORE1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_PROXY_MCU_R5_CORE1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_PROXY_MCU_R5_CORE1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_R5_CORE1_CLKSEL_PROXY_MCU_R5_CORE1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

/* MCU_TIMER0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_PROXY_MCU_TIMER0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_PROXY_MCU_TIMER0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER0_CLKSEL_PROXY_MCU_TIMER0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_PROXY_MCU_TIMER1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_PROXY_MCU_TIMER1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER1_CLKSEL_PROXY_MCU_TIMER1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER2_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_PROXY_MCU_TIMER2_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_PROXY_MCU_TIMER2_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER2_CLKSEL_PROXY_MCU_TIMER2_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER3_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_PROXY_MCU_TIMER3_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_PROXY_MCU_TIMER3_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER3_CLKSEL_PROXY_MCU_TIMER3_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER4_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_PROXY_MCU_TIMER4_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_PROXY_MCU_TIMER4_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER4_CLKSEL_PROXY_MCU_TIMER4_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER5_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_PROXY_MCU_TIMER5_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_PROXY_MCU_TIMER5_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER5_CLKSEL_PROXY_MCU_TIMER5_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER6_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_PROXY_MCU_TIMER6_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_PROXY_MCU_TIMER6_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER6_CLKSEL_PROXY_MCU_TIMER6_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER7_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_PROXY_MCU_TIMER7_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_PROXY_MCU_TIMER7_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER7_CLKSEL_PROXY_MCU_TIMER7_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER8_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_PROXY_MCU_TIMER8_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_PROXY_MCU_TIMER8_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER8_CLKSEL_PROXY_MCU_TIMER8_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_TIMER9_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_PROXY_MCU_TIMER9_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_PROXY_MCU_TIMER9_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_TIMER9_CLKSEL_PROXY_MCU_TIMER9_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

/* MCU_RTI0_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_WRTLOCK_PROXY_MASK (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_WRTLOCK_PROXY_SHIFT (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_PROXY_MCU_RTI0_CLKSEL_WRTLOCK_PROXY_MAX (0x00000001U)

/* MCU_RTI1_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_CLK_SEL_PROXY_MASK (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_CLK_SEL_PROXY_MAX (0x00000007U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_WRTLOCK_PROXY_MASK (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_WRTLOCK_PROXY_SHIFT (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_PROXY_MCU_RTI1_CLKSEL_WRTLOCK_PROXY_MAX (0x00000001U)

/* MCU_USART_CLKSEL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_PROXY_MCU_USART_CLKSEL_CLK_SEL_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_PROXY_MCU_USART_CLKSEL_CLK_SEL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_USART_CLKSEL_PROXY_MCU_USART_CLKSEL_CLK_SEL_PROXY_MAX (0x00000001U)

/* LOCK2_KICK0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_PROXY_LOCK2_KICK0_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_PROXY_LOCK2_KICK0_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0_PROXY_LOCK2_KICK0_PROXY_MAX       (0xFFFFFFFFU)

/* LOCK2_KICK1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_PROXY_LOCK2_KICK1_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_PROXY_LOCK2_KICK1_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1_PROXY_LOCK2_KICK1_PROXY_MAX       (0xFFFFFFFFU)

/* CLAIMREG_P2_R0 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_CLAIMREG_P2_R0_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_CLAIMREG_P2_R0_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R0_CLAIMREG_P2_R0_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P2_R1 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_CLAIMREG_P2_R1_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_CLAIMREG_P2_R1_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R1_CLAIMREG_P2_R1_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P2_R2 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_CLAIMREG_P2_R2_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_CLAIMREG_P2_R2_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R2_CLAIMREG_P2_R2_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P2_R3 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_CLAIMREG_P2_R3_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_CLAIMREG_P2_R3_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P2_R3_CLAIMREG_P2_R3_MAX             (0xFFFFFFFFU)

/* MCU_LBIST_CTRL */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DIVIDE_RATIO_MASK              (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DIVIDE_RATIO_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DIVIDE_RATIO_MAX               (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_LOAD_DIV_MASK                  (0x00000080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_LOAD_DIV_SHIFT                 (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_LOAD_DIV_MAX                   (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DC_DEF_MASK                    (0x00000300U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DC_DEF_SHIFT                   (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_DC_DEF_MAX                     (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_RUNBIST_MODE_MASK              (0x0000F000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_RUNBIST_MODE_SHIFT             (0x0000000CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_RUNBIST_MODE_MAX               (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RUN_MASK                  (0x0F000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RUN_SHIFT                 (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RUN_MAX                   (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RESET_MASK                (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RESET_SHIFT               (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_BIST_RESET_MAX                 (0x00000001U)

/* MCU_LBIST_PATCOUNT */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_MASK           (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_SHIFT          (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_MAX            (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_RESET_PC_DEF_MASK          (0x000000F0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_RESET_PC_DEF_SHIFT         (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_RESET_PC_DEF_MAX           (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SET_PC_DEF_MASK            (0x00000F00U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SET_PC_DEF_SHIFT           (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_SET_PC_DEF_MAX             (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_MASK         (0x3FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_SHIFT        (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_MAX          (0x00003FFFU)

/* MCU_LBIST_SEED0 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PRPG_DEF_MASK                 (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PRPG_DEF_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PRPG_DEF_MAX                  (0xFFFFFFFFU)

/* MCU_LBIST_SEED1 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PRPG_DEF_MASK                 (0x001FFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PRPG_DEF_SHIFT                (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PRPG_DEF_MAX                  (0x001FFFFFU)

/* MCU_LBIST_SPARE0 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_MASK       (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_SHIFT      (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_MAX        (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_MASK       (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_SHIFT      (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_MAX        (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_SPARE0_MASK                  (0xFFFFFFFCU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_SPARE0_SHIFT                 (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_SPARE0_MAX                   (0x3FFFFFFFU)

/* MCU_LBIST_SPARE1 */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_SPARE1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_SPARE1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_SPARE1_MAX                   (0xFFFFFFFFU)

/* MCU_LBIST_STAT */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_MISR_MUX_CTL_MASK              (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_MISR_MUX_CTL_SHIFT             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_MISR_MUX_CTL_MAX               (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_OUT_MUX_CTL_MASK               (0x00000300U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_OUT_MUX_CTL_SHIFT              (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_OUT_MUX_CTL_MAX                (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_RUNNING_MASK              (0x00008000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_RUNNING_SHIFT             (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_RUNNING_MAX               (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_DONE_MASK                 (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_DONE_SHIFT                (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_BIST_DONE_MAX                  (0x00000001U)

/* MCU_LBIST_MISR */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_MISR_RESULT_MASK               (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_MISR_RESULT_SHIFT              (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_MISR_RESULT_MAX                (0xFFFFFFFFU)

/* MCU_LBIST_SIG */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_MISR_SIG_MASK                   (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_MISR_SIG_SHIFT                  (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_MISR_SIG_MAX                    (0xFFFFFFFFU)

/* LOCK3_KICK0 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_LOCK3_KICK0_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_LOCK3_KICK0_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_LOCK3_KICK0_MAX                   (0xFFFFFFFFU)

/* LOCK3_KICK1 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_LOCK3_KICK1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_LOCK3_KICK1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_LOCK3_KICK1_MAX                   (0xFFFFFFFFU)

/* CLAIMREG_P3_R0_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_READONLY_CLAIMREG_P3_R0_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_READONLY_CLAIMREG_P3_R0_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_READONLY_CLAIMREG_P3_R0_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P3_R1_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_READONLY_CLAIMREG_P3_R1_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_READONLY_CLAIMREG_P3_R1_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_READONLY_CLAIMREG_P3_R1_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P3_R2_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_READONLY_CLAIMREG_P3_R2_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_READONLY_CLAIMREG_P3_R2_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_READONLY_CLAIMREG_P3_R2_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P3_R3_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_READONLY_CLAIMREG_P3_R3_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_READONLY_CLAIMREG_P3_R3_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_READONLY_CLAIMREG_P3_R3_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P3_R4_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_READONLY_CLAIMREG_P3_R4_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_READONLY_CLAIMREG_P3_R4_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_READONLY_CLAIMREG_P3_R4_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P3_R5_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_READONLY_CLAIMREG_P3_R5_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_READONLY_CLAIMREG_P3_R5_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_READONLY_CLAIMREG_P3_R5_READONLY_MAX (0xFFFFFFFFU)

/* MCU_LBIST_CTRL_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DIVIDE_RATIO_PROXY_MASK (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DIVIDE_RATIO_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DIVIDE_RATIO_PROXY_MAX (0x0000001FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_LOAD_DIV_PROXY_MASK (0x00000080U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_LOAD_DIV_PROXY_SHIFT (0x00000007U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_LOAD_DIV_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DC_DEF_PROXY_MASK (0x00000300U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DC_DEF_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_DC_DEF_PROXY_MAX (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_RUNBIST_MODE_PROXY_MASK (0x0000F000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_RUNBIST_MODE_PROXY_SHIFT (0x0000000CU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_RUNBIST_MODE_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RUN_PROXY_MASK (0x0F000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RUN_PROXY_SHIFT (0x00000018U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RUN_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RESET_PROXY_MASK (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RESET_PROXY_SHIFT (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_CTRL_PROXY_MCU_LBIST_CTRL_BIST_RESET_PROXY_MAX (0x00000001U)

/* MCU_LBIST_PATCOUNT_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_PROXY_MASK (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SCAN_PC_DEF_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_RESET_PC_DEF_PROXY_MASK (0x000000F0U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_RESET_PC_DEF_PROXY_SHIFT (0x00000004U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_RESET_PC_DEF_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SET_PC_DEF_PROXY_MASK (0x00000F00U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SET_PC_DEF_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_SET_PC_DEF_PROXY_MAX (0x0000000FU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_PROXY_MASK (0x3FFF0000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_PROXY_SHIFT (0x00000010U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_PATCOUNT_PROXY_MCU_LBIST_PATCOUNT_STATIC_PC_DEF_PROXY_MAX (0x00003FFFU)

/* MCU_LBIST_SEED0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PROXY_MCU_LBIST_SEED0_PRPG_DEF_PROXY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PROXY_MCU_LBIST_SEED0_PRPG_DEF_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED0_PROXY_MCU_LBIST_SEED0_PRPG_DEF_PROXY_MAX (0xFFFFFFFFU)

/* MCU_LBIST_SEED1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PROXY_MCU_LBIST_SEED1_PRPG_DEF_PROXY_MASK (0x001FFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PROXY_MCU_LBIST_SEED1_PRPG_DEF_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SEED1_PROXY_MCU_LBIST_SEED1_PRPG_DEF_PROXY_MAX (0x001FFFFFU)

/* MCU_LBIST_SPARE0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_PROXY_MASK (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_LBIST_SELFTEST_EN_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_PROXY_MASK (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_PROXY_SHIFT (0x00000001U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_PBIST_SELFTEST_EN_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_SPARE0_PROXY_MASK (0xFFFFFFFCU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_SPARE0_PROXY_SHIFT (0x00000002U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE0_PROXY_MCU_LBIST_SPARE0_SPARE0_PROXY_MAX (0x3FFFFFFFU)

/* MCU_LBIST_SPARE1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_PROXY_MCU_LBIST_SPARE1_SPARE1_PROXY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_PROXY_MCU_LBIST_SPARE1_SPARE1_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SPARE1_PROXY_MCU_LBIST_SPARE1_SPARE1_PROXY_MAX (0xFFFFFFFFU)

/* MCU_LBIST_STAT_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_MISR_MUX_CTL_PROXY_MASK (0x000000FFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_MISR_MUX_CTL_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_MISR_MUX_CTL_PROXY_MAX (0x000000FFU)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_OUT_MUX_CTL_PROXY_MASK (0x00000300U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_OUT_MUX_CTL_PROXY_SHIFT (0x00000008U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_OUT_MUX_CTL_PROXY_MAX (0x00000003U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_RUNNING_PROXY_MASK (0x00008000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_RUNNING_PROXY_SHIFT (0x0000000FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_RUNNING_PROXY_MAX (0x00000001U)

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_DONE_PROXY_MASK (0x80000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_DONE_PROXY_SHIFT (0x0000001FU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_STAT_PROXY_MCU_LBIST_STAT_BIST_DONE_PROXY_MAX (0x00000001U)

/* MCU_LBIST_MISR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_PROXY_MCU_LBIST_MISR_MISR_RESULT_PROXY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_PROXY_MCU_LBIST_MISR_MISR_RESULT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_MISR_PROXY_MCU_LBIST_MISR_MISR_RESULT_PROXY_MAX (0xFFFFFFFFU)

/* MCU_LBIST_SIG_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_PROXY_MCU_LBIST_SIG_MISR_SIG_PROXY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_PROXY_MCU_LBIST_SIG_MISR_SIG_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_MCU_LBIST_SIG_PROXY_MCU_LBIST_SIG_MISR_SIG_PROXY_MAX (0xFFFFFFFFU)

/* LOCK3_KICK0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_PROXY_LOCK3_KICK0_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_PROXY_LOCK3_KICK0_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0_PROXY_LOCK3_KICK0_PROXY_MAX       (0xFFFFFFFFU)

/* LOCK3_KICK1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_PROXY_LOCK3_KICK1_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_PROXY_LOCK3_KICK1_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1_PROXY_LOCK3_KICK1_PROXY_MAX       (0xFFFFFFFFU)

/* CLAIMREG_P3_R0 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_CLAIMREG_P3_R0_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_CLAIMREG_P3_R0_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R0_CLAIMREG_P3_R0_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P3_R1 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_CLAIMREG_P3_R1_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_CLAIMREG_P3_R1_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R1_CLAIMREG_P3_R1_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P3_R2 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_CLAIMREG_P3_R2_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_CLAIMREG_P3_R2_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R2_CLAIMREG_P3_R2_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P3_R3 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_CLAIMREG_P3_R3_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_CLAIMREG_P3_R3_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R3_CLAIMREG_P3_R3_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P3_R4 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_CLAIMREG_P3_R4_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_CLAIMREG_P3_R4_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R4_CLAIMREG_P3_R4_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P3_R5 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_CLAIMREG_P3_R5_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_CLAIMREG_P3_R5_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P3_R5_CLAIMREG_P3_R5_MAX             (0xFFFFFFFFU)

/* DV_REG0 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG1 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG2 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG3 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG4 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG5 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG6 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG7 */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_BIT_MASK                              (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_BIT_SHIFT                             (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_BIT_MAX                               (0xFFFFFFFFU)

/* DV_REG0_SET */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG1_SET */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG2_SET */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG3_SET */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG0_CLR */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG1_CLR */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG2_CLR */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_BIT_MAX                           (0xFFFFFFFFU)

/* DV_REG3_CLR */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_BIT_MASK                          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_BIT_SHIFT                         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_BIT_MAX                           (0xFFFFFFFFU)

/* LOCK4_KICK0 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_LOCK4_KICK0_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_LOCK4_KICK0_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_LOCK4_KICK0_MAX                   (0xFFFFFFFFU)

/* LOCK4_KICK1 */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_LOCK4_KICK1_MASK                  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_LOCK4_KICK1_SHIFT                 (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_LOCK4_KICK1_MAX                   (0xFFFFFFFFU)

/* CLAIMREG_P4_R0_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_READONLY_CLAIMREG_P4_R0_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_READONLY_CLAIMREG_P4_R0_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_READONLY_CLAIMREG_P4_R0_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R1_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_READONLY_CLAIMREG_P4_R1_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_READONLY_CLAIMREG_P4_R1_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_READONLY_CLAIMREG_P4_R1_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R2_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_READONLY_CLAIMREG_P4_R2_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_READONLY_CLAIMREG_P4_R2_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_READONLY_CLAIMREG_P4_R2_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R3_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_READONLY_CLAIMREG_P4_R3_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_READONLY_CLAIMREG_P4_R3_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_READONLY_CLAIMREG_P4_R3_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R4_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_READONLY_CLAIMREG_P4_R4_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_READONLY_CLAIMREG_P4_R4_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_READONLY_CLAIMREG_P4_R4_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R5_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_READONLY_CLAIMREG_P4_R5_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_READONLY_CLAIMREG_P4_R5_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_READONLY_CLAIMREG_P4_R5_READONLY_MAX (0xFFFFFFFFU)

/* CLAIMREG_P4_R6_READONLY */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_READONLY_CLAIMREG_P4_R6_READONLY_MASK (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_READONLY_CLAIMREG_P4_R6_READONLY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_READONLY_CLAIMREG_P4_R6_READONLY_MAX (0xFFFFFFFFU)

/* DV_REG0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_PROXY_DV_REG0_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_PROXY_DV_REG0_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_PROXY_DV_REG0_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_PROXY_DV_REG1_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_PROXY_DV_REG1_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_PROXY_DV_REG1_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG2_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_PROXY_DV_REG2_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_PROXY_DV_REG2_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_PROXY_DV_REG2_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG3_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_PROXY_DV_REG3_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_PROXY_DV_REG3_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_PROXY_DV_REG3_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG4_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_PROXY_DV_REG4_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_PROXY_DV_REG4_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG4_PROXY_DV_REG4_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG5_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_PROXY_DV_REG5_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_PROXY_DV_REG5_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG5_PROXY_DV_REG5_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG6_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_PROXY_DV_REG6_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_PROXY_DV_REG6_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG6_PROXY_DV_REG6_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG7_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_PROXY_DV_REG7_BIT_PROXY_MASK          (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_PROXY_DV_REG7_BIT_PROXY_SHIFT         (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG7_PROXY_DV_REG7_BIT_PROXY_MAX           (0xFFFFFFFFU)

/* DV_REG0_SET_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_PROXY_DV_REG0_SET_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_PROXY_DV_REG0_SET_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_SET_PROXY_DV_REG0_SET_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG1_SET_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_PROXY_DV_REG1_SET_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_PROXY_DV_REG1_SET_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_SET_PROXY_DV_REG1_SET_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG2_SET_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_PROXY_DV_REG2_SET_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_PROXY_DV_REG2_SET_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_SET_PROXY_DV_REG2_SET_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG3_SET_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_PROXY_DV_REG3_SET_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_PROXY_DV_REG3_SET_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_SET_PROXY_DV_REG3_SET_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG0_CLR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_PROXY_DV_REG0_CLR_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_PROXY_DV_REG0_CLR_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG0_CLR_PROXY_DV_REG0_CLR_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG1_CLR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_PROXY_DV_REG1_CLR_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_PROXY_DV_REG1_CLR_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG1_CLR_PROXY_DV_REG1_CLR_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG2_CLR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_PROXY_DV_REG2_CLR_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_PROXY_DV_REG2_CLR_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG2_CLR_PROXY_DV_REG2_CLR_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* DV_REG3_CLR_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_PROXY_DV_REG3_CLR_BIT_PROXY_MASK  (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_PROXY_DV_REG3_CLR_BIT_PROXY_SHIFT (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_DV_REG3_CLR_PROXY_DV_REG3_CLR_BIT_PROXY_MAX   (0xFFFFFFFFU)

/* LOCK4_KICK0_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_PROXY_LOCK4_KICK0_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_PROXY_LOCK4_KICK0_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK0_PROXY_LOCK4_KICK0_PROXY_MAX       (0xFFFFFFFFU)

/* LOCK4_KICK1_PROXY */

#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_PROXY_LOCK4_KICK1_PROXY_MASK      (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_PROXY_LOCK4_KICK1_PROXY_SHIFT     (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_LOCK4_KICK1_PROXY_LOCK4_KICK1_PROXY_MAX       (0xFFFFFFFFU)

/* CLAIMREG_P4_R0 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_CLAIMREG_P4_R0_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_CLAIMREG_P4_R0_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R0_CLAIMREG_P4_R0_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R1 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_CLAIMREG_P4_R1_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_CLAIMREG_P4_R1_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R1_CLAIMREG_P4_R1_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R2 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_CLAIMREG_P4_R2_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_CLAIMREG_P4_R2_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R2_CLAIMREG_P4_R2_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R3 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_CLAIMREG_P4_R3_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_CLAIMREG_P4_R3_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R3_CLAIMREG_P4_R3_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R4 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_CLAIMREG_P4_R4_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_CLAIMREG_P4_R4_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R4_CLAIMREG_P4_R4_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R5 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_CLAIMREG_P4_R5_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_CLAIMREG_P4_R5_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R5_CLAIMREG_P4_R5_MAX             (0xFFFFFFFFU)

/* CLAIMREG_P4_R6 */

#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_CLAIMREG_P4_R6_MASK            (0xFFFFFFFFU)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_CLAIMREG_P4_R6_SHIFT           (0x00000000U)
#define CSL_MCU_CTRL_MMR_CFG0_CLAIMREG_P4_R6_CLAIMREG_P4_R6_MAX             (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
