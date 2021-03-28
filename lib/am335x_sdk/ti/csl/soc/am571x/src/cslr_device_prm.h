/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_DEVICE_PRM_H
#define CSLR_DEVICE_PRM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 PRM_RSTCTRL_REG;
    volatile Uint32 PRM_RSTST_REG;
    volatile Uint32 PRM_RSTTIME_REG;
    volatile Uint32 PRM_CLKREQCTRL_REG;
    volatile Uint32 PRM_VOLTCTRL_REG;
    volatile Uint32 PRM_PWRREQCTRL_REG;
    volatile Uint32 PRM_PSCON_COUNT_REG;
    volatile Uint32 PRM_IO_COUNT_REG;
    volatile Uint32 PRM_IO_PMCTRL_REG;
    volatile Uint32 PRM_VOLTSETUP_WARMRESET_REG;
    volatile Uint32 PRM_VOLTSETUP_CORE_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_MPU_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_MM_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_CORE_RET_SLEEP_REG;
    volatile Uint32 PRM_VOLTSETUP_MPU_RET_SLEEP_REG;
    volatile Uint32 PRM_VOLTSETUP_MM_RET_SLEEP_REG;
    volatile Uint32 PRM_VP_CORE_CONFIG_REG;
    volatile Uint32 PRM_VP_CORE_STATUS_REG;
    volatile Uint32 PRM_VP_CORE_VLIMITTO_REG;
    volatile Uint32 PRM_VP_CORE_VOLTAGE_REG;
    volatile Uint32 PRM_VP_CORE_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_CORE_VSTEPMIN_REG;
    volatile Uint32 PRM_VP_MPU_CONFIG_REG;
    volatile Uint32 PRM_VP_MPU_STATUS_REG;
    volatile Uint32 PRM_VP_MPU_VLIMITTO_REG;
    volatile Uint32 PRM_VP_MPU_VOLTAGE_REG;
    volatile Uint32 PRM_VP_MPU_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_MPU_VSTEPMIN_REG;
    volatile Uint32 PRM_VP_MM_CONFIG_REG;
    volatile Uint32 PRM_VP_MM_STATUS_REG;
    volatile Uint32 PRM_VP_MM_VLIMITTO_REG;
    volatile Uint32 PRM_VP_MM_VOLTAGE_REG;
    volatile Uint32 PRM_VP_MM_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_MM_VSTEPMIN_REG;
    volatile Uint32 PRM_VC_SMPS_CORE_CONFIG_REG;
    volatile Uint32 PRM_VC_SMPS_MM_CONFIG_REG;
    volatile Uint32 PRM_VC_SMPS_MPU_CONFIG_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_CORE_L_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_MM_L_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_MPU_L_REG;
    volatile Uint32 PRM_VC_VAL_BYPASS_REG;
    volatile Uint32 PRM_VC_CORE_ERRST_REG;
    volatile Uint32 PRM_VC_MM_ERRST_REG;
    volatile Uint32 PRM_VC_MPU_ERRST_REG;
    volatile Uint32 PRM_VC_BYPASS_ERRST_REG;
    volatile Uint32 PRM_VC_CFG_I2C_MODE_REG;
    volatile Uint32 PRM_VC_CFG_I2C_CLK_REG;
    volatile Uint32 PRM_SRAM_COUNT_REG;
    volatile Uint32 PRM_SRAM_WKUP_SETUP_REG;
    volatile Uint32 PRM_SLDO_CORE_SETUP_REG;
    volatile Uint32 PRM_SLDO_CORE_CTRL_REG;
    volatile Uint32 PRM_SLDO_MPU_SETUP_REG;
    volatile Uint32 PRM_SLDO_MPU_CTRL_REG;
    volatile Uint32 PRM_SLDO_GPU_SETUP_REG;
    volatile Uint32 PRM_SLDO_GPU_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_MPU_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_MPU_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_GPU_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_GPU_CTRL_REG;
    volatile Uint32 PRM_BANDGAP_SETUP_REG;
    volatile Uint32 PRM_DEVICE_OFF_CTRL_REG;
    volatile Uint32 PRM_PHASE1_CNDP_REG;
    volatile Uint32 PRM_PHASE2A_CNDP_REG;
    volatile Uint32 PRM_PHASE2B_CNDP_REG;
    volatile Uint32 PRM_MODEM_IF_CTRL_REG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 PRM_VOLTST_MPU_REG;
    volatile Uint32 PRM_VOLTST_MM_REG;
    volatile Uint32 PRM_SLDO_DSPEVE_SETUP_REG;
    volatile Uint32 PRM_SLDO_IVA_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_DSPEVE_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_IVA_CTRL_REG;
    volatile Uint32 PRM_SLDO_DSPEVE_CTRL_REG;
    volatile Uint32 PRM_SLDO_IVA_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_DSPEVE_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_IVA_SETUP_REG;
} CSL_device_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Global software cold and warm reset control. This register is auto-cleared. 
 * Only write 1 is possible. A read returns 0 only. */
#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG                          (0x0U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL            (CSL_DEVICE_PRM_PRM_RSTCTRL_REG)


/* This register logs the global reset sources. Each bit is set upon release 
 * of the domain reset signal. Must be cleared by software. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_RSTST_REG                            (0x4U)
/* Below define for backward compatibility */
#define PRM_RSTST              (CSL_DEVICE_PRM_PRM_RSTST_REG)


/* Reset duration control. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_RSTTIME_REG                          (0x8U)
/* Below define for backward compatibility */
#define PRM_RSTTIME            (CSL_DEVICE_PRM_PRM_RSTTIME_REG)


/* This register allows controlling the CLKREQ signal towards SCRM. */
#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG                       (0xCU)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL         (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG)


/* This register provides voltage domain management controls. */
#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG                         (0x10U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL           (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG)


/* This register allows controlling the PWRREQ signal towards power IC. */
#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG                       (0x14U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL         (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG)


/* This register allows controlling 2 parameters for power state controller. 
 * [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG                      (0x18U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT        (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG)


/* This register allows controlling LPDDR2 IO isolation removal setup. [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG                         (0x1CU)
/* Below define for backward compatibility */
#define PRM_IO_COUNT           (CSL_DEVICE_PRM_PRM_IO_COUNT_REG)


/* This register allows controlling power management features of the IOs. */
#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG                        (0x20U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL          (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG)


/* This register provides bit-fields for specifying voltage stabilization 
 * duration upon a global warm reset. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG              (0x24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET  (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_CORE_L domain transitions with OFF state. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG               (0x28U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_MPU_L domain transitions to or from OFF state. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG                (0x2CU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_MM_L domain transitions to or from OFF state. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG                 (0x30U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_CORE_L domain transitions between ON and RET or SLEEP state. [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG         (0x34U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_MPU_L domain transitions between ON and RET or SLEEP state. [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG          (0x38U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG)


/* This register provides bit-fields for specifying voltage ramp-up and 
 * ramp-down times for PRM managed external regulators. These values are used 
 * for VDD_MM_L domain transitions between ON and RET or SLEEP state. [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG           (0x3CU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG)


/* This register allows the configuration of the Voltage Processor dedicated 
 * to CORE Voltage Domain (VDD_CORE_L). */
#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG                   (0x40U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG     (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG)


/* This register reflects the idle state of the Voltage Processor dedicated to 
 * the CORE Voltage Domain (VDD_CORE_L. This register is read only and 
 * automatically updated. */
#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG                   (0x44U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_STATUS     (CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG)


/* This register allows the configuration of the voltage limits and timeout 
 * values of the Voltage Processor dedicated to the CORE Voltage Domain 
 * (VDD_CORE_L). */
#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG                 (0x48U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO   (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG)


/* This register indicates the current value of the SMPS voltage for the 
 * Voltage Processor dedicated to the CORE Voltage Domain (VDD_CORE_L). */
#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG                  (0x4CU)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VOLTAGE    (CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG)


/* This register allows the programming of the maximum voltage step and 
 * waiting time of the Voltage Processor dedicated to CORE Voltage Domain 
 * (VDD_CORE_L). */
#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG                 (0x50U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMAX   (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG)


/* This register allows the programming of the minimum voltage step and 
 * waiting time of the Voltage Processor dedicated to the CORE Voltage Domain 
 * (VDD_CORE_L). */
#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG                 (0x54U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMIN   (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG)


/* This register allows the configuration of the Voltage Processor dedicated 
 * to MPU Voltage Domain (VDD_MPU_L). */
#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG                    (0x58U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG      (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG)


/* This register reflects the idle state of the Voltage Processor dedicated to 
 * the MPU Voltage Domain (VDD_MPU_L. This register is read only and 
 * automatically updated. */
#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG                    (0x5CU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_STATUS      (CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG)


/* This register allows the configuration of the voltage limits and timeout 
 * values of the Voltage Processor dedicated to the MPU Voltage Domain 
 * (VDD_MPU_L). */
#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG                  (0x60U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO    (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG)


/* This register indicates the current value of the SMPS voltage for the 
 * Voltage Processor dedicated to the MPU Voltage Domain (VDD_MPU_L). */
#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG                   (0x64U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VOLTAGE     (CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG)


/* This register allows the programming of the maximum voltage step and 
 * waiting time of the Voltage Processor dedicated to MPU Voltage Domain 
 * (VDD_MPU_L). */
#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG                  (0x68U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMAX    (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG)


/* This register allows the programming of the minimum voltage step and 
 * waiting time of the Voltage Processor dedicated to the MPU Voltage Domain 
 * (VDD_MPU_L). */
#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG                  (0x6CU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMIN    (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG)


/* This register allows the configuration of the Voltage Processor dedicated 
 * to MM Voltage Domain (VDD_MM_L). */
#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG                     (0x70U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG       (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG)


/* This register reflects the idle state of the Voltage Processor dedicated to 
 * the MPU Voltage Domain (VDD_MM_L. This register is read only and 
 * automatically updated. */
#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG                     (0x74U)
/* Below define for backward compatibility */
#define PRM_VP_MM_STATUS       (CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG)


/* This register allows the configuration of the voltage limits and timeout 
 * values of the Voltage Processor dedicated to the MM voltage Domain 
 * (VDD_MM_L). */
#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG                   (0x78U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO     (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG)


/* This register indicates the current value of the SMPS voltage for the 
 * Voltage Processor dedicated to the MM voltage Domain (VDD_MM_L). */
#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG                    (0x7CU)
/* Below define for backward compatibility */
#define PRM_VP_MM_VOLTAGE      (CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG)


/* This register allows the programming of the maximum voltage step and 
 * waiting time of the Voltage Processor dedicated to MM voltage Domain 
 * (VDD_MM_L). */
#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG                   (0x80U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMAX     (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG)


/* This register allows the programming of the minimum voltage step and 
 * waiting time of the Voltage Processor dedicated to the MM voltage Domain 
 * (VDD_MM_L). */
#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG                   (0x84U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMIN     (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG)


/* This register allows the setting of the I2C slave address of the Power IC 
 * device, the setting of the voltage configuration register address for the 
 * CORE VDD and the Command (ON/ON-Low-Power/Retention/OFF) configuration 
 * register address values for CORE VDD (if used SMPS chips have different 
 * command configuration register than voltage configuration register). [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG              (0x88U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG)


/* This register allows the setting of the I2C slave address of the Power IC 
 * device, the setting of the voltage configuration register address for the 
 * MM VDD and the Command (ON/ON-Low-Power/Retention/OFF) configuration 
 * register address values for MM VDD (if used SMPS chips have different 
 * command configuration register than voltage configuration register).. [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG                (0x8CU)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG  (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG)


/* This register allows the setting of the I2C slave address of the Power IC 
 * device, the setting of the voltage configuration register address for the 
 * MPU VDD and the Command (ON/ON-Low-Power/Retention/OFF) configuration 
 * register address values for MPU VDD (if used SMPS chips have different 
 * command configuration register than voltage configuration register). [warm 
 * reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG               (0x90U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG)


/* This register allows the setting of the ON/ON-Low-Power/Retention/OFF 
 * command values for VDD_CORE_L channel. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG            (0x94U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L  (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG)


/* This register allows the setting of the ON/ON-Low-Power/Retention/OFF 
 * command values for VDD_MM_L channel. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG              (0x98U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L  (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG)


/* This register allows the setting of the ON/ON-Low-Power/Retention/OFF 
 * command values for VDD_MPU_L channel. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG             (0x9CU)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L  (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG)


/* Bypass data values register used for bypass command channel to send other 
 * configuration information (other then voltage configuration parameters) for 
 * SMPS chips which have no other configuration interface then this I2C 
 * interface and flag to indicate OPP change to EMIF to allow read/write 
 * leveling. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG                    (0xA0U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS      (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG)


/* This debug register logs CORE related error status coming from Voltage 
 * Controller. Must be cleared by software. */
#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG                    (0xA4U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG)


/* This debug register logs MM related error status coming from Voltage 
 * Controller. Must be cleared by software. */
#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG                      (0xA8U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST        (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG)


/* This debug register logs MPU related error status coming from Voltage 
 * Controller. Must be cleared by software. */
#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG                     (0xACU)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST       (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG)


/* This debug register logs BYPASS related error status coming from Voltage 
 * Controller. Must be cleared by software. */
#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG                  (0xB0U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST    (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG)


/* I2C configuration register. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG                  (0xB4U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE    (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG)


/* I2C Interface clock configuration parameters. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG                   (0xB8U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK     (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG)


/* Common setup for SRAM LDO transition counters. Applies to all voltage 
 * domains. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG                       (0xBCU)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT         (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG)


/* Setup of memory in WKUP voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG                  (0xC0U)
/* Below define for backward compatibility */
#define PRM_SRAM_WKUP_SETUP    (CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG)


/* Setup of the SRAM LDO for CORE voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG                  (0xC4U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP    (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG)


/* Control and status of the SRAM LDO for CORE voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG                   (0xC8U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL     (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG)


/* Setup of the SRAM LDO for MPU voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG                   (0xCCU)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP     (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG)


/* Control and status of the SRAM LDO for MPU voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG                    (0xD0U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL      (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG)


/* Setup of the SRAM LDO for GPU voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG                   (0xD4U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP     (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG)


/* Control and status of the SRAM LDO for GPU voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG                    (0xD8U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL      (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG)


/* Selects the MPU_ABB LDO mode. */
#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG                 (0xDCU)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP   (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG)


/* Control and Status of ABB on MPU voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG                  (0xE0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL    (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG)


/* Selects the GPU_ABB LDO mode. */
#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG                 (0xE4U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP   (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG)


/* Control and Status of ABB on GPU voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG                  (0xE8U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL    (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG)


/* Setup of the bandgap. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG                    (0xECU)
/* Below define for backward compatibility */
#define PRM_BANDGAP_SETUP      (CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG)


/* This register is used to control device OFF transition. */
#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG                  (0xF0U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL    (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG)


/* This register stores the start descriptor address of automatic restore 
 * phase1. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG                      (0xF4U)
/* Below define for backward compatibility */
#define PRM_PHASE1_CNDP        (CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG)


/* This register stores the start descriptor address of automatic restore 
 * phase2A. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG                     (0xF8U)
/* Below define for backward compatibility */
#define PRM_PHASE2A_CNDP       (CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG)


/* This register stores the start descriptor address of automatic restore 
 * phase2B. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG                     (0xFCU)
/* Below define for backward compatibility */
#define PRM_PHASE2B_CNDP       (CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG)


/* This register is used to control dedicated interfaces between on-chip modem 
 * and APE. */
#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG                    (0x100U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL      (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG)


/* This register provides a status on the current MPU voltage domain state. 
 * [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG                       (0x110U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU         (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG)


/* This register provides a status on the current MM voltage domain state. 
 * [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG                        (0x114U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM          (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG)


/* Setup of the SRAM LDO for DSPEVE voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG                (0x118U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG)


/* Setup of the SRAM LDO for IVA voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG                   (0x11CU)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP     (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG)


/* Control and Status of ABB on DSPEVE voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG               (0x120U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG)


/* Control and Status of ABB on IVA voltage domain. [warm reset insensitive] */
#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG                  (0x124U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL    (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG)


/* Control and status of the SRAM LDO for CORE voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG                 (0x128U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL   (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG)


/* Control and status of the SRAM LDO for CORE voltage domain. [warm reset 
 * insensitive] */
#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG                    (0x12CU)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL      (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG)


/* Selects the GPU_ABB LDO mode. */
#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG              (0x130U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG)


/* Selects the GPU_ABB LDO mode. */
#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG                 (0x134U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP   (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PRM_RSTCTRL_REG */

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_MASK           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW_MASK)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW_SHIFT          (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW__0X0           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW__0X0)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_WARM_SW__0X1           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_WARM_SW__0X1)


#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_MASK           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW_MASK)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW_SHIFT          (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW__0X0           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW__0X0)

#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTCTRL_RST_GLOBAL_COLD_SW__0X1           (CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RST_GLOBAL_COLD_SW__0X1)


#define CSL_DEVICE_PRM_PRM_RSTCTRL_REG_RESETVAL                 (0x00000000U)

/* PRM_RSTST_REG */

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_COLD_RST_MASK                (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST_RESETVAL   (0x00000001U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST_SHIFT      (0U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_COLD_RST_SHIFT               (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST__0X0       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_COLD_RST__0X0                (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST__0X1       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_COLD_RST__0X1                (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_COLD_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST_MASK    (0x00000002U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_WARM_SW_RST_MASK             (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST_SHIFT   (1U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_WARM_SW_RST_SHIFT            (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST__0X0    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_WARM_SW_RST__0X0             (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST__0X1    (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_GLOBAL_WARM_SW_RST__0X1             (CSL_DEVICE_PRM_PRM_RSTST_REG_GLOBAL_WARM_SW_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_SECURITY_VIOL_RST_MASK          (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_SECURITY_VIOL_RST_SHIFT         (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_SECURITY_VIOL_RST__0X0          (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_SECURITY_VIOL_RST__0X1          (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_SECURITY_VIOL_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST_MASK           (0x00000008U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_WDT_RST_MASK                    (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST_RESETVAL       (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST_SHIFT          (3U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_WDT_RST_SHIFT                   (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST__0X0           (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_WDT_RST__0X0                    (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST__0X1           (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_MPU_WDT_RST__0X1                    (CSL_DEVICE_PRM_PRM_RSTST_REG_MPU_WDT_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST_MASK     (0x00000020U)
/* Below define for backward compatibility */
#define PRM_RSTST_EXTERNAL_WARM_RST_MASK              (CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST_SHIFT    (5U)
/* Below define for backward compatibility */
#define PRM_RSTST_EXTERNAL_WARM_RST_SHIFT             (CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST__0X0     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_EXTERNAL_WARM_RST__0X0              (CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST__0X1     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_EXTERNAL_WARM_RST__0X1              (CSL_DEVICE_PRM_PRM_RSTST_REG_EXTERNAL_WARM_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST_MASK        (0x00000010U)
/* Below define for backward compatibility */
#define PRM_RSTST_SECURE_WDT_RST_MASK                 (CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST_RESETVAL    (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST_SHIFT       (4U)
/* Below define for backward compatibility */
#define PRM_RSTST_SECURE_WDT_RST_SHIFT                (CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST__0X0        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_SECURE_WDT_RST__0X0                 (CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST__0X1        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_SECURE_WDT_RST__0X1                 (CSL_DEVICE_PRM_PRM_RSTST_REG_SECURE_WDT_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MPU_VOLT_MGR_RST_MASK           (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MPU_VOLT_MGR_RST_SHIFT          (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MPU_VOLT_MGR_RST__0X0           (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MPU_VOLT_MGR_RST__0X1           (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MPU_VOLT_MGR_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST_MASK   (0x00000080U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_MASK            (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST_SHIFT           (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST__0X0   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST__0X0            (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST__0X1   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_MM_VOLT_MGR_RST__0X1            (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_MM_VOLT_MGR_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_MASK          (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST_SHIFT         (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST__0X0  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST__0X0          (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST__0X1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_VDD_CORE_VOLT_MGR_RST__0X1          (CSL_DEVICE_PRM_PRM_RSTST_REG_VDD_CORE_VOLT_MGR_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST_MASK           (0x00000200U)
/* Below define for backward compatibility */
#define PRM_RSTST_ICEPICK_RST_MASK                    (CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST_RESETVAL       (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST_SHIFT          (9U)
/* Below define for backward compatibility */
#define PRM_RSTST_ICEPICK_RST_SHIFT                   (CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST__0X0           (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_ICEPICK_RST__0X0                    (CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST__0X1           (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_ICEPICK_RST__0X1                    (CSL_DEVICE_PRM_PRM_RSTST_REG_ICEPICK_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST_MASK               (0x00000400U)
/* Below define for backward compatibility */
#define PRM_RSTST_C2C_RST_MASK                        (CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST_RESETVAL           (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST_SHIFT              (10U)
/* Below define for backward compatibility */
#define PRM_RSTST_C2C_RST_SHIFT                       (CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST__0X0               (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_C2C_RST__0X0                        (CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST__0X1               (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_C2C_RST__0X1                        (CSL_DEVICE_PRM_PRM_RSTST_REG_C2C_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST_MASK         (0x00000800U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MPU_RST_MASK                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST_RESETVAL     (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST_SHIFT        (11U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MPU_RST_SHIFT                 (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST__0X0         (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MPU_RST__0X0                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST__0X1         (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MPU_RST__0X1                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MPU_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST_MASK          (0x00001000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MM_RST_MASK                   (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST_RESETVAL      (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST_SHIFT         (12U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MM_RST_SHIFT                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST__0X0          (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MM_RST__0X0                   (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST__0X1          (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_MM_RST__0X1                   (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_MM_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST_MASK        (0x00002000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_CORE_RST_MASK                 (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST_RESETVAL    (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST_SHIFT       (13U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_CORE_RST_SHIFT                (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST__0X0        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_CORE_RST__0X0                 (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST__0X1        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_CORE_RST__0X1                 (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_CORE_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST_MASK               (0x00004000U)
/* Below define for backward compatibility */
#define PRM_RSTST_LLI_RST_MASK                        (CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST_RESETVAL           (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST_SHIFT              (14U)
/* Below define for backward compatibility */
#define PRM_RSTST_LLI_RST_SHIFT                       (CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST__0X0               (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_LLI_RST__0X0                        (CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST__0X1               (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_LLI_RST__0X1                        (CSL_DEVICE_PRM_PRM_RSTST_REG_LLI_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST_MASK      (0x00008000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_DSPEVE_RST_MASK               (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST_SHIFT     (15U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_DSPEVE_RST_SHIFT              (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST__0X0      (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_DSPEVE_RST__0X0               (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST__0X1      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_DSPEVE_RST__0X1               (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_DSPEVE_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST_MASK         (0x00010000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_IVA_RST_MASK                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST_MASK)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST_RESETVAL     (0x00000000U)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST_SHIFT        (16U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_IVA_RST_SHIFT                 (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST__0X0         (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_IVA_RST__0X0                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST__0X0)

#define CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST__0X1         (0x00000001U)
/* Below define for backward compatibility */
#define PRM_RSTST_TSHUT_IVA_RST__0X1                  (CSL_DEVICE_PRM_PRM_RSTST_REG_TSHUT_IVA_RST__0X1)


#define CSL_DEVICE_PRM_PRM_RSTST_REG_RESETVAL                   (0x00000001U)

/* PRM_RSTTIME_REG */

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_MASK            (0x000003FFU)
/* Below define for backward compatibility */
#define PRM_RSTTIME_RSTTIME1_MASK                     (CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_MASK)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_RESETVAL        (0x00000006U)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_SHIFT           (0U)
/* Below define for backward compatibility */
#define PRM_RSTTIME_RSTTIME1_SHIFT                    (CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME1_MAX             (0x000003ffU)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_MASK            (0x00007C00U)
/* Below define for backward compatibility */
#define PRM_RSTTIME_RSTTIME2_MASK                     (CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_MASK)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_RESETVAL        (0x00000010U)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_SHIFT           (10U)
/* Below define for backward compatibility */
#define PRM_RSTTIME_RSTTIME2_SHIFT                    (CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_SHIFT)

#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_RESERVED        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_RSTTIME_RSTTIME2_RESERVED                 (CSL_DEVICE_PRM_PRM_RSTTIME_REG_RSTTIME2_RESERVED)


#define CSL_DEVICE_PRM_PRM_RSTTIME_REG_RESETVAL                 (0x00004006U)

/* PRM_CLKREQCTRL_REG */

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_MASK      (0x00000007U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_MASK               (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_MASK)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_SHIFT              (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_SHIFT)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_NEVER     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_NEVER              (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_NEVER)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_OFF       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_OFF                (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_OFF)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RET       (0x00000002U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_RET                (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RET)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_SLEEP     (0x00000003U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_SLEEP              (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_SLEEP)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_ON        (0x00000004U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_ON                 (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_ON)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_5  (0x00000005U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_5         (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_5)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_6  (0x00000006U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_6         (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_6)

#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_7  (0x00000007U)
/* Below define for backward compatibility */
#define PRM_CLKREQCTRL_CLKREQ_COND_RESERVED_7         (CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_CLKREQ_COND_RESERVED_7)


#define CSL_DEVICE_PRM_PRM_CLKREQCTRL_REG_RESETVAL              (0x00000000U)

/* PRM_VOLTCTRL_REG */

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_MASK  (0x0000000CU)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_MASK         (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_SHIFT        (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_DISABLED     (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_DISABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_AUTO_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_AUTO_SLEEP   (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_AUTO_SLEEP)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_AUTO_RET  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_AUTO_RET     (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_AUTO_RET)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MPU_L_RESERVED     (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MPU_L_RESERVED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_MASK        (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_SHIFT       (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_DISABLED    (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_DISABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_AUTO_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_AUTO_SLEEP  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_AUTO_SLEEP)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_AUTO_RET  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_AUTO_RET    (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_AUTO_RET)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_CORE_L_RESERVED    (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_CORE_L_RESERVED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_MASK   (0x00000100U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_PRESENCE_MASK            (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_PRESENCE_SHIFT           (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_VOLTAGE_PRESENT  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_PRESENCE_VOLTAGE_PRESENT  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_VOLTAGE_PRESENT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_VOLTAGE_ABSENT  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_PRESENCE_VOLTAGE_ABSENT  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_PRESENCE_VOLTAGE_ABSENT)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_MASK  (0x00000030U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_MASK          (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_SHIFT         (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_DISABLED      (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_DISABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_AUTO_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_AUTO_SLEEP    (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_AUTO_SLEEP)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_AUTO_RET  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_AUTO_RET      (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_AUTO_RET)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_AUTO_CTRL_VDD_MM_L_RESERVED      (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_AUTO_CTRL_VDD_MM_L_RESERVED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_MASK             (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_SHIFT            (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_VOLTAGE_PRESENT  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_VOLTAGE_PRESENT  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_VOLTAGE_PRESENT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_VOLTAGE_ABSENT  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_PRESENCE_VOLTAGE_ABSENT   (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_PRESENCE_VOLTAGE_ABSENT)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_MASK        (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_SHIFT       (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_I2C_ENABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_I2C_ENABLED  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_I2C_ENABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_I2C_DISABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_CORE_I2C_DISABLE_I2C_DISABLED  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_CORE_I2C_DISABLE_I2C_DISABLED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_I2C_DISABLE_MASK         (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_SHIFT  (13U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_I2C_DISABLE_SHIFT        (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_I2C_ENABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_I2C_DISABLE_I2C_ENABLED  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_I2C_ENABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_I2C_DISABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MPU_I2C_DISABLE_I2C_DISABLED  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MPU_I2C_DISABLE_I2C_DISABLED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_MASK          (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_SHIFT  (14U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_SHIFT         (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_I2C_ENABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_I2C_ENABLED   (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_I2C_ENABLED)

#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_I2C_DISABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTCTRL_VDD_MM_I2C_DISABLE_I2C_DISABLED  (CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_VDD_MM_I2C_DISABLE_I2C_DISABLED)


#define CSL_DEVICE_PRM_PRM_VOLTCTRL_REG_RESETVAL                (0x00000300U)

/* PRM_PWRREQCTRL_REG */

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_MASK               (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_MASK)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_SHIFT              (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_SHIFT)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_NEVER     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_NEVER              (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_NEVER)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_SLEEP     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_SLEEP              (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_SLEEP)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_RET       (0x00000002U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_RET                (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_RET)

#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_OFF       (0x00000003U)
/* Below define for backward compatibility */
#define PRM_PWRREQCTRL_PWRREQ_COND_OFF                (CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_PWRREQ_COND_OFF)


#define CSL_DEVICE_PRM_PRM_PWRREQCTRL_REG_RESETVAL              (0x00000000U)

/* PRM_PSCON_COUNT_REG */

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MASK    (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_PCHARGE_TIME_MASK             (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MASK)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_RESETVAL  (0x00000017U)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_PCHARGE_TIME_SHIFT            (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_SHIFT)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PCHARGE_TIME_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_PONOUT_2_PGOODIN_TIME_MASK    (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_MASK)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_RESETVAL  (0x00000030U)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_PONOUT_2_PGOODIN_TIME_SHIFT   (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_SHIFT)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_PONOUT_2_PGOODIN_TIME_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_HG_PONOUT_2_PGOODIN_TIME_MASK  (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_MASK)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_RESETVAL  (0x00000030U)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_PSCON_COUNT_HG_PONOUT_2_PGOODIN_TIME_SHIFT  (CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_SHIFT)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_HG_PONOUT_2_PGOODIN_TIME_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_PSCON_COUNT_REG_RESETVAL             (0x00303017U)

/* PRM_IO_COUNT_REG */

#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_MASK      (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_IO_COUNT_ISO_2_ON_TIME_MASK               (CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_MASK)

#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_RESETVAL  (0x0000003aU)

#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_IO_COUNT_ISO_2_ON_TIME_SHIFT              (CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG_ISO_2_ON_TIME_MAX       (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_IO_COUNT_REG_RESETVAL                (0x0000003aU)

/* PRM_IO_PMCTRL_REG */

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_MASK            (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_SHIFT           (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_NOOVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE      (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_NOOVERRIDE)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_OVERRIDE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE        (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_OVERRIDE_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_MASK     (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_STATUS_MASK              (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_SHIFT    (1U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOCLK_STATUS_SHIFT             (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOCLK_STATUS_MAX      (0x00000001U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_MASK        (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_CTRL_MASK                 (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_RESETVAL    (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_SHIFT       (8U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_CTRL_SHIFT                (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_LOW         (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_CTRL_LOW                  (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_LOW)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_HIGH        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_CTRL_HIGH                 (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_CTRL_HIGH)


#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_MASK      (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_STATUS_MASK               (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_SHIFT     (9U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_WUCLK_STATUS_SHIFT              (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_WUCLK_STATUS_MAX       (0x00000001U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_MASK       (0x00010000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_GLOBAL_WUEN_MASK                (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_SHIFT      (16U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_GLOBAL_WUEN_SHIFT               (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_DISABLED   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_GLOBAL_WUEN_DISABLED            (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_DISABLED)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_ENABLED    (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_GLOBAL_WUEN_ENABLED             (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_GLOBAL_WUEN_ENABLED)


#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_MASK     (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_MASK              (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_SHIFT    (4U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_SHIFT             (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_NOOVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_NOOVERRIDE        (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_NOOVERRIDE)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_OVERRIDE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_ISOOVR_EXTEND_OVERRIDE          (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_ISOOVR_EXTEND_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_MASK      (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_IO_ON_STATUS_MASK               (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_SHIFT     (5U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_IO_ON_STATUS_SHIFT              (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_LOW       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_IO_ON_STATUS_LOW                (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_LOW)

#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_HIGH      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IO_PMCTRL_IO_ON_STATUS_HIGH               (CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_IO_ON_STATUS_HIGH)


#define CSL_DEVICE_PRM_PRM_IO_PMCTRL_REG_RESETVAL               (0x00000020U)

/* PRM_VOLTSETUP_WARMRESET_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_COUNT_MASK     (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_COUNT_SHIFT    (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_MASK   (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X32  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X32    (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X32)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X256   (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X2048  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X2048)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X16384  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_WARMRESET_STABLE_PRESCAL_X16384  (CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_STABLE_PRESCAL_X16384)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_WARMRESET_REG_RESETVAL     (0x00000000U)

/* PRM_VOLTSETUP_CORE_OFF_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_COUNT_MASK     (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_COUNT_SHIFT    (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_MASK   (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X64    (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X256   (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X512   (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_UP_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_COUNT_MASK   (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_OFF_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_OFF_REG_RESETVAL      (0x00000000U)

/* PRM_VOLTSETUP_MPU_OFF_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_COUNT_MASK      (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_COUNT_SHIFT     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_MASK    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_SHIFT   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_X64     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_X256    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_X512    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_UP_PRESCAL_X2048   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_COUNT_MASK    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_COUNT_SHIFT   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_X64   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_OFF_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_OFF_REG_RESETVAL       (0x00000000U)

/* PRM_VOLTSETUP_MM_OFF_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_COUNT_MASK       (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_COUNT_SHIFT      (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_MASK     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_SHIFT    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X64      (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X256     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X512     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_UP_PRESCAL_X2048    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_COUNT_MASK     (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_COUNT_SHIFT    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_MASK   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X64    (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X256   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X512   (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_OFF_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_OFF_REG_RESETVAL        (0x00000000U)

/* PRM_VOLTSETUP_CORE_RET_SLEEP_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_UP_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_CORE_RET_SLEEP_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_CORE_RET_SLEEP_REG_RESETVAL  (0x00000000U)

/* PRM_VOLTSETUP_MPU_RET_SLEEP_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_UP_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MPU_RET_SLEEP_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MPU_RET_SLEEP_REG_RESETVAL  (0x00000000U)

/* PRM_VOLTSETUP_MM_RET_SLEEP_REG */

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_UP_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_UP_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK  (0x003F0000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_COUNT_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_COUNT_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_COUNT_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_MASK  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_SHIFT  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X64  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X64)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X256  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X256)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X512  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X512)

#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTSETUP_MM_RET_SLEEP_RAMP_DOWN_PRESCAL_X2048  (CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RAMP_DOWN_PRESCAL_X2048)


#define CSL_DEVICE_PRM_PRM_VOLTSETUP_MM_RET_SLEEP_REG_RESETVAL  (0x00000000U)

/* PRM_VP_CORE_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_MASK    (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_TIMEOUTEN_MASK             (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_SHIFT   (3U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_TIMEOUTEN_SHIFT            (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_EN      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_TIMEOUTEN_EN               (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_EN)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_DIS     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_TIMEOUTEN_DIS              (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_TIMEOUTEN_DIS)


#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_FORCEUPDATE_MASK           (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_FORCEUPDATE_SHIFT          (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_NEGEDGE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_FORCEUPDATE_NEGEDGE        (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_NEGEDGE)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_POSEDGE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_FORCEUPDATE_POSEDGE        (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_FORCEUPDATE_POSEDGE)


#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_MASK      (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVDD_MASK               (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_SHIFT     (2U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVDD_SHIFT              (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_POSEDGE   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVDD_POSEDGE            (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_POSEDGE)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_NEGEDGE   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVDD_NEGEDGE            (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVDD_NEGEDGE)


#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVOLTAGE_MASK           (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_INITVOLTAGE_SHIFT          (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_INITVOLTAGE_MAX   (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_VPENABLE_MASK              (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_VPENABLE_SHIFT             (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_EN       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_VPENABLE_EN                (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_EN)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_DIS      (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_VPENABLE_DIS               (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_VPENABLE_DIS)


#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_MASK  (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_ERROROFFSET_MASK           (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_ERROROFFSET_SHIFT          (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERROROFFSET_MAX   (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_MASK    (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_ERRORGAIN_MASK             (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_SHIFT   (16U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_CONFIG_ERRORGAIN_SHIFT            (CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_ERRORGAIN_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_CONFIG_REG_RESETVAL          (0x00000000U)

/* PRM_VP_CORE_STATUS_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_MASK     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_STATUS_VPINIDLE_MASK              (CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_STATUS_VPINIDLE_SHIFT             (CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_ISIDLE   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_STATUS_VPINIDLE_ISIDLE            (CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_ISIDLE)

#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_NORMAL   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_STATUS_VPINIDLE_NORMAL            (CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_VPINIDLE_NORMAL)


#define CSL_DEVICE_PRM_PRM_VP_CORE_STATUS_REG_RESETVAL          (0x00000001U)

/* PRM_VP_CORE_VLIMITTO_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_MASK     (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_VDDMAX_MASK              (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_SHIFT    (24U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_VDDMAX_SHIFT             (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMAX_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_MASK     (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_VDDMIN_MASK              (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_SHIFT    (16U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_VDDMIN_SHIFT             (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_VDDMIN_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_MASK    (0x0000FFFFU)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_TIMEOUT_MASK             (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VLIMITTO_TIMEOUT_SHIFT            (CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_TIMEOUT_MAX     (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VLIMITTO_REG_RESETVAL        (0x00000000U)

/* PRM_VP_CORE_VOLTAGE_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_MASK   (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VOLTAGE_VPVOLTAGE_MASK            (CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VOLTAGE_VPVOLTAGE_SHIFT           (CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_VPVOLTAGE_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_MASK  (0xFFFFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VOLTAGE_FORCEUPDATEWAIT_MASK      (CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_RESETVAL  (0x00000111U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VOLTAGE_FORCEUPDATEWAIT_SHIFT     (CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_FORCEUPDATEWAIT_MAX  (0x00ffffffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VOLTAGE_REG_RESETVAL         (0x00011100U)

/* PRM_VP_CORE_VSTEPMAX_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_MASK   (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMAX_VSTEPMAX_MASK            (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMAX_VSTEPMAX_SHIFT           (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_VSTEPMAX_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMAX_SMPSWAITTIMEMAX_MASK     (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMAX_SMPSWAITTIMEMAX_SHIFT    (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_SMPSWAITTIMEMAX_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMAX_REG_RESETVAL        (0x00000000U)

/* PRM_VP_CORE_VSTEPMIN_REG */

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMIN_SMPSWAITTIMEMIN_MASK     (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMIN_SMPSWAITTIMEMIN_SHIFT    (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_SMPSWAITTIMEMIN_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_MASK   (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMIN_VSTEPMIN_MASK            (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VP_CORE_VSTEPMIN_VSTEPMIN_SHIFT           (CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_VSTEPMIN_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_CORE_VSTEPMIN_REG_RESETVAL        (0x00000000U)

/* PRM_VP_MPU_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_MASK     (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_TIMEOUTEN_MASK              (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_SHIFT    (3U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_TIMEOUTEN_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_EN       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_TIMEOUTEN_EN                (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_EN)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_DIS      (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_TIMEOUTEN_DIS               (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_TIMEOUTEN_DIS)


#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_MASK   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_FORCEUPDATE_MASK            (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_FORCEUPDATE_SHIFT           (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_NEGEDGE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_FORCEUPDATE_NEGEDGE         (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_NEGEDGE)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_POSEDGE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_FORCEUPDATE_POSEDGE         (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_FORCEUPDATE_POSEDGE)


#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_MASK       (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVDD_MASK                (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_SHIFT      (2U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVDD_SHIFT               (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_POSEDGE    (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVDD_POSEDGE             (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_POSEDGE)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_NEGEDGE    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVDD_NEGEDGE             (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVDD_NEGEDGE)


#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_MASK   (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVOLTAGE_MASK            (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_INITVOLTAGE_SHIFT           (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_INITVOLTAGE_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_VPENABLE_MASK               (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_VPENABLE_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_EN        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_VPENABLE_EN                 (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_EN)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_DIS       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_VPENABLE_DIS                (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_VPENABLE_DIS)


#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_MASK   (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_ERROROFFSET_MASK            (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_ERROROFFSET_SHIFT           (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERROROFFSET_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_MASK     (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_ERRORGAIN_MASK              (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_SHIFT    (16U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_CONFIG_ERRORGAIN_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_ERRORGAIN_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_CONFIG_REG_RESETVAL           (0x00000000U)

/* PRM_VP_MPU_STATUS_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_STATUS_VPINIDLE_MASK               (CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_STATUS_VPINIDLE_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_ISIDLE    (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_STATUS_VPINIDLE_ISIDLE             (CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_ISIDLE)

#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_NORMAL    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_STATUS_VPINIDLE_NORMAL             (CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_VPINIDLE_NORMAL)


#define CSL_DEVICE_PRM_PRM_VP_MPU_STATUS_REG_RESETVAL           (0x00000001U)

/* PRM_VP_MPU_VLIMITTO_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_MASK      (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_VDDMAX_MASK               (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_SHIFT     (24U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_VDDMAX_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMAX_MAX       (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_MASK      (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_VDDMIN_MASK               (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_SHIFT     (16U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_VDDMIN_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_VDDMIN_MAX       (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_MASK     (0x0000FFFFU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_TIMEOUT_MASK              (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VLIMITTO_TIMEOUT_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_TIMEOUT_MAX      (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VLIMITTO_REG_RESETVAL         (0x00000000U)

/* PRM_VP_MPU_VOLTAGE_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_MASK    (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VOLTAGE_VPVOLTAGE_MASK             (CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VOLTAGE_VPVOLTAGE_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_VPVOLTAGE_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_MASK  (0xFFFFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VOLTAGE_FORCEUPDATEWAIT_MASK       (CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_RESETVAL  (0x00000111U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VOLTAGE_FORCEUPDATEWAIT_SHIFT      (CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_FORCEUPDATEWAIT_MAX  (0x00ffffffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VOLTAGE_REG_RESETVAL          (0x00011100U)

/* PRM_VP_MPU_VSTEPMAX_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_MASK    (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMAX_VSTEPMAX_MASK             (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMAX_VSTEPMAX_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_VSTEPMAX_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMAX_SMPSWAITTIMEMAX_MASK      (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMAX_SMPSWAITTIMEMAX_SHIFT     (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_SMPSWAITTIMEMAX_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMAX_REG_RESETVAL         (0x00000000U)

/* PRM_VP_MPU_VSTEPMIN_REG */

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMIN_SMPSWAITTIMEMIN_MASK      (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMIN_SMPSWAITTIMEMIN_SHIFT     (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_SMPSWAITTIMEMIN_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_MASK    (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMIN_VSTEPMIN_MASK             (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_VP_MPU_VSTEPMIN_VSTEPMIN_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_VSTEPMIN_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MPU_VSTEPMIN_REG_RESETVAL         (0x00000000U)

/* PRM_VP_MM_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_MASK      (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_TIMEOUTEN_MASK               (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_SHIFT     (3U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_TIMEOUTEN_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_EN        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_TIMEOUTEN_EN                 (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_EN)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_DIS       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_TIMEOUTEN_DIS                (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_TIMEOUTEN_DIS)


#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_MASK    (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_FORCEUPDATE_MASK             (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_SHIFT   (1U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_FORCEUPDATE_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_NEGEDGE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_FORCEUPDATE_NEGEDGE          (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_NEGEDGE)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_POSEDGE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_FORCEUPDATE_POSEDGE          (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_FORCEUPDATE_POSEDGE)


#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_MASK        (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVDD_MASK                 (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_RESETVAL    (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_SHIFT       (2U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVDD_SHIFT                (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_POSEDGE     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVDD_POSEDGE              (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_POSEDGE)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_NEGEDGE     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVDD_NEGEDGE              (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVDD_NEGEDGE)


#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_MASK    (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVOLTAGE_MASK             (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_SHIFT   (8U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_INITVOLTAGE_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_INITVOLTAGE_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_VPENABLE_MASK                (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_SHIFT      (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_VPENABLE_SHIFT               (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_EN         (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_VPENABLE_EN                  (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_EN)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_DIS        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_VPENABLE_DIS                 (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_VPENABLE_DIS)


#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_MASK    (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_ERROROFFSET_MASK             (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_SHIFT   (24U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_ERROROFFSET_SHIFT            (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERROROFFSET_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_MASK      (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_ERRORGAIN_MASK               (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_SHIFT     (16U)
/* Below define for backward compatibility */
#define PRM_VP_MM_CONFIG_ERRORGAIN_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_ERRORGAIN_MAX       (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_CONFIG_REG_RESETVAL            (0x00000000U)

/* PRM_VP_MM_STATUS_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_MASK       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_STATUS_VPINIDLE_MASK                (CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_RESETVAL   (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_SHIFT      (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_STATUS_VPINIDLE_SHIFT               (CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_ISIDLE     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VP_MM_STATUS_VPINIDLE_ISIDLE              (CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_ISIDLE)

#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_NORMAL     (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_STATUS_VPINIDLE_NORMAL              (CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_VPINIDLE_NORMAL)


#define CSL_DEVICE_PRM_PRM_VP_MM_STATUS_REG_RESETVAL            (0x00000001U)

/* PRM_VP_MM_VLIMITTO_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_MASK       (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_VDDMAX_MASK                (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_SHIFT      (24U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_VDDMAX_SHIFT               (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMAX_MAX        (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_MASK       (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_VDDMIN_MASK                (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_SHIFT      (16U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_VDDMIN_SHIFT               (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_VDDMIN_MAX        (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_MASK      (0x0000FFFFU)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_TIMEOUT_MASK               (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VLIMITTO_TIMEOUT_SHIFT              (CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_TIMEOUT_MAX       (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VLIMITTO_REG_RESETVAL          (0x00000000U)

/* PRM_VP_MM_VOLTAGE_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_MASK     (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MM_VOLTAGE_VPVOLTAGE_MASK              (CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VOLTAGE_VPVOLTAGE_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_VPVOLTAGE_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_MASK  (0xFFFFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VOLTAGE_FORCEUPDATEWAIT_MASK        (CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_RESETVAL  (0x00000111U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VOLTAGE_FORCEUPDATEWAIT_SHIFT       (CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_FORCEUPDATEWAIT_MAX  (0x00ffffffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VOLTAGE_REG_RESETVAL           (0x00011100U)

/* PRM_VP_MM_VSTEPMAX_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_MASK     (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMAX_VSTEPMAX_MASK              (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMAX_VSTEPMAX_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_VSTEPMAX_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMAX_SMPSWAITTIMEMAX_MASK       (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMAX_SMPSWAITTIMEMAX_SHIFT      (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_SMPSWAITTIMEMAX_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMAX_REG_RESETVAL          (0x00000000U)

/* PRM_VP_MM_VSTEPMIN_REG */

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK  (0x00FFFF00U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMIN_SMPSWAITTIMEMIN_MASK       (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMIN_SMPSWAITTIMEMIN_SHIFT      (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_SMPSWAITTIMEMIN_MAX  (0x0000ffffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_MASK     (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMIN_VSTEPMIN_MASK              (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_MASK)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VP_MM_VSTEPMIN_VSTEPMIN_SHIFT             (CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_VSTEPMIN_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VP_MM_VSTEPMIN_REG_RESETVAL          (0x00000000U)

/* PRM_VC_SMPS_CORE_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_MASK  (0x0000007FU)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SA_VDD_CORE_L_MASK    (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SA_VDD_CORE_L_SHIFT   (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SA_VDD_CORE_L_MAX  (0x0000007fU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_VOLRA_VDD_CORE_L_MASK  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_VOLRA_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_VOLRA_VDD_CORE_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMDRA_VDD_CORE_L_MASK  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMDRA_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMDRA_VDD_CORE_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMD_VDD_CORE_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMD_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMD_VDD_CORE_L_MPU    (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_CORE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_CMD_VDD_CORE_L_CORE   (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_CMD_VDD_CORE_L_CORE)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SEL_SA_VDD_CORE_L_MASK  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SEL_SA_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SEL_SA_VDD_CORE_L_SEL_MPU  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SEL_CORE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_SEL_SA_VDD_CORE_L_SEL_CORE  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_SEL_SA_VDD_CORE_L_SEL_CORE)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAV_VDD_CORE_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SHIFT  (25U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAV_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAV_VDD_CORE_L_SEL_MPU  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SEL_CORE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAV_VDD_CORE_L_SEL_CORE  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAV_VDD_CORE_L_SEL_CORE)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAC_VDD_CORE_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SHIFT  (26U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAC_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAC_VDD_CORE_L_SEL_MPU  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SEL_CORE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RAC_VDD_CORE_L_SEL_CORE  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RAC_VDD_CORE_L_SEL_CORE)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RACEN_VDD_CORE_L_MASK  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_SHIFT  (27U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RACEN_VDD_CORE_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_VOLRA  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RACEN_VDD_CORE_L_VOLRA  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_VOLRA)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_CMDRA  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_CORE_CONFIG_RACEN_VDD_CORE_L_CMDRA  (CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RACEN_VDD_CORE_L_CMDRA)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_CORE_CONFIG_REG_RESETVAL     (0x16000000U)

/* PRM_VC_SMPS_MM_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_MASK  (0x0000007FU)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SA_VDD_MM_L_MASK        (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SA_VDD_MM_L_SHIFT       (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SA_VDD_MM_L_MAX  (0x0000007fU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_VOLRA_VDD_MM_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_VOLRA_VDD_MM_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_VOLRA_VDD_MM_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMDRA_VDD_MM_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMDRA_VDD_MM_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMDRA_VDD_MM_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SEL_SA_VDD_MM_L_MASK    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SEL_SA_VDD_MM_L_SHIFT   (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SEL_SA_VDD_MM_L_SEL_MPU  (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SEL_MM  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_SEL_SA_VDD_MM_L_SEL_MM  (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_SEL_SA_VDD_MM_L_SEL_MM)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAV_VDD_MM_L_MASK       (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SHIFT  (25U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAV_VDD_MM_L_SHIFT      (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAV_VDD_MM_L_SEL_MPU    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SEL_MM  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAV_VDD_MM_L_SEL_MM     (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAV_VDD_MM_L_SEL_MM)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAC_VDD_MM_L_MASK       (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SHIFT  (26U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAC_VDD_MM_L_SHIFT      (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SEL_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAC_VDD_MM_L_SEL_MPU    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SEL_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SEL_MM  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RAC_VDD_MM_L_SEL_MM     (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RAC_VDD_MM_L_SEL_MM)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RACEN_VDD_MM_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_SHIFT  (27U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RACEN_VDD_MM_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_VOLRA  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RACEN_VDD_MM_L_VOLRA    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_VOLRA)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_CMDRA  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_RACEN_VDD_MM_L_CMDRA    (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RACEN_VDD_MM_L_CMDRA)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMD_VDD_MM_L_MASK       (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMD_VDD_MM_L_SHIFT      (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MPU  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMD_VDD_MM_L_MPU        (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MPU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MM  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MM_CONFIG_CMD_VDD_MM_L_MM         (CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_CMD_VDD_MM_L_MM)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MM_CONFIG_REG_RESETVAL       (0x16000000U)

/* PRM_VC_SMPS_MPU_CONFIG_REG */

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_MASK  (0x0000007FU)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_SA_VDD_MPU_L_MASK      (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_SA_VDD_MPU_L_SHIFT     (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SA_VDD_MPU_L_MAX  (0x0000007fU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_VOLRA_VDD_MPU_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_VOLRA_VDD_MPU_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_VOLRA_VDD_MPU_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_CMDRA_VDD_MPU_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_CMDRA_VDD_MPU_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMDRA_VDD_MPU_L_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_SEL_SA_VDD_MPU_L_MASK  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_SHIFT  (24U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_SEL_SA_VDD_MPU_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_SEL_SA_VDD_MPU_L_MAX  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RAV_VDD_MPU_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_SHIFT  (25U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RAV_VDD_MPU_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAV_VDD_MPU_L_MAX  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RAC_VDD_MPU_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_SHIFT  (26U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RAC_VDD_MPU_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RAC_VDD_MPU_L_MAX  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RACEN_VDD_MPU_L_MASK   (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_SHIFT  (27U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RACEN_VDD_MPU_L_SHIFT  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_VOLRA  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RACEN_VDD_MPU_L_VOLRA  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_VOLRA)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_CMDRA  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_RACEN_VDD_MPU_L_CMDRA  (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RACEN_VDD_MPU_L_CMDRA)


#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_CMD_VDD_MPU_L_MASK     (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_MASK)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_VC_SMPS_MPU_CONFIG_CMD_VDD_MPU_L_SHIFT    (CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_CMD_VDD_MPU_L_MAX  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_SMPS_MPU_CONFIG_REG_RESETVAL      (0x00000000U)

/* PRM_VC_VAL_CMD_VDD_CORE_L_REG */

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_MASK    (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_ON_MASK             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_SHIFT   (24U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_ON_SHIFT            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ON_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_MASK  (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_ONLP_MASK           (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_ONLP_SHIFT          (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_ONLP_MAX   (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_MASK   (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_RET_MASK            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_RET_SHIFT           (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RET_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_MASK   (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_OFF_MASK            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_CORE_L_OFF_SHIFT           (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_OFF_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_CORE_L_REG_RESETVAL   (0x00000000U)

/* PRM_VC_VAL_CMD_VDD_MM_L_REG */

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_MASK    (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_ONLP_MASK             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_SHIFT   (16U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_ONLP_SHIFT            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ONLP_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_MASK      (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_ON_MASK               (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_SHIFT     (24U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_ON_SHIFT              (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_ON_MAX       (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_MASK     (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_RET_MASK              (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_SHIFT    (8U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_RET_SHIFT             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RET_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_MASK     (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_OFF_MASK              (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MM_L_OFF_SHIFT             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_OFF_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MM_L_REG_RESETVAL     (0x00000000U)

/* PRM_VC_VAL_CMD_VDD_MPU_L_REG */

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_MASK   (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_ONLP_MASK            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_SHIFT  (16U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_ONLP_SHIFT           (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ONLP_MAX    (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_MASK     (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_ON_MASK              (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_SHIFT    (24U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_ON_SHIFT             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_ON_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_MASK    (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_RET_MASK             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_SHIFT   (8U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_RET_SHIFT            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RET_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_MASK    (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_OFF_MASK             (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_SHIFT   (0U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_CMD_VDD_MPU_L_OFF_SHIFT            (CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_OFF_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_CMD_VDD_MPU_L_REG_RESETVAL    (0x00000000U)

/* PRM_VC_VAL_BYPASS_REG */

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_MASK       (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_REGADDR_MASK                (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_SHIFT      (8U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_REGADDR_SHIFT               (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_REGADDR_MAX        (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_MASK          (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_DATA_MASK                   (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_RESETVAL      (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_SHIFT         (16U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_DATA_SHIFT                  (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_DATA_MAX           (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_MASK     (0x0000007FU)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_SLAVEADDR_MASK              (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_SLAVEADDR_SHIFT             (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_SLAVEADDR_MAX      (0x0000007fU)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_MASK         (0x01000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_VALID_MASK                  (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_RESETVAL     (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_SHIFT        (24U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_VALID_SHIFT                 (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_ACK          (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_VALID_ACK                   (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_ACK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_PENDING      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_VALID_PENDING               (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_VALID_PENDING)


#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_MASK    (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_MASK)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_SHIFT  (25U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_SHIFT   (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_EN_LVL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_EN_LVL  (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_EN_LVL)

#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_DIS_LVL  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_DIS_LVL  (CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_OPP_CHANGE_EMIF_LVL_DIS_LVL)


#define CSL_DEVICE_PRM_PRM_VC_VAL_BYPASS_REG_RESETVAL           (0x00000000U)

/* PRM_VC_CORE_ERRST_REG */

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_SA_ERR_CORE_MASK       (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_SA_ERR_CORE_SHIFT      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_SA_ERR_CORE_ERROR      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_SA_ERR_CORE_OK         (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_SA_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_RA_ERR_CORE_MASK       (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_RA_ERR_CORE_SHIFT      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_RA_ERR_CORE_ERROR      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_RA_ERR_CORE_OK         (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_RA_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_TIMEOUT_ERR_CORE_MASK  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_TIMEOUT_ERR_CORE_SHIFT  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_TIMEOUT_ERR_CORE_ERROR  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_SMPS_TIMEOUT_ERR_CORE_OK    (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_SMPS_TIMEOUT_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_SA_ERR_CORE_MASK       (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_SA_ERR_CORE_SHIFT      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_SA_ERR_CORE_ERROR      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_SA_ERR_CORE_OK         (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_SA_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_RA_ERR_CORE_MASK       (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_RA_ERR_CORE_SHIFT      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_RA_ERR_CORE_ERROR      (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_RA_ERR_CORE_OK         (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_RA_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_TIMEOUT_ERR_CORE_MASK  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_TIMEOUT_ERR_CORE_SHIFT  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_TIMEOUT_ERR_CORE_ERROR  (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CORE_ERRST_VFSM_TIMEOUT_ERR_CORE_OK    (CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_VFSM_TIMEOUT_ERR_CORE_OK)


#define CSL_DEVICE_PRM_PRM_VC_CORE_ERRST_REG_RESETVAL           (0x00000000U)

/* PRM_VC_MM_ERRST_REG */

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_SA_ERR_MM_MASK           (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_SA_ERR_MM_SHIFT          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_SA_ERR_MM_ERROR          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_OK    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_SA_ERR_MM_OK             (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_SA_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_RA_ERR_MM_MASK           (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_RA_ERR_MM_SHIFT          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_RA_ERR_MM_ERROR          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_OK    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_RA_ERR_MM_OK             (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_RA_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_TIMEOUT_ERR_MM_MASK      (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_TIMEOUT_ERR_MM_SHIFT     (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_TIMEOUT_ERR_MM_ERROR     (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_SMPS_TIMEOUT_ERR_MM_OK        (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_SMPS_TIMEOUT_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_SA_ERR_MM_MASK           (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_SA_ERR_MM_SHIFT          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_SA_ERR_MM_ERROR          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_OK    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_SA_ERR_MM_OK             (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_SA_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_RA_ERR_MM_MASK           (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_RA_ERR_MM_SHIFT          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_RA_ERR_MM_ERROR          (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_OK    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_RA_ERR_MM_OK             (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_RA_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_TIMEOUT_ERR_MM_MASK      (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_TIMEOUT_ERR_MM_SHIFT     (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_TIMEOUT_ERR_MM_ERROR     (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MM_ERRST_VFSM_TIMEOUT_ERR_MM_OK        (CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_VFSM_TIMEOUT_ERR_MM_OK)


#define CSL_DEVICE_PRM_PRM_VC_MM_ERRST_REG_RESETVAL             (0x00000000U)

/* PRM_VC_MPU_ERRST_REG */

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_SA_ERR_MPU_MASK         (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_SA_ERR_MPU_SHIFT        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_SA_ERR_MPU_ERROR        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_SA_ERR_MPU_OK           (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_SA_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_RA_ERR_MPU_MASK         (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_RA_ERR_MPU_SHIFT        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_RA_ERR_MPU_ERROR        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_RA_ERR_MPU_OK           (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_RA_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_TIMEOUT_ERR_MPU_MASK    (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_TIMEOUT_ERR_MPU_SHIFT   (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_TIMEOUT_ERR_MPU_ERROR   (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_SMPS_TIMEOUT_ERR_MPU_OK      (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_SMPS_TIMEOUT_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_SA_ERR_MPU_MASK         (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_SA_ERR_MPU_SHIFT        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_SA_ERR_MPU_ERROR        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_SA_ERR_MPU_OK           (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_SA_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_RA_ERR_MPU_MASK         (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_RA_ERR_MPU_SHIFT        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_RA_ERR_MPU_ERROR        (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_RA_ERR_MPU_OK           (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_RA_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_TIMEOUT_ERR_MPU_MASK    (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_MASK)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_TIMEOUT_ERR_MPU_SHIFT   (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_TIMEOUT_ERR_MPU_ERROR   (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_MPU_ERRST_VFSM_TIMEOUT_ERR_MPU_OK      (CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_VFSM_TIMEOUT_ERR_MPU_OK)


#define CSL_DEVICE_PRM_PRM_VC_MPU_ERRST_REG_RESETVAL            (0x00000000U)

/* PRM_VC_BYPASS_ERRST_REG */

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_SA_ERR_MASK          (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_MASK)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_SA_ERR_SHIFT         (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_SA_ERR_ERROR         (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_OK   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_SA_ERR_OK            (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_SA_ERR_OK)


#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_RA_ERR_MASK          (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_MASK)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_RA_ERR_SHIFT         (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_RA_ERR_ERROR         (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_OK   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_RA_ERR_OK            (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_RA_ERR_OK)


#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_TIMEOUT_ERR_MASK     (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_MASK)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_TIMEOUT_ERR_SHIFT    (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_ERROR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_TIMEOUT_ERR_ERROR    (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_ERROR)

#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_OK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_BYPASS_ERRST_BYPS_TIMEOUT_ERR_OK       (CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_BYPS_TIMEOUT_ERR_OK)


#define CSL_DEVICE_PRM_PRM_VC_BYPASS_ERRST_REG_RESETVAL         (0x00000000U)

/* PRM_VC_CFG_I2C_MODE_REG */

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_MASK    (0x00000010U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_SRMODEEN_MASK             (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_SHIFT   (4U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_SRMODEEN_SHIFT            (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_EN_SR   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_SRMODEEN_EN_SR            (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_EN_SR)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_DIS_SR  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_SRMODEEN_DIS_SR           (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_SRMODEEN_DIS_SR)


#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_MASK     (0x00000007U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMCODE_MASK              (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMCODE_SHIFT             (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMCODE_MAX      (0x00000007U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_MASK    (0x00000008U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMODEEN_MASK             (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_RESETVAL  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_SHIFT   (3U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMODEEN_SHIFT            (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_EN_HS   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMODEEN_EN_HS            (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_EN_HS)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_DIS_HS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_HSMODEEN_DIS_HS           (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_HSMODEEN_DIS_HS)


#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_MASK   (0x00000040U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_DFILTEREN_MASK            (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_DFILTEREN_SHIFT           (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_DFILTER_EN1  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_DFILTEREN_DFILTER_EN1     (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_DFILTER_EN1)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_DFILTER_EN2  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_MODE_DFILTEREN_DFILTER_EN2     (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_DFILTEREN_DFILTER_EN2)


#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_MODE_REG_RESETVAL         (0x00000018U)

/* PRM_VC_CFG_I2C_CLK_REG */

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_MASK         (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_SCLH_MASK                  (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_RESETVAL     (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_SHIFT        (0U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_SCLH_SHIFT                 (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLH_MAX          (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_MASK         (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_SCLL_MASK                  (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_RESETVAL     (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_SHIFT        (8U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_SCLL_SHIFT                 (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_SCLL_MAX          (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_MASK       (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_HSSCLH_MASK                (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_SHIFT      (16U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_HSSCLH_SHIFT               (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLH_MAX        (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_MASK       (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_HSSCLL_MASK                (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_MASK)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_SHIFT      (24U)
/* Below define for backward compatibility */
#define PRM_VC_CFG_I2C_CLK_HSSCLL_SHIFT               (CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_SHIFT)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_HSSCLL_MAX        (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_VC_CFG_I2C_CLK_REG_RESETVAL          (0x00000000U)

/* PRM_SRAM_COUNT_REG */

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_MASK  (0x0000003FU)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_PCHARGECNT_VALUE_MASK          (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_RESETVAL  (0x00000017U)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_PCHARGECNT_VALUE_SHIFT         (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_PCHARGECNT_VALUE_MAX  (0x0000003fU)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_VSETUPCNT_VALUE_MASK           (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_VSETUPCNT_VALUE_SHIFT          (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_VSETUPCNT_VALUE_MAX   (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_MASK     (0x00FF0000U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_SLPCNT_VALUE_MASK              (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_SHIFT    (16U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_SLPCNT_VALUE_SHIFT             (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_SLPCNT_VALUE_MAX      (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_MASK    (0xFF000000U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_STARTUP_COUNT_MASK             (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_RESETVAL  (0x00000078U)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_SHIFT   (24U)
/* Below define for backward compatibility */
#define PRM_SRAM_COUNT_STARTUP_COUNT_SHIFT            (CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_STARTUP_COUNT_MAX     (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_SRAM_COUNT_REG_RESETVAL              (0x78000017U)

/* PRM_SRAM_WKUP_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_MASK           (CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_SHIFT          (CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_RTA_ENABLED    (CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SRAM_WKUP_SETUP_ENABLE_RTA_RTA_DISABLED   (CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SRAM_WKUP_SETUP_REG_RESETVAL         (0x00000000U)

/* PRM_SLDO_CORE_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_MASK           (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SHIFT          (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_MASK         (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_MASK           (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_SHIFT          (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_RTA_ENABLED    (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENABLE_RTA_RTA_DISABLED   (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_MASK     (0x00000008U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC1_MASK              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHIFT    (3U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHIFT             (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHORT_PROT_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC1_SHORT_PROT_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_MASK     (0x00000010U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC2_MASK              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_SHIFT    (4U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC2_SHIFT             (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_EXT_CAP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC2_EXT_CAP           (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_EXT_CAP)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_NO_EXT_CAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC2_NO_EXT_CAP        (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC2_NO_EXT_CAP)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_MASK     (0x00000020U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC3_MASK              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SHIFT    (5U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC3_SHIFT             (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC3_SUB_REGUL_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC3_SUB_REGUL_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_MASK     (0x00000040U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC4_MASK              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_SHIFT    (6U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC4_SHIFT             (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_EXT_CLOCK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC4_EXT_CLOCK         (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_EXT_CLOCK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_NO_EXT_CLOCK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC4_NO_EXT_CLOCK      (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC4_NO_EXT_CLOCK)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_MASK     (0x00000080U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC5_MASK              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_SHIFT    (7U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC5_SHIFT             (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_ONE_STEP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC5_ONE_STEP          (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_ONE_STEP)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_TWO_STEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_ENFUNC5_TWO_STEP          (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_ENFUNC5_TWO_STEP)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_MASK      (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_AIPOFF_MASK               (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_SHIFT     (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_AIPOFF_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_NO_OVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_AIPOFF_NO_OVERRIDE        (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_NO_OVERRIDE)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_OVERRIDE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_SETUP_AIPOFF_OVERRIDE           (CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_AIPOFF_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_SETUP_REG_RESETVAL         (0x00000000U)

/* PRM_SLDO_CORE_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_MASK        (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_SHIFT       (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_ACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_ACTIVE      (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_ACTIVE)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_RETENTION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAMLDO_STATUS_RETENTION   (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAMLDO_STATUS_RETENTION)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_MASK    (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_SHIFT   (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_IDLE    (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION  (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_MASK        (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_SHIFT       (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_CORE_CTRL_RETMODE_ENABLE_DISABLED    (CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RETMODE_ENABLE_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_CORE_CTRL_REG_RESETVAL          (0x00000000U)

/* PRM_SLDO_MPU_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_MASK   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_ACT_MASK            (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_ACT_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_SLEEP_MASK          (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_SLEEP_SHIFT         (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_MASK      (0x00000040U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC4_MASK               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_SHIFT     (6U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC4_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_EXT_CLOCK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC4_EXT_CLOCK          (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_EXT_CLOCK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_NO_EXT_CLOCK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC4_NO_EXT_CLOCK       (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC4_NO_EXT_CLOCK)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_MASK      (0x00000080U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC5_MASK               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_SHIFT     (7U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC5_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_ONE_STEP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC5_ONE_STEP           (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_ONE_STEP)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_TWO_STEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC5_TWO_STEP           (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC5_TWO_STEP)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_MASK       (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_AIPOFF_MASK                (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_SHIFT      (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_AIPOFF_SHIFT               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_NO_OVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_AIPOFF_NO_OVERRIDE         (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_NO_OVERRIDE)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_OVERRIDE   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_AIPOFF_OVERRIDE            (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_AIPOFF_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENABLE_RTA_MASK            (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENABLE_RTA_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENABLE_RTA_RTA_ENABLED     (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENABLE_RTA_RTA_DISABLED    (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_MASK      (0x00000008U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC1_MASK               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHIFT     (3U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC1_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC1_SHORT_PROT_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC1_SHORT_PROT_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC2_MASK               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC2_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_EXT_CAP   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC2_EXT_CAP            (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_EXT_CAP)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_NO_EXT_CAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC2_NO_EXT_CAP         (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC2_NO_EXT_CAP)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_MASK      (0x00000020U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC3_MASK               (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SHIFT     (5U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC3_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC3_SUB_REGUL_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_SETUP_ENFUNC3_SUB_REGUL_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_SETUP_REG_RESETVAL          (0x00000000U)

/* PRM_SLDO_MPU_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAMLDO_STATUS_MASK         (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAMLDO_STATUS_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_ACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAMLDO_STATUS_ACTIVE       (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_ACTIVE)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_RETENTION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAMLDO_STATUS_RETENTION    (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAMLDO_STATUS_RETENTION)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAM_IN_TRANSITION_MASK     (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAM_IN_TRANSITION_SHIFT    (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAM_IN_TRANSITION_IDLE     (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION  (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_RETMODE_ENABLE_MASK         (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_RETMODE_ENABLE_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_RETMODE_ENABLE_DISABLED     (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_MPU_CTRL_RETMODE_ENABLE_ENABLED      (CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RETMODE_ENABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_MPU_CTRL_REG_RESETVAL           (0x00000000U)

/* PRM_SLDO_GPU_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_MASK   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_ACT_MASK            (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_ACT_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_SLEEP_MASK          (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_SLEEP_SHIFT         (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_MASK      (0x00000040U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC4_MASK               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_SHIFT     (6U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC4_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_EXT_CLOCK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC4_EXT_CLOCK          (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_EXT_CLOCK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_NO_EXT_CLOCK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC4_NO_EXT_CLOCK       (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC4_NO_EXT_CLOCK)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_MASK      (0x00000080U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC5_MASK               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_SHIFT     (7U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC5_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_ONE_STEP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC5_ONE_STEP           (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_ONE_STEP)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_TWO_STEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC5_TWO_STEP           (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC5_TWO_STEP)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_MASK       (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_AIPOFF_MASK                (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_SHIFT      (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_AIPOFF_SHIFT               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_NO_OVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_AIPOFF_NO_OVERRIDE         (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_NO_OVERRIDE)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_OVERRIDE   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_AIPOFF_OVERRIDE            (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_AIPOFF_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENABLE_RTA_MASK            (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENABLE_RTA_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENABLE_RTA_RTA_ENABLED     (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENABLE_RTA_RTA_DISABLED    (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_MASK      (0x00000008U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC1_MASK               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHIFT     (3U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC1_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC1_SHORT_PROT_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC1_SHORT_PROT_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC2_MASK               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC2_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_EXT_CAP   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC2_EXT_CAP            (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_EXT_CAP)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_NO_EXT_CAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC2_NO_EXT_CAP         (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC2_NO_EXT_CAP)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_MASK      (0x00000020U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC3_MASK               (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SHIFT     (5U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC3_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC3_SUB_REGUL_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_SETUP_ENFUNC3_SUB_REGUL_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_SETUP_REG_RESETVAL          (0x00000000U)

/* PRM_SLDO_GPU_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAMLDO_STATUS_MASK         (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAMLDO_STATUS_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_ACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAMLDO_STATUS_ACTIVE       (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_ACTIVE)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_RETENTION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAMLDO_STATUS_RETENTION    (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAMLDO_STATUS_RETENTION)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAM_IN_TRANSITION_MASK     (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAM_IN_TRANSITION_SHIFT    (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAM_IN_TRANSITION_IDLE     (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION  (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_RETMODE_ENABLE_MASK         (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_RETMODE_ENABLE_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_RETMODE_ENABLE_DISABLED     (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_GPU_CTRL_RETMODE_ENABLE_ENABLED      (CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RETMODE_ENABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_GPU_CTRL_REG_RESETVAL           (0x00000000U)

/* PRM_ABBLDO_MPU_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_ACTIVE_FBB_SEL_MASK      (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_ACTIVE_FBB_SEL_SHIFT     (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_ACTIVE_FBB_SEL_BYPASS    (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_FBB  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_ACTIVE_FBB_SEL_FBB       (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_ACTIVE_FBB_SEL_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2EN_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2EN_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_BYPASS    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2EN_BYPASS             (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_FUNCTIONAL  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2EN_FUNCTIONAL         (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2EN_FUNCTIONAL)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2_WTCNT_VALUE_MASK     (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_SR2_WTCNT_VALUE_SHIFT    (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_SR2_WTCNT_VALUE_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_NOCAP_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_NOCAP_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_CAP       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_NOCAP_CAP                (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_CAP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_NOCAP     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_SETUP_NOCAP_NOCAP              (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_NOCAP_NOCAP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_SETUP_REG_RESETVAL        (0x00000000U)

/* PRM_ABBLDO_MPU_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_MASK     (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_MASK              (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_SHIFT             (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_DEFAULT_NOMINAL   (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_FASTOPP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_FASTOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_FASTOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_NOMINALOPP  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_NOMINALOPP        (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_NOMINALOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_SLOWOPP  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_SEL_SLOWOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_SEL_SLOWOPP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_CHANGE_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_OPP_CHANGE_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_OPP_CHANGE_MAX   (0x00000001U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_MASK  (0x00000018U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_BYPASS         (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_FBB   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_FBB            (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_FBB)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_RESERVED       (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_RESERVED)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_STATUS_RESERVED1      (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_STATUS_RESERVED1)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_IN_TRANSITION_MASK    (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_IN_TRANSITION_SHIFT   (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_IN_TRANSITION_IDLE    (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_MPU_CTRL_SR2_IN_TRANSITION_INTRANSITION  (CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION)


#define CSL_DEVICE_PRM_PRM_ABBLDO_MPU_CTRL_REG_RESETVAL         (0x00000000U)

/* PRM_ABBLDO_GPU_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2EN_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2EN_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_BYPASS    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2EN_BYPASS             (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_FUNCTIONAL  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2EN_FUNCTIONAL         (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2EN_FUNCTIONAL)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_ACTIVE_FBB_SEL_MASK      (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_ACTIVE_FBB_SEL_SHIFT     (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_ACTIVE_FBB_SEL_BYPASS    (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_FBB  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_ACTIVE_FBB_SEL_FBB       (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_ACTIVE_FBB_SEL_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_NOCAP_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_NOCAP_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_CAP       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_NOCAP_CAP                (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_CAP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_NOCAP     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_NOCAP_NOCAP              (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_NOCAP_NOCAP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2_WTCNT_VALUE_MASK     (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_SETUP_SR2_WTCNT_VALUE_SHIFT    (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_SR2_WTCNT_VALUE_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_SETUP_REG_RESETVAL        (0x00000000U)

/* PRM_ABBLDO_GPU_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_MASK     (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_MASK              (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_SHIFT             (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_DEFAULT_NOMINAL   (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_FASTOPP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_FASTOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_FASTOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_NOMINALOPP  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_NOMINALOPP        (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_NOMINALOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_SLOWOPP  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_SEL_SLOWOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_SEL_SLOWOPP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_CHANGE_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_OPP_CHANGE_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_OPP_CHANGE_MAX   (0x00000001U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_MASK  (0x00000018U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_BYPASS         (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_RESERVED1      (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_RESERVED1)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_RESERVED       (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_RESERVED)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_FBB   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_STATUS_FBB            (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_STATUS_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_IN_TRANSITION_MASK    (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_IN_TRANSITION_SHIFT   (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_IN_TRANSITION_IDLE    (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_GPU_CTRL_SR2_IN_TRANSITION_INTRANSITION  (CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION)


#define CSL_DEVICE_PRM_PRM_ABBLDO_GPU_CTRL_REG_RESETVAL         (0x00000000U)

/* PRM_BANDGAP_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_MASK  (0x000000FFU)
/* Below define for backward compatibility */
#define PRM_BANDGAP_SETUP_STARTUP_COUNT_MASK          (CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_MASK)

#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_RESETVAL  (0x00000078U)

#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_BANDGAP_SETUP_STARTUP_COUNT_SHIFT         (CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_SHIFT)

#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_STARTUP_COUNT_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_BANDGAP_SETUP_REG_RESETVAL           (0x00000078U)

/* PRM_DEVICE_OFF_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_MASK    (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_SHIFT   (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_DISABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_DEVICE_OFF_ENABLE_ENABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_DEVICE_OFF_ENABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_MASK  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_MASK)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_SHIFT  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_DISABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_DISABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_ENABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF1_OFFWKUP_DISABLE_ENABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF1_OFFWKUP_DISABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF2_OFFWKUP_DISABLE_MASK  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_MASK)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF2_OFFWKUP_DISABLE_SHIFT  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_DISABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF2_OFFWKUP_DISABLE_DISABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_ENABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_DEVICE_OFF_CTRL_EMIF2_OFFWKUP_DISABLE_ENABLED  (CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_EMIF2_OFFWKUP_DISABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_DEVICE_OFF_CTRL_REG_RESETVAL         (0x00000000U)

/* PRM_PHASE1_CNDP_REG */

#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_MASK     (0xFFFFFFFFU)
/* Below define for backward compatibility */
#define PRM_PHASE1_CNDP_PHASE1_CNDP_MASK              (CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_MASK)

#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_RESETVAL  (0x4a05e000U)

#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_PHASE1_CNDP_PHASE1_CNDP_SHIFT             (CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_SHIFT)

#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_PHASE1_CNDP_MAX      (0xffffffffU)

#define CSL_DEVICE_PRM_PRM_PHASE1_CNDP_REG_RESETVAL             (0x4a05e000U)

/* PRM_PHASE2A_CNDP_REG */

#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_MASK   (0xFFFFFFFFU)
/* Below define for backward compatibility */
#define PRM_PHASE2A_CNDP_PHASE2A_CNDP_MASK            (CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_MASK)

#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_RESETVAL  (0x4a05e030U)

#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_PHASE2A_CNDP_PHASE2A_CNDP_SHIFT           (CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_SHIFT)

#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_PHASE2A_CNDP_MAX    (0xffffffffU)

#define CSL_DEVICE_PRM_PRM_PHASE2A_CNDP_REG_RESETVAL            (0x4a05e030U)

/* PRM_PHASE2B_CNDP_REG */

#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_MASK   (0xFFFFFFFFU)
/* Below define for backward compatibility */
#define PRM_PHASE2B_CNDP_PHASE2B_CNDP_MASK            (CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_MASK)

#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_RESETVAL  (0x4a05e060U)

#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_PHASE2B_CNDP_PHASE2B_CNDP_SHIFT           (CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_SHIFT)

#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_PHASE2B_CNDP_MAX    (0xffffffffU)

#define CSL_DEVICE_PRM_PRM_PHASE2B_CNDP_REG_RESETVAL            (0x4a05e060U)

/* PRM_MODEM_IF_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_MASK         (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_MASK)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_SHIFT        (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_SHIFT)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_ACTIVE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_ACTIVE       (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_ACTIVE)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_INACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_WAKE_IRQ_INACTIVE     (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_WAKE_IRQ_INACTIVE)


#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_MASK     (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_MASK)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_SHIFT    (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_SHIFT)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_ACTIVE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_ACTIVE   (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_ACTIVE)

#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_INACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_MODEM_IF_CTRL_MODEM_SHUTDOWN_IRQ_INACTIVE  (CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_MODEM_SHUTDOWN_IRQ_INACTIVE)


#define CSL_DEVICE_PRM_PRM_MODEM_IF_CTRL_REG_RESETVAL           (0x00000000U)

/* PRM_VOLTST_MPU_REG */

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_MASK               (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_RESETVAL  (0x00000003U)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_SHIFT              (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_OFF                (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_OFF)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_RET                (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_RET)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_SLEEP     (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_SLEEP              (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_SLEEP)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_VOLTSTATEST_ON                 (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_VOLTSTATEST_ON)


#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_MASK     (0x00100000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_INTRANSITION_MASK              (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_SHIFT    (20U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_INTRANSITION_SHIFT             (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_NO       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_INTRANSITION_NO                (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_NO)

#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_ONGOING  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MPU_INTRANSITION_ONGOING           (CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_INTRANSITION_ONGOING)


#define CSL_DEVICE_PRM_PRM_VOLTST_MPU_REG_RESETVAL              (0x00000003U)

/* PRM_VOLTST_MM_REG */

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_MASK       (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_MASK                (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_RESETVAL   (0x00000003U)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_SHIFT      (0U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_SHIFT               (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_OFF        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_OFF                 (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_OFF)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_RET        (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_RET                 (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_RET)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_SLEEP      (0x00000002U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_SLEEP               (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_SLEEP)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_ON         (0x00000003U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_VOLTSTATEST_ON                  (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_VOLTSTATEST_ON)


#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_MASK      (0x00100000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_INTRANSITION_MASK               (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_SHIFT     (20U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_INTRANSITION_SHIFT              (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_NO        (0x00000000U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_INTRANSITION_NO                 (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_NO)

#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_ONGOING   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_VOLTST_MM_INTRANSITION_ONGOING            (CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_INTRANSITION_ONGOING)


#define CSL_DEVICE_PRM_PRM_VOLTST_MM_REG_RESETVAL               (0x00000003U)

/* PRM_SLDO_DSPEVE_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_MASK         (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_MASK       (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SHIFT      (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_MASK   (0x00000040U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_MASK            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_EXT_CLOCK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_EXT_CLOCK       (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_EXT_CLOCK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_NO_EXT_CLOCK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC4_NO_EXT_CLOCK    (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC4_NO_EXT_CLOCK)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_MASK   (0x00000080U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_MASK            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_ONE_STEP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_ONE_STEP        (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_ONE_STEP)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_TWO_STEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC5_TWO_STEP        (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC5_TWO_STEP)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_MASK    (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_MASK             (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_SHIFT   (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_SHIFT            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_NO_OVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_NO_OVERRIDE      (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_NO_OVERRIDE)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_OVERRIDE  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_AIPOFF_OVERRIDE         (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_AIPOFF_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_MASK         (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_RTA_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENABLE_RTA_RTA_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_MASK   (0x00000008U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_MASK            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHORT_PROT_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC1_SHORT_PROT_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_MASK   (0x00000010U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_MASK            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_EXT_CAP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_EXT_CAP         (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_EXT_CAP)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_NO_EXT_CAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC2_NO_EXT_CAP      (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC2_NO_EXT_CAP)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_MASK   (0x00000020U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_MASK            (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SUB_REGUL_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_SETUP_ENFUNC3_SUB_REGUL_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_SETUP_REG_RESETVAL       (0x00000000U)

/* PRM_SLDO_IVA_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_MASK   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_ACT_MASK            (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_ACT_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_ACT_SRAMNW_ACT_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_ACT_SRAMNW_ACT_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_SLEEP_MASK          (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_SLEEP_SHIFT         (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDS  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDS)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ABBOFF_SLEEP_SRAMNW_SLP_VDDAR)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_MASK      (0x00000040U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC4_MASK               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_SHIFT     (6U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC4_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_EXT_CLOCK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC4_EXT_CLOCK          (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_EXT_CLOCK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_NO_EXT_CLOCK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC4_NO_EXT_CLOCK       (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC4_NO_EXT_CLOCK)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_MASK      (0x00000080U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC5_MASK               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_SHIFT     (7U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC5_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_ONE_STEP  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC5_ONE_STEP           (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_ONE_STEP)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_TWO_STEP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC5_TWO_STEP           (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC5_TWO_STEP)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_MASK       (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_AIPOFF_MASK                (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_RESETVAL   (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_SHIFT      (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_AIPOFF_SHIFT               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_NO_OVERRIDE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_AIPOFF_NO_OVERRIDE         (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_NO_OVERRIDE)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_OVERRIDE   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_AIPOFF_OVERRIDE            (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_AIPOFF_OVERRIDE)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENABLE_RTA_MASK            (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENABLE_RTA_SHIFT           (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_RTA_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENABLE_RTA_RTA_ENABLED     (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_RTA_ENABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_RTA_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENABLE_RTA_RTA_DISABLED    (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENABLE_RTA_RTA_DISABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_MASK      (0x00000008U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC1_MASK               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHIFT     (3U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC1_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC1_SHORT_PROT_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHORT_PROT_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC1_SHORT_PROT_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC1_SHORT_PROT_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC2_MASK               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC2_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_EXT_CAP   (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC2_EXT_CAP            (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_EXT_CAP)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_NO_EXT_CAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC2_NO_EXT_CAP         (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC2_NO_EXT_CAP)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_MASK      (0x00000020U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC3_MASK               (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SHIFT     (5U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC3_SHIFT              (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC3_SUB_REGUL_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SUB_REGUL_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_SETUP_ENFUNC3_SUB_REGUL_ENABLED  (CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_ENFUNC3_SUB_REGUL_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_SETUP_REG_RESETVAL          (0x00000000U)

/* PRM_ABBLDO_DSPEVE_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_DEFAULT_NOMINAL  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_FASTOPP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_FASTOPP        (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_FASTOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_NOMINALOPP  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_NOMINALOPP     (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_NOMINALOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_SLOWOPP  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_SEL_SLOWOPP        (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_SEL_SLOWOPP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_CHANGE_MASK        (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_OPP_CHANGE_SHIFT       (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_OPP_CHANGE_MAX  (0x00000001U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_MASK  (0x00000018U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_MASK        (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_SHIFT       (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_BYPASS      (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_RESERVED1   (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_RESERVED1)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_RESERVED    (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_RESERVED)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_FBB  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_STATUS_FBB         (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_STATUS_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_MASK  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_SHIFT  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_IDLE  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_CTRL_SR2_IN_TRANSITION_INTRANSITION  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_CTRL_REG_RESETVAL      (0x00000000U)

/* PRM_ABBLDO_IVA_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_MASK     (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_MASK              (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_SHIFT    (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_SHIFT             (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_DEFAULT_NOMINAL   (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_DEFAULT_NOMINAL)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_FASTOPP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_FASTOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_FASTOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_NOMINALOPP  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_NOMINALOPP        (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_NOMINALOPP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_SLOWOPP  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_SEL_SLOWOPP           (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_SEL_SLOWOPP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_CHANGE_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_OPP_CHANGE_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_OPP_CHANGE_MAX   (0x00000001U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_MASK  (0x00000018U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_MASK           (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_SHIFT          (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_BYPASS         (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_RESERVED1      (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_RESERVED1)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_RESERVED       (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_RESERVED)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_FBB   (0x00000002U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_STATUS_FBB            (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_STATUS_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_IN_TRANSITION_MASK    (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_IN_TRANSITION_SHIFT   (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_IN_TRANSITION_IDLE    (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_CTRL_SR2_IN_TRANSITION_INTRANSITION  (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_SR2_IN_TRANSITION_INTRANSITION)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_CTRL_REG_RESETVAL         (0x00000000U)

/* PRM_SLDO_DSPEVE_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_MASK      (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_SHIFT     (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_ACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_ACTIVE    (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_ACTIVE)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_RETENTION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAMLDO_STATUS_RETENTION  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAMLDO_STATUS_RETENTION)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_MASK  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_SHIFT  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_IDLE  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_MASK      (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_SHIFT     (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_DISABLED  (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_DSPEVE_CTRL_RETMODE_ENABLE_ENABLED   (CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RETMODE_ENABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_DSPEVE_CTRL_REG_RESETVAL        (0x00000000U)

/* PRM_SLDO_IVA_CTRL_REG */

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAMLDO_STATUS_MASK         (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAMLDO_STATUS_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_ACTIVE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAMLDO_STATUS_ACTIVE       (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_ACTIVE)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_RETENTION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAMLDO_STATUS_RETENTION    (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAMLDO_STATUS_RETENTION)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAM_IN_TRANSITION_MASK     (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_SHIFT  (9U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAM_IN_TRANSITION_SHIFT    (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_IDLE  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAM_IN_TRANSITION_IDLE     (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_IDLE)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_SRAM_IN_TRANSITION_IN_TRANSITION  (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_SRAM_IN_TRANSITION_IN_TRANSITION)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_RETMODE_ENABLE_MASK         (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_MASK)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_RETMODE_ENABLE_SHIFT        (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_SHIFT)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_RETMODE_ENABLE_DISABLED     (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_DISABLED)

#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_SLDO_IVA_CTRL_RETMODE_ENABLE_ENABLED      (CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RETMODE_ENABLE_ENABLED)


#define CSL_DEVICE_PRM_PRM_SLDO_IVA_CTRL_REG_RESETVAL           (0x00000000U)

/* PRM_ABBLDO_DSPEVE_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_MASK            (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_SHIFT           (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_BYPASS          (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_FUNCTIONAL  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2EN_FUNCTIONAL      (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2EN_FUNCTIONAL)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_MASK   (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_SHIFT  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_BYPASS  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_FBB  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_ACTIVE_FBB_SEL_FBB    (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_ACTIVE_FBB_SEL_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_MASK   (0x00000010U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_MASK            (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_SHIFT           (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_CAP    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_CAP             (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_CAP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_NOCAP  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_NOCAP_NOCAP           (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_NOCAP_NOCAP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2_WTCNT_VALUE_MASK  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_DSPEVE_SETUP_SR2_WTCNT_VALUE_SHIFT  (CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_SR2_WTCNT_VALUE_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_ABBLDO_DSPEVE_SETUP_REG_RESETVAL     (0x00000000U)

/* PRM_ABBLDO_IVA_SETUP_REG */

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_MASK      (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2EN_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_SHIFT     (0U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2EN_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_BYPASS    (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2EN_BYPASS             (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_FUNCTIONAL  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2EN_FUNCTIONAL         (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2EN_FUNCTIONAL)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_ACTIVE_FBB_SEL_MASK      (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_ACTIVE_FBB_SEL_SHIFT     (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_BYPASS  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_ACTIVE_FBB_SEL_BYPASS    (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_BYPASS)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_FBB  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_ACTIVE_FBB_SEL_FBB       (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_ACTIVE_FBB_SEL_FBB)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_MASK      (0x00000010U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_NOCAP_MASK               (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_SHIFT     (4U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_NOCAP_SHIFT              (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_CAP       (0x00000000U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_NOCAP_CAP                (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_CAP)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_NOCAP     (0x00000001U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_NOCAP_NOCAP              (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_NOCAP_NOCAP)


#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_MASK  (0x0000FF00U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2_WTCNT_VALUE_MASK     (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_MASK)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_RESETVAL  (0x00000000U)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_ABBLDO_IVA_SETUP_SR2_WTCNT_VALUE_SHIFT    (CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_SHIFT)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_SR2_WTCNT_VALUE_MAX  (0x000000ffU)

#define CSL_DEVICE_PRM_PRM_ABBLDO_IVA_SETUP_REG_RESETVAL        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
