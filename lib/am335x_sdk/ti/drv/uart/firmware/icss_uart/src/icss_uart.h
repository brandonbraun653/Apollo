/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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

/*
* file:   icss_uart.h
*
* brief: This is a common header file for shared definitions for the UART LLD & UART PRU FW.
*
*/

#ifndef _ICSS_UART_H_
#define _ICSS_UART_H_


// TX and RX buffer size; assumptions are made based on 8-bit rollover
#define BUFF_SIZE                               ( 0x100 )


//
// Firmware UART instance registers
//

// UART instance register addresses

// UART configuration register offsets
#define UART_CTRL_OFFSET                        ( 0 )   // UART control offset
#define UART_CFG_OFFSET                         ( 4 )   // UART configuration offset
#define UART_RD_WR_PTRS_OFFSET                  ( 8 )   // Tx/Rx read/write buffer pointers offset
#define UART_TX_PIN_INT_OFFSET                  ( 12 )  // Tx pin/int offset
#define UART_RX_PIN_INT_OFFSET                  ( 16 )  // Rx pin/int offset
// UART register sizes (bytes)
#define UART_CTRL_SZ                            ( 4 )   // UART control size 
#define UART_CFG_SZ                             ( 4 )   // UART configuration size 
#define UART_RD_WR_PTRS_SZ                      ( 4 )   // Tx/Rx read/write buffer pointers size
#define UART_TX_PIN_INT_SZ                      ( 4 )   // Tx pin/int size
#define UART_RX_PIN_INT_SZ                      ( 4 )   // Rx pin/int size

// UART0 addresses
#define ICSS_UART0_CFG_ADDR                     ( 0x0014 )
#define UART0_CTRL                              ( ICSS_UART0_CFG_ADDR + UART_CTRL_OFFSET )          // UART0_CTRL FW register, UART control
#define UART0_CFG                               ( ICSS_UART0_CFG_ADDR + UART_CFG_OFFSET )           // UART0_CFG FW register, UART configuration
#define UART0_RD_WR_PTRS                        ( ICSS_UART0_CFG_ADDR + UART_RD_WR_PTRS_OFFSET )    // UART0_RD_WR_PTRS FW register, Tx/Rx Buffer Read/Write Pointers
#define UART0_TX_PIN_INT_CFG                    ( ICSS_UART0_CFG_ADDR + UART_TX_PIN_INT_OFFSET )    // UART0_TX_PIN_INT_CFG register, Tx pin/interrupt configuration
#define UART0_RX_PIN_INT_CFG                    ( ICSS_UART0_CFG_ADDR + UART_RX_PIN_INT_OFFSET )    // UART0_RX_PIN_INT_CFG register, Rx pin/interrupt configuration
#define UART0_TX_BUFFER                         ( 0x0100 )  // UART0 Tx buffer address
#define UART0_RX_BUFFER                         ( 0x0200 )  // UART0 Rx buffer address 

// UART1 addresses
#define ICSS_UART1_CFG_ADDR                     ( 0x0028 )
#define UART1_CTRL                              ( ICSS_UART1_CFG_ADDR + UART_CTRL_OFFSET )          // UART1_CTRL FW register, UART control
#define UART1_CFG                               ( ICSS_UART1_CFG_ADDR + UART_CFG_OFFSET )           // UART1_CFG FW register, UART configuration
#define UART1_RD_WR_PTRS                        ( ICSS_UART1_CFG_ADDR + UART_RD_WR_PTRS_OFFSET )    // UART1_RD_WR_PTRS FW register, Tx/Rx Buffer Read/Write Pointers
#define UART1_TX_PIN_INT_CFG                    ( ICSS_UART1_CFG_ADDR + UART_TX_PIN_INT_OFFSET )    // UART1_TX_PIN_INT_CFG register, Tx pin/interrupt configuration
#define UART1_RX_PIN_INT_CFG                    ( ICSS_UART1_CFG_ADDR + UART_RX_PIN_INT_OFFSET )    // UART1_RX_PIN_INT_CFG register, Rx pin/interrupt configuration
#define UART1_TX_BUFFER                         ( 0x0300 )  // UART1 Tx buffer address
#define UART1_RX_BUFFER                         ( 0x0400 )  // UART1 Rx buffer address

// UART2 addresses
#define ICSS_UART2_CFG_ADDR                     ( 0x003C )
#define UART2_CTRL                              ( ICSS_UART2_CFG_ADDR + UART_CTRL_OFFSET )          // UART2_CTRL FW register, UART control
#define UART2_CFG                               ( ICSS_UART2_CFG_ADDR + UART_CFG_OFFSET )           // UART2_CFG FW register, UART configuration
#define UART2_RD_WR_PTRS                        ( ICSS_UART2_CFG_ADDR + UART_RD_WR_PTRS_OFFSET )    // UART2_RD_WR_PTRS FW register, Tx/Rx Buffer Read/Write Pointers
#define UART2_TX_PIN_INT_CFG                    ( ICSS_UART2_CFG_ADDR + UART_TX_PIN_INT_OFFSET )    // UART2_TX_PIN_INT_CFG register, Tx pin/interrupt configuration
#define UART2_RX_PIN_INT_CFG                    ( ICSS_UART2_CFG_ADDR + UART_RX_PIN_INT_OFFSET )    // UART2_RX_PIN_INT_CFG register, Rx pin/interrupt configuration
#define UART2_TX_BUFFER                         ( 0x0500 )  // UART2 Tx buffer address
#define UART2_RX_BUFFER                         ( 0x0600 )  // UART2 Rx buffer address


// UART instance register bit fields

// UARTn_CTRL FW register bit fields
#define UART_CTRL__EN_SHIFT                     ( 0 )                                       // UART enable bit-field shift
#define UART_CTRL__EN_MASK                      ( 0x1 << UART_CTRL__EN_SHIFT )              // UART enable bit-field mask
#define UART_CTRL__TX_EN_ACK_SHIFT              ( 8 )                                       // UART Tx enable-ack bit-field shift
#define UART_CTRL__TX_EN_ACK_MASK               ( 0x1 << UART_CTRL__TX_EN_ACK_SHIFT )       // UART Tx enable-ack bit-field mask
#define UART_CTRL__RX_EN_ACK_SHIFT              ( 9 )                                       // UART Tx enable-ack bit-field shift
#define UART_CTRL__RX_EN_ACK_MASK               ( 0x1 << UART_CTRL__RX_EN_ACK_SHIFT )       // UART Rx enable-ack bit-field mask

// UARTn_CFG FW register bit fields
#define UART_CFG__BAUD_RATE_SHIFT               ( 0 )                                       // Baud rate bit-field shift
#define UART_CFG__BAUD_RATE_MASK                ( 0xF << UART_CFG__BAUD_RATE_SHIFT )        // Baud rate bit-field mask
#define UART_CFG__NO_BITS_PER_CHAR_SHIFT        ( 4 )                                       // Number of bits per character shift
#define UART_CFG__NO_BITS_PER_CHAR_MASK         ( 0x7 << UART_CFG__NO_BITS_PER_CHAR_SHIFT ) // Number of bits per character mask
#define UART_CFG__STOP_BIT_SZ_SHIFT             ( 7 )                                       // Stop bit shift
#define UART_CFG__STOP_BIT_SZ_MASK              ( 0x3 << UART_CFG__STOP_BIT_SZ_SHIFT )      // Stop bit size mask
#define UART_CFG__PARITY_EN_SHIFT               ( 9 )                                       // Parity enable shift
#define UART_CFG__PARITY_EN_MASK                ( 0x1 << UART_CFG__PARITY_EN_SHIFT)         // Parity enable mask
#define UART_CFG__PARITY_TYPE_SHIFT             ( 10 )                                      // Parity enable shift
#define UART_CFG__PARITY_TYPE_MASK              ( 0x1 << UART_CFG__PARITY_TYPE_SHIFT )      // Parity enable mask
#define UART_CFG__FC_EN_SHIFT                   ( 12 )                                      // Flow Control enable shift
#define UART_CFG__FC_EN_MASK                    ( 0x1 << UART_CFG__FC_EN_SHIFT )            // Flow Control enable mask
#define UART_CFG__FC_TYPE_SHIFT                 ( 13 )                                      // Flow Control type shift
#define UART_CFG__FC_TYPE_MASK                  ( 0x1 << UART_CFG__FC_TYPE_SHIFT )          // Flow Control type mask
#define UART_CFG__HW_FC_THR_SHIFT               ( 16 )                                      // HW Flow Control threshold shift
#define UART_CFG__HW_FC_THR_MASK                ( 0xFF << UART_CFG__HW_FC_THR_SHIFT )       // HW Flow Control threshold mask

// UARTn_RD_WR_PTRS FW register bit fields
#define TX_BUFF_RD_IDX_BYTEN                    ( 0 )
#define TX_BUFF_RD_IDX_SHIFT                    ( 0 )
#define TX_BUFF_RD_IDX_MASK                     ( 0xFF )
#define UART_RD_WR_PTRS__TX_BUFF_RD_IDX_SHIFT   ( TX_BUFF_RD_IDX_BYTEN*8 + TX_BUFF_RD_IDX_SHIFT )                   // Tx buffer read index shift 
#define UART_RD_WR_PTRS__TX_BUFF_RD_IDX_MASK    ( TX_BUFF_RD_IDX_MASK << UART_RD_WR_PTRS__TX_BUFF_RD_IDX_SHIFT )    // Tx buffer read index mask
#define TX_BUFF_WR_IDX_BYTEN                    ( 1 )
#define TX_BUFF_WR_IDX_SHIFT                    ( 0 )
#define TX_BUFF_WR_IDX_MASK                     ( 0xFF )
#define UART_RD_WR_PTRS__TX_BUFF_WR_IDX_SHIFT   ( TX_BUFF_WR_IDX_BYTEN*8 + TX_BUFF_WR_IDX_SHIFT )                   // Tx buffer write index shift
#define UART_RD_WR_PTRS__TX_BUFF_WR_IDX_MASK    ( TX_BUFF_WR_IDX_MASK << UART_RD_WR_PTRS__TX_BUFF_WR_IDX_SHIFT )    // Tx buffer write index mask
#define RX_BUFF_RD_IDX_BYTEN                    ( 2 )
#define RX_BUFF_RD_IDX_SHIFT                    ( 0 )
#define RX_BUFF_RD_IDX_MASK                     ( 0xFF )
#define UART_RD_WR_PTRS__RX_BUFF_RD_IDX_SHIFT   ( TX_BUFF_RD_IDX_BYTEN*8 + TX_BUFF_RD_IDX_SHIFT )                   // Rx buffer read index shift
#define UART_RD_WR_PTRS__RX_BUFF_RD_IDX_MASK    ( TX_BUFF_RD_IDX_MASK << UART_RD_WR_PTRS__RX_BUFF_RD_IDX_SHIFT )    // Rx buffer read index mask
#define RX_BUFF_WR_IDX_BYTEN                    ( 3 )
#define RX_BUFF_WR_IDX_SHIFT                    ( 0 )
#define RX_BUFF_WR_IDX_MASK                     ( 0xFF )
#define UART_RD_WR_PTRS__RX_BUFF_WR_IDX_SHIFT   ( RX_BUFF_WR_IDX_BYTEN*8 + RX_BUFF_WR_IDX_SHIFT )                   // Rx buffer write index shift
#define UART_RD_WR_PTRS__RX_BUFF_WR_IDX_MASK    ( RX_BUFF_WR_IDX_MASK << UART_RD_WR_PTRS__RX_BUFF_WR_IDX_SHIFT )    // Rx buffer write index mask

// UARTn_TX_PIN_INT_CFG FW register bit fields
#define TX_INT_NUM_BYTEN                        ( 0 )
#define TX_INT_NUM_SHIFT                        ( 0 )
#define TX_INT_NUM_MASK                         ( 0xF )
#define UART_TX_PIN_INT_CFG__TX_INT_NUM_SHIFT   ( TX_INT_NUM_BYTEN*8 + TX_INT_NUM_SHIFT )                           // Tx interrupt (System Event) number shift
#define UART_TX_PIN_INT_CFG__TX_INT_NUM_MASK    ( TX_INT_NUM_MASK << UART_TX_PIN_INT_CFG__TX_INT_NUM_SHIFT )        // Tx interrupt (System Event) number mask
#define TX_INT_EN_BYTEN                         ( 1 )
#define TX_INT_EN_SHIFT                         ( 0 )
#define TX_INT_EN_MASK                          ( 0x1 )
#define UART_TX_PIN_INT_CFG__TX_INT_EN_SHIFT    ( TX_INT_EN_BYTEN*8 + TX_INT_EN_SHIFT )                             // Tx interrupt enable shift
#define UART_TX_PIN_INT_CFG__TX_INT_EN_MASK     ( TX_INT_EN_MASK << UART_TX_PIN_INT_CFG__TX_INT_EN_SHIFT )          // Tx interrupt enable mask
#define TX_PIN_BYTEN                            ( 2 )
#define TX_PIN_SHIFT                            ( 0 )
#define TX_PIN_MASK                             ( 0xFF )
#define UART_TX_PIN_INT_CFG__TX_PIN_SHIFT       ( TX_PIN_BYTEN*8 + TX_PIN_SHIFT )                                   // Tx pin number shift
#define UART_TX_PIN_INT_CFG__TX_PIN_MASK        ( TX_PIN_MASK << UART_TX_PIN_INT_CFG__TX_PIN_SHIFT )                // Tx pin number mask
#define CTS_PIN_BYTEN                           ( 3 )
#define CTS_PIN_SHIFT                           ( 0 )
#define CTS_PIN_MASK                            ( 0xFF )
#define UART_TX_PIN_INT_CFG__CTS_PIN_SHIFT      ( CTS_PIN_BYTEN*8 + CTS_PIN_SHIFT )                                 // Tx CTS pin shift
#define UART_TX_PIN_INT_CFG__CTS_PIN_MASK       ( CTS_PIN_MASK << UART_TX_PIN_INT_CFG__CTS_PIN_SHIFT )               // Tx CTS pin mask

// UARTn_RX_PIN_INT_CFG FW register bit fields
#define RX_INT_NUM_BYTEN                        ( 0 )
#define RX_INT_NUM_SHIFT                        ( 0 )
#define RX_INT_NUM_MASK                         ( 0xF )
#define UART_RX_PIN_INT_CFG__RX_INT_NUM_SHIFT   ( RX_INT_NUM_BYTEN*8 + RX_INT_NUM_SHIFT )                           // Rx interrupt (System Event) number shift
#define UART_RX_PIN_INT_CFG__RX_INT_NUM_MASK    ( RX_INT_NUM_MASK << UART_RX_PIN_INT_CFG__RX_INT_NUM_SHIFT )        // Rx interrupt (System Event) number mask
#define RX_INT_EN_BYTEN                         ( 1 )
#define RX_INT_EN_SHIFT                         ( 0 )
#define RX_INT_EN_MASK                          ( 0x1 )
#define UART_RX_PIN_INT_CFG__RX_INT_EN_SHIFT    ( RX_INT_EN_BYTEN*8 + RX_INT_EN_SHIFT )                             // Rx interrupt enable shift
#define UART_RX_PIN_INT_CFG__RX_INT_EN_MASK     ( RX_INT_EN_MASK << UART_RX_PIN_INT_CFG__RX_INT_EN_SHIFT )          // Rx interrupt enable mask
#define RX_PIN_BYTEN                            ( 2 )
#define RX_PIN_SHIFT                            ( 0 )
#define RX_PIN_MASK                             ( 0xFF )
#define UART_RX_PIN_INT_CFG__RX_PIN_SHIFT       ( RX_PIN_BYTEN*8 + RX_PIN_SHIFT )                                   // Rx pin number shift
#define UART_RX_PIN_INT_CFG__RX_PIN_MASK        ( RX_PIN_MASK << UART_RX_PIN_INT_CFG__RX_PIN_SHIFT )                // Rx pin number mask
#define RTS_PIN_BYTEN                           ( 3 )
#define RTS_PIN_SHIFT                           ( 0 )
#define RTS_PIN_MASK                            ( 0xFF )
#define UART_RX_PIN_INT_CFG__RTS_PIN_SHIFT      ( RTS_PIN_BYTEN*8 + RTS_PIN_SHIFT )                                 // Rx RTS pin shift
#define UART_RX_PIN_INT_CFG__RTS_PIN_MASK       ( RTS_PIN_MASK << UART_RX_PIN_INT_CFG__RTS_PIN_SHIFT )              // Rx RTS pin mask

// Error bit locations in Rx character
#define RX_CHAR_FRAMING_ERR_SHIFT               ( 14 )                                  // Rx character framing error shift
#define RX_CHAR_FRAMING_ERR_MASK                ( 1 << RX_CHAR_FRAMING_ERR_SHIFT )      // Rx character frame error mask
#define RX_CHAR_PARITY_ERR_SHIFT                ( 15 )                                  // Rx character parity error shift
#define RX_CHAR_PARITY_ERR_MASK                 ( 1 <<  RX_CHAR_PARITY_ERR_SHIFT )      // Rx character parity error mask
#define RX_CHAR_ERR_MASK                        ( RX_CHAR_FRAMING_ERR_MASK | RX_CHAR_PARITY_ERR_MASK )


// UART instance bit field settings

// UART control
#define UART_CTRL__EN_DISABLE                   ( 0 )   // UART disabled 
#define UART_CTRL__EN_ENABLE                    ( 1 )   // UART enable
#define UART_CTRL__EN_ACK_DISABLE               ( 0 )   // UART disable ack
#define UART_CTRL__EN_ACK_ENABLE                ( 1 )   // UART enable ack

// Baud Rate
#define UART_CFG__BAUD_RATE_300                 ( 0 )   // 300 baud / sec 
#define UART_CFG__BAUD_RATE_600                 ( 1 )   // 600 baud / sec 
#define UART_CFG__BAUD_RATE_1200                ( 2 )   // 1200 baud / sec 
#define UART_CFG__BAUD_RATE_2400                ( 3 )   // 2400 baud / sec 
#define UART_CFG__BAUD_RATE_4800                ( 4 )   // 4800 baud / sec 
#define UART_CFG__BAUD_RATE_9600                ( 5 )   // 9600 baud / sec 
#define UART_CFG__BAUD_RATE_14400               ( 6 )   // 14400 baud / sec 
#define UART_CFG__BAUD_RATE_19200               ( 7 )   // 19200 baud / sec 
#define UART_CFG__BAUD_RATE_28800               ( 8 )   // 28800 baud / sec 
#define UART_CFG__BAUD_RATE_38400               ( 9 )   // 38400 baud / sec 
#define UART_CFG__BAUD_RATE_57600               ( 10 )  // 57600 baud / sec 
#define UART_CFG__BAUD_RATE_115200              ( 11 )  // 115200 baud / sec 

// Number of Bit per Character
#define UART_CFG__NUM_BITS_PER_CHAR_5           ( 0 )   // 5 bits per char
#define UART_CFG__NUM_BITS_PER_CHAR_6           ( 1 )   // 6 bits per char
#define UART_CFG__NUM_BITS_PER_CHAR_7           ( 2 )   // 7 bits per char
#define UART_CFG__NUM_BITS_PER_CHAR_8           ( 3 )   // 8 bits per char
#define UART_CFG__NUM_BITS_PER_CHAR_9           ( 4 )   // 9 bits per char

// Stop Bit Size
#define UART_CFG__STOP_BIT_SZ_1                 ( 0 )   // 1   stop bit size
#define UART_CFG__STOP_BIT_SZ_1_5               ( 1 )   // 1.5 stop bit size
#define UART_CFG__STOP_BIT_SZ_2                 ( 2 )   // 2   stop bit size

// Parity Enable
#define UART_CFG__PARITY_EN_DISABLE             ( 0 )   // parity disable
#define UART_CFG__PARITY_EN_ENABLE              ( 1 )   // parity enable

// Parity Type
#define UART_CFG__PARITY_TYPE_EVEN              ( 0 )   // parity even
#define UART_CFG__PARITY_TYPE_ODD               ( 1 )   // parity odd

// Flow Control Enable
#define UART_CFG__FC_EN_DISABLE                 ( 0 )   // flow control disable
#define UART_CFG__FC_EN_ENABLE                  ( 1 )   // flow control enable


//
// Firmware global registers
//

// Global register

#define ICSS_UART_GCFG_ADDR                     ( 0x0050 )
#define ICSS_UART_CGFG_OFFSET                   ( 0 )
#define ICSS_UART_GCFG_SZ                       ( 4 )   // bytes

// Firmware global register bit fields

#define PRU_ID_MASK                             ( 0x1 )
#define FW_INIT_MASK                            ( 0x1 )

#define ICSS_UART_GCFG__PRU_ID_SHIFT            ( 0 )                                               // PRU ID bit-field shift
#define ICSS_UART_GCFG__PRU_ID_MASK             ( PRU_ID_MASK << ICSS_UART_GCFG__PRU_ID_SHIFT )     // PRU ID bit-field mask
#define ICSS_UART_GCFG__FW_INIT_SHIFT           ( 1 )                                               // FW init bit-field shift
#define ICSS_UART_GCFG__FW_INIT_MASK            ( FW_INIT_MASK << ICSS_UART_GCFG__FW_INIT_SHIFT )   // FW init bit-field mask    

#define ICSS_UART_GCFG__FW_INIT_FALSE           ( 0 )   // FW not initialized
#define ICSS_UART_GCFG__FW_INIT_TRUE            ( 1 )   // FW initialized


#endif // _ICSS_UART_H_
