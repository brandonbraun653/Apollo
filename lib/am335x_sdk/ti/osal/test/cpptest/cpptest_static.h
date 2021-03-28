/**
 *  \file   cpptest_static.h
 *
 *  \brief  cpptest static header file for AM335x/AM437x platforms
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef CPPTEST_STATIC_H
#define CPPTEST_STATIC_H
/* Board Header Files */
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>

/* CSL Header Files */
#include <ti/csl/csl.h>
#include <ti/csl/cslr.h>
#include <ti/csl/cslr_a15.h>
#include <ti/csl/cslr_adc.h>
#include <ti/csl/cslr_aes.h>
#include <ti/csl/cslr_aif2.h>
#include <ti/csl/cslr_aintc.h>
#include <ti/csl/cslr_ale.h>
#include <ti/csl/cslr_arm_gic.h>
#include <ti/csl/cslr_arp32.h>
#include <ti/csl/cslr_asrc.h>
#include <ti/csl/cslr_at.h>
#include <ti/csl/cslr_axi2ocp_misc.h>
#include <ti/csl/cslr_axi2ocp_rpt.h>
#include <ti/csl/cslr_bb2d.h>
#include <ti/csl/cslr_bcp.h>
#include <ti/csl/cslr_bootcfg.h>
#include <ti/csl/cslr_cache.h>
#include <ti/csl/cslr_cal.h>
#include <ti/csl/cslr_cdma.h>
#include <ti/csl/cslr_cgem.h>
#include <ti/csl/cslr_chip.h>
#include <ti/csl/cslr_chr_us.h>
#include <ti/csl/cslr_cm3_nvic.h>
#include <ti/csl/cslr_cmi.h>
#include <ti/csl/cslr_cmu_mpu.h>
#include <ti/csl/cslr_cortexa15_nogic.h>
#include <ti/csl/cslr_cpdma.h>
#include <ti/csl/cslr_cpgmac_sl.h>
#include <ti/csl/cslr_cpintc.h>
#include <ti/csl/cslr_cppidma_global_config.h>
#include <ti/csl/cslr_cppidma_rx_channel_config.h>
#include <ti/csl/cslr_cppidma_rx_flow_config.h>
#include <ti/csl/cslr_cppidma_tx_channel_config.h>
#include <ti/csl/cslr_cppidma_tx_scheduler_config.h>
#include <ti/csl/cslr_cpsgmii.h>
#include <ti/csl/cslr_cpsw.h>
#include <ti/csl/cslr_cpsw_ss_s.h>
#include <ti/csl/cslr_cpsw_thread_mapper.h>
#include <ti/csl/cslr_cpts.h>
#include <ti/csl/cslr_cp_ace.h>
#include <ti/csl/cslr_cp_timer16.h>
#include <ti/csl/cslr_crc.h>
#include <ti/csl/cslr_csc.h>
#include <ti/csl/cslr_cscti.h>
#include <ti/csl/cslr_csstm.h>
#include <ti/csl/cslr_cstf.h>
#include <ti/csl/cslr_ctm.h>
#include <ti/csl/cslr_ct_tbr.h>
#include <ti/csl/cslr_ct_tracecell_tetris.h>
#include <ti/csl/cslr_cxstm_tetris.h>
#include <ti/csl/cslr_dap_pc.h>
#include <ti/csl/cslr_dcan.h>
#include <ti/csl/cslr_dcc.h>
#include <ti/csl/cslr_ddr2_mddr.h>
#include <ti/csl/cslr_debug_rom.h>
#include <ti/csl/cslr_dei.h>
#include <ti/csl/cslr_des.h>
#include <ti/csl/cslr_des_hdcp.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_dfe_autocp.h>
#include <ti/csl/cslr_dfe_bb.h>
#include <ti/csl/cslr_dfe_cb.h>
#include <ti/csl/cslr_dfe_cdfr.h>
#include <ti/csl/cslr_dfe_cfr.h>
#include <ti/csl/cslr_dfe_dduc.h>
#include <ti/csl/cslr_dfe_dpd.h>
#include <ti/csl/cslr_dfe_dpda.h>
#include <ti/csl/cslr_dfe_fb.h>
#include <ti/csl/cslr_dfe_jesd.h>
#include <ti/csl/cslr_dfe_misc.h>
#include <ti/csl/cslr_dfe_rx.h>
#include <ti/csl/cslr_dfe_summer.h>
#include <ti/csl/cslr_dfe_tx.h>
#include <ti/csl/cslr_dma4_ocp.h>
#include <ti/csl/cslr_dmm.h>
#include <ti/csl/cslr_dmm_core.h>
#include <ti/csl/cslr_dss.h>
#include <ti/csl/cslr_eaglenest.h>
#include <ti/csl/cslr_ecap.h>
#include <ti/csl/cslr_ecc_aggr.h>
#include <ti/csl/cslr_ectl.h>
#include <ti/csl/cslr_edma.h>
#include <ti/csl/cslr_elm.h>
#include <ti/csl/cslr_emac.h>
#include <ti/csl/cslr_emif.h>
#include <ti/csl/cslr_emif16.h>
#include <ti/csl/cslr_emif4f.h>
#include <ti/csl/cslr_epwm.h>
#include <ti/csl/cslr_eqep.h>
#include <ti/csl/cslr_esm.h>
#include <ti/csl/cslr_eve.h>
#include <ti/csl/cslr_eve_mmu.h>
#include <ti/csl/cslr_eve_tpcc.h>
#include <ti/csl/cslr_fftc.h>
#include <ti/csl/cslr_gccp_cfg.h>
#include <ti/csl/cslr_gic400.h>
#include <ti/csl/cslr_gpio.h>
#include <ti/csl/cslr_gpmc.h>
#include <ti/csl/cslr_gpu.h>
#include <ti/csl/cslr_hdqw.h>
#include <ti/csl/cslr_hpi.h>
#include <ti/csl/cslr_hydra2.h>
#include <ti/csl/cslr_i2c.h>
#include <ti/csl/cslr_icont.h>
#include <ti/csl/cslr_icss.h>
#include <ti/csl/cslr_ilf3.h>
#include <ti/csl/cslr_ime3.h>
#include <ti/csl/cslr_ipc.h>
#include <ti/csl/cslr_iqn2.h>
#include <ti/csl/cslr_iss.h>
#include <ti/csl/cslr_iva_hd.h>
#include <ti/csl/cslr_iva_sys.h>
#include <ti/csl/cslr_kbd.h>
#include <ti/csl/cslr_klio.h>
#include <ti/csl/cslr_l3fw.h>
#include <ti/csl/cslr_l4fw.h>
#include <ti/csl/cslr_lcdc.h>
#include <ti/csl/cslr_mailbox.h>
#include <ti/csl/cslr_ma_mpu_lsm.h>
#include <ti/csl/cslr_ma_mpu_nttp.h>
#include <ti/csl/cslr_ma_mpu_wp.h>
#include <ti/csl/cslr_mcan.h>
#include <ti/csl/cslr_mcbsp.h>
#include <ti/csl/cslr_mcdma.h>
#include <ti/csl/cslr_mcspi.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/csl/cslr_mlb.h>
#include <ti/csl/cslr_mmc.h>
#include <ti/csl/cslr_mmchs.h>
#include <ti/csl/cslr_mmcsd.h>
#include <ti/csl/cslr_mmu.h>
#include <ti/csl/cslr_mmu_eve.h>
#include <ti/csl/cslr_mpu.h>
#include <ti/csl/cslr_msgmgr.h>
#include <ti/csl/cslr_msmc.h>
#include <ti/csl/cslr_navss.h>
#include <ti/csl/cslr_ocmc_ecc.h>
#include <ti/csl/cslr_pa_ss.h>
#include <ti/csl/cslr_pcache_raw.h>
#include <ti/csl/cslr_pcache_tags.h>
#include <ti/csl/cslr_pcie.h>
#include <ti/csl/cslr_pdsp.h>
#include <ti/csl/cslr_pka.h>
#include <ti/csl/cslr_pllc.h>
#include <ti/csl/cslr_pmmc.h>
#include <ti/csl/cslr_psc.h>
#include <ti/csl/cslr_pwmss.h>
#include <ti/csl/cslr_qmss.h>
#include <ti/csl/cslr_qm_config.h>
#include <ti/csl/cslr_qm_descriptor_region_config.h>
#include <ti/csl/cslr_qm_intd.h>
#include <ti/csl/cslr_qm_qos_pdsp.h>
#include <ti/csl/cslr_qm_queue_management.h>
#include <ti/csl/cslr_qm_queue_status_config.h>
#include <ti/csl/cslr_qspi.h>
#include <ti/csl/cslr_rac_cfg.h>
#include <ti/csl/cslr_rac_data.h>
#include <ti/csl/cslr_rincewind_b8.h>
#include <ti/csl/cslr_rng.h>
#include <ti/csl/cslr_rtc.h>
#include <ti/csl/cslr_rti.h>
#include <ti/csl/cslr_rw_table.h>
#include <ti/csl/cslr_sata.h>
#include <ti/csl/cslr_sc.h>
#include <ti/csl/cslr_scm.h>
#include <ti/csl/cslr_scp.h>
#include <ti/csl/cslr_sdma.h>
#include <ti/csl/cslr_sem.h>
#include <ti/csl/cslr_sgu.h>
#include <ti/csl/cslr_sha.h>
#include <ti/csl/cslr_smset_conf.h>
#include <ti/csl/cslr_smset_sw.h>
#include <ti/csl/cslr_spf.h>
#include <ti/csl/cslr_spi.h>
#include <ti/csl/cslr_spinlock.h>
#include <ti/csl/cslr_srio.h>
#include <ti/csl/cslr_srss.h>
#include <ti/csl/cslr_sr_c3.h>
#include <ti/csl/cslr_synctimer.h>
#include <ti/csl/cslr_syscfg.h>
#include <ti/csl/cslr_t16.h>
#include <ti/csl/cslr_tac2_cfg.h>
#include <ti/csl/cslr_tac2_data.h>
#include <ti/csl/cslr_tac2_sgcp_cfg.h>
#include <ti/csl/cslr_tcp3d_cfg.h>
#include <ti/csl/cslr_tcp3d_dma.h>
#include <ti/csl/cslr_tcp3d_dma_offsets.h>
#include <ti/csl/cslr_tesoc.h>
#include <ti/csl/cslr_tetris_tbr_sys.h>
#include <ti/csl/cslr_tetris_vbusp.h>
#include <ti/csl/cslr_timer.h>
#include <ti/csl/cslr_tmr.h>
#include <ti/csl/cslr_tpcc.h>
#include <ti/csl/cslr_tptc.h>
#include <ti/csl/cslr_tsip.h>
#include <ti/csl/cslr_uart.h>
#include <ti/csl/cslr_unicache_cfg.h>
#include <ti/csl/cslr_unicache_ctm.h>
#include <ti/csl/cslr_unicache_mmu.h>
#include <ti/csl/cslr_upp.h>
#include <ti/csl/cslr_usimocp.h>
#include <ti/csl/cslr_vbusp.h>
#include <ti/csl/cslr_vcop.h>
#include <ti/csl/cslr_vcp2.h>
#include <ti/csl/cslr_vdma.h>
#include <ti/csl/cslr_vip.h>
#include <ti/csl/cslr_vip_parser.h>
#include <ti/csl/cslr_vpdma.h>
#include <ti/csl/cslr_vpe.h>
#include <ti/csl/cslr_vpif.h>
#include <ti/csl/cslr_vusr.h>
#include <ti/csl/cslr_wdt.h>
#include <ti/csl/cslr_wd_timer.h>
#include <ti/csl/cslr_wr.h>
#include <ti/csl/cslr_wugen_mpu.h>
#include <ti/csl/cslr_xge_cpsw.h>
#include <ti/csl/cslr_xge_cpsw_ss_s.h>
#include <ti/csl/cslr_xge_cpxmac_sl.h>
#include <ti/csl/cslr_xmc.h>
#include <ti/csl/cslver.h>
#include <ti/csl/csl_a15.h>
#include <ti/csl/csl_adc.h>
#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_armGic.h>
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/csl_bwmngmt.h>
#include <ti/csl/csl_bwmngmtAux.h>
#include <ti/csl/csl_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/csl_cpIntc.h>
#include <ti/csl/csl_cpIntcAux.h>
#include <ti/csl/csl_cppi.h>
#include <ti/csl/csl_cpsgmii.h>
#include <ti/csl/csl_cpsgmiiAux.h>
#include <ti/csl/csl_cpsgmii_def.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/csl_cpsw_ssAux.h>
#include <ti/csl/csl_cpsw_ss_s.h>
#include <ti/csl/csl_cpts.h>
#include <ti/csl/csl_cptsAux.h>
#include <ti/csl/csl_crc.h>
#include <ti/csl/csl_dcan.h>
#include <ti/csl/csl_dcc.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/csl/csl_edma.h>
#include <ti/csl/csl_edma3.h>
#include <ti/csl/csl_edma3Aux.h>
#include <ti/csl/csl_elm.h>
#include <ti/csl/csl_emac.h>
#include <ti/csl/csl_emacAux.h>
#include <ti/csl/csl_emif.h>
#include <ti/csl/csl_emif4f.h>
#include <ti/csl/csl_emif4fAux.h>
#include <ti/csl/csl_epwm.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/csl_esm.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/csl_gpmc.h>
#include <ti/csl/csl_i2c.h>
#include <ti/csl/csl_idma.h>
#include <ti/csl/csl_ipc.h>
#include <ti/csl/csl_l3fw.h>
#include <ti/csl/csl_l4fw.h>
#include <ti/csl/csl_mailbox.h>
#include <ti/csl/csl_mcan.h>
#include <ti/csl/csl_mcspi.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/csl_mdio_def.h>
#include <ti/csl/csl_mmcsd.h>
#include <ti/csl/csl_mmu.h>
#include <ti/csl/csl_mpu.h>
#include <ti/csl/csl_msmc.h>
#include <ti/csl/csl_ocmc_ecc.h>
#include <ti/csl/csl_pcie.h>
#include <ti/csl/csl_pllc.h>
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_qm_queue.h>
#include <ti/csl/csl_qspi.h>
#include <ti/csl/csl_rac.h>
#include <ti/csl/csl_rtc.h>
#include <ti/csl/csl_rtcAux.h>
#include <ti/csl/csl_rti.h>
#include <ti/csl/csl_sem.h>
#include <ti/csl/csl_serdes.h>
#include <ti/csl/csl_serdes_10ge.h>
#include <ti/csl/csl_serdes_aif2.h>
#include <ti/csl/csl_serdes_dfe.h>
#include <ti/csl/csl_serdes_ethernet.h>
#include <ti/csl/csl_serdes_hyperlink.h>
#include <ti/csl/csl_serdes_iqn.h>
#include <ti/csl/csl_serdes_pcie.h>
#include <ti/csl/csl_serdes_restore_default.h>
#include <ti/csl/csl_serdes_srio.h>
#include <ti/csl/csl_spinlock.h>
#include <ti/csl/csl_srio.h>
#include <ti/csl/csl_srioAux.h>
#include <ti/csl/csl_srioAuxPhyLayer.h>
#include <ti/csl/csl_syscfg.h>
#include <ti/csl/csl_syscfgAux.h>
#include <ti/csl/csl_tac2.h>
#include <ti/csl/csl_tesoc.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/csl_tmr.h>
#include <ti/csl/csl_tmrAux.h>
#include <ti/csl/csl_tsc.h>
#include <ti/csl/csl_tsip.h>
#include <ti/csl/csl_tsipAux.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_uart.h>
#include <ti/csl/csl_utils.h>
#include <ti/csl/csl_vcp2.h>
#include <ti/csl/csl_vcp2Aux.h>
#include <ti/csl/csl_version.h>
#include <ti/csl/csl_wdt.h>
#include <ti/csl/csl_wdtAux.h>
#include <ti/csl/csl_wd_timer.h>
#include <ti/csl/csl_xmc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/tistdtypes.h>

/* Drv Header Files */
#include <ti/drv/emac/emacver.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/emac_hwcfg.h>
#include <ti/drv/emac/nss_if.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/GPIOver.h>
#include <ti/drv/gpmc/GPMC.h>
#include <ti/drv/gpmc/GPMCver.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/I2Cver.h>
#include <ti/drv/icss_emac/icss_emacCommon.h>
#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/icss_emacDrv_Def.h>
#include <ti/drv/icss_emac/icss_emacFwInit.h>
#include <ti/drv/icss_emac/icss_emacLearning.h>
#include <ti/drv/icss_emac/icss_emacStatistics.h>
#include <ti/drv/icss_emac/icss_emacStormControl.h>
#include <ti/drv/icss_emac/icss_emac_ver.h>
#include <ti/drv/mcasp/mcaspver.h>
#include <ti/drv/mcasp/mcasp_drv.h>
#include <ti/drv/mcasp/mcasp_osal.h>
#include <ti/drv/mcasp/mcasp_types.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/MMCSDver.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/pmver.h>
#include <ti/drv/pm/Power.h>
#include <ti/drv/pm/PowerDevice.h>
#include <ti/drv/pm/PowerExtended.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/pruicss_ver.h>
#include <ti/drv/spi/MCSPI.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/SPIver.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/UART_ver.h>

/* FATFS Header Files */
#include <ti/fs/fatfs/diskio.h>
#include <ti/fs/fatfs/FATFS.h>
#include <ti/fs/fatfs/FATFSver.h>
#include <ti/fs/fatfs/ff.h>
#include <ti/fs/fatfs/ffconf.h>
#include <ti/fs/fatfs/integer.h>

/* OSAL Header Files */
#include <ti/osal/CacheP.h>
#include <ti/osal/EventCombinerP.h>
#include <ti/osal/EventP.h>
#include <ti/osal/HwiP.h>
#include <ti/osal/MuxIntcP.h>
#include <ti/osal/osal.h>
#include <ti/osal/osalver.h>
#include <ti/osal/Queue.h>
#include <ti/osal/RegisterIntr.h>
#include <ti/osal/SemaphoreP.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/TimerP.h>

/* NIMU Header Files */
#include <ti/transport/ndk/nimu/nimu_eth.h>
#include <ti/transport/ndk/nimu/nimu_ver.h>
#include <ti/transport/ndk/nimu_icss/nimu_icssIoctl.h>
#include <ti/transport/ndk/nimu_icss/nimu_icss_ver.h>

/* Utils Header Files */
#include <ti/utils/profiling/profilingHooks.h>
#include <ti/utils/profiling/profilingver.h>

#endif /* CPPTEST_STATIC_H */
