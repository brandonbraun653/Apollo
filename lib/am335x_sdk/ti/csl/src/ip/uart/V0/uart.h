/**
 * @file   uart.h
 *
 * @brief  This file contains the prototypes of the functions defined in
 *         <uart.c>. This also contains some related macro
 *         definitions and some files to be included.
 *
 */

/*
* Copyright (C) 2015 - 2018 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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

#ifndef UART_K2_LLD_H
#define UART_K2_LLD_H


#include <ti/csl/src/ip/uart/V0/cslr_uart.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
**                       MACRO DEFINITIONS
****************************************************************************/
#ifndef CSL_UART_FCR
#define CSL_UART_FCR                (CSL_UART_IIR) /* IIR & FCR have same offset */
#endif

#ifndef CSL_UART_THR
#define CSL_UART_THR                (CSL_UART_RBR) /* RBR & THR have same offset */
#endif

#define MEM_BARRIER_DISABLE
/* The size of the Transmitter FIFO. */
#define TX_FIFO_SIZE                        (16U)
/* The size of the Receiver FIFO. */
#define RX_FIFO_SIZE                        (16U)

/*
** Values to configure the Operating modes of UART.
*/
#define UART16x_OPER_MODE                   (CSL_UART_MDR_OSM_SEL__16XOVERSAMPLING)
#define UART13x_OPER_MODE                   (CSL_UART_MDR_OSM_SEL__13XOVERSAMPLING)
#define UART_DISABLED_MODE                  (CSL_UART_MDR_OSM_SEL_RESETVAL)

/****************************************************************************/
/*
** Values to control the Line characteristics.
*/

/* Break condition generation controls. */
#define UART_BREAK_COND_DISABLE             (CSL_UART_LCR_BC_DISABLE << \
                                             CSL_UART_LCR_BC_SHIFT)
#define UART_BREAK_COND_ENABLE              (CSL_UART_LCR_BC_ENABLE << \
                                             CSL_UART_LCR_BC_SHIFT)

/* Values to control parity feature. */

#define UART_PARITY_REPR_1                  (CSL_UART_LCR_SP_MASK | \
                                             (0 << \
                                             CSL_UART_LCR_EPS_SHIFT) | \
                                             CSL_UART_LCR_PEN_MASK)

#define UART_PARITY_REPR_0                  (CSL_UART_LCR_SP_MASK | \
                                             (1 << CSL_UART_LCR_EPS_SHIFT) | \
                                              CSL_UART_LCR_PEN_MASK)

#define UART_ODD_PARITY                     ((0 << CSL_UART_LCR_EPS_SHIFT) | \
                                             CSL_UART_LCR_PEN_MASK)

#define UART_EVEN_PARITY                    ((1 << CSL_UART_LCR_EPS_SHIFT) | \
                                             CSL_UART_LCR_PEN_MASK)

#define UART_PARITY_NONE                    (0x0 << CSL_UART_LCR_PEN_SHIFT)


#define UART_INT_MODEM_STAT                 (0x00000008u)
#define UART_INT_LINE_STAT                  (0x00000004u)
#define UART_INT_THR                        (0x00000002u)
#define UART_INT_RHR_CTI                    (0x00000001u)

/*
** \name Values related to status of Interrupt souces.
* @{
*/

/* \brief Values pertaining to status of UART Interrupt sources. */

#define UART_INTID_TX_THRES_REACH           (CSL_UART_IIR_INITD_THRE    \
                                             <<                         \
											 CSL_UART_IIR_INITD_SHIFT)
#define UART_INTID_RX_THRES_REACH           (CSL_UART_IIR_INITD_RDA     \
                                             <<                         \
											 CSL_UART_IIR_INITD_SHIFT)
#define UART_INTID_RX_LINE_STAT_ERROR       (CSL_UART_IIR_INITD_RLS     \
                                             <<                         \
											 CSL_UART_IIR_INITD_SHIFT)
#define UART_INTID_CHAR_TIMEOUT             (CSL_UART_IIR_INITD_CTI     \
                                             <<                         \
											 CSL_UART_IIR_INITD_SHIFT)

/****************************************************************************/
/*
** Miscellaneous macros.
*/
/*
** Values used to choose the trigger level granularity.
*/
#define UART_TRIG_LVL_GRANULARITY_4         (0x0000)
#define UART_TRIG_LVL_GRANULARITY_1         (0x0001)

/* Values to be used while switching between register configuration modes. */

#define UART_REG_CONFIG_MODE_A              (0x0080U)
#define UART_REG_CONFIG_MODE_B              (0x00BFU)
#define UART_REG_OPERATIONAL_MODE           (0x007FU)

/* Parameterized macro to configure the FIFO settings. */
#define UART_FIFO_CONFIG(rxTrig, txClr, rxClr, dmaMode1) \
                        ((uint32_t) \
                         ((((rxTrig) & 0xFFU) << 6U) | \
                          (((txClr) & 0x1U) << 5U) | \
                          (((rxClr) & 0x1U) << 4U) | \
                          ((dmaMode1) & 0x1U)))

/****************************************************************************/
/*
** Values to configure the FIFO control.
*/
#define UART_FIFO_ENABLE            ((uint32_t)0x1u)    /* TX/RX FIFOs mode enable */
#define UART_FIFO_DISABLE           ((uint32_t)0x0u)    /* TX/RX FIFOs mode disable */
#define UART_FIFO_TXCLR             ((uint32_t)0x1u)    /* Clears TX FIFO */
#define UART_FIFO_RXCLR             ((uint32_t)0x1u)    /* Clears RX FIFO */
#define UART_FIFO_DMAMODE1_ENABLE   ((uint32_t)0x1u)    /* DMA mode 1 enable */
#define UART_FIFO_DMAMODE1_DISABLE  ((uint32_t)0x0u)    /* DMA mode 1 disable */
#define UART_FIFO_RXTL0             ((uint32_t)0x0u)    /* RX FIFO trigger level 0: 1 byte */
#define UART_FIFO_RXTL1             ((uint32_t)0x1u)    /* RX FIFO trigger level 1: 4 byte */
#define UART_FIFO_RXTL2             ((uint32_t)0x2u)    /* RX FIFO trigger level 2: 8 byte */
#define UART_FIFO_RXTL3             ((uint32_t)0x3u)    /* RX FIFO trigger level 3: 14 byte */

#define UART_FIFO_RXTRIG_SHIFT      (CSL_UART_FCR_RXFIFTL_SHIFT)

#define UART_FIFO_CONFIG_RXTRIG     ((0xFFU) << 6U)
#define UART_FIFO_CONFIG_TXCLR      (UART_FIFO_TXCLR << 5)
#define UART_FIFO_CONFIG_RXCLR      (UART_FIFO_RXCLR << 4)
#define UART_FIFO_CONFIG_DMAMODE1   (UART_FIFO_DMAMODE1_ENABLE << 0)

/* Parameterized macro used to determine a value to be written to FCR. */
#define UART_FCR_PROGRAM(rxFIFOTrig, dmaMode1, txClr, rxClr, fifoEn) \
                        ((uint32_t) \
                         ((((rxFIFOTrig) << CSL_UART_FCR_RXFIFTL_SHIFT) & CSL_UART_FCR_RXFIFTL_MASK) | \
                          (((dmaMode1) << CSL_UART_FCR_DMAMODE1_SHIFT) & CSL_UART_FCR_DMAMODE1_MASK)| \
                          (((txClr) << CSL_UART_FCR_TXCLR_SHIFT) & CSL_UART_FCR_TXCLR_MASK) | \
                          (((rxClr) << CSL_UART_FCR_RXCLR_SHIFT) & CSL_UART_FCR_RXCLR_MASK)| \
                          ((fifoEn) & CSL_UART_FCR_FIFOEN_MASK)))

/*
** Values used to configure the power and emulation management register.
*/
#define UART_PWREMU_MGMT_ENABLE         (CSL_UART_PWREMU_MGMT_UTRST_MASK | \
                                         CSL_UART_PWREMU_MGMT_URRST_MASK | \
                                         CSL_UART_PWREMU_MGMT_FREE_MASK)


/*
** Values related to Line Status information.
*/
#define UART_FIFO_PE_FE_BI_DETECTED         (CSL_UART_LSR_RXFIFOE_MASK)
#define UART_BREAK_DETECTED_ERROR           (CSL_UART_LSR_BI_MASK)
#define UART_FRAMING_ERROR                  (CSL_UART_LSR_FE_MASK)
#define UART_PARITY_ERROR                   (CSL_UART_LSR_PE_MASK)
#define UART_OVERRUN_ERROR                  (CSL_UART_LSR_OE_MASK)

/* Values to enable/disable Loopback mode of operation. */

#define UART_LOOPBACK_MODE_ENABLE           (       \
        (uint32_t) CSL_UART_MCR_LOOP_ENABLE << \
        CSL_UART_MCR_LOOP_SHIFT)
#define UART_LOOPBACK_MODE_DISABLE          (       \
        (uint32_t) CSL_UART_MCR_LOOP_DISABLE << \
        CSL_UART_MCR_LOOP_SHIFT)

/******************************************************************************
**                  FUNCTION PROTOTYPES
******************************************************************************/

/* APIs pertaining to UART. */

extern uint32_t UART_operatingModeSelect_v0(uint32_t baseAdd,
                                            uint32_t modeFlag);
extern uint32_t UART_divisorValCompute_v0(uint32_t moduleClk,
                                          uint32_t baudRate,
                                          uint32_t modeFlag);
extern uint32_t UART_divisorLatchWrite_v0(uint32_t baseAdd,
                                          uint32_t divisorValue);
extern void UART_divisorLatchEnable_v0(uint32_t baseAdd);
extern void UART_divisorLatchDisable_v0(uint32_t baseAdd);
extern uint32_t UART_regConfigModeEnable_v0(uint32_t baseAdd,
                                     uint32_t modeFlag);
extern void UART_breakCtl_v0(uint32_t baseAdd, uint32_t breakState);
extern void UART_lineCharacConfig_v0(uint32_t baseAdd,
                                 uint32_t wLenStbFlag,
                                 uint32_t parityFlag);
extern void UART_parityModeSet_v0(uint32_t baseAdd, uint32_t parityFlag);
extern uint32_t UART_parityModeGet_v0(uint32_t baseAdd);

extern uint32_t UART_fIFOConfig_v0(uint32_t baseAdd,
                                   uint32_t fifoConfig);

extern void UART_intEnable_v0(uint32_t baseAdd, uint32_t intFlag);
extern void UART_intDisable_v0(uint32_t baseAdd, uint32_t intFlag);
extern int8_t UART_charGetNonBlocking_v0(uint32_t baseAdd);
extern int8_t UART_charGet_v0(uint32_t baseAdd);
extern int32_t UART_charGetTimeout_v0(uint32_t baseAdd,
                                        uint32_t timeOutVal);

extern void UART_charPut_v0(uint32_t baseAdd, uint8_t byteTx);
extern void UART_fIFOCharPut_v0(uint32_t baseAdd, uint8_t byteTx);
extern int8_t UART_fIFOCharGet_v0(uint32_t baseAdd);
extern uint32_t UART_fIFOWrite_v0(uint32_t baseAdd, const uint8_t *pBuffer,
                                  uint32_t numTxBytes);
extern void UART_fIFORegisterWrite_v0(uint32_t baseAdd, uint32_t fcrValue);
extern void UART_fifoWait_v0(uint32_t baseAdd);
extern uint32_t UART_fifoEmpty_v0(uint32_t baseAdd);

extern uint32_t UART_intIdentityGet_v0(uint32_t baseAdd);
extern uint32_t UART_pwremuConfig_v0(uint32_t baseAdd, uint32_t pwremuConfig);
extern uint32_t UART_readLineStatus_v0(uint32_t baseAddr);

/**
 * \brief  This API controls(enables/disables) the Loopback mode of operation
 *         for the UART instance.
 *
 * \param  baseAddr     Memory address of the UART instance being used
 * \param  controlFlag  This specifies whether to enable or disable Loopback
 *                      mode of operation
 * 'controlFlag' can take one of the following values:
 * - UART_LOOPBACK_MODE_ENABLE -  to enable Loopback mode of operation\n
 * - UART_LOOPBACK_MODE_DISABLE - to disable Loopback mode and thus resulting
 *                                in switching to Normal operating mode\n
 *
 * \return None
 */
extern void UART_loopbackModeControl_v0(uint32_t baseAddr, uint32_t controlFlag);

/**
 * \brief    This API reads a byte from the Receiver Buffer Register
 *           (RBR). It checks once if any character is ready to be read.
 *
 * \param    baseAddr     Memory address of the UART instance being used.
 *
 * \param    pChar        Pointer to the byte variable which saves the byte
 *                        read from RBR if there is any char ready to be read
 *
 * \return   If the RHR was found to have atleast one byte of data
 *           ,then this API returns TRUE. Else it returns FALSE.
 */
extern uint32_t UART_charGetNonBlocking2_v0(uint32_t baseAdd, uint8_t *pChar);

/**
 * \brief   This API waits for the arrival of atleast one byte into the
 *          Receiver FIFO or until a specified timeout value gets decremented
 *          to zero, whichever happens first. This is a replacement for the
 *          UART_charGetTimeout_v0 which will incorrectly return timeout if
 *          the UART receives 0xFF as data.
 *
 * \param   baseAdd     Memory address of the UART instance being used.
 * \param   timeOutVal  The timeout value that is to be used. This timeout
 *                      value gets decremented once per iteration of the
 *                      wait loop.
 * \param    pChar      Pointer to the byte variable which saves the byte
 *                      read from RBR if there is any char ready to be read
 *
 * \return  This returns either of the below two values:\n
 *          1) If a character was keyed in before the timeout value gets
 *             decremented to zero, this API returns TRUE.\n
 *          2) If no character was input within the timeout value getting
 *             decremented to zero, this API returns FLASE.\n
 */
 extern uint32_t UART_charGetTimeout2_v0(uint32_t baseAdd,
                                        uint32_t timeOutVal,
                                        uint8_t *pChar);
#ifdef __cplusplus
}
#endif

#endif

/********************************* End of File********************************/

