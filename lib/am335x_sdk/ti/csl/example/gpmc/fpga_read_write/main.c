/*
 *  Copyright (C) 2013-2019 Texas Instruments Incorporated - http://www.ti.com/
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
/**
 *   \file    main.c
 *
 *   \brief   GPMC test application optimized for FPGA read and write using CPU and DMA.
              Use the macros to select between synchronous/non-synchronous,
              burst/non-burst, and CPU/DMA modes. The application will perform
              reads and writes and output the benchmarks to UART terminal. The
              test will pass/fail depending on whether the benchmark numbers fall
              within the predefined bounds.
              The timing values configured in GPMC_init() can be tuned to further
              optimize your application.

              One of the following configurations can be tested at a time by defining/undefining the macros below.
              1. Synchronous Burst DMA Mode
              2. Synchronous Non-burst DMA Mode
              3. Asynchronous Burst DMA Mode
              4. Asynchronous Non-burst DMA Mode
              5. Synchronous Burst CPU Mode
              6. Synchronous Non-burst CPU Mode
              7. Asynchronous Burst CPU Mode
              8. Asynchronous Non-burst CPU Mode
 *
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include <ti/csl/csl_gpmc.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_edma.h>
#include <ti/csl/example/edma/edma_test/sample.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define BURST_MODE
#define SYNC_MODE
#define DMA_ENABLE

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

signed char __attribute__((section(".my_sect_ddr"))) _srcBuff1[MAX_BUFFER_SIZE];
signed char __attribute__((section(".my_sect_ddr"))) _dstBuff1[MAX_BUFFER_SIZE];

uint32_t edma_ch_num = 1;
uint32_t edma_tcc_num = 1;
uint32_t edma_evtq_num = 0;

uint32_t region = EDMA3_CC_REGION;

signed char *srcBuff1;
signed char *dstBuff1;

extern uint32_t base_address;

/*To use UARTConfigPuts function for prints*/
uint32_t uartBaseAddr = SOC_UART3_BASE;

/* To use for benchmarking */
#define TIMER14_TCLR (*((volatile uint32_t *)0x4882A038))
#define TIMER14_TLDR (*((volatile uint32_t *)0x4882A040))
#define TIMER14_TCRR (*((volatile uint32_t *)0x4882A03C))
#define TIMER14_TMAR (*((volatile uint32_t *)0x4882A04C))
#define TIMER14_TSICR (*((volatile uint32_t *)0x4882A054))
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void GPMC_init(void);
void padConfig_prcmEnable(void);

int main(void)
{

    uint32_t i, t_start, t_stop, t_overhead;

#ifdef DMA_ENABLE
    uint32_t t_delta_dma_writes, t_delta_dma_reads;
#else
    uint32_t t_delta_cpu_writes, t_delta_cpu_reads;
    uint32_t var0 = 0xFFFFFFFF;

    volatile uint32_t * GPMC0 = (volatile uint32_t*) 0x08000000;
    volatile uint32_t * GPMC1 = (volatile uint32_t*) 0x08000004;
    volatile uint32_t * GPMC2 = (volatile uint32_t*) 0x08000008;
    volatile uint32_t * GPMC3 = (volatile uint32_t*) 0x0800000C;
    volatile uint32_t * GPMC4 = (volatile uint32_t*) 0x08000010;
    volatile uint32_t * GPMC5 = (volatile uint32_t*) 0x08000014;
    volatile uint32_t * GPMC6 = (volatile uint32_t*) 0x08000018;
    volatile uint32_t * GPMC7 = (volatile uint32_t*) 0x0800001C;
#endif
    /*MMC1 PAD Configuration*/
    padConfig_prcmEnable();

    /* Configure the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8,
    UART_STOP_BIT_1,
                   UART_NO_PARITY, UART_16x_MODE);
#ifdef DMA_ENABLE
    EDMAsetRegion(region);

    /* Do EDMA init once in the beginning of application */
    EDMA3Init(base_address, 0);
#endif
    /* Configure GPMC registers with timing values optimized for an FPGA */
    GPMC_init();

    UARTConfigPuts(uartBaseAddr, "\nGPMC FPGA Example\n\n", -1);
#ifdef SYNC_MODE
    UARTConfigPuts(uartBaseAddr, "Synchronous,", -1);
#else
    UARTConfigPuts(uartBaseAddr, "Asynchronous,", -1);
#endif

#ifdef BURST_MODE
    UARTConfigPuts(uartBaseAddr, " Burst,", -1);
#else
    UARTConfigPuts(uartBaseAddr, " Non-burst,", -1);
#endif

#ifdef DMA_ENABLE
    UARTConfigPuts(uartBaseAddr, " DMA Mode\n", -1);
#else
    UARTConfigPuts(uartBaseAddr, " CPU Mode\n", -1);
#endif

    /* Initialize timer14 for benchmarking */
    TIMER14_TCLR = 0;
    TIMER14_TLDR = 0;
    TIMER14_TCRR = 0;
    TIMER14_TMAR = 0;
    TIMER14_TSICR = 0;
    TIMER14_TCLR = 0x1;

    /* Calculate timer overhead */
    t_start = TIMER14_TCRR;
    t_stop = TIMER14_TCRR;
    t_overhead = t_stop - t_start;

#ifdef DMA_ENABLE  //DMA

    srcBuff1 = (signed char *) (_srcBuff1);
    dstBuff1 = (signed char *) 0x08000000;

    /*
     * Initialize the source address with a pattern
     */
    for (i = 0U; i < (MAX_ACOUNT * MAX_BCOUNT * MAX_CCOUNT); i += 4)
    {
        srcBuff1[i] = (int) 0xFF;
        srcBuff1[i + 1] = (int) 0xFF;
        srcBuff1[i + 2] = (int) 0x00;
        srcBuff1[i + 3] = (int) 0x00;
    }

    UARTConfigPuts(uartBaseAddr, "\nStarting DMA Writes", -1);

    /* Start DMA writes */
    t_delta_dma_writes = dma_polled(edma_ch_num, edma_tcc_num, edma_evtq_num,
    MAX_ACOUNT,
                                    MAX_BCOUNT,
                                    MAX_CCOUNT);

    t_delta_dma_writes -= t_overhead;

    srcBuff1 = (signed char *) 0x08000000;
    dstBuff1 = (signed char *) (_dstBuff1);

    UARTConfigPuts(uartBaseAddr, "\nCompleted DMA Writes\n", -1);

    UARTConfigPuts(uartBaseAddr, "\nStarting DMA Reads", -1);

    /* Start DMA reads */

    t_delta_dma_reads = dma_polled(edma_ch_num, edma_tcc_num, edma_evtq_num,
    MAX_ACOUNT,
                                   MAX_BCOUNT,
                                   MAX_CCOUNT);

    t_delta_dma_reads -= t_overhead;

    UARTConfigPuts(uartBaseAddr, "\nCompleted DMA Reads\n", -1);

#else //CPU
    UARTConfigPuts(uartBaseAddr, "\nStarting CPU Writes", -1);

    t_start = TIMER14_TCRR;
    for(i=0;i<4;i++)
    {
        *GPMC0 = 0xFFFFFFFF;
        *GPMC1 = 0x00000000;
        *GPMC2 = 0xAAAAAAAA;
        *GPMC3 = 0x55555555;
        *GPMC4 = 0xFFFFFFFF;
        *GPMC5 = 0x00000000;
        *GPMC6 = 0xFFFFFFFF;
        *GPMC7 = 0xAAAAAAAA;
    }
    t_stop = TIMER14_TCRR;
    t_delta_cpu_writes = t_stop - t_start - t_overhead;

    UARTConfigPuts(uartBaseAddr, "\nCompleted CPU Writes\n", -1);
    UARTConfigPuts(uartBaseAddr, "\nStarting CPU Reads", -1);

    t_start = TIMER14_TCRR;
    for(i=0;i<4;i++)
    {
        var0 = *GPMC0;
        var0 = *GPMC1;
        var0 = *GPMC2;
        var0 = *GPMC3;
        var0 = *GPMC4;
        var0 = *GPMC5;
        var0 = *GPMC6;
        var0 = *GPMC7;
    }
    t_stop = TIMER14_TCRR;
    t_delta_cpu_reads = t_stop - t_start - t_overhead;

    UARTConfigPuts(uartBaseAddr, "\nCompleted CPU Reads\n", -1);

#endif

    UARTConfigPuts(uartBaseAddr, "\nBenchmarks:\n", -1);

#ifdef DMA_ENABLE
    UARTConfigPuts(uartBaseAddr, "\nDMA Write: ", -1);
    UARTConfigPutNum(uartBaseAddr, t_delta_dma_writes);
    UARTConfigPuts(uartBaseAddr, " Cycles", -1);
    UARTConfigPuts(uartBaseAddr, "\nDMA Read: ", -1);
    UARTConfigPutNum(uartBaseAddr, t_delta_dma_reads);
    UARTConfigPuts(uartBaseAddr, " Cycles", -1);
#else
    UARTConfigPuts(uartBaseAddr, "\nCPU Write: ", -1);
    UARTConfigPutNum(uartBaseAddr, t_delta_cpu_writes);
    UARTConfigPuts(uartBaseAddr, " Cycles", -1);
    UARTConfigPuts(uartBaseAddr, "\nCPU Read: ", -1);
    UARTConfigPutNum(uartBaseAddr, t_delta_cpu_reads);
    UARTConfigPuts(uartBaseAddr, " Cycles", -1);

#endif

#ifdef DMA_ENABLE
#ifdef SYNC_MODE

#ifdef BURST_MODE

    if ((0 <= t_delta_dma_writes && t_delta_dma_writes < 35)
            && (0 <= t_delta_dma_reads && t_delta_dma_reads < 35))
    {
        UARTConfigPuts(uartBaseAddr,
                       "\n\nSynchronous, Burst, DMA GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr,
                       "\n\nSynchronous, Burst, DMA GPMC Test Has Failed.", -1);
    }

#else
    if((0 <= t_delta_dma_writes && t_delta_dma_writes < 50) && (0 <= t_delta_dma_reads && t_delta_dma_reads < 45))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Non-burst DMA GPMC Test Has Passed.", -1);
        else
        {
            UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Non-burst, DMA GPMC Test Has Failed.", -1);
        }
#endif
#else
#ifdef BURST_MODE

    if((0 <= t_delta_dma_writes && t_delta_dma_writes < 50) && (0 <= t_delta_dma_reads && t_delta_dma_reads < 35))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Burst, DMA GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Burst, DMA GPMC Test Has Failed.", -1);
    }

#else

    if((0 <= t_delta_dma_writes && t_delta_dma_writes < 55) && (0 <= t_delta_dma_reads && t_delta_dma_reads < 40))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Non-burst, DMA GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Non-burst, DMA GPMC Test Has Failed.", -1);
    }

#endif
#endif
#else
#ifdef SYNC_MODE
#ifdef BURST_MODE

    if((0 <= t_delta_cpu_writes && t_delta_cpu_writes < 10) && (0 <= t_delta_cpu_reads && t_delta_cpu_reads < 310))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Burst, CPU GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Burst, CPU GPMC Test Has Failed.", -1);
    }

#else

    if((0 <= t_delta_cpu_writes && t_delta_cpu_writes < 25) && (0 <= t_delta_cpu_reads && t_delta_cpu_reads < 700))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Non-burst, CPU GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nSynchronous, Non-burst, CPU GPMC Test Has Failed.", -1);
    }

#endif
#else

#ifdef BURST_MODE

    if((0 <= t_delta_cpu_writes && t_delta_cpu_writes < 25) && (0 <= t_delta_cpu_reads && t_delta_cpu_reads < 300))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Burst, CPU GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Burst, CPU GPMC Test Has Failed.", -1);
    }

#else

    if((0 <= t_delta_cpu_writes && t_delta_cpu_writes < 20) && (0 <= t_delta_cpu_reads && t_delta_cpu_reads < 700))
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Non-burst, CPU GPMC Test Has Passed.", -1);
    }
    else
    {
        UARTConfigPuts(uartBaseAddr, "\n\nAsynchronous, Non-burst, CPU GPMC Test Has Failed.", -1);
    }

#endif
#endif
#endif
    UARTConfigPuts(uartBaseAddr, "\n\nExiting the GPMC Example\n", -1);

    while (1); //hang here

    return 0;
}

/* Configures GPMC registers with timing values optimized for an FPGA */
void GPMC_init(void)
{
    uint32_t baseAddr = CSL_MPU_GPMC_CONF_REGS_REGS;
    uint32_t config;

    /* Enable the chip select */
    GPMCCSConfig(baseAddr, GPMC_CHIP_SELECT_0, GPMC_CS_ENABLE);

    /* Select the chip-select base address, chip addr needs to be given */
    GPMCBaseAddrSet(baseAddr, GPMC_CHIP_SELECT_0, 0x00000008);

    /* Select the chip-select mask address */
    GPMCMaskAddrSet(baseAddr, GPMC_CHIP_SELECT_0, GPMC_CS_SIZE_64MB);

    /* Set the device size attached */
    GPMCDevSizeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_DEVICESIZE_16BITS);

    /* Set the read mode operation and write mode operation */
#ifdef SYNC_MODE
    GPMCReadTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_READTYPE_SYNC);
    GPMCWriteTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_WRITETYPE_SYNC);
#else
    GPMCReadTypeSelect(baseAddr,GPMC_CHIP_SELECT_0, GPMC_READTYPE_ASYNC);
    GPMCWriteTypeSelect(baseAddr,GPMC_CHIP_SELECT_0, GPMC_WRITETYPE_ASYNC);
#endif

    /* Select single access or multiple access reads and writes*/
#ifdef BURST_MODE
    GPMCAccessTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_MODE_READ,
    GPMC_ACCESSTYPE_MULTIPLE);
    GPMCAccessTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_MODE_WRITE,
    GPMC_ACCESSTYPE_MULTIPLE);
#else
    GPMCAccessTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_MODE_READ, GPMC_ACCESSTYPE_SINGLE);
    GPMCAccessTypeSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_MODE_WRITE, GPMC_ACCESSTYPE_SINGLE);
#endif

    /* Set the signals timing latencies scalar factor */
    GPMCTimeParaGranularitySelect(baseAddr, GPMC_CHIP_SELECT_0,
    GPMC_TIMEPARAGRANULARITY_X1);

    /* Set the address and data multiplexed protocol */
    GPMCAddrDataMuxProtocolSelect(baseAddr, GPMC_CHIP_SELECT_0,
    GPMC_MUXADDDATA_NOMUX);

    /* Set the timing parameters for the chip select signal */
    //CSWROFFTIME, CSRDOFFTIME, CSEXTRADELAY, CSONTIME
    config = GPMC_CS_TIMING_CONFIG(10, 7, GPMC_CS_EXTRA_NODELAY, 0);
    GPMCCSTimingConfig(baseAddr, GPMC_CHIP_SELECT_0, config);

    /* Set the timing parameters for the ADV# signal */
    /* ADVAADMUXWROFFTIME, ADVAADMUXRDOFFTIME, ADVWROFFTIME, ADVRDOFFTIME, ADVEXTRADELAY, ADVAADMUXONTIME, ADVONTIME */
    config = GPMC_ADV_TIMING_CONFIG(0, 0, 4, 4, GPMC_ADV_EXTRA_NODELAY, 0, 0);
    GPMCADVTimingConfig(baseAddr, GPMC_CHIP_SELECT_0, config);

    /* Set the timing parameters for the WE# and OE# signals */
    /* WEOFFTIME, WEEXTRADELAY, WEONTIME, OEAADMUX_OFFTIME, OEOFFTIME, OEEXTRADELAY, OEAADMUX_ONTIME, OEONTIME */
    config = GPMC_WE_OE_TIMING_CONFIG(7, 0, 4, 0, 7, GPMC_OE_EXTRA_NODELAY, 0,
                                      4);
    GPMCWEAndOETimingConfig(baseAddr, GPMC_CHIP_SELECT_0, config);

    /* Set the RdAccessTime and CycleTime timing parameters */
    /* RDCYCLETIME, WRCYCLETIME, RDACCESSTIME, PAGEBURSTACCESSTIME */
    config = GPMC_RDACCESS_CYCLETIME_TIMING_CONFIG(9, 9, 6, 3);
    GPMCRdAccessAndCycleTimeTimingConfig(baseAddr, GPMC_CHIP_SELECT_0, config);

    /* Configure the Cycle2Cycle and BusTurnAround timing parameters */
    /* CYCLE2CYCLEDELAY, CYCLE2CYCLEDELAYSAMECSCFG, CYCLE2CYCLEDELAYDIFFCSCFG, BUSTATIME */
    config = GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG(
            2, GPMC_CYCLE2CYCLESAMECSEN_C2CDELAY,
            GPMC_CYCLE2CYCLEDIFFCSEN_NOC2CDELAY, 0);
    GPMCycle2CycleAndTurnArndTimeTimingConfig(baseAddr, GPMC_CHIP_SELECT_0,
                                              config);

    /* Configure the WrAccessTime, Cycle2Cycle andBusTurnAround timing parameters.*/
    /* WRACCESSTIME, WRDATAONADMUXBUS */
    GPMCWrAccessAndWrDataOnADMUXBusTimingConfig(baseAddr, GPMC_CHIP_SELECT_0, 6,
                                                4);

    /* Set the FCLK divide down value */
    GPMCFclkDividerSelect(baseAddr, GPMC_CHIP_SELECT_0, GPMC_FCLK_DIV_BY_3);

    /* Set the attached device page (burst) length */
    GPMCDevPageLenSet(baseAddr, GPMC_CHIP_SELECT_0,
    GPMC_DEV_PAGELENGTH_SIXTEEN);

}

void padConfig_prcmEnable(void)
{
    /*Pad configurations */
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART3_RXD,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART3_TXD,
            0x00000000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART2_CTSN,
            0x00060002);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART2_RTSN,
            0x00060001);
    /*Pad configurations*/
    /*GPMC Data lines AD0-AD15*/
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD0,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD1,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD2,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD3,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD4,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD5,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD6,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD7,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD8,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD9,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD10,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD11,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD12,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD13,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD14,
            0x00050000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_AD15,
            0x00050000);
    /*GPMC Add lines A0-A27*/
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A0,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A1,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A2,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A3,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A4,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A5,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A6,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A7,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A8,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A9,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A10,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A11,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A12,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A13,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A14,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A15,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A16,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A17,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A18,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A19,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A20,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A21,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A22,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A23,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A24,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A25,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A26,
            0x00040000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_A27,
            0x00040000);
    /*GPMC chip select*/
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_CS0,
            0x00060000);
    /*GPMC control lines*/
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_ADVN_ALE,
            0x00060000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_OEN_REN,
            0x00070000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_WEN,
            0x00070000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_BEN0,
            0x00070000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_WAIT0,
            0x000F0000);
    HW_WR_REG32(
            CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_GPMC_CLK,
            0x00060000);
}
/***************************** End Of File ***********************************/
