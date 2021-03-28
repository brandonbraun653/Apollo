/*
 * prussdrv.h
 * 
 * Describes PRUSS userspace driver for Industrial Communications
 *
 * Copyright (C) 2010-2016 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
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

#ifndef _LINUXOSAL_H
#define _LINUXOSAL_H

#include <sys/types.h>
#include <pthread.h>

#if defined (__cplusplus)
extern "C" {
#endif

#define NUM_PRU_HOSTIRQS        8
#define NUM_PRU_HOSTS          10
#define NUM_PRU_CHANNELS       10
#define NUM_PRU_SYS_EVTS       64

#define PRUSS_PRU0_DATARAM     0
#define PRUSS_PRU1_DATARAM     1
#define PRUSS_PRU0_IRAM        2
#define PRUSS_PRU1_IRAM        3

#define PRUSS_SHARED_DATARAM   4
#define	PRUSS_CFG              5
#define	PRUSS_UART             6
#define	PRUSS_IEP              7
#define	PRUSS_ECAP             8
#define	PRUSS_MII_RT           9
#define	PRUSS_MDIO            10

#define PRU_EVTOUT_0            0
#define PRU_EVTOUT_1            1
#define PRU_EVTOUT_2            2
#define PRU_EVTOUT_3            3
#define PRU_EVTOUT_4            4
#define PRU_EVTOUT_5            5
#define PRU_EVTOUT_6            6
#define PRU_EVTOUT_7            7

#define PRUSSDRV_ERROR_INVALID_NAME           (-2)
#define PRUSSDRV_ERROR_OPEN_PRUSS_MEM         (-3)
#define PRUSSDRV_ERROR_OPEN_PRUSS_MEM2        (-4)
#define PRUSSDRV_ERROR_OPEN_PRU0_MEM          (-5)
#define PRUSSDRV_ERROR_OPEN_PRU1_MEM          (-6)
#define PRUSSDRV_ERROR_DRAM0_MEM_SECTION      (-7)
#define PRUSSDRV_ERROR_DRAM1_MEM_SECTION      (-8)
#define PRUSSDRV_ERROR_INTC_MEM_SECTION       (-9)
#define PRUSSDRV_ERROR_SHRDRAM2_MEM_SECTION  (-10)
#define PRUSSDRV_ERROR_CFG_MEM_SECTION       (-11)
#define PRUSSDRV_ERROR_IEP_MEM_SECTION       (-12)
#define PRUSSDRV_ERROR_UART_MEM_SECTION      (-13)
#define PRUSSDRV_ERROR_ECAP_MEM_SECTION      (-14)
#define PRUSSDRV_ERROR_MDIO_MEM_SECTION      (-15)
#define PRUSSDRV_ERROR_MIIRT_MEM_SECTION     (-16)
#define PRUSSDRV_ERROR_IRAM_MEM_SECTION      (-17)
#define PRUSSDRV_ERROR_CONTROL_MEM_SECTION   (-18)
#define PRUSSDRV_ERROR_DEBUG_MEM_SECTION     (-19)

#define PRUSSDRV_ERROR_OPEN_GET_UIO_DEVICE   (-1)
#define PRUSSDRV_ERROR_OPEN_DISABLE_INTRPT   (-2)
#define PRUSSDRV_ERROR_OPEN_ENABLE_INTRPT    (-3)
#define PRUSSDRV_ERROR_OPEN_UIOFD_NONZERO    (-4)

#define DISABLE_L3RAM_SUPPORT
#define MAX_DEVICE_NAME_LENGTH 16
typedef struct __prussdrv {
    int version;
    char device_name[MAX_DEVICE_NAME_LENGTH];
    int fd[NUM_PRU_HOSTIRQS];
    void *pru0_dataram_base;
    void *pru1_dataram_base;
    void *intc_base;
    void *pru0_control_base;
    void *pru0_debug_base;
    void *pru1_control_base;
    void *pru1_debug_base;
    void *pru0_iram_base;
    void *pru1_iram_base;
    void *l3ram_base;
    void *extram_base;
    pthread_t irq_thread[NUM_PRU_HOSTIRQS];
    int mmap_fd;
    int mmap_fd2;
    int pru0_mmap_fd;
    int pru1_mmap_fd;
    void *pruss_sharedram_base;
    void *pruss_cfg_base;
    void *pruss_uart_base;
    void *pruss_iep_base;
    void *pruss_ecap_base;
    void *pruss_miirt_base;
    void *pruss_mdio_base;
    unsigned int pru0_dataram_phy_base;
    unsigned int pru0_dataram_size;
    unsigned int pru1_dataram_phy_base;
    unsigned int pru1_dataram_size;
    unsigned int intc_phy_base;
    unsigned int intc_size;
    unsigned int pru0_control_phy_base;
    unsigned int pru0_control_size;
    unsigned int pru0_debug_phy_base;
    unsigned int pru0_debug_size;
    unsigned int pru1_control_phy_base;
    unsigned int pru1_control_size;
    unsigned int pru1_debug_phy_base;
    unsigned int pru1_debug_size;
    unsigned int pru0_iram_phy_base;
    unsigned int pru0_iram_size;
    unsigned int pru1_iram_phy_base;
    unsigned int pru1_iram_size;
    unsigned int pruss_sharedram_phy_base;
    unsigned int pruss_sharedram_size;
    unsigned int pruss_cfg_phy_base;
    unsigned int pruss_cfg_size;
    unsigned int pruss_uart_phy_base;
    unsigned int pruss_uart_size;
    unsigned int pruss_iep_phy_base;
    unsigned int pruss_iep_size;
    unsigned int pruss_ecap_phy_base;
    unsigned int pruss_ecap_size;
    unsigned int pruss_miirt_phy_base;
    unsigned int pruss_miirt_size;
    unsigned int pruss_mdio_phy_base;
    unsigned int pruss_mdio_size;
#ifdef DISABLE_L3RAM_SUPPORT
    unsigned int l3ram_phys_base;
    unsigned int l3ram_map_size;
#endif
#ifdef DISABLE_EXTRAM_SUPPORT
    unsigned int extram_phys_base;
    unsigned int extram_map_size;
#endif
} tprussdrv;

#define DEFAULT_STACK_SIZE  0x8000

typedef void *(*prussdrv_function_handler) (void *);

int prussdrv_init(void **prussdrv_handle, char *pruss_name);

int prussdrv_open(void *prussdrv_handle, unsigned int pru_evtout_num);

int prussdrv_pru_reset(void *prussdrv_handle, unsigned int prunum);

int prussdrv_exec_program(void *prussdrv_handle, int prunum, char *filename);

int prussdrv_start_irqthread(void *prussdrv_handle,
                             unsigned int pru_evtout_num, int priority,
                             prussdrv_function_handler irqhandler);

int prussdrv_pru_wait_event(void *prussdrv_handle, unsigned int pru_evtout_num);

void linux_init(void **pruss_drv_handle_dptr, void *linux_prussInitCfg, int pru_num);

#if defined (__cplusplus)
}
#endif
#endif
