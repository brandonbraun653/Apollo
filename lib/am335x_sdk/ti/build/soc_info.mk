#Various SOC support for J6 TDA family of devices
SOC_LIST_J6_TDA   = tda2xx tda2ex tda3xx tda2px

#Various SOC support for Catalog family of devices
SOC_LIST_CATALOG   = am335x am572x am571x am574x k2h k2k k2e k2l k2g omapl138 omapl137 am437x c6678 c6657 am65xx j721e j7200 am64x tpr12

#Various SOC support for Infotainment family of devices
SOC_LIST_INFOTAINMENT   = dra72x dra75x dra78x

# LIST of Boards for each SOC
BOARD_LIST_k2h = evmK2H
BOARD_LIST_k2k = evmK2K
BOARD_LIST_k2l = evmK2L
BOARD_LIST_k2e = evmK2E
BOARD_LIST_c6657 = evmC6657
BOARD_LIST_c6678 = evmC6678
BOARD_LIST_k2g = evmK2G iceK2G
BOARD_LIST_am335x = evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x
BOARD_LIST_am437x = evmAM437x idkAM437x skAM437x
BOARD_LIST_am571x = idkAM571x
BOARD_LIST_am572x = evmAM572x idkAM572x
BOARD_LIST_am574x = idkAM574x
BOARD_LIST_dra72x = evmDRA72x
BOARD_LIST_dra75x = evmDRA75x
BOARD_LIST_dra78x = evmDRA78x
BOARD_LIST_omapl137 =  evmOMAPL137
BOARD_LIST_omapl138 =  lcdkOMAPL138
BOARD_LIST_am65xx = am65xx_evm am65xx_idk
BOARD_LIST_j721e = j721e_evm
BOARD_LIST_j7200 = j7200_evm
BOARD_LIST_tpr12 = tpr12_evm

# LIST of cores for each SOC
CORE_LIST_tda2xx = a15_0 ipu1_0 c66x arp32_1
CORE_LIST_tda2px = a15_0 ipu1_0 c66x arp32_1
CORE_LIST_am571x = a15_0 ipu1_0 c66x pru_0 pru_1
CORE_LIST_am572x = a15_0 ipu1_0 c66x pru_0 pru_1 arp32_1
CORE_LIST_am574x = a15_0 ipu1_0 c66x pru_0 pru_1 arp32_1
CORE_LIST_dra72x = a15_0 ipu1_0 c66x
CORE_LIST_dra75x = a15_0 ipu1_0 c66x arp32_1
CORE_LIST_tda2ex = a15_0 ipu1_0 c66x
CORE_LIST_tda3xx = ipu1_0 c66x arp32_1
CORE_LIST_dra78x = ipu1_0 c66x arp32_1
CORE_LIST_k2h    = a15_0 c66x
CORE_LIST_k2k    = a15_0 c66x
CORE_LIST_k2l    = a15_0 c66x
CORE_LIST_k2e    = a15_0 c66x
CORE_LIST_k2g    = a15_0 c66x pru_0 pru_1
CORE_LIST_c6678  = c66x
CORE_LIST_c6657  = c66x
CORE_LIST_am335x = a8host pru_0 pru_1
CORE_LIST_am437x = a9host pru_0 pru_1
CORE_LIST_omapl137 = arm9_0 c674x
CORE_LIST_omapl138 = arm9_0 c674x
CORE_LIST_am65xx   = mpu1_0 mcu1_0 mcu1_1 mpu1_1 mpu2_0 mpu2_1
CORE_LIST_j721e    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1 c66xdsp_1 c66xdsp_2 c7x_1 mpu1_1
CORE_LIST_j7200    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mpu1_1
CORE_LIST_am64x    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 ipu1_0
CORE_LIST_k3_CORELIST = m3
CORE_LIST_PRU = pru_0 pru_1
CORE_LIST_tpr12    = mcu1_0 c66xdsp_1
