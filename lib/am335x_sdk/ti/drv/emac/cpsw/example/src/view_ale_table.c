/*
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
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



// $Id: view_ale_table.c,v 1.2 2010-10-15 19:48:13 a0797633 Exp $

#include "cpsw_singlecore.h"

/* Chip Level definitions include */
#include <ti/csl/csl_chip.h>
#ifdef __LINUX_USER_SPACE
#include "armv7/linux/fw_test.h"
#endif

/* CSL EMAC include */
#include <ti/csl/csl_cpsw.h>

#ifdef __LINUX_USER_SPACE
void view_ale_table(void)
{
   return;
}
#else
void view_ale_table(void)
{
	int i;
	CSL_CPSW_ALE_UNICASTADDR_ENTRY  ucastAddrCfg;
	
	for (i = 0; i < CSL_CPSW_NUMALE_ENTRIES; i++) {
		if (CSL_CPSW_getALEEntryType(i) != ALE_ENTRYTYPE_FREE) {	/* Found a free entry */
			CSL_CPSW_getAleUnicastAddrEntry (i, &ucastAddrCfg);
			System_printf("Port = %d, ", ucastAddrCfg.portNumber);
			System_printf("MAC address = %02x:%02x:%02x:%02x:%02x:%02x, ",
				ucastAddrCfg.macAddress[0],
				ucastAddrCfg.macAddress[1],
				ucastAddrCfg.macAddress[2],
				ucastAddrCfg.macAddress[3],
				ucastAddrCfg.macAddress[4],
				ucastAddrCfg.macAddress[5]);
			System_printf("unicast_type = %d\n", ucastAddrCfg.ucastType);
		}
	}
}
#endif
