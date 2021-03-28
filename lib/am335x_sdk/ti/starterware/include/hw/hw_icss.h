/*
* hw_icss.h
*
* Register-level header file for HW_ICSS
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef HW_ICSS_H_
#define HW_ICSS_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
/** \brief PRUSS PRU Dataram offset. */
#define PRU_ICSS_DATARAM(n)        		(0x00000 + ((n) * 0x02000))

/** \brief PRUSS INTC register offset. */
#define PRU_ICSS_INTC           	    0x20000

/** \brief PRUSS PRUn Control register offset. */
#define PRU_ICSS_PRU_CTRL(n)	        (0x22000 + ((n) * 0x02000))

/** \brief PRUSS PRUn Debug register offset. */
#define PRU_ICSS_PRU_DEBUG(n)           (0x22400 + ((n) * 0x02000))

/** \brief PRUSS PRUn IRAM offset. */
#define PRU_ICSS_IRAM(n) 		        (0x34000 + ((n) * 0x04000))

/** \brief PRUSS PRU Shared RAM offset. */
#define PRU_ICSS_SHARED_RAM		        0x10000

/** \brief PRUSS PRU IEP register offset. */
#define	PRU_ICSS_CFG	                0x26000

/** \brief PRUSS PRU UART register offset. */
#define	PRU_ICSS_UART	                0x28000

/** \brief PRUSS PRU IEP register offset. */
#define	PRU_ICSS_IEP	                0x2e000

/** \brief PRUSS PRU ECAP register offset. */
#define	PRU_ICSS_ECAP		            0x30000

/** \brief PRUSS PRU MII-RT register offset. */
#define	PRU_ICSS_MIIRT	            	0x32000

/** \brief PRUSS PRU MDIO register offset. */
#define	PRU_ICSS_MDIO		            0x32400

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_H_ */
