#**********************************************************************************************************************
# File:
#   cpu_init.tcl
#
# Description:
#   Initialization procedures for the beaglebone black. This was taken from the TI CCS gel file for
#   this device and then modified to work with Jim-TCL for OpenOCD.
#
# 2021 | Brandon Braun | brandonbraun653@gmail.com
#**********************************************************************************************************************

#****************************************************
# PRCM module definitions
#****************************************************
set PRCM_BASE_ADDR                                    0x44E00000
set CM_PER_EMIF_CLKCTRL                               [expr $PRCM_BASE_ADDR + 0x028]
set CM_PER_EMIF_FW_CLKCTRL                            [expr $PRCM_BASE_ADDR + 0x0D0]

set CM_AUTOIDLE_DPLL_MPU                              [expr $PRCM_BASE_ADDR + 0x41C]
set CM_IDLEST_DPLL_MPU                                [expr $PRCM_BASE_ADDR + 0x420]
set CM_CLKSEL_DPLL_MPU                                [expr $PRCM_BASE_ADDR + 0x42C]
set CM_AUTOIDLE_DPLL_DDR                              [expr $PRCM_BASE_ADDR + 0x430]
set CM_IDLEST_DPLL_DDR                                [expr $PRCM_BASE_ADDR + 0x434]
set CM_CLKSEL_DPLL_DDR                                [expr $PRCM_BASE_ADDR + 0x440]
set CM_AUTOIDLE_DPLL_DISP                             [expr $PRCM_BASE_ADDR + 0x444]
set CM_IDLEST_DPLL_DISP                               [expr $PRCM_BASE_ADDR + 0x448]
set CM_CLKSEL_DPLL_DISP                               [expr $PRCM_BASE_ADDR + 0x454]
set CM_AUTOIDLE_DPLL_CORE                             [expr $PRCM_BASE_ADDR + 0x458]
set CM_IDLEST_DPLL_CORE                               [expr $PRCM_BASE_ADDR + 0x45C]
set CM_CLKSEL_DPLL_CORE                               [expr $PRCM_BASE_ADDR + 0x468]
set CM_AUTOIDLE_DPLL_PER                              [expr $PRCM_BASE_ADDR + 0x46C]
set CM_IDLEST_DPLL_PER                                [expr $PRCM_BASE_ADDR + 0x470]
set CM_CLKSEL_DPLL_PER                                [expr $PRCM_BASE_ADDR + 0x49C]

set CM_DIV_M4_DPLL_CORE                               [expr $PRCM_BASE_ADDR + 0x480]
set CM_DIV_M5_DPLL_CORE                               [expr $PRCM_BASE_ADDR + 0x484]
set CM_CLKMODE_DPLL_MPU                               [expr $PRCM_BASE_ADDR + 0x488]
set CM_CLKMODE_DPLL_PER                               [expr $PRCM_BASE_ADDR + 0x48C]
set CM_CLKMODE_DPLL_CORE                              [expr $PRCM_BASE_ADDR + 0x490]
set CM_CLKMODE_DPLL_DDR                               [expr $PRCM_BASE_ADDR + 0x494]
set CM_CLKMODE_DPLL_DISP                              [expr $PRCM_BASE_ADDR + 0x498]

set CM_DIV_M2_DPLL_DDR                                [expr $PRCM_BASE_ADDR + 0x4A0]
set CM_DIV_M2_DPLL_DISP                               [expr $PRCM_BASE_ADDR + 0x4A4]
set CM_DIV_M2_DPLL_MPU                                [expr $PRCM_BASE_ADDR + 0x4A8]
set CM_DIV_M2_DPLL_PER                                [expr $PRCM_BASE_ADDR + 0x4AC]
set CM_DIV_M6_DPLL_CORE                               [expr $PRCM_BASE_ADDR + 0x4D8]

set CM_CLKOUT_CTRL                                    [expr $PRCM_BASE_ADDR + 0x700]

#****************************************************
# Control module definitions
#****************************************************
set CONTROL_BASE_ADDR                                 0x44E10000

set CONTROL_STATUS                                    [expr $CONTROL_BASE_ADDR + 0x40]
set CONF_XDMA_EVENT_INTR1                             [expr $CONTROL_BASE_ADDR + 0x9b4]

# DDR IO Control Registers
set DDR_IO_CTRL                                       [expr $CONTROL_BASE_ADDR + 0x0E04]
set VTP_CTRL_REG                                      [expr $CONTROL_BASE_ADDR + 0x0E0C]
set DDR_CKE_CTRL                                      [expr $CONTROL_BASE_ADDR + 0x131C]
set DDR_CMD0_IOCTRL                                   [expr $CONTROL_BASE_ADDR + 0x1404]
set DDR_CMD1_IOCTRL                                   [expr $CONTROL_BASE_ADDR + 0x1408]
set DDR_CMD2_IOCTRL                                   [expr $CONTROL_BASE_ADDR + 0x140C]
set DDR_DATA0_IOCTRL                                  [expr $CONTROL_BASE_ADDR + 0x1440]
set DDR_DATA1_IOCTRL                                  [expr $CONTROL_BASE_ADDR + 0x1444]

#********************************************************************
# EMIF4DC module definitions
#********************************************************************
set EMIF_BASE_ADDR                                    0x4C000000
set EMIF_STATUS_REG                                   [expr $EMIF_BASE_ADDR + 0x004]
set EMIF_SDRAM_CONFIG_REG                             [expr $EMIF_BASE_ADDR + 0x008]
set EMIF_SDRAM_CONFIG_2_REG                           [expr $EMIF_BASE_ADDR + 0x00C]
set EMIF_SDRAM_REF_CTRL_REG                           [expr $EMIF_BASE_ADDR + 0x010]
set EMIF_SDRAM_REF_CTRL_SHDW_REG                      [expr $EMIF_BASE_ADDR + 0x014]
set EMIF_SDRAM_TIM_1_REG                              [expr $EMIF_BASE_ADDR + 0x018]
set EMIF_SDRAM_TIM_1_SHDW_REG                         [expr $EMIF_BASE_ADDR + 0x01C]
set EMIF_SDRAM_TIM_2_REG                              [expr $EMIF_BASE_ADDR + 0x020]
set EMIF_SDRAM_TIM_2_SHDW_REG                         [expr $EMIF_BASE_ADDR + 0x024]
set EMIF_SDRAM_TIM_3_REG                              [expr $EMIF_BASE_ADDR + 0x028]
set EMIF_SDRAM_TIM_3_SHDW_REG                         [expr $EMIF_BASE_ADDR + 0x02C]
set EMIF_LPDDR2_NVM_TIM_REG                           [expr $EMIF_BASE_ADDR + 0x030]
set EMIF_LPDDR2_NVM_TIM_SHDW_REG                      [expr $EMIF_BASE_ADDR + 0x034]
set EMIF_PWR_MGMT_CTRL_REG                            [expr $EMIF_BASE_ADDR + 0x038]
set EMIF_PWR_MGMT_CTRL_SHDW_REG                       [expr $EMIF_BASE_ADDR + 0x03C]
set EMIF_LPDDR2_MODE_REG_DATA_REG                     [expr $EMIF_BASE_ADDR + 0x040]
set EMIF_LPDDR2_MODE_REG_CFG_REG                      [expr $EMIF_BASE_ADDR + 0x050]
set EMIF_OCP_CONFIG_REG                               [expr $EMIF_BASE_ADDR + 0x054]
set EMIF_OCP_CFG_VAL_1_REG                            [expr $EMIF_BASE_ADDR + 0x058]
set EMIF_OCP_CFG_VAL_2_REG                            [expr $EMIF_BASE_ADDR + 0x05C]
set EMIF_IODFT_TLGC_REG                               [expr $EMIF_BASE_ADDR + 0x060]
set EMIF_IODFT_CTRL_MISR_RSLT_REG                     [expr $EMIF_BASE_ADDR + 0x064]
set EMIF_IODFT_ADDR_MISR_RSLT_REG                     [expr $EMIF_BASE_ADDR + 0x068]
set EMIF_IODFT_DATA_MISR_RSLT_1_REG                   [expr $EMIF_BASE_ADDR + 0x06C]
set EMIF_IODFT_DATA_MISR_RSLT_2_REG                   [expr $EMIF_BASE_ADDR + 0x070]
set EMIF_IODFT_DATA_MISR_RSLT_3_REG                   [expr $EMIF_BASE_ADDR + 0x074]
set EMIF_PERF_CNT_1_REG                               [expr $EMIF_BASE_ADDR + 0x080]
set EMIF_PERF_CNT_2_REG                               [expr $EMIF_BASE_ADDR + 0x084]
set EMIF_PERF_CNT_CFG_REG                             [expr $EMIF_BASE_ADDR + 0x088]
set EMIF_PERF_CNT_SEL_REG                             [expr $EMIF_BASE_ADDR + 0x08C]
set EMIF_PERF_CNT_TIM_REG                             [expr $EMIF_BASE_ADDR + 0x090]
set EMIF_READ_IDLE_CTRL_REG                           [expr $EMIF_BASE_ADDR + 0x098]
set EMIF_READ_IDLE_CTRL_SHDW_REG                      [expr $EMIF_BASE_ADDR + 0x09C]
set EMIF_IRQ_EOI_REG                                  [expr $EMIF_BASE_ADDR + 0x0A0]
set EMIF_IRQSTATUS_RAW_SYS_REG                        [expr $EMIF_BASE_ADDR + 0x0A4]
set EMIF_IRQSTATUS_SYS_REG                            [expr $EMIF_BASE_ADDR + 0x0AC]
set EMIF_IRQENABLE_SET_SYS_REG                        [expr $EMIF_BASE_ADDR + 0x0B4]
set EMIF_IRQENABLE_CLR_SYS_REG                        [expr $EMIF_BASE_ADDR + 0x0BC]
set EMIF_ZQ_CONFIG_REG                                [expr $EMIF_BASE_ADDR + 0x0C8]
set EMIF_TEMP_ALERT_CONFIG_REG                        [expr $EMIF_BASE_ADDR + 0x0CC]
set EMIF_OCP_ERR_LOG_REG                              [expr $EMIF_BASE_ADDR + 0x0D0]
set EMIF_RDWR_LVL_RMP_WIN_REG                         [expr $EMIF_BASE_ADDR + 0x0D4]
set EMIF_RDWR_LVL_RMP_CTRL_REG                        [expr $EMIF_BASE_ADDR + 0x0D8]
set EMIF_RDWR_LVL_CTRL_REG                            [expr $EMIF_BASE_ADDR + 0x0DC]
set EMIF_DDR_PHY_CTRL_1_REG                           [expr $EMIF_BASE_ADDR + 0x0E4]
set EMIF_DDR_PHY_CTRL_1_SHDW_REG                      [expr $EMIF_BASE_ADDR + 0x0E8]
set EMIF_DDR_PHY_CTRL_2_REG                           [expr $EMIF_BASE_ADDR + 0x0EC]
set EMIF_PRI_COS_MAP_REG                              [expr $EMIF_BASE_ADDR + 0x100]
set EMIF_CONNID_COS_1_MAP_REG                         [expr $EMIF_BASE_ADDR + 0x104]
set EMIF_CONNID_COS_2_MAP_REG                         [expr $EMIF_BASE_ADDR + 0x108]
set EMIF_RD_WR_EXEC_THRSH_REG                         [expr $EMIF_BASE_ADDR + 0x120]


#*******************************************************************
# DDR PHY registers
#*******************************************************************
set DDR_PHY_BASE_ADDR                                 0x44E12000

# CMD0
set CMD0_REG_PHY_CTRL_SLAVE_RATIO_0                   [expr 0x01C + $DDR_PHY_BASE_ADDR]
set CMD0_REG_PHY_CTRL_SLAVE_FORCE_0                   [expr 0x020 + $DDR_PHY_BASE_ADDR]
set CMD0_REG_PHY_CTRL_SLAVE_DELAY_0                   [expr 0x024 + $DDR_PHY_BASE_ADDR]
set CMD0_REG_PHY_DLL_LOCK_DIFF_0                      [expr 0x028 + $DDR_PHY_BASE_ADDR]
set CMD0_REG_PHY_INVERT_CLKOUT_0                      [expr 0x02C + $DDR_PHY_BASE_ADDR]
set CMD0_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0           [expr 0x030 + $DDR_PHY_BASE_ADDR]
set CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0   [expr 0x034 + $DDR_PHY_BASE_ADDR]
set CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0  [expr 0x038 + $DDR_PHY_BASE_ADDR]
set CMD0_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0 [expr 0x03C + $DDR_PHY_BASE_ADDR]

# CMD1
set CMD1_REG_PHY_CTRL_SLAVE_RATIO_0                   [expr 0x050 + $DDR_PHY_BASE_ADDR]
set CMD1_REG_PHY_CTRL_SLAVE_FORCE_0                   [expr 0x054 + $DDR_PHY_BASE_ADDR]
set CMD1_REG_PHY_CTRL_SLAVE_DELAY_0                   [expr 0x058 + $DDR_PHY_BASE_ADDR]
set CMD1_REG_PHY_DLL_LOCK_DIFF_0                      [expr 0x05C + $DDR_PHY_BASE_ADDR]
set CMD1_REG_PHY_INVERT_CLKOUT_0                      [expr 0x060 + $DDR_PHY_BASE_ADDR]
set CMD1_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0           [expr 0x064 + $DDR_PHY_BASE_ADDR]
set CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0   [expr 0x068 + $DDR_PHY_BASE_ADDR]
set CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0  [expr 0x06C + $DDR_PHY_BASE_ADDR]
set CMD1_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0 [expr 0x070 + $DDR_PHY_BASE_ADDR]

# CMD2
set CMD2_REG_PHY_CTRL_SLAVE_RATIO_0                   [expr 0x084 + $DDR_PHY_BASE_ADDR]
set CMD2_REG_PHY_CTRL_SLAVE_FORCE_0                   [expr 0x088 + $DDR_PHY_BASE_ADDR]
set CMD2_REG_PHY_CTRL_SLAVE_DELAY_0                   [expr 0x08C + $DDR_PHY_BASE_ADDR]
set CMD2_REG_PHY_DLL_LOCK_DIFF_0                      [expr 0x090 + $DDR_PHY_BASE_ADDR]
set CMD2_REG_PHY_INVERT_CLKOUT_0                      [expr 0x094 + $DDR_PHY_BASE_ADDR]
set CMD2_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0           [expr 0x098 + $DDR_PHY_BASE_ADDR]
set CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0   [expr 0x09C + $DDR_PHY_BASE_ADDR]
set CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0  [expr 0x0A0 + $DDR_PHY_BASE_ADDR]
set CMD2_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0 [expr 0x0A4 + $DDR_PHY_BASE_ADDR]

# DATA0
set DATA0_REG_PHY_DATA_SLICE_IN_USE_0                 [expr 0x0B8 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_DIS_CALIB_RST_0                     [expr 0x0BC + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0          [expr 0x0C0 + $DDR_PHY_BASE_ADDR]
set DATA0_PHY_RDC_FIFO_RST_ERR_CNT_0                  [expr 0x0C4 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0                [expr 0x0C8 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_1                [expr 0x0CC + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RD_DQS_SLAVE_FORCE_0                [expr 0x0D0 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_0                [expr 0x0D4 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_1                [expr 0x0D8 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0                [expr 0x0DC + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_1                [expr 0x0E0 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DQS_SLAVE_FORCE_0                [expr 0x0E4 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_0                [expr 0x0E8 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_1                [expr 0x0EC + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WRLVL_INIT_RATIO_0                  [expr 0x0F0 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WRLVL_INIT_RATIO_1                  [expr 0x0F4 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WRLVL_INIT_MODE_0                   [expr 0x0F8 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_GATELVL_INIT_RATIO_0                [expr 0x0FC + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_GATELVL_INIT_RATIO_1                [expr 0x100 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_GATELVL_INIT_MODE_0                 [expr 0x104 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0               [expr 0x108 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_1               [expr 0x10C + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_FIFO_WE_IN_FORCE_0                  [expr 0x110 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_FIFO_WE_IN_DELAY_0                  [expr 0x114 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_FIFO_WE_IN_DELAY_1                  [expr 0x118 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_DQ_OFFSET_0                         [expr 0x11C + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0               [expr 0x120 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_1               [expr 0x124 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DATA_SLAVE_FORCE_0               [expr 0x128 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_0               [expr 0x12C + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_1               [expr 0x130 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_USE_RANK0_DELAYS_0                  [expr 0x134 + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_DLL_LOCK_DIFF_0                     [expr 0x138 + $DDR_PHY_BASE_ADDR]
set DATA0_PHY_REG_STATUS_DLL_LOCK_0                   [expr 0x13C + $DDR_PHY_BASE_ADDR]
set DATA0_PHY_REG_STATUS_OF_IN_LOCK_STATE_0           [expr 0x140 + $DDR_PHY_BASE_ADDR]
set DATA0_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0          [expr 0x144 + $DDR_PHY_BASE_ADDR]
set DATA0_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0         [expr 0x148 + $DDR_PHY_BASE_ADDR]

# DATA1
set DATA1_REG_PHY_DATA_SLICE_IN_USE_0                 [expr 0x15C + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_DIS_CALIB_RST_0                     [expr 0x160 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0          [expr 0x164 + $DDR_PHY_BASE_ADDR]
set DATA1_PHY_RDC_FIFO_RST_ERR_CNT_0                  [expr 0x168 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_0                [expr 0x16C + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_1                [expr 0x170 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RD_DQS_SLAVE_FORCE_0                [expr 0x174 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_0                [expr 0x178 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_1                [expr 0x17C + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_0                [expr 0x180 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_1                [expr 0x184 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DQS_SLAVE_FORCE_0                [expr 0x188 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_0                [expr 0x18C + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_1                [expr 0x190 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WRLVL_INIT_RATIO_0                  [expr 0x194 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WRLVL_INIT_RATIO_1                  [expr 0x198 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WRLVL_INIT_MODE_0                   [expr 0x19C + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_GATELVL_INIT_RATIO_0                [expr 0x1A0 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_GATELVL_INIT_RATIO_1                [expr 0x1A4 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_GATELVL_INIT_MODE_0                 [expr 0x1A8 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_0               [expr 0x1AC + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_1               [expr 0x1B0 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_FIFO_WE_IN_FORCE_0                  [expr 0x1B4 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_FIFO_WE_IN_DELAY_0                  [expr 0x1B8 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_FIFO_WE_IN_DELAY_1                  [expr 0x1BC + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_DQ_OFFSET_0                         [expr 0x1C0 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_0               [expr 0x1C4 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_1               [expr 0x1C8 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DATA_SLAVE_FORCE_0               [expr 0x1CC + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_0               [expr 0x1D0 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_1               [expr 0x1D4 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_USE_RANK0_DELAYS_0                  [expr 0x1D8 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_DLL_LOCK_DIFF_0                     [expr 0x1DC + $DDR_PHY_BASE_ADDR]
set DATA1_PHY_REG_STATUS_DLL_LOCK_0                   [expr 0x1E0 + $DDR_PHY_BASE_ADDR]
set DATA1_PHY_REG_STATUS_OF_IN_LOCK_STATE_0           [expr 0x1E4 + $DDR_PHY_BASE_ADDR]
set DATA1_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0          [expr 0x1E8 + $DDR_PHY_BASE_ADDR]
set DATA1_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0         [expr 0x1EC + $DDR_PHY_BASE_ADDR]

# FIFO
set FIFO_WE_OUT0_IO_CONFIG_I_0                        [expr 0x338 + $DDR_PHY_BASE_ADDR]
set FIFO_WE_OUT0_IO_CONFIG_SR_0                       [expr 0x33C + $DDR_PHY_BASE_ADDR]
set FIFO_WE_OUT1_IO_CONFIG_I_0                        [expr 0x340 + $DDR_PHY_BASE_ADDR]
set FIFO_WE_OUT1_IO_CONFIG_SR_0                       [expr 0x344 + $DDR_PHY_BASE_ADDR]
set FIFO_WE_IN2_IO_CONFIG_I_0                         [expr 0x348 + $DDR_PHY_BASE_ADDR]
set FIFO_WE_IN2_IO_CONFIG_SR_0                        [expr 0x34C + $DDR_PHY_BASE_ADDR]
set FIFO_WE_IN3_IO_CONFIG_I_0                         [expr 0x350 + $DDR_PHY_BASE_ADDR]
set FIFO_WE_IN3_IO_CONFIG_SR_0                        [expr 0x354 + $DDR_PHY_BASE_ADDR]

# Leveling
set DATA0_REG_PHY_WRLVL_NUM_OF_DQ0                    [expr 0x35C + $DDR_PHY_BASE_ADDR]
set DATA0_REG_PHY_GATELVL_NUM_OF_DQ0                  [expr 0x360 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_WRLVL_NUM_OF_DQ0                    [expr 0x364 + $DDR_PHY_BASE_ADDR]
set DATA1_REG_PHY_GATELVL_NUM_OF_DQ0                  [expr 0x368 + $DDR_PHY_BASE_ADDR]

#*******************************************************************
# Watchdog Timer registers
#*******************************************************************
set WDT1_BASE_ADDR                                    0x44E35000
set WDT1_WSPR                                         [expr $WDT1_BASE_ADDR + 0x48]

#******************************************************************
# DDR3=400MHz
# OPP100
# DDR3 PHY parameters
#******************************************************************
set CMD_PHY_CTRL_SLAVE_RATIO                          0x80
set CMD_PHY_INVERT_CLKOUT                             0x0
set DATA_PHY_RD_DQS_SLAVE_RATIO                       0x38
set DATA_PHY_FIFO_WE_SLAVE_RATIO                      0x94
set DATA_PHY_WR_DQS_SLAVE_RATIO                       0x44
set DATA_PHY_WR_DATA_SLAVE_RATIO                      0x7d
set DDR_IOCTRL_VALUE                                  0x18B

#******************************************************************
# EMIF parameters
# DDR3 = 400MHz
#******************************************************************
# RD_Latency = (CL + 2) - 1; CL=6 for DDR3-1600 speed grade and CK of 2.5ns
set ALLOPP_DDR3_READ_LATENCY                          0x07

#400MHz settings
set ALLOPP_DDR3_SDRAM_TIMING1                         0x0AAAD4DB
set ALLOPP_DDR3_SDRAM_TIMING2                         0x266B7FDA
set ALLOPP_DDR3_SDRAM_TIMING3                         0x501F867F

# dynamic ODT = 2 (RZQ/2)
# SDRAM drive = 0 (RZQ/6)
# CWL = 0 (CAS write latency = 5)
# CL = 4 (CAS latency = 6)
# ROWSIZE = 6 (15 row bits)
# PAGESIZE = 2 (10 column bits)
# termination = 1 (RZQ/4)
# 400 * 7.8us = 0xC30
set ALLOPP_DDR3_SDRAM_CONFIG                          0x61C05332
set ALLOPP_DDR3_REF_CTRL                              0x00000C30
set ALLOPP_DDR3_ZQ_CONFIG                             0x50074BE4


#******************************************************************
# AM335xPowerUp
#   Powers up the processor clocks and initializes the external
#   memory controller.
#******************************************************************
proc AM335xPowerUp {} {
  echo "****  AM335x BeagleBlack Initialization is in progress .........."
  ARM_OPP100_Config
  DDR3_EMIF_Config

  echo "Enabling debug core"
  cortex_a dbginit

  echo "****  AM335x BeagleBlack Initialization is Done ******************"
}


#******************************************************************************
# GetInputClockFrequency
#   Reads the SYSBOOT registers to determine which strapping resistors
#   are set, then uses this info to discover the input crystal frequency.
#
#******************************************************************************
proc GetInputClockFrequency {} {
  global CONTROL_STATUS

  set tmp [expr [expr [mrw $CONTROL_STATUS] >> 22] & 0x3]

  if {$tmp == 0} {
    echo {Input Clock Read from SYSBOOT[15:14]: 19.2MHz}
    return 19
  } elseif {$tmp == 1} {
    echo {Input Clock Read from SYSBOOT[15:14]: 24MHz}
    return 24
  } elseif {$tmp == 2} {
    echo {Input Clock Read from SYSBOOT[15:14]: 25MHz}
    return 25
  } elseif {$tmp == 3} {
    echo {Input Clock Read from SYSBOOT[15:14]: 26MHz}
    return 26
  } else {
    echo {ERROR: Invalid clock configuration value [$tmp]}
    return 0
  }
}

#******************************************************************************
# ARM_OPPP100_Config
#   Configures the processor PLLs to run in OPP100 mode.
#
#******************************************************************************
proc ARM_OPP100_Config {} {
  set clkin [GetInputClockFrequency]

  if {$clkin == 24} {
    # Set core clock to 600MHz, DDR clock to 400MHz
    MPU_PLL_Config  $clkin 0 25  1
    CORE_PLL_Config $clkin 2 125 10 8 4
    DDR_PLL_Config  $clkin 2 50  1
    PER_PLL_Config  $clkin 9 400 5
    DISP_PLL_Config $clkin 0 2   1
  } else {
    echo {ERROR: Can't configure OPP100 due to invalid input frequency}
  }
}


#******************************************************************************
# DDR3_EMIF_Config
#   Configures the DDR external memory interface controller
#
#******************************************************************************
proc DDR3_EMIF_Config {} {
  global ALLOPP_DDR3_READ_LATENCY
  global ALLOPP_DDR3_REF_CTRL
  global ALLOPP_DDR3_SDRAM_CONFIG
  global ALLOPP_DDR3_SDRAM_TIMING1
  global ALLOPP_DDR3_SDRAM_TIMING2
  global ALLOPP_DDR3_SDRAM_TIMING3
  global ALLOPP_DDR3_ZQ_CONFIG
  global DDR_CKE_CTRL
  global DDR_CMD0_IOCTRL
  global DDR_CMD1_IOCTRL
  global DDR_CMD2_IOCTRL
  global DDR_DATA0_IOCTRL
  global DDR_DATA1_IOCTRL
  global DDR_IOCTRL_VALUE
  global DDR_IO_CTRL
  global EMIF_DDR_PHY_CTRL_1_REG
  global EMIF_DDR_PHY_CTRL_1_SHDW_REG
  global EMIF_DDR_PHY_CTRL_2_REG
  global EMIF_SDRAM_CONFIG_REG
  global EMIF_SDRAM_REF_CTRL_REG
  global EMIF_SDRAM_REF_CTRL_SHDW_REG
  global EMIF_SDRAM_TIM_1_REG
  global EMIF_SDRAM_TIM_1_SHDW_REG
  global EMIF_SDRAM_TIM_2_REG
  global EMIF_SDRAM_TIM_2_SHDW_REG
  global EMIF_SDRAM_TIM_3_REG
  global EMIF_SDRAM_TIM_3_SHDW_REG
  global EMIF_STATUS_REG
  global EMIF_ZQ_CONFIG_REG

  echo {AM335x DDR3 EMIF and PHY configuration is in progress.........}
  EMIF_PRCM_CLK_ENABLE
  VTP_Enable
  PHY_Config_CMD
  PHY_Config_DATA

  echo {Setting IO control registers.......}
  mww phys $DDR_CMD0_IOCTRL  $DDR_IOCTRL_VALUE
  mww phys $DDR_CMD1_IOCTRL  $DDR_IOCTRL_VALUE
  mww phys $DDR_CMD2_IOCTRL  $DDR_IOCTRL_VALUE
  mww phys $DDR_DATA0_IOCTRL $DDR_IOCTRL_VALUE
  mww phys $DDR_DATA1_IOCTRL $DDR_IOCTRL_VALUE

  # IO to work for DDR3
  mww phys $DDR_IO_CTRL [expr [mrw $DDR_IO_CTRL] & ~0x10000000];

  # CKE controlled by EMIF/DDR_PHY
  mww phys $DDR_CKE_CTRL [expr [mrw $DDR_CKE_CTRL] | 0x00000001];

  echo {EMIF Timing register configuration is in progress.......}
  mww phys $EMIF_DDR_PHY_CTRL_1_REG       $ALLOPP_DDR3_READ_LATENCY
  mww phys $EMIF_DDR_PHY_CTRL_1_SHDW_REG  $ALLOPP_DDR3_READ_LATENCY
  mww phys $EMIF_DDR_PHY_CTRL_2_REG       $ALLOPP_DDR3_READ_LATENCY
  mww phys $EMIF_SDRAM_TIM_1_REG          $ALLOPP_DDR3_SDRAM_TIMING1
  mww phys $EMIF_SDRAM_TIM_1_SHDW_REG     $ALLOPP_DDR3_SDRAM_TIMING1
  mww phys $EMIF_SDRAM_TIM_2_REG          $ALLOPP_DDR3_SDRAM_TIMING2
  mww phys $EMIF_SDRAM_TIM_2_SHDW_REG     $ALLOPP_DDR3_SDRAM_TIMING2
  mww phys $EMIF_SDRAM_TIM_3_REG          $ALLOPP_DDR3_SDRAM_TIMING3
  mww phys $EMIF_SDRAM_TIM_3_SHDW_REG     $ALLOPP_DDR3_SDRAM_TIMING3
  mww phys $EMIF_SDRAM_REF_CTRL_REG       $ALLOPP_DDR3_REF_CTRL
  mww phys $EMIF_SDRAM_REF_CTRL_SHDW_REG  $ALLOPP_DDR3_REF_CTRL
  mww phys $EMIF_ZQ_CONFIG_REG            $ALLOPP_DDR3_ZQ_CONFIG
  mww phys $EMIF_SDRAM_CONFIG_REG         $ALLOPP_DDR3_SDRAM_CONFIG
  echo {EMIF Timing register configuration is done.......}

  if {[expr [mrw $EMIF_STATUS_REG] & 0x4] == 0x4} {
    echo {PHY is READY!!}
  }
  echo {AM335x DDR3 EMIF and PHY configuration done}
}


#******************************************************************************
# CORE_PLL_Config
#   Configures the CORE PLL using steps from TRM 8.1.6.7.1
#
# CLKIN:  External clock input frequency in MHz (integer)
#     N:  PLL Divisor
#     M:  PLL Multiplier
#    M4:  PLL M4 Divisor
#    M5:  PLL M5 Divisor
#    M6:  PLL M6 Divisor
#******************************************************************************
proc CORE_PLL_Config {CLKIN N M M4 M5 M6} {
  global CM_CLKMODE_DPLL_CORE
  global CM_CLKSEL_DPLL_CORE
  global CM_DIV_M4_DPLL_CORE
  global CM_DIV_M5_DPLL_CORE
  global CM_DIV_M6_DPLL_CORE
  global CM_IDLEST_DPLL_CORE

  echo {Configuring CORE PLL}

  # Pre-calculate desired outputs
  set ref_clk   [expr $CLKIN/($N+1)]
  set clk_out4  [expr ($ref_clk*$M)/$M4]
  set clk_out5  [expr ($ref_clk*$M)/$M5]
  set clk_out6  [expr ($ref_clk*$M)/$M6]

  # Read current register values
  set clkmode   [mrw $CM_CLKMODE_DPLL_CORE]
  set clksel    [mrw $CM_CLKSEL_DPLL_CORE]
  set div_m4    [mrw $CM_DIV_M4_DPLL_CORE]
  set div_m5    [mrw $CM_DIV_M5_DPLL_CORE]
  set div_m6    [mrw $CM_DIV_M6_DPLL_CORE]

  # Place the DPLL into bypass mode
  echo {Going to bypass...}
  set clkmode [expr ($clkmode & 0xFFFFFFF8) | 0x00000004]
  mww phys $CM_CLKMODE_DPLL_CORE $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_CORE] & 0x00000100] != 0x00000100]} {}
  echo {Bypassed, changing values}

  # Set multiply & divide values
  set clksel [expr $clksel & (~0x7FFFF)]
  set clksel [expr $clksel | (($M << 0x8) | $N)]
  mww $CM_CLKSEL_DPLL_CORE $clksel

  set div_m4 $M4
  mww $CM_DIV_M4_DPLL_CORE $div_m4

  set div_m5 $M5
  mww $CM_DIV_M5_DPLL_CORE $div_m5

  set div_m6 $M6
  mww $CM_DIV_M6_DPLL_CORE $div_m6

  # Apply the PLL settings and acquire lock
  echo {Locking CORE PLL}
  set clkmode [expr ($clkmode & 0xFFFFFFF8) | 0x00000007]
  mww phys $CM_CLKMODE_DPLL_CORE $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_CORE] & 0x00000001] != 0x000000001]} {}
  echo {Locked!}


  # Verify the settings were applied correctly

}


#******************************************************************************
# PER_PLL_Config
#   Configures the PER PLL using steps from TRM 8.1.6.8.1
#
# CLKIN:  External clock input frequency in MHz (integer)
#     N:  PLL Divisor
#     M:  PLL Multiplier
#    M2:  PLL M2 Divisor
#******************************************************************************
proc PER_PLL_Config {CLKIN N M M2} {
  global CM_CLKMODE_DPLL_PER
  global CM_CLKSEL_DPLL_PER
  global CM_DIV_M2_DPLL_PER
  global CM_IDLEST_DPLL_PER

  echo {Configuring PER PLL}

  # Pre-calculate desired outputs
  set ref_clk [expr $CLKIN/($N+1)]
  set clk_out [expr ($ref_clk*$M)/$M2]

  # Cache current register values
  set clkmode [mrw $CM_CLKMODE_DPLL_PER]
  set clksel  [mrw $CM_CLKSEL_DPLL_PER]
  set div_m2  [mrw $CM_DIV_M2_DPLL_PER]

  # Transition the PLL to bypass mode
  echo {Going to bypass...}
  set clkmode [expr ($clkmode & 0xFFFFFFF8) | 0x00000004]
  mww $CM_CLKMODE_DPLL_PER $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_PER] & 0x100] != 0x100]} {}
  echo {Bypassed, changing values...}

  # Set multiply and divide values
  set clksel [expr $clksel & (~0xFF0FFFFF)]
  set clksel [expr $clksel | 0x04000000]
  set clksel [expr $clksel | (($M << 0x8) | $N)]
  mww $CM_CLKSEL_DPLL_PER $clksel

  # Set M2 divisor
  set div_m2 [expr 0xFFFFFF80 | $M2]
  mww $CM_DIV_M2_DPLL_PER $div_m2

  # Apply the PLL settings and acquire lock
  echo {Locking DDR PLL}
  set clkmode [expr ( $clkmode & 0xFFFFFFF8) | 0x00000007]
  mww phys $CM_CLKMODE_DPLL_PER $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_PER] & 0x00000001] != 0x00000001]} {}
  echo {Locked!}
}


#******************************************************************************
# MPU_PLL_Config
#   Configures the MPU PLL using steps from TRM 8.1.6.9.1
#
# CLKIN:  External clock input frequency in MHz (integer)
#     N:  PLL Divisor
#     M:  PLL Multiplier
#    M2:  PLL M2 Divisor
#******************************************************************************
proc MPU_PLL_Config {CLKIN N M M2} {
  global CM_CLKMODE_DPLL_MPU
  global CM_CLKSEL_DPLL_MPU
  global CM_DIV_M2_DPLL_MPU
  global CM_IDLEST_DPLL_MPU

  echo {Configuring MPU PLL}

  # Calculate the desired reference clock and the output clock
  set ref_clk [expr $CLKIN/($N+1)]
  set clk_out [expr ($ref_clk*$M)/$M2]

  # Cache current register values
  set clkmode [mrw $CM_CLKMODE_DPLL_MPU]
  set clksel  [mrw $CM_CLKSEL_DPLL_MPU]
  set div_m2  [mrw $CM_DIV_M2_DPLL_MPU]

  # Transition the PLL to bypass mode
  echo {Going to bypass...}
  mww phys $CM_CLKMODE_DPLL_MPU 0x4
  while {[expr [expr [mrw $CM_IDLEST_DPLL_MPU] & 0x101] != 0x00000100]} {}
  echo {Bypassed, changing values...}

  # Set multiply (M) & divide (N) values
  set clksel [expr $clksel & (~0x7FFFF)]
  set clksel [expr $clksel | (($M << 0x8) | $N)]
  mww $CM_CLKSEL_DPLL_MPU $clksel

  # Set M2 divide value
  set div_m2 [expr $div_m2 & ~0x1F]
  set div_m2 [expr $div_m2 | $M2]
  mww $CM_DIV_M2_DPLL_MPU $div_m2

  # Apply the PLL settings and acquire lock
  echo {Locking MPU PLL}
  set clkmode [expr $clkmode | 0x7]
  mww phys $CM_CLKMODE_DPLL_MPU $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_MPU] & 0x101] != 0x1]} {}
  echo {Locked!}
}


#******************************************************************************
# DISP_PLL_Config
#   Configures the DISP PLL using steps from TRM 8.1.6.10.1
#
# CLKIN:  External clock input frequency in MHz (integer)
#     N:  PLL Divisor
#     M:  PLL Multiplier
#    M2:  PLL M2 Divisor
#******************************************************************************
proc DISP_PLL_Config {CLKIN N M M2} {
  global CM_CLKMODE_DPLL_DISP
  global CM_CLKSEL_DPLL_DISP
  global CM_DIV_M2_DPLL_DISP
  global CM_IDLEST_DPLL_DISP

  echo {Configuring DISP PLL}

  # Pre-calculate desired outputs
  set ref_clk [expr $CLKIN/($N+1)]
  set clk_out [expr ($ref_clk*$M)/$M2]

  # Cache current register values
  set clkmode [mrw $CM_CLKMODE_DPLL_DISP]
  set clksel  [mrw $CM_CLKSEL_DPLL_DISP]
  set div_m2  [mrw $CM_DIV_M2_DPLL_DISP]

  # Transition the PLL to bypass mode
  echo {Going to bypass...}
  set clkmode [expr ($clkmode & 0xFFFFFFF8) | 0x00000004]
  mww $CM_CLKMODE_DPLL_DISP $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_DISP] & 0x100] != 0x100]} {}
  echo {Bypassed, changing values...}

  # Set multiply and divide values
  set clksel [expr $clksel & (~0x7FFFF)]
  set clksel [expr $clksel | (($M << 0x8) | $N)]
  mww $CM_CLKSEL_DPLL_DISP $clksel

  # Set M2 divisor
  set div_m2 [expr 0xFFFFFFE0 | $M2]
  mww $CM_DIV_M2_DPLL_DISP $div_m2

  # Apply the PLL settings and acquire lock
  echo {Locking DDR PLL}
  set clkmode [expr ( $clkmode & 0xFFFFFFF8) | 0x00000007]
  mww phys $CM_CLKMODE_DPLL_DISP $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_DISP] & 0x00000001] != 0x00000001]} {}
  echo {Locked!}
}


#******************************************************************************
# DDR_PLL_Config
#   Configures the DDR PLL using steps from TRM 8.1.6.11.1
#
# CLKIN:  External clock input frequency in MHz (integer)
#     N:  PLL Divisor
#     M:  PLL Multiplier
#    M2:  PLL M2 Divisor
#******************************************************************************
proc DDR_PLL_Config {CLKIN N M M2} {
  global CM_CLKMODE_DPLL_DDR
  global CM_CLKSEL_DPLL_DDR
  global CM_DIV_M2_DPLL_DDR
  global CM_IDLEST_DPLL_DDR

  echo {Configuring DDR PLL}

  # Pre-calculate desired outputs
  set ref_clk [expr $CLKIN/($N+1)]
  set clk_out [expr ($ref_clk*$M)/$M2]

  # Cache current register values
  set clkmode [mrw $CM_CLKMODE_DPLL_DDR]
  set clksel  [mrw $CM_CLKSEL_DPLL_DDR]
  set div_m2  [mrw $CM_DIV_M2_DPLL_DDR]

  # Transition the PLL to bypass mode
  echo {Going to bypass...}
  mww phys $CM_CLKMODE_DPLL_DDR 0x4
  while {[expr [expr [mrw $CM_IDLEST_DPLL_DDR] & 0x100] != 0x00000100]} {}
  echo {Bypassed, changing values...}

  # Set multiply & divide values
  set clksel [expr $clksel & (~0x7FFFF)]
  set clksel [expr $clksel | (($M << 0x8) | $N)]
  mww $CM_CLKSEL_DPLL_DDR $clksel

  # Set M2 divisor
  set div_m2 [expr ($div_m2 & 0xFFFFFFE0) | $M2]
  mww phys $CM_DIV_M2_DPLL_DDR $div_m2

  # Apply the PLL settings and acquire lock
  echo {Locking DDR PLL}
  set clkmode [expr ( $clkmode & 0xFFFFFFF8) | 0x00000007]
  mww phys $CM_CLKMODE_DPLL_DDR $clkmode
  while {[expr [expr [mrw $CM_IDLEST_DPLL_DDR] & 0x00000001] != 0x00000001]} {}
  echo {Locked!}
}


#******************************************************************************
# EMIF_PRCM_CLK_ENABLE
#   Turns on the EMIF clock
#
#******************************************************************************
proc EMIF_PRCM_CLK_ENABLE {} {
  global CM_PER_EMIF_CLKCTRL

  echo {EMIF PRCM is in progress......}
  mww $CM_PER_EMIF_CLKCTRL 0x02
  while {[expr [expr [mrw $CM_PER_EMIF_CLKCTRL] & 0x02] != 0x02]} {}
  echo {EMIF PRCM done}
}


#******************************************************************************
# VTP_Enable
#   DDR VTP enable
#
#******************************************************************************
proc VTP_Enable {} {
  global VTP_CTRL_REG

  #clear the register
  mww $VTP_CTRL_REG 0x0

  #set filter bits to 011b
  mww $VTP_CTRL_REG 0x6

  #Write 1 to enable VTP
  mww $VTP_CTRL_REG [expr [mrw $VTP_CTRL_REG] | 0x00000040]

  #Write 0 to CLRZ bit
  mww $VTP_CTRL_REG [expr [mrw $VTP_CTRL_REG] & 0xFFFFFFFE]

  #Write 1 to CLRZ bit
  mww $VTP_CTRL_REG [expr [mrw $VTP_CTRL_REG] | 0x00000001]

  #Check for VTP ready bit
  echo {Waiting for VTP Ready......}
  while {[expr [expr [mrw $VTP_CTRL_REG] & 0x20] != 0x20]} {}
  echo {VTP is Ready!}
}


#******************************************************************************
# PHY_Config_CMD
#   Configures DDR command registers
#
#******************************************************************************
proc PHY_Config_CMD {} {
    global CMD0_REG_PHY_CTRL_SLAVE_RATIO_0
    global CMD0_REG_PHY_INVERT_CLKOUT_0
    global CMD_PHY_CTRL_SLAVE_RATIO
    global CMD_PHY_INVERT_CLKOUT

  for {set i 0} {$i < 3} {incr i} {
    echo "DDR PHY CMD$i Register configuration is in progress......"

    mww [expr $CMD0_REG_PHY_CTRL_SLAVE_RATIO_0 + ($i*0x34)] $CMD_PHY_CTRL_SLAVE_RATIO
    mww [expr $CMD0_REG_PHY_INVERT_CLKOUT_0    + ($i*0x34)] $CMD_PHY_INVERT_CLKOUT
  }
}


#******************************************************************************
# PHY_Config_DATA
#   Configures DDR data registers
#
#******************************************************************************
proc PHY_Config_DATA {} {
    global DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0
    global DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0
    global DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0
    global DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0
    global DATA_PHY_RD_DQS_SLAVE_RATIO
    global DATA_PHY_WR_DQS_SLAVE_RATIO
    global DATA_PHY_FIFO_WE_SLAVE_RATIO
    global DATA_PHY_WR_DATA_SLAVE_RATIO

  for {set i 0} {$i < 2} {incr i} {
    echo "DDR PHY DATA$i Register configuration is in progress......"

    mww [expr $DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0   + ($i*0xA4)] $DATA_PHY_RD_DQS_SLAVE_RATIO
    mww [expr $DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0   + ($i*0xA4)] $DATA_PHY_WR_DQS_SLAVE_RATIO
    mww [expr $DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0  + ($i*0xA4)] $DATA_PHY_FIFO_WE_SLAVE_RATIO
    mww [expr $DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0  + ($i*0xA4)] $DATA_PHY_WR_DATA_SLAVE_RATIO
  }
}
