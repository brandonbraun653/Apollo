/********************************************************************
* Copyright (C) 2003-2018 Texas Instruments Incorporated.
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

/** ============================================================================
 *   @file  cslr_mdio.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Desciptions for MDIO
 *
 */

#ifndef CSLR_MDIO_H_
#define CSLR_MDIO_H_

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a)  Modified the header file includes to be RTSC compliant
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 VERSION;
    volatile Uint32 CONTROL;
    volatile Uint32 ALIVE;
    volatile Uint32 LINK;
    volatile Uint32 LINKINTRAW;
    volatile Uint32 LINKINTMASKED;
    volatile Uint8 RSVD0[8];
    volatile Uint32 USERINTRAW;
    volatile Uint32 USERINTMASKED;
    volatile Uint32 USERINTMASKSET;
    volatile Uint32 USERINTMASKCLEAR;
    volatile Uint8 RSVD1[80];
    volatile Uint32 USERACCESS0;
    volatile Uint32 USERPHYSEL0;
    volatile Uint32 USERACCESS1;
    volatile Uint32 USERPHYSEL1;
} CSL_MdioRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* VERSION */

#define CSL_MDIO_VERSION_MODID_MASK      ((uint32_t)(0xFFFF0000u))
#define CSL_MDIO_VERSION_MODID_SHIFT     ((uint32_t)(0x00000010u))
#define CSL_MDIO_VERSION_MODID_RESETVAL  ((uint32_t)(0x00000007u))

#define CSL_MDIO_VERSION_REVMAJ_MASK     ((uint32_t)(0x0000FF00u))
#define CSL_MDIO_VERSION_REVMAJ_SHIFT    ((uint32_t)(0x00000008u))
#define CSL_MDIO_VERSION_REVMAJ_RESETVAL ((uint32_t)(0x00000001u))

#define CSL_MDIO_VERSION_REVMIN_MASK     ((uint32_t)(0x000000FFu))
#define CSL_MDIO_VERSION_REVMIN_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_MDIO_VERSION_REVMIN_RESETVAL ((uint32_t)(0x00000004u))

#define CSL_MDIO_VERSION_RESETVAL        ((uint32_t)(0x00070104u))

/* CONTROL */

#define CSL_MDIO_CONTROL_IDLE_MASK       ((uint32_t)(0x80000000u))
#define CSL_MDIO_CONTROL_IDLE_SHIFT      ((uint32_t)(0x0000001Fu))
#define CSL_MDIO_CONTROL_IDLE_RESETVAL   ((uint32_t)(0x00000001u))

/*----IDLE Tokens----*/
#define CSL_MDIO_CONTROL_IDLE_NO         ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_IDLE_YES        ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_ENABLE_MASK     ((uint32_t)(0x40000000u))
#define CSL_MDIO_CONTROL_ENABLE_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_MDIO_CONTROL_ENABLE_RESETVAL ((uint32_t)(0x00000000u))

/*----ENABLE Tokens----*/
#define CSL_MDIO_CONTROL_ENABLE_NO       ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_ENABLE_YES      ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_HIGHEST_USER_CHANNEL_MASK ((uint32_t)(0x1F000000u))
#define CSL_MDIO_CONTROL_HIGHEST_USER_CHANNEL_SHIFT ((uint32_t)(0x00000018u))
#define CSL_MDIO_CONTROL_HIGHEST_USER_CHANNEL_RESETVAL ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_PREAMBLE_MASK   ((uint32_t)(0x00100000u))
#define CSL_MDIO_CONTROL_PREAMBLE_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_MDIO_CONTROL_PREAMBLE_RESETVAL ((uint32_t)(0x00000000u))

/*----PREAMBLE Tokens----*/
#define CSL_MDIO_CONTROL_PREAMBLE_ENABLED ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_PREAMBLE_DISABLED ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_FAULT_MASK      ((uint32_t)(0x00080000u))
#define CSL_MDIO_CONTROL_FAULT_SHIFT     ((uint32_t)(0x00000013u))
#define CSL_MDIO_CONTROL_FAULT_RESETVAL  ((uint32_t)(0x00000000u))

/*----FAULT Tokens----*/
#define CSL_MDIO_CONTROL_FAULT_NO        ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_FAULT_YES       ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_FAULTENB_MASK   ((uint32_t)(0x00040000u))
#define CSL_MDIO_CONTROL_FAULTENB_SHIFT  ((uint32_t)(0x00000012u))
#define CSL_MDIO_CONTROL_FAULTENB_RESETVAL ((uint32_t)(0x00000000u))

/*----FAULTENB Tokens----*/
#define CSL_MDIO_CONTROL_FAULTENB_NO     ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_FAULTENB_YES    ((uint32_t)(0x00000001u))

#define CSL_MDIO_CONTROL_CLKDIV_MASK     ((uint32_t)(0x0000FFFFu))
#define CSL_MDIO_CONTROL_CLKDIV_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_MDIO_CONTROL_CLKDIV_RESETVAL ((uint32_t)(0x000000FFu))

#define CSL_MDIO_CONTROL_RESETVAL        ((uint32_t)(0x810000FFu))

/* ALIVE */

#define CSL_MDIO_ALIVE_ALIVE_MASK        ((uint32_t)(0xFFFFFFFFu))
#define CSL_MDIO_ALIVE_ALIVE_SHIFT       ((uint32_t)(0x00000000u))
#define CSL_MDIO_ALIVE_ALIVE_RESETVAL    ((uint32_t)(0x00000000u))

/*----ALIVE Tokens----*/
#define CSL_MDIO_ALIVE_ALIVE_DEAD        ((uint32_t)(0x00000000u))
#define CSL_MDIO_ALIVE_ALIVE_ALIVE       ((uint32_t)(0x00000001u))

#define CSL_MDIO_ALIVE_RESETVAL          ((uint32_t)(0x00000000u))

/* LINK */

#define CSL_MDIO_LINK_LINK_MASK          ((uint32_t)(0xFFFFFFFFu))
#define CSL_MDIO_LINK_LINK_SHIFT         ((uint32_t)(0x00000000u))
#define CSL_MDIO_LINK_LINK_RESETVAL      ((uint32_t)(0x00000000u))

/*----LINK Tokens----*/
#define CSL_MDIO_LINK_LINK_NOLINK        ((uint32_t)(0x00000000u))
#define CSL_MDIO_LINK_LINK_LINK          ((uint32_t)(0x00000001u))

#define CSL_MDIO_LINK_RESETVAL           ((uint32_t)(0x00000000u))

/* LINKINTRAW */

#define CSL_MDIO_LINKINTRAW_LINKINTRAW_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_LINKINTRAW_LINKINTRAW_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_LINKINTRAW_LINKINTRAW_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_LINKINTRAW_RESETVAL     ((uint32_t)(0x00000000u))

/* LINKINTMASKED */

#define CSL_MDIO_LINKINTMASKED_LINKINTMASKED_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_LINKINTMASKED_LINKINTMASKED_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_LINKINTMASKED_LINKINTMASKED_RESETVAL ((uint32_t)(0x00000000u))
/*----LINKINTMASKED Tokens----*/
#define CSL_MDIO_LINKINTMASKED_LINKINTMASKED_CLEAR_EVENT ((uint32_t)(0x00000001u))

#define CSL_MDIO_LINKINTMASKED_RESETVAL  ((uint32_t)(0x00000000u))

/* USERINTRAW */

#define CSL_MDIO_USERINTRAW_USERINTRAW_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_USERINTRAW_USERINTRAW_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERINTRAW_USERINTRAW_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERINTRAW_RESETVAL     ((uint32_t)(0x00000000u))

/* USERINTMASKED */

#define CSL_MDIO_USERINTMASKED_USERINTMASKED_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_USERINTMASKED_USERINTMASKED_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERINTMASKED_USERINTMASKED_RESETVAL ((uint32_t)(0x00000000u))
/*----USERINTMASKED Tokens----*/
#define CSL_MDIO_USERINTMASKED_USERINTMASKED_CLEAR_EVENT ((uint32_t)(0x00000001u))

#define CSL_MDIO_USERINTMASKED_RESETVAL  ((uint32_t)(0x00000000u))

/* USERINTMASKSET */

#define CSL_MDIO_USERINTMASKSET_USERINTMASKSET_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_USERINTMASKSET_USERINTMASKSET_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERINTMASKSET_USERINTMASKSET_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERINTMASKSET_RESETVAL ((uint32_t)(0x00000000u))

/* USERINTMASKCLEAR */

#define CSL_MDIO_USERINTMASKCLEAR_USERINTMASKCLEAR_MASK ((uint32_t)(0x00000003u))
#define CSL_MDIO_USERINTMASKCLEAR_USERINTMASKCLEAR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERINTMASKCLEAR_USERINTMASKCLEAR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERINTMASKCLEAR_RESETVAL ((uint32_t)(0x00000000u))

/* USERACCESS0 */

#define CSL_MDIO_USERACCESS0_GO_MASK     ((uint32_t)(0x80000000u))
#define CSL_MDIO_USERACCESS0_GO_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_MDIO_USERACCESS0_GO_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS0_WRITE_MASK  ((uint32_t)(0x40000000u))
#define CSL_MDIO_USERACCESS0_WRITE_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_MDIO_USERACCESS0_WRITE_RESETVAL ((uint32_t)(0x00000000u))

/*----WRITE Tokens----*/
#define CSL_MDIO_USERACCESS0_WRITE_READ  ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERACCESS0_WRITE_WRITE ((uint32_t)(0x00000001u))

#define CSL_MDIO_USERACCESS0_ACK_MASK    ((uint32_t)(0x20000000u))
#define CSL_MDIO_USERACCESS0_ACK_SHIFT   ((uint32_t)(0x0000001Du))
#define CSL_MDIO_USERACCESS0_ACK_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS0_REGADR_MASK ((uint32_t)(0x03E00000u))
#define CSL_MDIO_USERACCESS0_REGADR_SHIFT ((uint32_t)(0x00000015u))
#define CSL_MDIO_USERACCESS0_REGADR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS0_PHYADR_MASK ((uint32_t)(0x001F0000u))
#define CSL_MDIO_USERACCESS0_PHYADR_SHIFT ((uint32_t)(0x00000010u))
#define CSL_MDIO_USERACCESS0_PHYADR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS0_DATA_MASK   ((uint32_t)(0x0000FFFFu))
#define CSL_MDIO_USERACCESS0_DATA_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERACCESS0_DATA_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS0_RESETVAL    ((uint32_t)(0x00000000u))

/* USERPHYSEL0 */

#define CSL_MDIO_USERPHYSEL0_LINKSEL_MASK ((uint32_t)(0x00000080u))
#define CSL_MDIO_USERPHYSEL0_LINKSEL_SHIFT ((uint32_t)(0x00000007u))
#define CSL_MDIO_USERPHYSEL0_LINKSEL_RESETVAL ((uint32_t)(0x00000000u))

/*----LINKSEL Tokens----*/
#define CSL_MDIO_USERPHYSEL0_LINKSEL_MDIO ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERPHYSEL0_LINKINTENB_MASK ((uint32_t)(0x00000040u))
#define CSL_MDIO_USERPHYSEL0_LINKINTENB_SHIFT ((uint32_t)(0x00000006u))
#define CSL_MDIO_USERPHYSEL0_LINKINTENB_RESETVAL ((uint32_t)(0x00000000u))

/*----LINKINTENB Tokens----*/
#define CSL_MDIO_USERPHYSEL0_LINKINTENB_DISABLE ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERPHYSEL0_LINKINTENB_ENABLE ((uint32_t)(0x00000001u))

#define CSL_MDIO_USERPHYSEL0_PHYADRMON_MASK ((uint32_t)(0x0000001Fu))
#define CSL_MDIO_USERPHYSEL0_PHYADRMON_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERPHYSEL0_PHYADRMON_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERPHYSEL0_RESETVAL    ((uint32_t)(0x00000000u))

/* USERACCESS1 */

#define CSL_MDIO_USERACCESS1_GO_MASK     ((uint32_t)(0x80000000u))
#define CSL_MDIO_USERACCESS1_GO_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_MDIO_USERACCESS1_GO_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS1_WRITE_MASK  ((uint32_t)(0x40000000u))
#define CSL_MDIO_USERACCESS1_WRITE_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_MDIO_USERACCESS1_WRITE_RESETVAL ((uint32_t)(0x00000000u))

/*----WRITE Tokens----*/
#define CSL_MDIO_USERACCESS1_WRITE_READ  ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERACCESS1_WRITE_WRITE ((uint32_t)(0x00000001u))

#define CSL_MDIO_USERACCESS1_ACK_MASK    ((uint32_t)(0x20000000u))
#define CSL_MDIO_USERACCESS1_ACK_SHIFT   ((uint32_t)(0x0000001Du))
#define CSL_MDIO_USERACCESS1_ACK_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS1_REGADR_MASK ((uint32_t)(0x03E00000u))
#define CSL_MDIO_USERACCESS1_REGADR_SHIFT ((uint32_t)(0x00000015u))
#define CSL_MDIO_USERACCESS1_REGADR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS1_PHYADR_MASK ((uint32_t)(0x001F0000u))
#define CSL_MDIO_USERACCESS1_PHYADR_SHIFT ((uint32_t)(0x00000010u))
#define CSL_MDIO_USERACCESS1_PHYADR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS1_DATA_MASK   ((uint32_t)(0x0000FFFFu))
#define CSL_MDIO_USERACCESS1_DATA_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERACCESS1_DATA_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERACCESS1_RESETVAL    ((uint32_t)(0x00000000u))

/* USERPHYSEL1 */

#define CSL_MDIO_USERPHYSEL1_LINKSEL_MASK ((uint32_t)(0x00000080u))
#define CSL_MDIO_USERPHYSEL1_LINKSEL_SHIFT ((uint32_t)(0x00000007u))
#define CSL_MDIO_USERPHYSEL1_LINKSEL_RESETVAL ((uint32_t)(0x00000000u))

/*----LINKSEL Tokens----*/
#define CSL_MDIO_USERPHYSEL1_LINKSEL_MDIO ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERPHYSEL1_LINKINTENB_MASK ((uint32_t)(0x00000040u))
#define CSL_MDIO_USERPHYSEL1_LINKINTENB_SHIFT ((uint32_t)(0x00000006u))
#define CSL_MDIO_USERPHYSEL1_LINKINTENB_RESETVAL ((uint32_t)(0x00000000u))

/*----LINKINTENB Tokens----*/
#define CSL_MDIO_USERPHYSEL1_LINKINTENB_DISABLE ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERPHYSEL1_LINKINTENB_ENABLE ((uint32_t)(0x00000001u))

#define CSL_MDIO_USERPHYSEL1_PHYADRMON_MASK ((uint32_t)(0x0000001Fu))
#define CSL_MDIO_USERPHYSEL1_PHYADRMON_SHIFT ((uint32_t)(0x00000000u))
#define CSL_MDIO_USERPHYSEL1_PHYADRMON_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_MDIO_USERPHYSEL1_RESETVAL    ((uint32_t)(0x00000000u))


#ifdef __cplusplus
}
#endif

#endif
