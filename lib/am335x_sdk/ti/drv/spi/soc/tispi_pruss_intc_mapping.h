/**
* @file ti_spi_pruss_intc_mapping.h
*
* @brief Pruss interrupt mapping related macros
*
* \par
* Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
* \par
*/

#ifndef TI_SPI_PRUSS_INTC_MAPPING_H
#define TI_SPI_PRUSS_INTC_MAPPING_H

#ifdef __cplusplus
extern "C" {
#endif

/* SYS_EVT_16-31 can be used for generating interrupts for IPC with hosts/prus etc */
#define IEP_TIM_CAP_CMP_EVENT	7
#define SYNC1_OUT_EVENT      13
#define SYNC0_OUT_EVENT      14
#define PRU_ARM_EVENT0       20 /* SYS_EVT_AL_EVENT_REQUEST */
#define PRU_ARM_EVENT1       21
#define PRU_ARM_EVENT2       22
#define PRU_ARM_EVENT3       23
#define PRU_ARM_EVENT4       24
#define PRU_ARM_EVENT5       25
#define PRU_ARM_EVENT6       26
#define PRU_ARM_EVENT7       27
#define ARM_PRU_EVENT        16 /* SYS_EVT_HOST_CMD */
#define PRU0_RX_ERR32_EVENT  33
#define PORT1_TX_UNDERFLOW	 39
#define PORT1_TX_OVERFLOW	 40
#define MII_LINK0_EVENT      41
#define PORT1_RX_EOF_EVENT   42   
#define PRU1_RX_ERR32_EVENT  45
#define PORT2_TX_UNDERFLOW	 51
#define PORT2_TX_OVERFLOW	 53
#define PORT2_RX_EOF_EVENT	 54	
#define MII_LINK1_EVENT      53

#define CHANNEL0                0
#define CHANNEL1                1
#define CHANNEL2                2
#define CHANNEL3                3
#define CHANNEL4                4
#define CHANNEL5                5
#define CHANNEL6                6
#define CHANNEL7                7
#define CHANNEL8                8
#define CHANNEL9                9

#define PRU0                    0
#define PRU1                    1
#define PRU_EVTOUT0             2
#define PRU_EVTOUT1             3
#define PRU_EVTOUT2             4
#define PRU_EVTOUT3             5
#define PRU_EVTOUT4             6
#define PRU_EVTOUT5             7
#define PRU_EVTOUT6             8
#define PRU_EVTOUT7             9

#define PRU0_HOSTEN_MASK            ((uint32_t)0x0001)
#define PRU1_HOSTEN_MASK            ((uint32_t)0x0002)
#define PRU_EVTOUT0_HOSTEN_MASK     ((uint32_t)0x0004)
#define PRU_EVTOUT1_HOSTEN_MASK     ((uint32_t)0x0008)
#define PRU_EVTOUT2_HOSTEN_MASK     ((uint32_t)0x0010)
#define PRU_EVTOUT3_HOSTEN_MASK     ((uint32_t)0x0020)
#define PRU_EVTOUT4_HOSTEN_MASK     ((uint32_t)0x0040)
#define PRU_EVTOUT5_HOSTEN_MASK     ((uint32_t)0x0080)
#define PRU_EVTOUT6_HOSTEN_MASK     ((uint32_t)0x0100)
#define PRU_EVTOUT7_HOSTEN_MASK     ((uint32_t)0x0200)

#define SYS_EVT_POLARITY_LOW        0
#define SYS_EVT_POLARITY_HIGH       1

#define SYS_EVT_TYPE_PULSE          0
#define SYS_EVT_TYPE_EDGE           1

#define PRUSS_INTC_INITDATA {   \
{ PRU_ARM_EVENT0, PRU_ARM_EVENT1, IEP_TIM_CAP_CMP_EVENT, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF /* initializing member [3-15] for Misra C standards */ \
  , 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF     /* initializing member [16-31] for Misra C standards */ \
  , 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF     /* initializing member [32-47] for Misra C standards */ \
  , 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},   /* initializing member [48-63] for Misra C standards */ \
{ {PRU_ARM_EVENT0, CHANNEL2, SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE},\
  {PRU_ARM_EVENT1, CHANNEL3, SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE},\
  {IEP_TIM_CAP_CMP_EVENT, CHANNEL7, SYS_EVT_POLARITY_HIGH ,SYS_EVT_TYPE_PULSE},	\
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [3] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [4] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [5] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [6] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [7] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [8] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [9] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [10] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [11] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [12] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [13] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [14] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [15] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [16] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [17] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [18] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [19] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [20] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [21] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [22] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [23] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [24] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [25] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [26] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [27] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [28] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [29] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [30] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [31] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [32] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [33] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [34] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [35] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [36] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [37] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [38] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [39] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [40] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [41] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [42] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [43] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [44] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [45] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [46] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [47] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [48] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [49] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [50] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [51] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [52] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [53] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [54] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [55] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [56] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [57] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [58] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [59] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [60] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [61] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}, /* initializing member [62] for Misra C standards */ \
  {0xFF,0xFF,0xFF,0xFF}}, /* initializing member [63] for Misra C standards */ \
  { {CHANNEL2, PRU_EVTOUT0}, {CHANNEL3, PRU_EVTOUT1}, {CHANNEL7, PRU1}\
  , {0xFF, 0xFF}, {0xFF, 0xFF}, {0xFF, 0xFF}, {0xFF, 0xFF}, {0xFF, 0xFF}, {0xFF, 0xFF}, {0xFF, 0xFF} }, /* Initializing members [3,4,5,6,7,8,9] of array for Misra C standards */ \
  (PRU0_HOSTEN_MASK | PRU1_HOSTEN_MASK | PRU_EVTOUT0_HOSTEN_MASK | PRU_EVTOUT1_HOSTEN_MASK \
  | PRU_EVTOUT2_HOSTEN_MASK | PRU_EVTOUT3_HOSTEN_MASK| PRU_EVTOUT4_HOSTEN_MASK| PRU_EVTOUT5_HOSTEN_MASK | PRU_EVTOUT6_HOSTEN_MASK|PRU_EVTOUT7_HOSTEN_MASK) /*Enable PRU0/1, PRU_EVTOUT0/1/2 */ \
} 
#ifdef __cplusplus
}
#endif


#endif /* TI_SPI_PRUSS_INTC_MAPPING_H */
