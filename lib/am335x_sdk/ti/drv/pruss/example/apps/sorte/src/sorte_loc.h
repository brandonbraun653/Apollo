/**
 * @file   sorte_loc.h
 *
 * @brief  SORTE(Simple Open Real Time Ethernet) on PRU-ICSS
 *
 * header file contains defines used by SORTE applicaton 
 */
/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/**<
 *  @brief      Defines for master and slave device
 */
#define SORTE_MASTER_DEVICE        0U
#define SORTE_SLAVE_DEVICE         1U

/**<
 *  @brief      Minimum number of slave devices connected to master required by SORTE protocol
 */
#define SORTE_MIN_NUM_SLAVE_DEVICES 2U

/**<
 *  @brief      Offset from shared DATA RAM base offset to collect number of receive packets with no crc error
 */
#define SORTE_RX_NO_CRC_ERR_PKT_OFFSET 0x54U

/**<
 *  @brief     Offset from PRU0 DATA RAM base address for master to  determine number of slave devices
 */
#define SORTE_DISCOV_NUM_SLAVE_OFFSET 0x20CU

/**<
 *  @brief     Minimum number of packets received by the SORTE slave device for pass criteria
 */
#define SORT_SLAVE_PASS_CRITERIA 0x8000U

/**<
 *  @brief    Offset from pruss Pru0 Dram Base to store CRC8 table
 */
#define SORTE_CRC8_TABLE_OFFSET    0x100

#ifdef __cplusplus
}
#endif
