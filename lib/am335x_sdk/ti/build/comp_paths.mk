################################################################################
# Individual component path, needed to build a component in a different location
# as that of PDK
################################################################################

PDK_SDL_ROOT_PATH ?= $(pdk_PATH)
export PDK_SDL_COMP_PATH = $(PDK_SDL_ROOT_PATH)/ti/sdl
PDK_CSL_ROOT_PATH ?= $(pdk_PATH)
export PDK_CSL_COMP_PATH = $(PDK_CSL_ROOT_PATH)/ti/csl
PDK_CSL2_ROOT_PATH  ?= $(pdk_PATH)
export PDK_CSL2_COMP_PATH = $(PDK_CSL2_ROOT_PATH)/ti/csl
PDK_PM_ROOT_PATH ?= $(pdk_PATH)
export PDK_PM_COMP_PATH = $(PDK_PM_ROOT_PATH)/ti/drv/pm
PDK_OSAL_ROOT_PATH ?= $(pdk_PATH)
export PDK_OSAL_COMP_PATH = $(PDK_OSAL_ROOT_PATH)/ti/osal
PDK_I2C_ROOT_PATH ?= $(pdk_PATH)
export PDK_I2C_COMP_PATH = $(PDK_I2C_ROOT_PATH)/ti/drv/i2c
PDK_VPS_ROOT_PATH ?= $(pdk_PATH)
export PDK_VPS_COMP_PATH = $(PDK_VPS_ROOT_PATH)/ti/drv/vps
PDK_GPIO_ROOT_PATH ?= $(pdk_PATH)
export PDK_GPIO_COMP_PATH = $(PDK_GPIO_ROOT_PATH)/ti/drv/gpio
PDK_FATFS_ROOT_PATH ?= $(pdk_PATH)
export PDK_FATFS_COMP_PATH = $(PDK_FATFS_ROOT_PATH)/ti/fs/fatfs
PDK_MMCSD_ROOT_PATH ?= $(pdk_PATH)
export PDK_MMCSD_COMP_PATH = $(PDK_MMCSD_ROOT_PATH)/ti/drv/mmcsd
PDK_PCIE_ROOT_PATH ?= $(pdk_PATH)
export PDK_PCIE_COMP_PATH = $(PDK_PCIE_ROOT_PATH)/ti/drv/pcie
PDK_USB_ROOT_PATH ?= $(pdk_PATH)
export PDK_USB_COMP_PATH = $(PDK_USB_ROOT_PATH)/ti/drv/usb
PDK_SERDES_DIAG_ROOT_PATH ?= $(pdk_PATH)
export PDK_SERDES_DIAG_COMP_PATH = $(PDK_SERDES_DIAG_ROOT_PATH)/ti/diag/serdes_diag
PDK_MCASP_ROOT_PATH ?= $(pdk_PATH)
export PDK_MCASP_COMP_PATH = $(PDK_MCASP_ROOT_PATH)/ti/drv/mcasp
PDK_MCBSP_ROOT_PATH ?= $(pdk_PATH)
export PDK_MCBSP_COMP_PATH = $(PDK_MCBSP_ROOT_PATH)/ti/drv/mcbsp
PDK_PROFILING_ROOT_PATH ?= $(pdk_PATH)
export PDK_PROFILING_COMP_PATH = $(PDK_PROFILING_ROOT_PATH)/ti/utils/profiling
PDK_TRACE_ROOT_PATH ?= $(pdk_PATH)
export PDK_TRACE_COMP_PATH = $(PDK_TRACE_ROOT_PATH)/ti/utils/trace
PDK_PRUSS_ROOT_PATH ?= $(pdk_PATH)
export PDK_PRUSS_COMP_PATH = $(PDK_PRUSS_ROOT_PATH)/ti/drv/pruss
PDK_NIMU_ROOT_PATH ?= $(pdk_PATH)
export PDK_NIMU_COMP_PATH = $(PDK_NIMU_ROOT_PATH)/ti/transport/ndk/nimu
PDK_NIMU_ICSS_ROOT_PATH ?= $(pdk_PATH)
export PDK_NIMU_ICSS_COMP_PATH = $(PDK_NIMU_ICSS_ROOT_PATH)/ti/transport/ndk/nimu_icss
PDK_TIMESYNC_ROOT_PATH ?= $(pdk_PATH)
export PDK_TIMESYNC_COMP_PATH = $(PDK_TIMESYNC_ROOT_PATH)/ti/transport/timeSync
PDK_ICSS_EMAC_ROOT_PATH ?= $(pdk_PATH)
export PDK_ICSS_EMAC_COMP_PATH = $(PDK_ICSS_EMAC_ROOT_PATH)/ti/drv/icss_emac
PDK_EMAC_ROOT_PATH ?= $(pdk_PATH)
export PDK_EMAC_COMP_PATH = $(PDK_EMAC_ROOT_PATH)/ti/drv/emac
PDK_UART_ROOT_PATH ?= $(pdk_PATH)
export PDK_UART_COMP_PATH = $(PDK_UART_ROOT_PATH)/ti/drv/uart
PDK_SPI_ROOT_PATH ?= $(pdk_PATH)
export PDK_SPI_COMP_PATH = $(PDK_SPI_ROOT_PATH)/ti/drv/spi
PDK_BOARD_ROOT_PATH ?= $(pdk_PATH)
export PDK_BOARD_COMP_PATH = $(PDK_BOARD_ROOT_PATH)/ti/board
PDK_GPMC_ROOT_PATH ?= $(pdk_PATH)
export PDK_GPMC_COMP_PATH = $(PDK_GPMC_ROOT_PATH)/ti/drv/gpmc
PDK_AUD_ROOT_PATH ?= $(pdk_PATH)
export PDK_AUD_COMP_PATH = $(PDK_AUD_ROOT_PATH)/ti/addon/aud
PDK_SBL_ROOT_PATH ?= $(pdk_PATH)
export PDK_SBL_COMP_PATH = $(PDK_SBL_ROOT_PATH)/ti/boot/sbl
PDK_SBL_AUTO_ROOT_PATH ?= $(pdk_PATH)
export PDK_SBL_AUTO_COMP_PATH = $(PDK_SBL_AUTO_ROOT_PATH)/ti/boot/sbl_auto
PDK_CMB_ROOT_PATH ?= $(pdk_PATH)
export PDK_CMB_COMP_PATH = $(PDK_CMB_ROOT_PATH)/ti/addon/cmb
PDK_BOARD_IND_ROOT_PATH ?= $(pdk_PATH)
export PDK_BOARD_IND_COMP_PATH = $(PDK_BOARD_IND_ROOT_PATH)/ti/addon/board_ind
PDK_BOARD_UTILS_ROOT_PATH ?= $(pdk_PATH)
export PDK_BOARD_UTILS_COMP_PATH = $(PDK_BOARD_UTILS_ROOT_PATH)/ti/board/utils
PDK_BOARD_DIAG_ROOT_PATH ?= $(pdk_PATH)
export PDK_BOARD_DIAG_COMP_PATH = $(PDK_BOARD_DIAG_ROOT_PATH)/ti/board/diag

PDK_SA_ROOT_PATH ?= $(pdk_PATH)
export PDK_SA_COMP_PATH = $(PDK_SA_ROOT_PATH)/ti/drv/sa

PDK_IOLINK_ROOT_PATH ?= $(pdk_PATH)
export PDK_IOLINK_COMP_PATH = $(PDK_IOLINK_ROOT_PATH)/ti/drv/iolink

#Below applicable only for K3 devices
PDK_UDMA_ROOT_PATH ?= $(pdk_PATH)
export PDK_UDMA_COMP_PATH = $(PDK_UDMA_ROOT_PATH)/ti/drv/udma
PDK_DSS_ROOT_PATH ?= $(pdk_PATH)
export PDK_DSS_COMP_PATH = $(PDK_DSS_ROOT_PATH)/ti/drv/dss
PDK_SCICLIENT_ROOT_PATH ?= $(pdk_PATH)
export PDK_SCICLIENT_COMP_PATH = $(PDK_SCICLIENT_ROOT_PATH)/ti/drv/sciclient
PDK_FVID2_ROOT_PATH ?= $(pdk_PATH)
export PDK_FVID2_COMP_PATH = $(PDK_FVID2_ROOT_PATH)/ti/drv/fvid2
PDK_CAL_ROOT_PATH ?= $(pdk_PATH)
export PDK_CAL_COMP_PATH = $(PDK_CAL_ROOT_PATH)/ti/drv/cal
PDK_VHWA_ROOT_PATH ?= $(pdk_PATH)
export PDK_VHWA_COMP_PATH = $(PDK_VHWA_ROOT_PATH)/ti/drv/vhwa
PDK_CSIRX_ROOT_PATH ?= $(pdk_PATH)
export PDK_CSIRX_COMP_PATH = $(PDK_CSIRX_ROOT_PATH)/ti/drv/csirx
PDK_IPC_ROOT_PATH ?= $(pdk_PATH)
export PDK_IPC_COMP_PATH = $(pdk_PATH)/ti/drv/ipc
PDK_CPSW_ROOT_PATH ?= $(pdk_PATH)
export PDK_CPSW_COMP_PATH = $(PDK_CPSW_ROOT_PATH)/ti/drv/cpsw
PDK_CSITX_ROOT_PATH ?= $(pdk_PATH)
export PDK_CSITX_COMP_PATH = $(PDK_CSITX_ROOT_PATH)/ti/drv/csitx

#Below applicable only for TPR12 devices
PDK_CRC_ROOT_PATH ?= $(pdk_PATH)
export PDK_CRC_COMP_PATH = $(PDK_CRC_ROOT_PATH)/ti/drv/crc
PDK_EDMA_ROOT_PATH ?= $(pdk_PATH)
export PDK_EDMA_COMP_PATH = $(PDK_EDMA_ROOT_PATH)/ti/drv/edma
PDK_MAILBOX_ROOT_PATH ?= $(pdk_PATH)
export PDK_MAILBOX_COMP_PATH = $(PDK_MAILBOX_ROOT_PATH)/ti/drv/mailbox
PDK_ESM_ROOT_PATH ?= $(pdk_PATH)
export PDK_ESM_COMP_PATH = $(PDK_ESM_ROOT_PATH)/ti/drv/esm
PDK_CAN_ROOT_PATH ?= $(pdk_PATH)
export PDK_CAN_COMP_PATH = $(PDK_CAN_ROOT_PATH)/ti/drv/can

#Below applicable only for K3 DMSC; not applicable for PRSDK
DMSC_ROOT_PATH ?= $(pdk_PATH)
export DMSC_COMP_PATH = $(DMSC_ROOT_PATH)/ti/dmsc

#Below applicable only for TDA devices
PDK_DIAG_ROOT_PATH ?= $(pdk_PATH)
export PDK_DIAG_COMP_PATH = $(PDK_DIAG_ROOT_PATH)/ti/diag
PDK_FIREWALL_L3L4_ROOT_PATH ?= $(pdk_PATH)
export PDK_FIREWALL_L3L4_COMP_PATH = $(PDK_FIREWALL_L3L4_ROOT_PATH)/ti/drv/fw_l3l4
PDK_IPCLITE_ROOT_PATH ?= $(pdk_PATH)
export PDK_IPCLITE_COMP_PATH = $(PDK_IPCLITE_ROOT_PATH)/ti/drv/ipc_lite
PDK_TDA3X_SECURITY_ROOT_PATH ?= $(pdk_PATH)
export PDK_TDA3X_SECURITY_COMP_PATH = $(PDK_TDA3X_SECURITY_ROOT_PATH)/ti/boot/sbl_auto/security

#Below applicable only for TDA devices for backward compatibility;not applicable for PRSDK
PDK_NORFLASH_ROOT_PATH ?= $(pdk_PATH)
export PDK_NORFLASH_COMP_PATH = $(PDK_NORFLASH_ROOT_PATH)/ti/boot/sbl_auto/norflash
PDK_QSPIFLASH_ROOT_PATH ?= $(pdk_PATH)
export PDK_QSPIFLASH_COMP_PATH = $(PDK_QSPIFLASH_ROOT_PATH)/ti/boot/sbl_auto/qspiflash
PDK_STW_LLD_ROOT_PATH ?= $(pdk_PATH)
export PDK_STW_LLD_COMP_PATH = $(PDK_STW_LLD_ROOT_PATH)/ti/drv/stw_lld
PDK_BSP_LLD_ROOT_PATH ?= $(pdk_PATH)
export PDK_BSP_LLD_COMP_PATH = $(PDK_BSP_LLD_ROOT_PATH)/ti/drv/bsp_lld
