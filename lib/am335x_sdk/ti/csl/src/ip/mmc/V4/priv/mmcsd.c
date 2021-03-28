/*
 *  Copyright (C) 2013-2016 Texas Instruments Incorporated - http://www.ti.com/
*  Copyright (C) 2017 Arasan Chip Systems Inc
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
/***************************************************************************
*
*  Description     : This file contains CSL APIs definitions to read/write the host controller
*                          registers
*
*  Change History :
*  <Date>            <Author>    <Version>      < Description >
*  14-June-2017   PB              0.1                 File structure creation
*  12-July-2017    PB              0.2                 Added APIs definition structure for CQ registers
*  14-July-2017    PB              0.3                 Defined CQ APIs
*  16-July-2017    PB              0.4                 Modified SD APIs for additional parameter validation.
*                                                                 Added a new parameter in couple of APIs
*  19-July-2017    PB              0.5                 Added additional SD API definitions for ease of configuration
*  28-July-2017    PB              1.0                 Modified for 64-bit addressing
*  07-Aug-2017    PB              1.1                 Added modification for error type returned in some APIs,
*                                                                 validation of parameters and macro names
*  25-Aug-2017    PB              1.2                 Added modification for validating parameters in APIs
*  28-Aug-2017    PB              1.3                 Added modification to replace macro calls with function calls for Misra compliance
*  29-Aug-2017    PB              1.4                 Modified macro name for CQVER registers for clarity
*
***************************************************************************/
/**
 *  \file   mmcsd.c
 *
 *  \brief  Device abstraction layer for HS MMC/SD
 *
 *   This file contains the device abstraction layer APIs for HS MMC/SD.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/src/ip/mmc/V4/priv/os_types.h>
#include <ti/csl/src/ip/mmc/V4/mmcsd.h>
#include <ti/csl/src/ip/mmc/V4/priv/low_level_hw.h>

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static int32_t HSMMCSDValidateBaseAddress(uintptr_t baseAddr)
{
	int32_t status = STW_SOK;

	/* TODO: Modify conditional check here as per requirement for validation of base address*/
	if(0x0U == baseAddr)
	{
		status = STW_EOUT_OF_RANGE;
	}

	return status;
}

int32_t HSMMCSDHCVersion(uintptr_t baseAddr, stSDMMCHCVersion *verInfo)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(verInfo != OS_NULL)
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_REV);
			verInfo->specVer = (uint8_t )((regValue & MMC_REV_SREV_MASK)>>MMC_REV_SREV_SHIFT);
			verInfo->vendorVer = (uint8_t )((regValue & MMC_REV_VREV_MASK)>>MMC_REV_VREV_SHIFT);

			regValue = 0;
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQVER);
			verInfo->cqMajorVer = (uint8_t )((regValue & MMC_CQVER_VER_MAJOR_MASK)>>MMC_CQVER_VER_MAJOR_SHIFT);
			verInfo->cqMinorVer = (uint8_t )((regValue & MMC_CQVER_VER_MINOR_MASK)>>MMC_CQVER_VER_MINOR_SHIFT);
			verInfo->cqSuffixVer = (uint8_t )((regValue & MMC_CQVER_VER_SUFFIX_MASK)>>MMC_CQVER_VER_SUFFIX_SHIFT);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDSoftReset(uintptr_t baseAddr)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFU;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_SRA_SHIFT,
			MMC_SYSCTL_SRA_MASK, MMC_SYSCTL_SRA_RESET);
		do
		{
			if (SdhcReadRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_SRA_SHIFT,
				MMC_SYSCTL_SRA_MASK) == MMC_SYSCTL_SRA_WORK)
			{
				break;
			}
			timeout--;
		} while (timeout > 0U);

		if (0U == timeout)
		{
			status = STW_ETIMEOUT;
		}
	}
	return status;
}

int32_t HSMMCSDeMMCardHardReset(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((flag == MMC_HCTL_EMMC_HW_RST_SET) || (flag == MMC_HCTL_EMMC_HW_RST_CLEAR))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_EMMC_HW_RST_SHIFT,
				MMC_HCTL_EMMC_HW_RST_MASK, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDLinesReset(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t sysCtlValue = 0U;
	volatile uint32_t timeout = 0xFFFFU;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_DATALINE_RESET |HS_MMCSD_CMDLINE_RESET | HS_MMCSD_ALL_RESET))))
		{
			sysCtlValue  = SdhcRegisterReadDWord(baseAddr + MMC_SYSCTL);
			sysCtlValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_SYSCTL, sysCtlValue);

			do
			{
				if ((SdhcRegisterReadDWord(baseAddr + MMC_SYSCTL) & flag) == (uint32_t)0U)
				{
					break;
				}
				timeout--;
			} while (timeout > 0U);

			if (0U == timeout)
			{
				status = STW_EFAIL;
			}
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDSystemConfig(uintptr_t baseAddr, const uint32_t *config)
{
	/* Placeholder to write system configuration code for SD/eMMC host controller as a peripheral.
	The code is to be added by platform developers if required. */
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(config == OS_NULL)
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDHostCapabilityGet(uintptr_t baseAddr, stSDMMCHCCapability *hcCapab)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(hcCapab != OS_NULL)
		{
			if(hcCapab->flag1 != 0U)
			{
				switch(hcCapab->flag1)
				{
					case HS_MMCSD_TIMEOUT_CLK_FREQ:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_TCF_SHIFT,
							MMC_CAPA_TCF_MASK);
						break;
					case HS_MMCSD_TIMEOUT_CLK_UNIT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_TCU_SHIFT,
							MMC_CAPA_TCU_MASK);
						break;
					case HS_MMCSD_BASE_CLK_FREQ_SD:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_BCF_SHIFT,
							MMC_CAPA_BCF_MASK);
						break;
					case HS_MMCSD_MAX_BLOCK_LENGTH:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_MBL_SHIFT,
							MMC_CAPA_MBL_MASK);
						break;
					case HS_MMCSD_EXTENDED_MEDIA_BUS:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_EMBS_SHIFT,
							MMC_CAPA_EMBS_MASK);
						break;
					case HS_MMCSD_ADMA2_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_AD2S_SHIFT,
							MMC_CAPA_AD2S_MASK);
						break;
					case HS_MMCSD_HS_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_HSS_SHIFT,
							MMC_CAPA_HSS_MASK);
						break;
					case HS_MMCSD_SDMA_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_SDMAS_SHIFT,
							MMC_CAPA_SDMAS_MASK);
						break;
					case HS_MMCSD_SUSPEND_RESUME_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_SRS_SHIFT,
							MMC_CAPA_SRS_MASK);
						break;
					case HS_MMCSD_VOLT_3V3_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_VS33_SHIFT,
							MMC_CAPA_VS33_MASK);
						break;
					case HS_MMCSD_VOLT_3V0_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_VS30_SHIFT,
							MMC_CAPA_VS30_MASK);
						break;
					case HS_MMCSD_VOLT_1V8_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_VS18_SHIFT,
							MMC_CAPA_VS18_MASK);
						break;
					case HS_MMCSD_64BIT_SYSTEMBUS_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_BIT64_SHIFT,
							MMC_CAPA_BIT64_MASK);
						break;
					case HS_MMCSD_ASYNC_INTR_SUPPORT:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_AIS_SHIFT,
							MMC_CAPA_AIS_MASK);
						break;
					case HS_MMCSD_SLOT_TYPE:
						hcCapab->retValue1 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_SLOT_TYPE_SHIFT,
							MMC_CAPA_SLOT_TYPE_MASK);
						break;
					case HS_MMCSD_CAPA_ALL:
						hcCapab->retValue1 = SdhcRegisterReadDWord(baseAddr + MMC_CAPA);
						break;
					default:
						hcCapab->retValue1 = ((uint32_t)0x0U);
						break;
				}
			}

			if(hcCapab->flag2 != 0U)
			{
				switch(hcCapab->flag2)
				{
					case HS_MMCSD_SDR50_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_SDR50_SHIFT,
							MMC_CAPA2_SDR50_MASK);
						break;
					case HS_MMCSD_SDR104_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_SDR104_SHIFT,
							MMC_CAPA2_SDR104_MASK);
						break;
					case HS_MMCSD_DDR50_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_DDR50_SHIFT,
							MMC_CAPA2_DDR50_MASK);
						break;
					case HS_MMCSD_DRIVER_TYPEA_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_DTA_SHIFT,
							MMC_CAPA2_DTA_MASK);
						break;
					case HS_MMCSD_DRIVER_TYPEC_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_DTC_SHIFT,
							MMC_CAPA2_DTC_MASK);
						break;
					case HS_MMCSD_DRIVER_TYPED_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_DTD_SHIFT,
							MMC_CAPA2_DTD_MASK);
						break;
					case HS_MMCSD_DRIVER_TYPE4_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_DT4_SHIFT,
							MMC_CAPA2_DT4_MASK);
						break;
					case HS_MMCSD_TIMER_COUNT_RETUNING:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_TCRT_SHIFT,
							MMC_CAPA2_TCRT_MASK);
						break;
					case HS_MMCSD_USE_TUNING_SDR50:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_TSDR50_SHIFT,
							MMC_CAPA2_TSDR50_MASK);
						break;
					case HS_MMCSD_RETUNING_MODES:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_RTM_SHIFT,
							MMC_CAPA2_RTM_MASK);
						break;
					case HS_MMCSD_CLOCK_MULTIPLIER:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_CM_SHIFT,
							MMC_CAPA2_CM_MASK);
						break;
					case HS_MMCSD_SPI_MODE:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_SPI_MODE_SHIFT,
							MMC_CAPA2_SPI_MODE_MASK);
						break;
					case HS_MMCSD_SPI_BLOCK_MODE:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_SPI_BMODE_SHIFT,
							MMC_CAPA2_SPI_BMODE_MASK);
						break;
					case HS_MMCSD_HS400_SUPPORT:
						hcCapab->retValue2 = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA2, MMC_CAPA2_HS400S_SHIFT,
							MMC_CAPA2_HS400S_MASK);
						break;
					case HS_MMCSD_CAPA_ALL:
						hcCapab->retValue2 = SdhcRegisterReadDWord(baseAddr + MMC_CAPA2);
						break;
					default:
						hcCapab->retValue2 = ((uint32_t)0x0U);
						break;
				}
			}

			if((hcCapab->flag1 == 0U) && (hcCapab->flag2 == 0U))
			{
				status = STW_EINVALID_PARAMS;
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDSwitchSignalVoltage(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((flag == MMC_AC12_V1V8_SIGEN_1V8) || (flag == MMC_AC12_V1V8_SIGEN_3V3))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_V1V8_SIGEN_SHIFT,
				MMC_AC12_V1V8_SIGEN_MASK, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDGetSignalVoltage(uintptr_t baseAddr)
{
	int32_t status;
	uint32_t val=0;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
	  val = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_V1V8_SIGEN_SHIFT,
				MMC_AC12_V1V8_SIGEN_MASK);
	}
	return val;
}
int32_t HSMMCSDUhsModeSet(uintptr_t baseAddr, uint32_t mode)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{

		if((mode == MMC_AC12_UHSMS_SDR12) || (mode == MMC_AC12_UHSMS_SDR25) ||
			(mode == MMC_AC12_UHSMS_SDR50) || (mode == MMC_AC12_UHSMS_SDR104) ||
			(mode == MMC_AC12_UHSMS_DDR50) || (mode == MMC_AC12_UHSMS_HS400))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
				MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_DISABLE);
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_UHSMS_SHIFT,
				MMC_AC12_UHSMS_MASK, mode);
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
				MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_ENABLE);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDUhsDrvStrengthSet(uintptr_t baseAddr, uint32_t drvStrength)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_DRV_STRENGTH_SHIFT,
				MMC_AC12_DRV_STRENGTH_MASK, drvStrength);
		}
	}
	return status;
}


int32_t HSMMCSDBootModeSet(uintptr_t baseAddr, uint32_t bootMode,
	uint32_t bootAck, uint32_t timeout)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((bootMode == HS_MMCSD_BOOT_MODE_NORMAL) || (bootMode == HS_MMCSD_BOOT_MODE_BOOT) ||
			(bootMode == HS_MMCSD_BOOT_MODE_ALTBOOT)) && ((bootAck == HS_MMCSD_BOOT_ACK_WAIT) ||
			(bootAck == HS_MMCSD_BOOT_ACK_NOWAIT)))
		{
			switch(bootMode)
			{
				case HS_MMCSD_BOOT_MODE_NORMAL:
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_BOOTEN_SHIFT,
						MMC_HCTL_BOOTEN_MASK, MMC_HCTL_STOP_BOOT_ACCESS);
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_ALTBOOTEN_SHIFT,
						MMC_HCTL_ALTBOOTEN_MASK, MMC_HCTL_STOP_ALTBOOT_ACCESS);
					break;
				case HS_MMCSD_BOOT_MODE_BOOT:
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_BOOTEN_SHIFT,
						MMC_HCTL_BOOTEN_MASK, MMC_HCTL_START_BOOT_ACCESS);
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_ALTBOOTEN_SHIFT,
						MMC_HCTL_ALTBOOTEN_MASK, MMC_HCTL_STOP_ALTBOOT_ACCESS);
					break;
				case HS_MMCSD_BOOT_MODE_ALTBOOT:
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_BOOTEN_SHIFT,
						MMC_HCTL_BOOTEN_MASK, MMC_HCTL_START_BOOT_ACCESS);
					SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_ALTBOOTEN_SHIFT,
						MMC_HCTL_ALTBOOTEN_MASK, MMC_HCTL_START_ALTBOOT_ACCESS);
					break;
				default:
					status = STW_EOUT_OF_RANGE;
					break;
			}

			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_BOOTACK_SHIFT,
				MMC_HCTL_BOOTACK_MASK, bootAck);
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_BTCR, MMC_BTCR_COUNTER_SHIFT,
				MMC_BTCR_COUNTER_MASK, timeout);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDBlockGapControl(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		switch(flag)
		{
			case HS_MMCSD_BLOCKGAP_STOP_REQ_ENABLE:
				SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_SBGR_SHIFT,
					MMC_HCTL_SBGR_MASK, MMC_HCTL_SBGR_STPBLK);
				break;
			case HS_MMCSD_BLOCKGAP_STOP_REQ_DISABLE:
				SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_SBGR_SHIFT,
					MMC_HCTL_SBGR_MASK, MMC_HCTL_SBGR_TRANSFER);
				break;
			case HS_MMCSD_BLOCKGAP_CONT_REQ_ENABLE:
				SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_CR_SHIFT,
					MMC_HCTL_CR_MASK, MMC_HCTL_CR_RESTART);
				break;
			case HS_MMCSD_BLOCKGAP_RD_WAIT_ENABLE:
				SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_RWC_SHIFT,
					MMC_HCTL_RWC_MASK, MMC_HCTL_RWC_RW);
				break;
			case HS_MMCSD_BLOCKGAP_RD_WAIT_DISABLE:
				SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_RWC_SHIFT,
					MMC_HCTL_RWC_MASK, MMC_HCTL_RWC_NORW);
				break;
			default:
				status = STW_EOUT_OF_RANGE;
				break;
		}
	}
	return status;
}

int32_t HSMMCSDWakeUpControl(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(MMC_HCTL_IWE_MASK|MMC_HCTL_INS_MASK | MMC_HCTL_REM_MASK))))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_HCTL);
			regValue &= ~(MMC_HCTL_IWE_MASK|MMC_HCTL_INS_MASK | MMC_HCTL_REM_MASK);
			regValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_HCTL, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDAsyncInterruptSet(uintptr_t baseAddr, uint32_t state)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((state == MMC_AC12_AI_ENABLE_ENABLED) || (state == MMC_AC12_AI_ENABLE_DISABLED))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_AI_ENABLE_SHIFT,
				MMC_AC12_AI_ENABLE_MASK, state);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDBusWidthSet(uintptr_t baseAddr, uint32_t width)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		switch (width)
		{
		    case HS_MMCSD_BUS_WIDTH_8BIT:
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_EDTW_SHIFT, MMC_HCTL_EDTW_MASK,
				MMC_HCTL_EDTW_8BIT_ENABLE);
		        break;
		    case HS_MMCSD_BUS_WIDTH_4BIT:
			 SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_EDTW_SHIFT, MMC_HCTL_EDTW_MASK,
				MMC_HCTL_EDTW_8BIT_DISABLE);
			 SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_DTW_SHIFT, MMC_HCTL_DTW_MASK,
				MMC_HCTL_DTW_4_BITMODE);
		        break;
		    case HS_MMCSD_BUS_WIDTH_1BIT:
			 SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_EDTW_SHIFT, MMC_HCTL_EDTW_MASK,
				MMC_HCTL_EDTW_8BIT_DISABLE);
			 SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_DTW_SHIFT, MMC_HCTL_DTW_MASK,
				MMC_HCTL_DTW_1_BITMODE);
		        break;
		    default:
			 status = STW_EOUT_OF_RANGE;
		        break;
		}
	}
	return status;
}

int32_t HSMMCSDBusVoltGet(uintptr_t baseAddr)
{
   return (SdhcReadRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_SDVS_SHIFT,
			MMC_HCTL_SDVS_MASK));
}
int32_t HSMMCSDBusVoltSet(uintptr_t baseAddr, uint32_t volt)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((volt == MMC_HCTL_SDVS_1V8) || (volt == MMC_HCTL_SDVS_3V0) || 	(volt == MMC_HCTL_SDVS_3V3))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_SDVS_SHIFT,
				MMC_HCTL_SDVS_MASK, volt);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDBusPower(uintptr_t baseAddr, uint32_t pwr)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFFU;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((pwr == MMC_HCTL_SDBP_PWRON) || (pwr == MMC_HCTL_SDBP_PWROFF))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_SDBP_SHIFT,
				MMC_HCTL_SDBP_MASK, pwr);

			if (pwr == MMC_HCTL_SDBP_PWRON)
			{
				do
				{
					if ((SdhcRegisterReadDWord(baseAddr + MMC_HCTL) & MMC_HCTL_SDBP_MASK) != 0U)
					{
						break;
					}
					timeout--;
				} while (timeout > 0U);
			}

			if(timeout == (uint32_t)0U)
			{
				status = STW_EFAIL;
			}
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIntClock(uintptr_t baseAddr, uint32_t clkState)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((clkState == HS_MMCSD_INTCLOCK_ON) || (clkState == HS_MMCSD_INTCLOCK_OFF))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_ICE_SHIFT,
				MMC_SYSCTL_ICE_MASK, clkState);

			if(clkState == HS_MMCSD_INTCLOCK_ON)
			{
				if(HSMMCSDIsIntClockStable(baseAddr, (uint32_t) 0xFFFFU) != (int32_t)MMC_SYSCTL_ICS_READY)
				{
					status = STW_EFAIL;
				}
			}
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIsIntClockStable(uintptr_t baseAddr, uint32_t retry)
{
	volatile int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		do
		{
			retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_ICS_SHIFT,
				MMC_SYSCTL_ICS_MASK);
			if ((retValue == (int32_t)MMC_SYSCTL_ICS_READY) || (retry == 0U))
			{
				break;
			}
			retry--;
		} while (retry > 0U);
	}
	return retValue;
}

int32_t HSMMCSDSupportedVoltSet(uintptr_t baseAddr, uint32_t volt)
{
	int32_t status;
	volatile uint32_t capaValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((volt == MMC_CAPA_VS18_MASK) || (volt == MMC_CAPA_VS30_MASK) ||
			(volt == MMC_CAPA_VS33_MASK))
		{
			capaValue = SdhcRegisterReadDWord(baseAddr + MMC_CAPA);
			capaValue &= ~(MMC_CAPA_VS18_MASK | MMC_CAPA_VS30_MASK |
			               MMC_CAPA_VS33_MASK);
			capaValue |= volt;
			SdhcRegisterWriteDWord(baseAddr + MMC_CAPA, capaValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIsHSupported(uintptr_t baseAddr)
{
	volatile int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CAPA, MMC_CAPA_HSS_SHIFT,
			MMC_CAPA_HSS_MASK);
	}
	return retValue;
}

int32_t HSMMCSDHSModeSet(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((flag == MMC_HCTL_HSPE_HIGHSPEED) || (flag == MMC_HCTL_HSPE_NORMALSPEED))
		{
			SdhcWriteRegisterFieldValueByte(baseAddr + MMC_HCTL, MMC_HCTL_HSPE_SHIFT,
				MMC_HCTL_HSPE_MASK, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDDmaSelect(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((flag == MMC_HCTL_DMAS_SDMA) || (flag == MMC_HCTL_DMAS_ADMA2_32BIT) ||
			(flag == MMC_HCTL_DMAS_ADMA2_64BIT))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_DMAS_SHIFT,
				MMC_HCTL_DMAS_MASK, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}


int32_t HSMMCSDAdmaLengthSelect(uintptr_t baseAddr, uint32_t length_mode)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((length_mode == MMC_ADMA2_LENGTH_MODE_16BIT) || (length_mode == MMC_ADMA2_LENGTH_MODE_26BIT))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_ADMA2_LENGTH_MODE_SHIFT,
				MMC_ADMA2_LENGTH_MODE_MASK, length_mode);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}


int32_t HSMMCSDHostVer4Select(uintptr_t baseAddr, uint32_t sel)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((sel == MMC_AC12_HOSTVER4_ENABLE) || (sel == MMC_AC12_HOSTVER4_DISABLE))
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_HOSTVER4_ENABLE_SHIFT,
				MMC_AC12_HOSTVER4_ENABLE_MASK, sel);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}
int32_t HSMMCSDDataTimeoutSet(uintptr_t baseAddr, uint32_t timeout)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(timeout <= MMC_SYSCTL_DTO_15THDTO)
		{
			SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_DTO_SHIFT,
				MMC_SYSCTL_DTO_MASK, timeout);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}
int32_t HSMMCSDSDClockDisable(uintptr_t baseAddr)
{
	SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
				MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_DISABLE);
    return STW_SOK;
}

int32_t HSMMCSDSDClockEnable(uintptr_t baseAddr)
{
	SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
				MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_ENABLE);
    return STW_SOK;
}



int32_t HSMMCSDBusFreqSet(uintptr_t baseAddr, uint32_t freq_in,
                          uint32_t freq_out, uint32_t bypass)
{
    volatile uint32_t clkd = 0U;
    int32_t retval;

    /* First enable the internal clocks */
    retval = HSMMCSDIntClock(baseAddr, (uint32_t) HS_MMCSD_INTCLOCK_ON);
	SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
				MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_DISABLE);

    if ((bypass == (uint32_t) 0U) && (STW_SOK == retval))
    {
        /* Calculate and program the divisor */
        clkd = freq_in / (freq_out*2);
        if (clkd > (uint32_t) 1023U)
        {
            clkd = 1023U;
        }
        /* Do not cross the required freq */
        while ((freq_in / clkd) > (2*freq_out))
        {
            if (clkd == 1023U)
            {
                /* Return we we cannot set the clock freq */
                retval = STW_EFAIL;
                break;
            }

            clkd++;
        }


        if (STW_SOK == retval)
        {
	    uint8_t clkd_bits07 = clkd & 0xff;
            uint8_t clkd_bits89 = (clkd & 0x3ff) >> 8;

            SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, 8,
			0xff00, clkd_bits07);

            SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL,6,
			0xC0, clkd_bits89);

            /* Wait for the interface clock stabilization */
            if (HSMMCSDIsIntClockStable(baseAddr, (uint32_t) 0xFFFFU) == (int32_t) 0U)
            {
                retval = STW_EFAIL;
            }

            if (STW_SOK == retval)
            {
                /* Enable clock to the card */
                SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SYSCTL, MMC_SYSCTL_CEN_SHIFT,
			MMC_SYSCTL_CEN_MASK, MMC_SYSCTL_CEN_ENABLE);
            }
        }
    }

    return retval;
}

int32_t HSMMCSDIntrStatusEnable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t ieValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_STAT_ALL)))
		{
			ieValue = SdhcRegisterReadDWord(baseAddr + MMC_IE);
			ieValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_IE, ieValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIntrStatusDisable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t ieValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_STAT_ALL)))
		{
			ieValue = SdhcRegisterReadDWord(baseAddr + MMC_IE);
			ieValue &= ~flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_IE, ieValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIntrEnable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t iseValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_SIGEN_ALL)))
		{
			iseValue = SdhcRegisterReadDWord(baseAddr + MMC_ISE);
			iseValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_ISE, iseValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDIntrDisable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t iseValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_SIGEN_ALL)))
		{
			iseValue = SdhcRegisterReadDWord(baseAddr + MMC_ISE);
			iseValue &= ~flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_ISE, iseValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}
int32_t HSMMCSDIntrGet(uintptr_t baseAddr)
{
	int32_t iseValue;

    iseValue = SdhcRegisterReadDWord(baseAddr + MMC_ISE);
	return iseValue;
}
int32_t HSMMCSDIntrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_INTR_ALL)))
			{
				*retValue = (SdhcRegisterReadDWord(baseAddr + MMC_STAT) & flag);
			}
			else
			{
				status = STW_EOUT_OF_RANGE;
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDIntrStatusClear(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_INTR_ALL)))
		{
			SdhcRegisterWriteDWord(baseAddr + MMC_STAT, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDAutoCmdErrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_STAT_ACMD_ALL)))
			{
				*retValue = (SdhcRegisterReadDWord(baseAddr + MMC_AC12) & flag);
			}
			else
			{
				status = STW_EOUT_OF_RANGE;
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDAdmaErrStatusGet(uintptr_t baseAddr, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			*retValue = ((SdhcRegisterReadDWord(baseAddr + MMC_ADMAES)) &  \
				(uint32_t)(MMC_ADMAES_LME_MASK | MMC_ADMAES_AES_MASK));
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDIsCmdComplete(uintptr_t baseAddr, uint32_t retry)
{
	volatile int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		do
		{
			status = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_STAT,
				MMC_STAT_CC_SHIFT, MMC_STAT_CC_MASK);
			if ((status == 1) || (retry == 0U))
			{
				break;
			}
			retry--;
		} while (retry > 0U);
	}
	return status;
}

int32_t HSMMCSDIsXferComplete(uintptr_t baseAddr, uint32_t retry)
{
	volatile int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		do
		{
			status = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_STAT,
				MMC_STAT_TC_SHIFT, MMC_STAT_TC_MASK);
			if ((status == 1) || (retry == 0U))
			{
				break;
			}
			retry--;
		} while (retry > 0U);
	}
	return status;
}

int32_t HSMMCSDSdmaBufferLenSet(uintptr_t baseAddr, uint32_t bufferLen)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(bufferLen <= MMC_BLK_HSBB_512KBYTES)
		{
                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_BLK, MMC_BLK_HSBB_SHIFT,
						MMC_BLK_HSBB_MASK, bufferLen);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDBlkLenSet(uintptr_t baseAddr, uint32_t blklen)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(blklen <= MMC_BLK_BLEN_2048BYTESLEN)
		{
                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_BLK, MMC_BLK_BLEN_SHIFT,
						MMC_BLK_BLEN_MASK, blklen);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCommandSend(uintptr_t baseAddr, uint32_t cmd,
                        uint32_t cmdarg, uint32_t dataPresent,
                        uint32_t nblks, uint32_t dmaEn, uint32_t autoCmd)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((dmaEn == 0U) || (dmaEn == 1U)) &&
			((autoCmd == 0U) || (autoCmd == 1U) || (autoCmd == 2U)) &&
			(nblks <= 0xFFFFU) && ((dataPresent == 0U) || (dataPresent == 1U)))
		{
			if (dataPresent == 1U)
			{
			    cmd |= MMC_CMD_DP_MASK;

			    if(nblks > 1)
				{
				   cmd |= MMC_CMD_MSBS_MASK ;
				   cmd |= MMC_CMD_BCE_MASK ;
				}
			}



			cmd |= (autoCmd << MMC_CMD_ACEN_SHIFT);

			if (dmaEn == 1U)
			{
			    cmd |= MMC_CMD_DE_MASK;
			}

			if(nblks > 1)
			{
			 /* Set the block information; block length is specified separately */
                        SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_BLK, MMC_BLK_NBLK_SHIFT,
				MMC_BLK_NBLK_MASK, nblks);
            }
			/* Set the command/command argument */
			SdhcRegisterWriteDWord(baseAddr + MMC_ARG, cmdarg);

			/* Write the CMD */
			SdhcRegisterWriteWord(baseAddr + MMC_CMD, 0);
			SdhcRegisterWriteWord(baseAddr + MMC_CMD, (cmd & 0xff));
			SdhcRegisterWriteWord(baseAddr + MMC_CMD + 2, (cmd >> 16));
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDSdmaAddressSet (uintptr_t baseAddr, uint32_t dmaAddr)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		regValue = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_DMAS_SHIFT,
			MMC_HCTL_DMAS_MASK);
		if(regValue == MMC_HCTL_DMAS_SDMA)
		{
			if(dmaAddr != ((uint32_t)0U))
			{
	                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_SDMASA, MMC_SDMASA_SDMA_ADDR_SHIFT,
							MMC_SDMASA_SDMA_ADDR_MASK, dmaAddr);
			}
			else
			{
				status = STW_EINVALID_PARAMS;
			}
		}
		else
		{
			status = STW_EPRECONDITION_FAIL;
		}
	}
	return status;
}

int32_t HSMMCSDAdmaAddressSet(uintptr_t baseAddr, uint32_t lowerDmaAddr,
	                 uint32_t upperDmaAddr)
{
	int32_t status;
	uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		regValue = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_HCTL, MMC_HCTL_DMAS_SHIFT,
			MMC_HCTL_DMAS_MASK);
		if((regValue == MMC_HCTL_DMAS_ADMA2_32BIT) || (regValue == MMC_HCTL_DMAS_ADMA2_64BIT))
		{
			if(lowerDmaAddr != ((uint32_t)0U))
			{
	                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_ADMASAL, MMC_ADMASAL_ADMA_A32B_SHIFT,
							MMC_ADMASAL_ADMA_A32B_MASK, lowerDmaAddr);
				if(regValue == MMC_HCTL_DMAS_ADMA2_64BIT)
				{
					if(upperDmaAddr != ((uint32_t)0U))
					{
			                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_ADMASAL2, MMC_ADMASAL2_ADMA_A64B_SHIFT,
									MMC_ADMASAL2_ADMA_A64B_MASK, upperDmaAddr);
					}
					else
					{
						status = STW_EINVALID_PARAMS;
			                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_ADMASAL, MMC_ADMASAL_ADMA_A32B_SHIFT,
									MMC_ADMASAL_ADMA_A32B_MASK, 0x0);
					}
				}
			}
			else
			{
				status = STW_EINVALID_PARAMS;
			}
		}
		else
		{
			status = STW_EPRECONDITION_FAIL;
		}
	}
	return status;
}

int32_t HSMMCSDResponseGet(uintptr_t baseAddr, uint32_t *rsp)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(rsp != OS_NULL)
		{
			rsp[0] = SdhcRegisterReadDWord(baseAddr + MMC_RSP10);
			rsp[1] = SdhcRegisterReadDWord(baseAddr + MMC_RSP32);
			rsp[2] = SdhcRegisterReadDWord(baseAddr + MMC_RSP54);
			rsp[3] = SdhcRegisterReadDWord(baseAddr + MMC_RSP76);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDDataGet(uintptr_t baseAddr, uint8_t *data, uint32_t len)
{
	int32_t status;
	uint32_t i = 0U;
	uint32_t ptr = 0U;
	volatile uint32_t regValue;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((data != OS_NULL) && (len > 0U) && ((len%4U) == 0U))
		{
			for(i = 0U, ptr = 0U; i<(len/4U) ; i++, ptr+=4U)
			{
				regValue = SdhcRegisterReadDWord(baseAddr + MMC_DATA);
				data[ptr] = (uint8_t)(regValue & ((uint32_t)0xffU));
				data[ptr+1U] = (uint8_t)((regValue >> 8U) & ((uint32_t)0xffU));
				data[ptr+2U] = (uint8_t)((regValue >> 16U) & ((uint32_t)0xffU));
				data[ptr+3U] = (uint8_t)((regValue >> 24U) & ((uint32_t)0xffU));
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDDataSet(uintptr_t baseAddr, const uint8_t *data, uint32_t len)
{
	int32_t status;
	uint32_t i = 0U;
	uint32_t ptr = 0U;
	volatile uint32_t regValue;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((data != OS_NULL) && (len > 0U) && ((len%4U) == 0U))
		{
			for(i = 0U, ptr = 0U; i<(len/4U) ; i++, ptr+=4U)
			{
				regValue = (uint32_t)data[ptr+3U];
				regValue = ((regValue << 8U) | (uint32_t)data[ptr+2U]);
				regValue = ((regValue << 8U) | (uint32_t)data[ptr+1U]);
				regValue = ((regValue << 8U) | (uint32_t)data[ptr]);

				SdhcRegisterWriteDWord(baseAddr + MMC_DATA, regValue);
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDIsCardInserted(uintptr_t baseAddr)
{
	volatile int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_PSTATE, MMC_PSTATE_CINS_SHIFT,
			MMC_PSTATE_CINS_MASK);
	}
	return retValue;
}

int32_t HSMMCSDIsCardWriteProtected(uintptr_t baseAddr)
{
	volatile int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_PSTATE, MMC_PSTATE_WP_SHIFT,
			MMC_PSTATE_WP_MASK);
	}
	return retValue;
}

int32_t HSMMCSDCardTuningSet(uintptr_t baseAddr, uint32_t state, uint32_t samplingClock)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((state == HS_MMCSD_EXEC_TUNING_ENABLE) || (state == HS_MMCSD_EXEC_TUNING_DISABLE)) &&
			((samplingClock == HS_MMCSD_CLCK_SELECT_ENABLE) || (samplingClock == HS_MMCSD_CLCK_SELECT_DISABLE)))
		{
                  /*   SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_SCLK_SEL_SHIFT,
						MMC_AC12_SCLK_SEL_MASK, samplingClock); */

                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_ET_SHIFT,
						MMC_AC12_ET_MASK, state);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCardTuningGet(uintptr_t baseAddr, uint32_t *state, uint32_t *samplingClock)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((state != OS_NULL) && (samplingClock != OS_NULL))
		{
			*samplingClock = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_SCLK_SEL_SHIFT,
				MMC_AC12_SCLK_SEL_MASK);
			*state = SdhcReadRegisterFieldValueDWord(baseAddr + MMC_AC12, MMC_AC12_ET_SHIFT, MMC_AC12_ET_MASK);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDEnhancedStrobeSet(uintptr_t baseAddr, uint32_t state)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((state == MMC_VREG_STROBE_ENABLE) || (state == MMC_VREG_STROBE_DISABLE))
		{
                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_VREG, MMC_VREG_STROBE_SHIFT,
						MMC_VREG_STROBE_MASK, state);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQConfigure(uintptr_t baseAddr, uint32_t cqState, uint32_t cqDescSize)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((cqState==HS_MMCSD_CQ_ENABLE)||(cqState==HS_MMCSD_CQ_DISABLE)) &&
		((cqDescSize==HS_MMCSD_CQ_DESC_128BIT)||(cqDescSize==HS_MMCSD_CQ_DESC_64BIT)))
		{
			/*Sets the CQ state to be enabled or disabled */
                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCFG, MMC_CQCFG_CQEN_SHIFT,
			MMC_CQCFG_CQEN_MASK, cqState);

			if(cqDescSize==HS_MMCSD_CQ_DESC_128BIT)
			{
				/* Sets the CQ task descriptor size to 128 bit */
	                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCFG, MMC_CQCFG_TDS_SHIFT,
		                     MMC_CQCFG_TDS_MASK, MMC_CQCFG_TDS_128BIT);
			}
			else
			{
				/* Sets the CQ task descriptor size to 64 bit */
	                     SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCFG, MMC_CQCFG_TDS_SHIFT,
		                     MMC_CQCFG_TDS_MASK, MMC_CQCFG_TDS_64BIT);
			}
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQSendStatusConfig(uintptr_t baseAddr, uint32_t counter, uint32_t timer, uint32_t rca)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((counter <= HS_MMCSD_CQ_SSC_MAX_COUNT) && (timer >= HS_MMCSD_CQ_SSC_MIN_TIMER) &&
			(timer <= HS_MMCSD_CQ_SSC_MAX_TIMER) && (rca >= HS_MMCSD_CQ_SSC_MIN_RCA) &&
			(rca <= HS_MMCSD_CQ_SSC_MAX_RCA))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQSSC1);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQSSC1_CBC_SHIFT, MMC_CQSSC1_CBC_MASK, counter);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQSSC1_CIT_SHIFT, MMC_CQSSC1_CIT_MASK, timer);
			SdhcRegisterWriteDWord(baseAddr + MMC_CQSSC1, regValue);

			regValue = 0;
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQSSC2);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQSSC2_SQSRCA_SHIFT, MMC_CQSSC2_SQSRCA_MASK, rca);
			SdhcRegisterWriteDWord(baseAddr + MMC_CQSSC2, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQTaskDescriptorListSet(uintptr_t baseAddr, uint32_t lowerAddress, uint32_t upperAddress)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQTDLBA, MMC_CQTDLBA_TDLBA_SHIFT,
				MMC_CQTDLBA_TDLBA_MASK, lowerAddress);
              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQTDLBAU, MMC_CQTDLBAU_TDLBA_SHIFT,
				MMC_CQTDLBAU_TDLBA_MASK, upperAddress);
	}
	return status;
}

int32_t HSMMCSDCQSendDirectCmd(uintptr_t baseAddr)
{
	int32_t status;
	volatile uint32_t regValue = 0U;
	uint32_t taskId = 31U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTDBR);
		if(0x80000000U == (regValue & (((uint32_t)1U) << taskId)))
		{
			status = STW_EPRECONDITION_FAIL;
		}
		else
		{
	              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCFG, MMC_CQCFG_DCMD_EN_SHIFT,
					MMC_CQCFG_DCMD_EN_MASK, MMC_CQCFG_DCMD_ENABLE);
			regValue = 0U;
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTDBR);
			regValue |= (((uint32_t)1U) << taskId);
			SdhcRegisterWriteDWord(baseAddr + MMC_CQTDBR, regValue);
		}
	}
	return status;
}

int32_t HSMMCSDCQReadDirectCmdResponse(uintptr_t baseAddr, uint32_t *resp)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFFU;
	volatile uint32_t regValue = 0U;
	uint32_t taskId = 31U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(resp != OS_NULL)
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTDBR);
			do
			{
				if(0U == (regValue & (((uint32_t)1U) << taskId)))
				{
					break;
				}
				timeout--;
			}while(timeout > 0U);

			if (timeout == 0U)
			{
				status = STW_EFAIL;
			}
			else
			{
				*resp = SdhcRegisterReadDWord(baseAddr + MMC_CQCRDCT);
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQSendTask(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTDBR);

		if((regValue & flag) != 0U)
		{
			status = STW_EPRECONDITION_FAIL;
		}
		else
		{
			regValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_CQTDBR, regValue);
		}
	}
	return status;
}

int32_t HSMMCSDCQHalt(uintptr_t baseAddr)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFFU;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCTL, MMC_CQCTL_HALT_SHIFT,
				MMC_CQCTL_HALT_MASK, MMC_CQCTL_HALT_ON);

		do
		{
			if(MMC_CQCTL_HALT_ON == SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQCTL,
				MMC_CQCTL_HALT_SHIFT, MMC_CQCTL_HALT_MASK))
			{
				break;
			}
			timeout--;
		}while(timeout > 0U);

		if (timeout == 0U)
		{
			status = STW_ETIMEOUT;
		}
	}
	return status;
}

int32_t HSMMCSDCQResume(uintptr_t baseAddr)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFFU;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCTL, MMC_CQCTL_HALT_SHIFT,
				MMC_CQCTL_HALT_MASK, MMC_CQCTL_HALT_CLEAR);

		do
		{
			if(MMC_CQCTL_HALT_CLEAR == SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQCTL,
				MMC_CQCTL_HALT_SHIFT, MMC_CQCTL_HALT_MASK))
			{
				break;
			}
			timeout--;
		}while(timeout > 0U);

		if (timeout == 0U)
		{
			status = STW_ETIMEOUT;
		}
	}
	return status;
}

int32_t HSMMCSDCQClearTask(uintptr_t baseAddr, uint32_t taskId)
{
	int32_t status;
	volatile uint32_t timeout = 0xFFFFFU;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(taskId <= HS_MMCSD_CQ_CLEAR_ALL_TASK)
		{
			if(MMC_CQCTL_HALT_ON == SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQCTL,
				MMC_CQCTL_HALT_SHIFT, MMC_CQCTL_HALT_MASK))
			{
				if(taskId == HS_MMCSD_CQ_CLEAR_ALL_TASK)
				{
			              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQCTL, MMC_CQCTL_CLR_TASK_SHIFT,
							MMC_CQCTL_CLR_TASK_MASK, MMC_CQCTL_CLR_ALL_TASKS_EN);

					do
					{
						if((~MMC_CQCTL_CLR_ALL_TASKS_EN) == SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQCTL,
							MMC_CQCTL_CLR_TASK_SHIFT, MMC_CQCTL_CLR_TASK_MASK))
						{
							break;
						}
						timeout--;
					}while(timeout > 0U);

					if (timeout == 0U)
					{
						status = STW_EFAIL;
					}
				}
				else
				{
					regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTCLR);
					regValue |= ((uint32_t)1U << taskId);
					SdhcRegisterWriteDWord(baseAddr + MMC_CQTCLR, regValue);

					do
					{
						regValue = 0U;
						regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTCLR);
						regValue &= (((uint32_t)1U) << taskId);
						if(regValue == 0U)
						{
							break;
						}
						timeout--;
					}while(timeout > 0U);

					if (timeout == 0U)
					{
						status = STW_EFAIL;
					}
				}
			}
			else
			{
				status = STW_EPRECONDITION_FAIL;
			}
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrEnable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_CQ_INTR_HALT_COMPLETE | \
			HS_MMCSD_CQ_INTR_TASK_COMPLETE | HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED | \
			HS_MMCSD_CQ_INTR_TASK_CLEARED))))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQISGE);
			regValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_CQISGE, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrDisable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_CQ_INTR_HALT_COMPLETE | \
			HS_MMCSD_CQ_INTR_TASK_COMPLETE | HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED |  \
			HS_MMCSD_CQ_INTR_TASK_CLEARED))))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQISGE);
			regValue &= ~flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_CQISGE, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrStatusEnable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_CQ_INTR_HALT_COMPLETE | \
			HS_MMCSD_CQ_INTR_TASK_COMPLETE | HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED |  \
			HS_MMCSD_CQ_INTR_TASK_CLEARED))))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQISTE);
			regValue |= flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_CQISTE, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrStatusDisable(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_CQ_INTR_HALT_COMPLETE |   \
			HS_MMCSD_CQ_INTR_TASK_COMPLETE |HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED |  \
			HS_MMCSD_CQ_INTR_TASK_CLEARED))))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQISTE);
			regValue &= ~flag;
			SdhcRegisterWriteDWord(baseAddr + MMC_CQISTE, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrStatusGet(uintptr_t baseAddr, uint32_t flag, uint32_t *retValue)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			if(((uint32_t)0U) == (flag & (uint32_t)(~HS_MMCSD_CQ_INTR_ALL)))
			{
				regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQIS);
				regValue &= flag;
				*retValue = regValue;
			}
			else
			{
				status = STW_EOUT_OF_RANGE;
			}
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrStatusClear(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(((uint32_t)0U) == (flag & (uint32_t)(~(HS_MMCSD_CQ_INTR_HALT_COMPLETE |    \
			HS_MMCSD_CQ_INTR_TASK_COMPLETE | HS_MMCSD_CQ_INTR_RSP_ERR_DETECTED |  \
			HS_MMCSD_CQ_INTR_TASK_CLEARED))))
		{
			SdhcRegisterWriteDWord(baseAddr + MMC_CQIS, flag);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQTaskCompletionStatusGet(uintptr_t baseAddr, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			*retValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTCN);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQTaskCompletionStatusClear(uintptr_t baseAddr, uint32_t flag)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		SdhcRegisterWriteDWord(baseAddr + MMC_CQTCN, flag);
	}
	return status;
}

int32_t HSMMCSDCQDevicePendingTaskGet(uintptr_t baseAddr, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			*retValue = SdhcRegisterReadDWord(baseAddr + MMC_CQDPT);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQDeviceQueueStatus(uintptr_t baseAddr, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			*retValue = SdhcRegisterReadDWord(baseAddr + MMC_CQDQS);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQTaskErrorGet(uintptr_t baseAddr, uint32_t *retValue)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(retValue != OS_NULL)
		{
			*retValue = SdhcRegisterReadDWord(baseAddr + MMC_CQTERRI);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQCmdResponseIndexGet(uintptr_t baseAddr)
{
	int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQCRI,
			MMC_CQCRI_LCRI_SHIFT, MMC_CQCRI_LCRI_MASK);
	}

	return retValue;
}

int32_t HSMMCSDCQCmdResponseGet(uintptr_t baseAddr, uint32_t *resp)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if(resp != OS_NULL)
		{
			*resp = SdhcRegisterReadDWord(baseAddr + MMC_CQCRA);
		}
		else
		{
			status = STW_EINVALID_PARAMS;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrCoalescingConfigure(uintptr_t baseAddr, uint32_t counter, uint32_t timeout)
{
	int32_t status;
	volatile uint32_t regValue = 0U;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((counter <= HS_MMCSD_CQ_IC_MAX_COUNT) && (timeout <= HS_MMCSD_CQ_IC_MAX_TIMEOUT))
		{
			regValue = SdhcRegisterReadDWord(baseAddr + MMC_CQIC);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQIC_ICCTHWEN_SHIFT,
				MMC_CQIC_ICCTHWEN_MASK, (uint32_t)0x1U);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQIC_ICCTH_SHIFT,
				MMC_CQIC_ICCTH_MASK, counter);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQIC_ICTOVALWEN_SHIFT,
				MMC_CQIC_ICTOVALWEN_MASK, (uint32_t)0x1U);
			regValue = SdhcSetFieldValueDWord(regValue, MMC_CQIC_ICTOVAL_SHIFT,
				MMC_CQIC_ICTOVAL_MASK, timeout);
			SdhcRegisterWriteDWord(baseAddr + MMC_CQIC, regValue);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrCoalescingStateSet(uintptr_t baseAddr, uint32_t state)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
		if((state == MMC_CQIC_ICEN_ENABLE) || (state == MMC_CQIC_ICEN_DISABLE))
		{
	              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQIC, MMC_CQIC_ICEN_SHIFT,
					MMC_CQIC_ICEN_MASK, state);
		}
		else
		{
			status = STW_EOUT_OF_RANGE;
		}
	}
	return status;
}

int32_t HSMMCSDCQIntrCoalescingStatusGet(uintptr_t baseAddr)
{
	volatile int32_t retValue;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		retValue = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_CQIC,
			MMC_CQIC_ICSB_SHIFT, MMC_CQIC_ICSB_MASK);
	}
	return retValue;
}

int32_t HSMMCSDCQIntrCoalescingReset(uintptr_t baseAddr)
{
	int32_t status;

	status = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == status)
	{
              SdhcWriteRegisterFieldValueDWord(baseAddr + MMC_CQIC, MMC_CQIC_ICCTR_SHIFT,
				MMC_CQIC_ICCTR_MASK, MMC_CQIC_ICCTR_RESET);
	}
	return status;
}

uint32_t HSMMCSDGetCmdSignalLevel(uintptr_t baseAddr)
{
	volatile int32_t retValue;
	uint32_t cmdLevels=0;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		cmdLevels = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_PSTATE,
			MMC_PSTATE_CLEV_SHIFT, MMC_PSTATE_CLEV_MASK);
	}
	return(cmdLevels);
}

uint32_t HSMMCSDGetDataSignalLevel(uintptr_t baseAddr)
{
	volatile int32_t retValue;
	uint32_t dataLevels=0;

	retValue = HSMMCSDValidateBaseAddress(baseAddr);
	if(STW_SOK == retValue)
	{
		dataLevels = (int32_t)SdhcReadRegisterFieldValueDWord(baseAddr + MMC_PSTATE,
			MMC_PSTATE_DLEV_SHIFT, MMC_PSTATE_DLEV_MASK);
	}
	return(dataLevels);
}
/********************************* End of file ******************************/
