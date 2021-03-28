/**
 * \file      mmap_helper.c
 *
 * \brief     This file contains pruss memory mapping code to allow
 *            pruss-lld to run on Linux through UIO
 *
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 */

#include "mmap_helper.h"

#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <pthread.h>
#include <dirent.h>
#include "__mmap_helper.h"

#define PRUSS_UIO_PRAM_PATH_LEN 128
#define PRUSS_UIO_PARAM_VAL_LEN 20
#define HEXA_DECIMAL_BASE 16
#define MAX_NAME_LENGTH 64

int uioutil_get_string (char *filename, char *str, int str_len)
{
    FILE *fpr = 0;
    int ret_val = -1;

    if (!filename || !str || !str_len) {
        goto close_n_exit;
    }

    fpr = fopen(filename, "r");
    if (!fpr) {
        goto close_n_exit;
    }
    if (!fgets(str, str_len, fpr)) {
        goto close_n_exit;
    }

    /* Terminate string at new line or carriage return if any */
    str[strcspn(str, "\n\r")] = '\0';

    ret_val = 0;

close_n_exit:
    if (fpr) fclose(fpr);
    return ret_val;
}

int uioutil_get_device (char *uio_name, char *class_name, int class_name_length)
{
    struct dirent *entry = 0;
    char filename[PRUSS_UIO_PRAM_PATH_LEN];
    char name[MAX_NAME_LENGTH];
    int ret_val = -1;
    DIR *dir = 0;

    if (!uio_name || !class_name || !strlen(uio_name)) {
        goto close_n_exit;
    }

    dir = opendir("/sys/class/uio");
    if (!dir) {
        perror("readdir /sys/class/uio");
        goto close_n_exit;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr (entry->d_name, "uio") == NULL) {
            continue;
        }

        snprintf(filename, PRUSS_UIO_PRAM_PATH_LEN, "/sys/class/uio/%s/name", entry->d_name);

        if (uioutil_get_string(filename, name, MAX_NAME_LENGTH) < 0)
            goto close_n_exit;

        if (!strncmp (uio_name, name, strlen(uio_name))) {
            ret_val = 0;
            strncpy (class_name, entry->d_name, class_name_length);
            goto close_n_exit;
        }
    }

close_n_exit:
    if (dir) closedir(dir);

    return ret_val;
}

int prussdrv_get_mem_section_by_id(char *class_name, int section_id, int mmap_fd,
    unsigned int *phys_base_p, unsigned int *size_p, void **va_base_p)
{    
    int fd;
    char hexstring[PRUSS_UIO_PARAM_VAL_LEN];
    char filename[PRUSS_UIO_PRAM_PATH_LEN];
    int ret=0;
    uint32_t page_size = getpagesize();

    sprintf(filename, "/sys/class/misc/%s/maps/map%d/addr", class_name, section_id);

    fd = open(filename, O_RDONLY);
    if (fd >= 0) {
     ret = read(fd, hexstring, PRUSS_UIO_PARAM_VAL_LEN);
     if ( ret == 0) {
         /* Read failed */
         ret = -1;
         goto err_exit;
     }
     *phys_base_p =
         strtoul(hexstring, NULL, HEXA_DECIMAL_BASE);
    } else
        return -1;
    close(fd);

    sprintf(filename, "/sys/class/misc/%s/maps/map%d/size", class_name, section_id);
    fd = open(filename, O_RDONLY);
    if (fd >= 0) {
        ret = read(fd, hexstring, PRUSS_UIO_PARAM_VAL_LEN);
        if ( ret == 0) {
            /* Read failed */
            ret = -1;
            goto err_exit;
        }

        *size_p =
            strtoul(hexstring, NULL, HEXA_DECIMAL_BASE);
    } else
        return -1;
    *va_base_p =  
        mmap(0, *size_p, PROT_READ | PROT_WRITE,
             MAP_SHARED, mmap_fd, section_id*page_size );
    if(*va_base_p == MAP_FAILED) {
        ret =-1;
        goto err_exit;
    }
    /* If the page start is not aligned, it needs correction here */
    *va_base_p += (*phys_base_p & (page_size-1));
err_exit:
    close(fd);
    return ret;
}

int prussdrv_get_mem_section_by_name(char *class_name, char *map_name,  int mmap_fd,
    unsigned int *phys_base_p, unsigned int *size_p, void **va_base_p)
{    
    int fd;
    char hexstring[PRUSS_UIO_PARAM_VAL_LEN];
    char filename[PRUSS_UIO_PRAM_PATH_LEN];
    int ret=0;
    int index;

    index = 0;
    do {
        sprintf(filename, "/sys/class/misc/%s/maps/map%d/name", class_name, index);

        fd = open(filename, O_RDONLY);
        if (fd >= 0) {
            ret = read(fd, hexstring, PRUSS_UIO_PARAM_VAL_LEN);
            if ( ret == 0) {
                /* Read failed */
                goto err_exit;
            }
            hexstring[ret-1] = '\0';
        } else {
		return -1;
	}
	
        close(fd);
        index++;
    } while(strcmp(map_name, hexstring));
    ret =  prussdrv_get_mem_section_by_id(class_name, index-1, mmap_fd, phys_base_p, size_p, va_base_p);
    if (ret < 0) {
        ret = -1;
        goto err_exit;
    }
#ifdef DEBUG
    printf("\nDEBUG:Got Memory section %s:%s physbase 0x%x, virtp %p, size 0x%x\n",
        class_name, map_name, *phys_base_p, *va_base_p,
        *size_p);
    printf("DEBUG:Memory section %s: First location 0x%x\n",
	map_name, (((uint32_t *)(*va_base_p))[0]));
#endif

err_exit:
	close(fd);
	return ret;
}

int __prussdrv_memmap_init(void *prussdrv_handle, char *pruss_device_name)
{
    char name[PRUSS_UIO_PRAM_PATH_LEN];
    char class_name[PRUSS_UIO_PRAM_PATH_LEN];
    char device_name[PRUSS_UIO_PRAM_PATH_LEN];
    int ret_val;
    tprussdrv *prussdrv_p = (tprussdrv *)prussdrv_handle;

    if (prussdrv_p->mmap_fd == 0) {
        sprintf(name, "uio_%s_mem", pruss_device_name);
        sprintf(device_name, "/dev/%s", name);
        prussdrv_p->mmap_fd = open(device_name, O_RDWR | O_SYNC);
	if(prussdrv_p->mmap_fd < 0) {
            return(PRUSSDRV_ERROR_OPEN_PRUSS_MEM);
	}
    }
    if (prussdrv_p->mmap_fd2 == 0) {
        sprintf(name, "uio_%s_mem2", pruss_device_name);
        sprintf(device_name, "/dev/%s", name);
        prussdrv_p->mmap_fd2 = open(device_name, O_RDWR | O_SYNC);
	if(prussdrv_p->mmap_fd2 < 0) {
            return(PRUSSDRV_ERROR_OPEN_PRUSS_MEM2);
	}
    }
    if (prussdrv_p->pru0_mmap_fd == 0) {
        sprintf(name, "uio_%s_0_mem", pruss_device_name);
        sprintf(device_name, "/dev/%s", name);
        prussdrv_p->pru0_mmap_fd = open(device_name, O_RDWR | O_SYNC);
	if(prussdrv_p->pru0_mmap_fd < 0) {
            return(PRUSSDRV_ERROR_OPEN_PRU0_MEM);
	}
    }
    if (prussdrv_p->pru1_mmap_fd == 0) {
        sprintf(name, "uio_%s_1_mem", pruss_device_name);
        sprintf(device_name, "/dev/%s", name);
        prussdrv_p->pru1_mmap_fd = open(device_name, O_RDWR | O_SYNC);
	if(prussdrv_p->pru1_mmap_fd < 0) {
            return(PRUSSDRV_ERROR_OPEN_PRU1_MEM);
	}
    }

    sprintf(class_name, "uio_%s_mem", pruss_device_name);
    ret_val = prussdrv_get_mem_section_by_name(class_name, "dram0", prussdrv_p->mmap_fd,
        &prussdrv_p->pru0_dataram_phy_base, &prussdrv_p->pru0_dataram_size, 
	&prussdrv_p->pru0_dataram_base);
    if (ret_val <  0) {
	return(PRUSSDRV_ERROR_DRAM0_MEM_SECTION);
    }
    ret_val = prussdrv_get_mem_section_by_name(class_name, "intc", prussdrv_p->mmap_fd,
               &prussdrv_p->intc_phy_base, &prussdrv_p->intc_size, 
               &prussdrv_p->intc_base);
    if(ret_val <  0) {
        return(PRUSSDRV_ERROR_INTC_MEM_SECTION);
    }
    prussdrv_p->version =
        __pruss_detect_hw_version(prussdrv_p->intc_base);
#ifdef DEBUG
    printf("DEBUG:Got hw version %d\n", prussdrv_p->version);
#endif

    ret_val = prussdrv_get_mem_section_by_name(class_name, "dram1" , prussdrv_p->mmap_fd,
        &prussdrv_p->pru1_dataram_phy_base, &prussdrv_p->pru1_dataram_size, 
	&prussdrv_p->pru1_dataram_base);
    if (ret_val <  0) {
        return(PRUSSDRV_ERROR_DRAM1_MEM_SECTION);
    }

    switch (prussdrv_p->version) {
    case PRUSS_V1:
        break;

    case PRUSS_V2:
#ifdef DEBUG
            printf("PRUSS V2 \n");
#endif
	    ret_val = prussdrv_get_mem_section_by_name(class_name, "shrdram2" , prussdrv_p->mmap_fd,
                &prussdrv_p->pruss_sharedram_phy_base, &prussdrv_p->pruss_sharedram_size, 
	        &prussdrv_p->pruss_sharedram_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_SHRDRAM2_MEM_SECTION);
            }

	    ret_val = prussdrv_get_mem_section_by_name(class_name, "cfg", prussdrv_p->mmap_fd,
                &prussdrv_p->pruss_cfg_phy_base, &prussdrv_p->pruss_cfg_size, 
	        &prussdrv_p->pruss_cfg_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_CFG_MEM_SECTION);
            }

	    ret_val = prussdrv_get_mem_section_by_name(class_name, "iep", prussdrv_p->mmap_fd,
                &prussdrv_p->pruss_iep_phy_base, &prussdrv_p->pruss_iep_size, 
	        &prussdrv_p->pruss_iep_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_IEP_MEM_SECTION);
            }

	    ret_val = prussdrv_get_mem_section_by_name(class_name, "mii_rt", prussdrv_p->mmap_fd,
                &prussdrv_p->pruss_miirt_phy_base, &prussdrv_p->pruss_miirt_size, 
	        &prussdrv_p->pruss_miirt_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_MIIRT_MEM_SECTION);
            }

            sprintf(class_name, "uio_%s_mem2", pruss_device_name);

	    ret_val = prussdrv_get_mem_section_by_name(class_name, "uart", prussdrv_p->mmap_fd2,
                &prussdrv_p->pruss_uart_phy_base, &prussdrv_p->pruss_uart_size, 
	        &prussdrv_p->pruss_uart_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_UART_MEM_SECTION);
            }
	    ret_val = prussdrv_get_mem_section_by_name(class_name, "ecap", prussdrv_p->mmap_fd2,
                &prussdrv_p->pruss_ecap_phy_base, &prussdrv_p->pruss_ecap_size, 
	        &prussdrv_p->pruss_ecap_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_ECAP_MEM_SECTION);
            }

	    ret_val = prussdrv_get_mem_section_by_name(class_name, "mdio", prussdrv_p->mmap_fd2,
                &prussdrv_p->pruss_mdio_phy_base, &prussdrv_p->pruss_ecap_size, 
	        &prussdrv_p->pruss_mdio_base);
            if (ret_val <  0) {
                return(PRUSSDRV_ERROR_MDIO_MEM_SECTION);
            }
        break;
    default:
#ifdef DEBUG
        printf("UNKNOWN pruss version\n");
#endif
	return(-11);
    }

    sprintf(class_name, "uio_%s_0_mem", pruss_device_name);
    ret_val = prussdrv_get_mem_section_by_name(class_name, "iram", prussdrv_p->pru0_mmap_fd,
        &prussdrv_p->pru0_iram_phy_base, &prussdrv_p->pru0_iram_size, 
        &prussdrv_p->pru0_iram_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_IRAM_MEM_SECTION);
   }
    ret_val = prussdrv_get_mem_section_by_name(class_name, "control", prussdrv_p->pru0_mmap_fd,
        &prussdrv_p->pru0_control_phy_base, &prussdrv_p->pru0_control_size, 
        &prussdrv_p->pru0_control_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_CONTROL_MEM_SECTION);
   }
    ret_val = prussdrv_get_mem_section_by_name(class_name, "debug", prussdrv_p->pru0_mmap_fd,
        &prussdrv_p->pru0_debug_phy_base, &prussdrv_p->pru0_debug_size, 
        &prussdrv_p->pru0_debug_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_DEBUG_MEM_SECTION);
   }
    sprintf(class_name, "uio_%s_1_mem", pruss_device_name);
    ret_val = prussdrv_get_mem_section_by_name(class_name, "iram", prussdrv_p->pru1_mmap_fd,
        &prussdrv_p->pru1_iram_phy_base, &prussdrv_p->pru1_iram_size, 
        &prussdrv_p->pru1_iram_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_IRAM_MEM_SECTION);
   }
    ret_val = prussdrv_get_mem_section_by_name(class_name, "control", prussdrv_p->pru1_mmap_fd,
        &prussdrv_p->pru1_control_phy_base, &prussdrv_p->pru1_control_size, 
        &prussdrv_p->pru1_control_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_CONTROL_MEM_SECTION);
   }
    ret_val = prussdrv_get_mem_section_by_name(class_name, "debug", prussdrv_p->pru1_mmap_fd,
        &prussdrv_p->pru1_debug_phy_base, &prussdrv_p->pru1_debug_size, 
        &prussdrv_p->pru1_debug_base);
   if (ret_val <  0) {
       return(PRUSSDRV_ERROR_DEBUG_MEM_SECTION);
   }

    return 0;

}

int prussdrv_init(void **handle, char *pruss_name)
{
    tprussdrv *prussdrv_p;
    int ret_val;

    if (strlen(pruss_name) >= MAX_DEVICE_NAME_LENGTH)
	return PRUSSDRV_ERROR_INVALID_NAME;

    prussdrv_p = malloc(sizeof(tprussdrv));
    memset(prussdrv_p, 0, sizeof(tprussdrv));

    ret_val = __prussdrv_memmap_init((void *)prussdrv_p, pruss_name);
    if (!ret_val) {
        *handle = (void *)prussdrv_p;
        strcpy(prussdrv_p->device_name, pruss_name);
    }
    return ret_val;

}

int prussdrv_open(void *prussdrv_handle, unsigned int pru_evtout_num)
{

    char name[PRUSS_UIO_PRAM_PATH_LEN];
    char class_name[PRUSS_UIO_PRAM_PATH_LEN];
    char device_name[PRUSS_UIO_PRAM_PATH_LEN];
    uint32_t value;
    int ret;
    tprussdrv *prussdrv_p = (tprussdrv *)prussdrv_handle;

    if (!prussdrv_p->fd[pru_evtout_num]) {
        sprintf(name, "uio_%s_evt%d", prussdrv_p->device_name, pru_evtout_num);
        if (uioutil_get_device(name, class_name, PRUSS_UIO_PRAM_PATH_LEN) < 0) {
#ifdef DEBUG
           printf("\nError getting device %s\n",name);fflush(stdout);
#endif
           return PRUSSDRV_ERROR_OPEN_GET_UIO_DEVICE;
        }
        sprintf(device_name, "/dev/%s", class_name);
        prussdrv_p->fd[pru_evtout_num] = open(device_name, O_RDWR | O_SYNC);

        /* Disable interrupt */
        value = 0;
        ret = write(prussdrv_p->fd[pru_evtout_num], &value, sizeof(uint32_t));
        if (ret != sizeof(uint32_t)) {
#ifdef DEBUG
            printf("\nunable to disable interrupt \n");
#endif
            return PRUSSDRV_ERROR_OPEN_DISABLE_INTRPT;
    }

#ifndef UIO_INTERRUPT_ONE_SHOT_MODE
        /* Enable interrupt */
        value = 1;
        ret = write(prussdrv_p->fd[pru_evtout_num], &value, sizeof(uint32_t));
        if (ret != sizeof(uint32_t)) {
#ifdef DEBUG
        printf("\nunable to enable interrupt \n");
#endif
        return PRUSSDRV_ERROR_OPEN_ENABLE_INTRPT;
    }
#endif

        return 0;
    } else {
        return PRUSSDRV_ERROR_OPEN_UIOFD_NONZERO;
    }
}




int prussdrv_pru_reset(void *prussdrv_handle, unsigned int prunum)
{
    unsigned int *prucontrolregs;
    tprussdrv *prussdrv_p = (tprussdrv *)prussdrv_handle;

    if (prunum == 0)
        prucontrolregs = (unsigned int *) prussdrv_p->pru0_control_base;
    else if (prunum == 1)
        prucontrolregs = (unsigned int *) prussdrv_p->pru1_control_base;
    else
        return -1;
    *prucontrolregs = 0;
    return 0;
}

int prussdrv_start_irqthread(void *prussdrv_handle, unsigned int pru_evtout_num,
                             int priority,
                             prussdrv_function_handler irqhandler)
{
    pthread_attr_t pthread_attr;
    struct sched_param sched_param;
    tprussdrv *prussdrv_p = (tprussdrv *)prussdrv_handle;
 
    pthread_attr_init(&pthread_attr);
    if (priority != 0) {
        pthread_attr_setinheritsched(&pthread_attr,
                                     PTHREAD_EXPLICIT_SCHED);
        pthread_attr_setschedpolicy(&pthread_attr, SCHED_FIFO);
        sched_param.sched_priority = priority;
        pthread_attr_setschedparam(&pthread_attr, &sched_param);
    }

    pthread_create(&prussdrv_p->irq_thread[pru_evtout_num], &pthread_attr,
                   irqhandler, NULL);

    pthread_attr_destroy(&pthread_attr);

    return 0;

}

int prussdrv_pru_wait_event(void *prussdrv_handle, unsigned int pru_evtout_num)
{
    int event_count;
    tprussdrv *prussdrv_p = (tprussdrv *)prussdrv_handle;
    unsigned int *pruintc_io = (unsigned int *) prussdrv_p->intc_base;
    int ret;

#ifdef UIO_INTERRUPT_ONE_SHOT_MODE
    /* This is needed only if the interrupt-mode is configured for one-shot mode */
    uint32_t value;
 
    value = 1;
    ret = write(prussdrv_p->fd[pru_evtout_num], &value, sizeof(uint32_t));
    if (ret != sizeof(uint32_t)) {
#ifdef DEBUG
        printf("\nunable to enable interrupt \n");
#endif
        return -1;
    }
#endif
    ret = read(prussdrv_p->fd[pru_evtout_num], &event_count, sizeof(int));
    if ( ret == 0) {
        /* Read failed */
        return -1;
    }
    pruintc_io[PRU_INTC_HIEISR_REG >> 2] = pru_evtout_num+2; 
    return 0;

}

void linux_init(void **pruss_drv_handle_dptr, void *linux_prussInitCfg, int pru_num) {
    PRUICSS_HwAttrs *hwAttrs = (PRUICSS_HwAttrs *)linux_prussInitCfg;
    tprussdrv *pruss_handle;
    int hwAttrs_index = pru_num - 1;

    //Initialize PRUSS UIO userspace
#ifdef icev2AM335x
    char *pru_dev_name = "pruss";
#else
    char *pru_dev_name = (pru_num == 1 ? "pruss1" : "pruss2");
#endif
    prussdrv_init(pruss_drv_handle_dptr, pru_dev_name);
    pruss_handle = *((tprussdrv **)pruss_drv_handle_dptr);

    hwAttrs[hwAttrs_index].baseAddr             = (uint32_t) pruss_handle->pru0_dataram_base;
    hwAttrs[hwAttrs_index].version              = (uint32_t) pruss_handle->version;
    hwAttrs[hwAttrs_index].prussPru0CtrlRegBase = (uint32_t) pruss_handle->pru0_control_base;
    hwAttrs[hwAttrs_index].prussPru1CtrlRegBase = (uint32_t) pruss_handle->pru1_control_base;
    hwAttrs[hwAttrs_index].prussIntcRegBase     = (uint32_t) pruss_handle->intc_base;
    hwAttrs[hwAttrs_index].prussCfgRegBase      = (uint32_t) pruss_handle->pruss_cfg_base;
    hwAttrs[hwAttrs_index].prussUartRegBase     = (uint32_t) pruss_handle->pruss_uart_base;
    hwAttrs[hwAttrs_index].prussIepRegBase      = (uint32_t) pruss_handle->pruss_iep_base;
    hwAttrs[hwAttrs_index].prussEcapRegBase     = (uint32_t) pruss_handle->pruss_ecap_base;
    hwAttrs[hwAttrs_index].prussMiiRtCfgRegBase = (uint32_t) pruss_handle->pruss_miirt_base;
    hwAttrs[hwAttrs_index].prussMiiMdioRegBase  = (uint32_t) pruss_handle->pruss_mdio_base;
    hwAttrs[hwAttrs_index].prussPru0DramBase    = (uint32_t) pruss_handle->pru0_dataram_base;
    hwAttrs[hwAttrs_index].prussPru1DramBase    = (uint32_t) pruss_handle->pru1_dataram_base;
    hwAttrs[hwAttrs_index].prussPru0IramBase    = (uint32_t) pruss_handle->pru0_iram_base;
    hwAttrs[hwAttrs_index].prussPru1IramBase    = (uint32_t) pruss_handle->pru1_iram_base;
    hwAttrs[hwAttrs_index].prussSharedDramBase  = (uint32_t) pruss_handle->pruss_sharedram_base;
}

